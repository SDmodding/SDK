#pragma once

class CharacterRigidBody : public hkReferencedObject, public hkpEntityListener, public hkpWorldPostSimulationListener
{
public:
	struct CollectorPair
	{
		hkContactPoint m_point;
		hkpCollidable* m_partner;
	};

	struct VertPointInfo
	{
		hkContactPoint m_vertPoint;
		class hkpSimpleConstraintContactMgr* m_mgr;
	};

	hkpRigidBody* m_character;
	hkVector4f mTopVertex;
	hkVector4f mBottomVertex;
	hkVector4f m_up;
	f32 m_maxSlopeCosine;
	int m_userPlanes;
	f32 m_penetrationRecoverySpeed;
	f32 m_maxSpeedForSimplexSolver;
	f32 m_supportDistance;
	f32 mSupportRadius;
	f32 m_heightAboveGround;
	bool m_isPlayer;
	bool m_fixCurbContacts;
	bool m_supportedOffCentre;
	bool m_isInWater;
	bool m_superMassive;
	hkArray<VertPointInfo> m_verticalContactPoints;
	hkVector4f m_acceleration;
	f32 m_maxForce;
};
