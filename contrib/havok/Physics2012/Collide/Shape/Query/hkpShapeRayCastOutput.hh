#pragma once

struct hkpShapeRayCastOutput : public hkpShapeRayCastCollectorOutput
{
	u32 m_shapeKeys[8];
	int m_shapeKeyIndex;
};