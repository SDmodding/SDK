#pragma once

class hkpExtendedMeshShape : public hkpShapeCollection
{
public:
	enum IndexStridingType : int8_t
	{
		INDICES_INVALID,	///< default, will raise assert.
		INDICES_INT8,		///< 8 bit "single byte" striding.
		INDICES_INT16,		///< 16 bit "short" striding.
		INDICES_INT32,		///< 32 bit "int" striding.
		INDICES_MAX_ID
	};

	enum MaterialIndexStridingType
	{
		MATERIAL_INDICES_INVALID = 0,
		MATERIAL_INDICES_INT8 = 1,
		MATERIAL_INDICES_INT16 = 2,
		MATERIAL_INDICES_MAX_ID = 3,
	};

	enum SubpartType
	{
		SUBPART_TRIANGLES = 0,
		SUBPART_SHAPE = 1,
		SUBPART_TYPE_MAX = 2,
	};

	struct Subpart
	{
		uint16_t m_typeAndFlags;
		uint16_t m_shapeInfo = 0;
		int16_t m_materialStriding = 0;
		uint16_t m_materialIndexStriding = 0;
		const void* m_materialIndexBase = nullptr;
		void* m_materialBase = nullptr;
		uint64_t m_userData = 0;
	};

	struct TrianglesSubpart : Subpart
	{
		int m_numTriangleShapes = -1; // the number of triangles
		const float* m_vertexBase = nullptr; // A pointer to the first vertex, defined by three floats. (Must be aligned on a 16 byte boundary)
		int m_numVertices = -1; // The number of vertices.
		const void* m_indexBase = nullptr; // A pointer to triples of vertex indices.
		uint16_t m_vertexStriding = 0; // The byte offset between two consecutive vertices (usually 12, 16 or more).
		int m_triangleOffset = -1;
		uint16_t m_indexStriding = 0;
		IndexStridingType m_stridingType = INDICES_INVALID;
		char m_flipAlternateTriangles = 0;
		hkVector4f m_extrusion;
		hkQsTransformf m_transform;
	};

	struct ShapesSubpart : Subpart
	{
		hkArray<hkRefPtr<hkpConvexShape>> m_childShapes;
		hkQuaternionf m_rotation;
		hkVector4f m_translation;
	};

	TrianglesSubpart m_embeddedTrianglesSubpart;
	hkVector4f m_aabbHalfExtents;
	hkVector4f m_aabbCenter;
	class hkClass* m_materialClass;
	int m_numBitsForSubpartIndex;
	hkArray<TrianglesSubpart> m_trianglesSubparts;
	hkArray<ShapesSubpart> m_shapesSubparts;
	hkArray<uint16_t> m_weldingInfo;
	uint8_t m_weldingType; // hkpWeldingUtility::WeldingType
	uint32_t m_defaultCollisionFilterInfo;
	int m_cachedNumChildShapes;
	float m_triangleRadius;
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
	UFG_STATIC_INLINE hkpExtendedMeshShape* New(float p_Radius = 0.f, int p_NumBitsForSubpartIndex = 12)
	{
		auto pShape = hkMemoryAllocator::Instance()->BlockAlloc<hkpExtendedMeshShape>();
		reinterpret_cast<void(__fastcall*)(void*, float, int)>(UFG_RVA(0xD12630))(pShape, p_Radius, p_NumBitsForSubpartIndex);
		return pShape;
	}

	// Adds a triangle subpart.
	UFG_INLINE void AddTrianglesSubpart(TrianglesSubpart* p_Part)
	{
		reinterpret_cast<void(__fastcall*)(void*, TrianglesSubpart*)>(UFG_RVA(0xD12E10))(this, p_Part);
	}
};