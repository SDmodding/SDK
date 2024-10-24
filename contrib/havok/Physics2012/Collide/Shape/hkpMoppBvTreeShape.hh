#pragma once

class hkMoppBvTreeShapeBase : public hkpBvTreeShape
{
public:
	hkpMoppCode* m_code;
	const char* m_moppData;
	u32 m_moppDataSize;
	hkVector4f m_codeInfoCopy;
};
SDK_ASSERT_SIZEOF(hkMoppBvTreeShapeBase, 0x50);

class hkpMoppBvTreeShape : public hkMoppBvTreeShapeBase
{
public:
	qProxy<hkpSingleShapeContainer> m_child;
	int m_childSize;
};
