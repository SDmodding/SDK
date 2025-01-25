#pragma once

class hkpCdBody
{
public:
	hkpShape* m_shape;
	u32 m_shapeKey;
	const void* m_motion;
	hkpCdBody* m_parent;
};