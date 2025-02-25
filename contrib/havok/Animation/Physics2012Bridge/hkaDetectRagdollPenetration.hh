#pragma once

class hkaRagdollRaycastInterface
{
public:
	virtual ~hkaRagdollRaycastInterface() = 0;
	virtual hkBool castRay(const class hkpAabbPhantom* phantomIn, const hkVector4& fromWS, const hkVector4& toWS, hkVector4& hitPointWS, hkVector4& hitNormalWS) = 0;
};