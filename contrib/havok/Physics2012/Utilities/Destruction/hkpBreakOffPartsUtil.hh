#pragma once

class hkpBreakOffPartsListener
{
public:
	struct ContactImpulseLimitBreachedEvent
	{
		struct PointInfo
		{
			hkpRigidBody* m_collidingBody;
			u32 m_brokenShapeKey;
			hkBool m_isContact;
			f32 m_breakingImpulse;
			f32 m_contactPointDirection;
			hkContactPoint* m_contactPoint;
			class hkpContactPointProperties* m_properties;
			class hkpSimpleConstraintContactMgr* m_internalContactMgr;
		};

		hkpRigidBody* m_breakingBody;
		hkInplaceArray<PointInfo, 4> m_points;
	};

	virtual ~hkpBreakOffPartsListener() = 0;
	virtual hkResult breakOffSubPart(const ContactImpulseLimitBreachedEvent& event, hkArray<hkpShapeKey>& keysBrokenOffOut, class hkpPhysicsSystem& bodiesOut) = 0;
	virtual hkResult breakOffSubPart(const ContactImpulseLimitBreachedEvent& event, class hkpPhysicsSystem& bodiesOut) = 0;
};

// Too lazy to implement right now...
//class hkpBreakOffPartsUtil : public hkpWorldExtension, public hkpContactImpulseLimitBreachedListener, public hkpEntityListener, public hkpConstraintListener
//{
//public:
//	hkCriticalSection* m_criticalSection;
//	hkpBreakOffPartsListener* m_breakOffPartsListener;
//	hkRefPtr<GameControlFunctor> m_breakOffGameControlFunctor;
//};