#pragma once

struct hkpShapeRayCastCollectorOutput
{
	hkVector4f m_normal;
	f32 m_hitFraction;
	int m_extraInfo;
	int m_pad[2];
};