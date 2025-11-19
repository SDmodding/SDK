#pragma once

class hkpShapeCollection : public hkpShape, public hkpShapeContainer
{
public:
	enum CollectionType
	{
		/// hkpListShape
		COLLECTION_LIST,

		/// hkpExtendedMeshShape
		COLLECTION_EXTENDED_MESH,

		/// hkpTriSampledHeightFieldCollection
		COLLECTION_TRISAMPLED_HEIGHTFIELD,

		/// All other collections.
		/// These are not simulated on SPU by default, but can be by changing registerSimulationFunctions()
		COLLECTION_USER,

		/// hkpSimpleMeshShape. Not simulated on the SPU.
		COLLECTION_SIMPLE_MESH,

		/// hkpMeshShape. Not simulated on the SPU.
		COLLECTION_MESH_SHAPE,

		/// hkpCompressedMeshShape
		COLLECTION_COMPRESSED_MESH,

		/// Maximum count
		COLLECTION_MAX
	};

	hkBool m_disableWelding;
	hkEnum<CollectionType, u8> m_collectionType;

	void ctor(hkcdShapeType::ShapeTypeEnum type, CollectionType subType) { SDK_CALL_FUNC(void, 0xD096E0, void*, hkcdShapeType::ShapeTypeEnum, CollectionType)(this, type, subType); }

	/// Sets the welding type for the collection. This is called automatically by hkpMeshWeldingUtility::computeWeldingInfo
	/// and hkpMeshWeldingUtility::computeWeldingInfoMultiShape. You can call this manually, which allows you to set the welding type to
	/// hkpWeldingUtility::WELDING_TYPE_NONE, clearing welding information
	virtual void initWeldingInfo(hkpWeldingUtility::WeldingType weldingType) = 0;

	/// Sets the welding info for a child shape in the collection. This is called automatically by hkpMeshWeldingUtility::computeWeldingInfo
	/// and hkpMeshWeldingUtility::computeWeldingInfoMultiShape
	virtual void setWeldingInfo(hkpShapeKey key, i16 weldingInfo) = 0;
};
SDK_ASSERT_SIZEOF(hkpShapeCollection, 0x30);