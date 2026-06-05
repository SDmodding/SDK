#pragma once

class hkpListShape : public hkpShapeCollection
{
public:
	struct __declspec(align(16)) ChildInfo
	{
		hkpShape* m_shape;
		u32 m_collisionFilterInfo;
		u16 m_shapeInfo;
		i16 m_shapeSize;
		int m_numChildShapes;
	};

	hkArray<ChildInfo> m_childInfo;
	u16 m_flags;
	u16 m_numDisabledChildren;
	hkVector4f m_aabbHalfExtents;
	hkVector4f m_aabbCenter;
	u32 m_enabledChildren[8];

	/* Functions */

	SDK_INLINE hkpShape* getChildShape(int i) const { return m_childInfo.m_data[i].m_shape; }
};