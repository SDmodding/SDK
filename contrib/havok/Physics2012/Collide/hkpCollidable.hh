#pragma once

class hkpCollidable : public hkpCdBody
{
public:
	struct BoundingVolumeData
	{
		u32 m_min[3];
		u8 m_expansionMin[3];
		u8 m_expansionShift;
		u32 m_max[3];
		u8 m_expansionMax[3];
		u8 m_padding;
		u16 m_numChildShapeAabbs;
		u16 m_capacityChildShapeAabbs;
		hkAabbUint32* m_childShapeAabbs;
		u32* m_childShapeKeys;
	};

	i8 m_ownerOffset;
	i8 m_forceCollideOntoPpu;
	u16 m_shapeSizeOnSpu;
	hkpTypedBroadPhaseHandle m_broadPhaseHandle;
	BoundingVolumeData m_boundingVolumeData;
	f32 m_allowedPenetrationDepth;
};