#pragma once

class DetectRagdollPenetration : public hkReferencedObject
{
public:
	enum BonePenetrationStatus
	{
		HK_NOP,
		HK_YESP,
		HK_YESP_DESCENDANT
	};

	struct BonePenetration
	{
		i16 m_boneBeginIndex;
		i16 m_boneEndIndex;
		hkVector4f m_penetrationPoint;
		hkVector4f m_penetrationNormal;
	};

	struct Output
	{
		hkArray<BonePenetration> m_penetrations;
	};

	struct Setup
	{
		hkaSkeleton* m_ragdollSkeleton;
		hkaRagdollRaycastInterface* m_raycastInterface;
		hkpAabbPhantom* m_ragdollPhantom;
	};

	Setup m_setup;
	int m_numBones;
	hkArray<BonePenetrationStatus> m_boneStates;
	hkBool m_ragdollIsOut;
};