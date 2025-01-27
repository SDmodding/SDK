#pragma once

class hkpCollisionFilter : public hkReferencedObject, public hkpCollidableCollidableFilter, public hkpShapeCollectionFilter, public hkpRayShapeCollectionFilter, public hkpRayCollidableFilter
{
public:
	enum hkpFilterType
	{
		HK_FILTER_UNKNOWN,
		HK_FILTER_NULL,
		HK_FILTER_GROUP,
		HK_FILTER_LIST,
		HK_FILTER_CUSTOM,
		HK_FILTER_PAIR,
		HK_FILTER_CONSTRAINT
	};

	u32 m_prepad[2];
	hkEnum<hkpFilterType, u32> m_type;
	u32 m_postpad[3];
};