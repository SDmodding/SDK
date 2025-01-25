#pragma once

class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
{
public:
	i8 m_type;
	i8 m_ownerOffset;
	i8 m_objectQualityType;
	u32 m_collisionFilterInfo;
};