#pragma once

class hkpBvTreeShape : public hkpShape
{
public:
	enum BvTreeType
	{
		BVTREE_MOPP,
		BVTREE_TRISAMPLED_HEIGHTFIELD,
		BVTREE_STATIC_COMPOUND,
		BVTREE_COMPRESSED_MESH,
		BVTREE_USER,
		BVTREE_MAX,
	};

	hkEnum<BvTreeType, u8> m_bvTreeType;
};
