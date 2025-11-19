#pragma once

class hkpExtendedMeshShape : public hkpShapeCollection
{
public:
	enum IndexStridingType
	{
		INDICES_INVALID,	///< default, will raise assert.
		INDICES_INT8,		///< 8 bit "single byte" striding.
		INDICES_INT16,		///< 16 bit "short" striding.
		INDICES_INT32,		///< 32 bit "int" striding.
		INDICES_MAX_ID
	};

	enum SubpartType
	{
		SUBPART_TRIANGLES = 0,
		SUBPART_SHAPE = 1,
		SUBPART_TYPE_MAX = 2
	};

	struct Subpart
	{
		/// Stores the number of materials, material index striding type and subpart type
		u16 m_typeAndFlags;

		/// Stores a 16 bit shape info
		u16 m_shapeInfo;

		/// The byte offset between two hkMeshMaterials
		i16 m_materialStriding; //+nosave

		/// The byte offset between two material indices (Usually sizeof(hkUint8) or...)
		u16 m_materialIndexStriding;

		/// A pointer, pointing to a strided array of material index (hkUint8), one index for each triangle.
		///  - You are limited to a maximum of 256 materials per subpart.
		///  - You are not forced to store those indices in a hkUint8 array, with the striding m_materialIndexStriding
		///    parameter you can extract this
		///  - If you do not want to use materials, simply set this element to HK_NULL
		const void* m_materialIndexBase; //+nosave

		/// The base for the material table, the byte offset between two hkMeshMaterials is defined by
		/// m_materialStriding.
		/// Note: On PlayStation(R)3 this must be aligned to a m_materialStriding boundary if you wish to access materials in your own code on SPU.
		const hkpMeshMaterial* m_materialBase; //+nosave

		/// User data associated with each subpart
		u64 m_userData;	//+default(0)
	};

	struct TrianglesSubpart : public Subpart
	{
		/// the number of triangles
		int	m_numTriangleShapes;

		//
		//	Vertex information
		//

		/// A pointer to the first vertex, defined by three floats.
		/// Must be aligned on a 16 byte boundary
		const f32* m_vertexBase; //+nosave

		/// The number of vertices.
		int m_numVertices;

		//
		// Triangle Index Information
		//

		/// A pointer to triples of vertex indices.
		/// Used to be a union type, but to make
		/// auto serialization possible, we leave it as
		/// a void* here.
		const void* m_indexBase; //+nosave

		/// The byte offset between two consecutive vertices (usually 12, 16 or more).
		u16 m_vertexStriding;

		/// This information is set automatically when a subpart is added to a mesh and should be left at -1.
		/// It is the offset in a global array for all triangles in the mesh of the first triangle of this sub piece.
		/// This info is used for "welding" collisions between triangles.
		int m_triangleOffset; //+default(-1)

		/// The byte offset between two indices triples.
		///  - E.g. (Usually sizeof(hkUint16) if you use triangle strips
		///  - or 3 * sizeof(hkUint16) if you use independent triangles
		u16 m_indexStriding;

		/// A type defining whether 8, 16, or 32 bits are used to index vertices.
		hkEnum<IndexStridingType, i8> m_stridingType;

		/// A flag used to specify whether triangles should be returned wound the same way
		/// or alternate ways. It must be set to 0 or 1, and defaults to 0.
		/// If Triangle strips are used, each subsequent triangle in a list
		/// will be wound the alternate way. However for one sided welding, we require that
		/// all triangles have a consistent winding. This flag should be set to 1 in this case. This
		/// means the first triangle will be returned with vertices set to (0, 1, 2) and the second
		/// triangle will be returned with vertices set to (1, 3, 2). If this flag is set to 0 the
		/// second triangle will be returned with vertices set to (1, 2, 3). If independent triangles
		/// are used this flag should be set to 0 to maintain winding.
		i8 m_flipAlternateTriangles;

		/// Triangle extrusion. This setting can help the bullet through paper issue in certain situations,
		/// without using continuous simulation, however it does not guarantee robust results. All triangles
		/// in this subpart are extruded in the direction specified (which defaults to 0, i.e is disabled). If you have a ground
		/// made of triangles, with nothing beneath it, you can extrude the triangles a few meters in the downwards direction.
		/// When high speed non-continuous debris hits the landscape it will be more likely to bounce off rather than
		/// tunnel through. The effects of this extrusion is improved when also using one sided welding, as contact
		/// points will be correctly rotated to point up, even when objects are deeply penetrating.
		hkVector4 m_extrusion;

		/// The transform to be applied on the vertices (translation, rotation, scaling). Usually used for instancing.
		hkQsTransformf m_transform;
	};

	struct ShapesSubpart : public Subpart
	{
		enum
		{
			FLAG_NONE,
			FLAG_TRANSLATE_SET,
			FLAG_ROTATE_SET
		};

		/// The child shapes forming this subpart.
		hkArray<hkRefPtr<hkpConvexShape>>	m_childShapes;
		hkQuaternionf	m_rotation;		///< The rotation of this subpart.
		hkVector4		m_translation;  ///< The translation of this subpart.
	};

	TrianglesSubpart m_embeddedTrianglesSubpart;
	hkVector4f m_aabbHalfExtents;
	hkVector4f m_aabbCenter;
	hkClass* m_materialClass;
	int m_numBitsForSubpartIndex;
	hkArray<TrianglesSubpart> m_trianglesSubparts;
	hkArray<ShapesSubpart> m_shapesSubparts;
	hkArray<u16> m_weldingInfo;
	hkEnum<hkpWeldingUtility::WeldingType, u8> m_weldingType;
	u32 m_defaultCollisionFilterInfo;
	int m_cachedNumChildShapes;
	f32 m_triangleRadius;
	int m_padding;

	/// Constructs a new hkpExtendedMeshShape.
	/// This mesh supports triangle soups as well as shape soups.
	///    - The triangles are grouped in subparts and can be transformed (translation, rotation, scaling) and get a radius applied
	///    - The shapes can be grouped in subparts and can be translated and rotated on a per subpart basis.
	/// "numBitsForSubpart" is the number of bits used (in the 32 bit shape key) for the subpart index.
	/// Note that the highest bit is used as the type identifier, discerning whether this subpart consists
	/// of triangles or convex shapes.
	/// The remaining bits from the 32 bit shape key are used for the terminal index. By
	/// default numBitsForSubpartIndex is 12, which means the mesh shape can have 2^11 - 1
	/// subparts (0xffffffff is the "invalid" shape key) = 2047, and each subpart can have 2^20 triangles = 1048576.
	/// The subpart is stored in the high bits, so you can extract subpart/terminal indices like this:
	///    - int subpartIndex = key >> ( 32 - mymesh->getNumBitsForSubpartIndex() );
	///    - int terminalIndex = key & ( ~0U >> mymesh->getNumBitsForSubpartIndex() );
	void ctor(f32 radius = 0.05f, int numBitsForSubpartIndex = 12) { SDK_CALL_FUNC(void, 0xD12630, void*, f32, int)(this, radius, numBitsForSubpartIndex); }

	/// Adds a triangle subpart. To modify member xxxx of this triangle subpart later on, call getTrianglesSubpartAt(int ).xxxx = yyyy.
	virtual void addTrianglesSubpart(const TrianglesSubpart& part) = 0;

	/// Adds a shape subpart. To modify member xxxx of this shape subpart later on, call getShapesSubpartAt(int ).xxxx = yyyy.
	/// returns the subpart index
	virtual int addShapesSubpart(const ShapesSubpart& part) = 0;
};
SDK_ASSERT_SIZEOF(hkpExtendedMeshShape, 0x140);