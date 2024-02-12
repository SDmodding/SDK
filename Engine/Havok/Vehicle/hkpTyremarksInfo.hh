#pragma once

struct hkpTyremarkPoint
{
	hkVector4f m_pointLeft;
	hkVector4f m_pointRight;
};

class hkpTyremarksWheel : public hkReferencedObject
{
public:
	int m_currentPosition;
	int m_numPoints;
	hkArray<hkpTyremarkPoint> m_tyremarkPoints;
};

class hkpTyremarksInfo : public hkReferencedObject
{
public:
	float m_minTyremarkEnergy;
	float m_maxTyremarkEnergy;
	hkArray<hkpTyremarksWheel*> m_tyremarksWheel;
};