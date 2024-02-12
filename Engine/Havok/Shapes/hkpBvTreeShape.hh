#pragma once

class hkpBvTreeShape : public hkpShape
{
public:
	enum BvTreeType : uint8_t
	{
		BVTREE_MOPP = 0x0,
		BVTREE_TRISAMPLED_HEIGHTFIELD = 0x1,
		BVTREE_STATIC_COMPOUND = 0x2,
		BVTREE_COMPRESSED_MESH = 0x3,
		BVTREE_USER = 0x4,
		BVTREE_MAX = 0x5,
	};
	BvTreeType m_bvTreeType;
};

class hkMoppBvTreeShapeBase : public hkpBvTreeShape
{
public:
	hkpMoppCode* m_code;
	const char* m_moppData;
	unsigned int m_moppDataSize;
	hkVector4f m_codeInfoCopy;
};

class hkpMoppBvTreeShape : public hkMoppBvTreeShapeBase
{
public:
	hkpSingleShapeContainer m_child;
	int m_childSize;

	void Constructor(hkpShapeCollection* p_ShapeCollection, hkpMoppCode* p_Code)
	{
		reinterpret_cast<void(__fastcall*)(void*, hkpShapeCollection*, hkpMoppCode*)>(UFG_RVA(0xD0CAB0))(this, p_ShapeCollection, p_Code);
	}
};