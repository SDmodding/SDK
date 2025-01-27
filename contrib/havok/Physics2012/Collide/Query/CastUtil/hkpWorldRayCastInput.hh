#pragma once

struct hkpWorldRayCastInput
{
	hkVector4f m_from;
	hkVector4f m_to;
	hkBool m_enableShapeCollectionFilter;
	u32 m_filterInfo;
	u64 m_userData;
};