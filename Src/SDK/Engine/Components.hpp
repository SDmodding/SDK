#pragma once

namespace UFG
{
	//...
	class CSimObject;
	class CSimCharacter;
	class CSimVehicle;

	class CTargetingSimObject
	{
	public:
		UFG_PAD(0x28);

		CSimObject* mTarget;

		UFG_PAD(0x8);
	};

	// Components
	class CSimComponent
	{
	public:
		UFG_PAD(0x18);

		unsigned int m_TypeUID;
		unsigned int m_NameUID;
		unsigned short m_Flags;
		short m_SimObjIndex;
		CSimObject* m_pSimObject;

		char m_BoundComponentHandles[0x10];
	};

	class CSimObjectPropertiesComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x10);

		eSimObjectTypeEnum m_eSimObjectType;

		UFG_PAD(0x4);

		void* m_pSubTargetingProfile;
		unsigned char m_BitField[8];

		UFG_PAD(0x30);
	};

	class CTransformNodeComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x10);

		void* mChildren[2];
		unsigned int mChangeID;
		CTransformNodeComponent* mParent;
		int mChanged;

		UFG_PAD(0xC);

		qMatrix44 mWorldTransform;
		qMatrix44 mLocalTransform;
		qVector3 mWorldVelocity;
		int mInheritXformType;
	};

	class CBaseAnimationComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x58);

		CCreature* mCreature;
	};

	class CRigidBodyComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x68);

		void* mBody;

		UFG_PAD(0x58);
		/*UFG::WaterFloatingTrackerBaseComponent* mWaterFloatingTrackerComponent;
		UFG::RebindingComponentHandle<UFG::TransformNodeComponent, 0> mRootTransformComponent;
		UFG::WindAction* mWindAction;
		BitArray256* mFractureState;
		UFG::qArray<UFG::qSafePointer<UFG::Constraint, UFG::Constraint>, 0> mConstraints;*/

		unsigned int mFlags;

		void SetMotionType(unsigned int mode)
		{
			reinterpret_cast<void(__fastcall*)(void*, unsigned int)>(UFG_RVA(0xB1500))(this, mode);
		}

		void SetVelocity(UFG::qVector3* vel)
		{
			reinterpret_cast<void(__fastcall*)(void*, UFG::qVector3*)>(UFG_RVA(0xB2850))(this, vel);
		}

		void GetVelocity(UFG::qVector3* result)
		{
			reinterpret_cast<void(__fastcall*)(void*, UFG::qVector3*)>(UFG_RVA(0xAB970))(this, result);
		}

		void EnablePhysics(bool m_Enable)
		{
			SetMotionType(m_Enable ? 128 : 256);
		}
	};

	class CTargetingSystemBaseComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x18);

		CTargetingSimObject* GetTarget(eTargetTypeEnum eTargetType)
		{
			uintptr_t m_pTargets		= *reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(this) + 0x58);
			uintptr_t m_pTargetingMap	= *reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(this) + 0x60);

			uint8_t m_TargetID			= *reinterpret_cast<uint8_t*>(m_pTargetingMap + 0x8 + eTargetType);
			return *reinterpret_cast<CTargetingSimObject**>(m_pTargets + (m_TargetID * sizeof(CTargetingSimObject)));
		}

		void SetTarget(eTargetTypeEnum eTargetType, CSimObject* pSimObject)
		{
			reinterpret_cast<void(__fastcall*)(void*, eTargetTypeEnum, CSimObject*)>(UFG_RVA(0x54ED20))(this, eTargetType, pSimObject);
		}

		void ClearTarget(eTargetTypeEnum eTargetType)
		{
			reinterpret_cast<void(__fastcall*)(void*, eTargetTypeEnum)>(UFG_RVA(0x15DFB0))(this, eTargetType);
		}
	};
}