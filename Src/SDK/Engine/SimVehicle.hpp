#pragma once

namespace UFG
{
	// ...
	class CSteering
	{
	public:
		UFG_PAD(0x20);
		float mMaxSteeringAngle;
		float mSteeringSensitivityLo;
		float mSteeringSensitivityHi;
		float mSteeringSensitivityMinSpeed;
		float mSteeringSensitivityMaxSpeed;
		float mSteeringCenteringRate;
		float mMaxSteeringAngleForSpeed;
		float mCurrentSteeringAngle;
		float mSteeringModel;
		float mPrevInputValue;
	};

	class CVehicleInput
	{
	public:
		float mSteering;
		float mForwardWeightShift;
		float mGasBrakes;
		float mRawGasBrakes;
		unsigned __int32 mInReverse : 1;
		unsigned __int32 mForceNeutral : 1;
		unsigned __int32 mHandBrakeSet : 1;
		unsigned __int32 mDoWheelie : 1;
		unsigned __int32 mDoOneEighty : 1;
		unsigned __int32 mDoBurnout : 1;
		unsigned __int32 mFreemanStopTask : 1;
		unsigned __int32 mFreemanSteerTask : 1;
		unsigned __int32 mFreemanPreventWheelie : 1;
		unsigned __int32 mHasHumanDriver : 1;
		unsigned __int32 mHasAiDriver : 1;
	};

	class CVehicleParams
	{
	public:
		UFG_PAD(0x18);

		CSimObject* mSimObject;
	};

	class CPhysicsVehicle : public CBasePhysicsObject
	{
	public:
		UFG_PAD(0x10);

		CVehicleParams* mParams;

		UFG_PAD(0x28);

		CRigidBodyComponent* mRigidBody;

		UFG_PAD(0x1F8);
	};

	class CPhysicsWheeledVehicle : public CPhysicsVehicle
	{
	public:
		void* mWheelCollider;
		void* mHavokVehicle;
		void* mVehicleAction;
		void* mEngine;
		void* mTransmission;
		void* mBrakes;
		CSteering* mSteering;
		void* mAerodynamics;
		qVector4 mHardPointChassisSpace[4];
		qVector4 mSuspensionDirChassisSpace[4];

		UFG_PAD(0xB4);
		/*UFG::qSafeArray<float, 4> mCurrentSuspensionLength;
		UFG::qSafeArray<float, 4> mSkidStrength;
		UFG::qSafeArray<float, 4> mForwardSkidStrength;
		UFG::qSafeArray<float, 4> mLateralSkidStrength;
		UFG::qSafeArray<float, 4> mWheelSpinAngle;
		UFG::qSafeArray<UFG::qVector3, 4> mGroundPoints;
		UFG::qSafeArray<bool, 4> mGroundHits;
		UFG::qSafeArray<float, 4> mRestingSuspensionLength;
		UFG::qSafeArray<float, 4> mSuspensionUpTravelLimit;
		UFG::qSafeArray<float, 4> mSuspensionDownTravelLimit;
		UFG::qSafeArray<float, 4> mTireDamage;*/

		float mWheelRadius;
		float mPreviousSpeed;
		float mBurnoutMinSpeed;
		float mBurnoutMaxSpeed;
		float mBurnoutSpinTorqueAtLowSpeed;
		float mBurnoutSpinTorqueAtHighSpeed;
		float mBurnoutSpinFrontTireFrictionAtLowSpeed;
		float mBurnoutSpinFrontTireFrictionAtHighSpeed;
		float mBurnoutSpinRearTireFrictionAtLowSpeed;
		float mBurnoutSpinRearTireFrictionAtHighSpeed;
		float mBurnoutTorqueFactor_LowSpeed;
		float mBurnoutFwdThrustFactor_LowSpeed;
		float mBurnoutSideThrustFactor_LowSpeed;
		float mBurnoutTorqueFactor_HighSpeed;
		float mBurnoutFwdThrustFactor_HighSpeed;
		float mBurnoutSideThrustFactor_HighSpeed;
		float mJTurnSpinTorque;
		float mJTurnSpinFrontTireFriction;
		float mJTurnSpinRearTireFriction;
		float mBlownTireWobbleMagnitude;
		float mBlownTireWobbleFrequency;
		float mBlownTireDrag;
		float mBlownTireFrictionMultiplier;
		float mLodHeightFixupFront;
		float mLodHeightFixupRear;
		unsigned __int32 mGroundFixupRaysRecieved : 3;
		unsigned __int32 mAllWheelsOffGround : 1;
		unsigned __int32 mAllWheelsOnGround : 1;
		unsigned __int32 mUseNewBurnoutMethod : 1;
		unsigned __int32 mWheelFrictionMultiplierOverriddenByFreeman : 1;

		UFG_PAD(0x10);
	};

	class CPhysicsCar : public CPhysicsWheeledVehicle
	{
	public:

	};

	class CPhysicsMoverInterface : public CSimComponent
	{
	public:
		UFG_PAD(0x18);

		CVehicleInput mInput;

		UFG_PAD(0x21C);

		CPhysicsVehicle* mPhysicsVehicle;
		void* mRammingState;
		float mPostRamImmunityTimer;
		qVector3 mBoundingBoxMin;
		qVector3 mBoundingBoxMax;
		float mForwardSpeed;
		float mOdometer;
		float mDamageMultiplierWorldCollisions;
		float mDamageMultiplierVehicleCollisions;
		float mDamageMultiplierAttack;
		float mDamageMultiplierBullets;
		float mDamageMultiplierTires;
		float mTireShotImpulse;
		float mTireBlownImpulse;
		float mWheelRenderAngle;
		float mLowLodThrottleAcceleration;
		float mLowLodBrakesAcceleration;
		float mLowLodCoastAcceleration;
		float mLowLodMaxSpeed;
		float mLowLodMaxLateralAcceleration;
		float mLowLodMinTurningRadius;
		float mAutoDeterioratingDamageThreshold;
		float mAutoDeterioratingDamageRate;
		float mNotMovingTime;
		float mPropellerAngle;
		int mGroundFixupRequired;
	};

	// Components
	class CSimObjectVehiclePropertiesComponent : public CSimObjectPropertiesComponent
	{
	public:
		UFG_PAD(0x10);

		eSimObjectVehicleTypeEnum m_eSimObjectVehicleType;
		eSimObjectBoatTypeEnum m_eSimObjectBoatType;

		UFG_PAD(0x20);
	
		qArray<void*> mDoorPhantomInfo;
		bool mIsGarageVehicle;
	};

	class CTargetingSystemVehicleComponent : public CTargetingSystemBaseComponent
	{
	public:
		void SetTargetLock(eTargetTypeEnum eTargetType, bool bLock, bool bModifyCollision)
		{
			reinterpret_cast<void(__fastcall*)(void*, eTargetTypeEnum, bool, bool, float, const char*, void*, void*)>(UFG_RVA(0x54F130))(this, eTargetType, bLock, bModifyCollision, 0.f, nullptr, nullptr, nullptr);
		}
	};

	class CVehicleAudioComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x23E);

		__int8 m_bHornOn : 1;
		__int8 m_bHornOnFlag : 1;
		__int8 m_bHornHasStimulus : 1;
		__int8 m_bSirenOn : 1;
		__int8 m_bSirenOnFlag : 1;
		__int8 m_bUnloadBanksFlag : 1;
		__int8 m_bShutdownOnExit : 1;

		bool IsHornTriggered() { return m_bHornOnFlag; }
		void StartHorn() { m_bHornOnFlag = true; }
		void StopHorn() { m_bHornOnFlag = false; }

		bool IsSirenTriggered() { return m_bSirenOnFlag; }
		void StartSiren() { m_bSirenOnFlag = true; }
		void StopSiren() { m_bSirenOnFlag = false; }
	};

	class CVehicleEffectsComponent : public CSimComponent
	{
	public:
		void TurnOnCopLights()
		{
			return reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x68E020))(this);
		}

		void TurnOffCopLights()
		{
			return reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x68D7F0))(this);
		}

		void TurnOnLightEffects(UFG::VehicleEffectId id)
		{
			return reinterpret_cast<void(__fastcall*)(void*, UFG::VehicleEffectId)>(UFG_RVA(0x68E850))(this, id);
		}

		void TurnOffLightEffects(UFG::VehicleEffectId id)
		{
			return reinterpret_cast<void(__fastcall*)(void*, UFG::VehicleEffectId)>(UFG_RVA(0x68DD20))(this, id);
		}
	};

	class CVehicleOccupantComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x28);

		CSimCharacter* mpDriver;

		UFG_PAD(0x100);

		unsigned int mSeatCount;

		CSimCharacter* GetPassenger(int iIndex, bool excludeEnteringAndExiting)
		{
			return reinterpret_cast<CSimCharacter*(__fastcall*)(void*, int, bool)>(UFG_RVA(0x67AF40))(this, iIndex, excludeEnteringAndExiting);
		}

		CSimCharacter* GetOccupant(unsigned int index, UFG::eTargetTypeEnum* pTargetType)
		{
			return reinterpret_cast<CSimCharacter*(__fastcall*)(void*, unsigned int, UFG::eTargetTypeEnum*)>(UFG_RVA(0x67AE50))(this, index, pTargetType);
		}

		CSimCharacter* FindOccupant(UFG::eTargetTypeEnum m_TargetType)
		{
			UFG::eTargetTypeEnum m_TargetTypeResult;

			for (unsigned int i = 0; mSeatCount > i; ++i)
			{
				CSimCharacter* m_Occupant = GetOccupant(i, &m_TargetTypeResult);
				if (m_TargetTypeResult == m_TargetType)
					return m_Occupant;
			}

			return nullptr;
		}

		bool IsOccupant(CSimCharacter* m_Character)
		{
			if (mpDriver == m_Character) 
				return true;

			for (unsigned int i = 0; mSeatCount > i; ++i)
			{
				if (GetPassenger(i, false) == m_Character)
					return true;
			}

			return false;
		}
	};

	class CRemoteDriverComponent
	{
	public:
		UFG_PAD(0x30);

		CPhysicsMoverInterface* mMoverComponent;

		UFG_PAD(0x28);

		CVehicleEffectsComponent* mRenderComponent;
	};

	// Main
	class CSimVehicle : public CSimObject
	{
	public:
		CSimObjectVehiclePropertiesComponent* GetVehicleProperties()
		{
			CSimComponent* m_Component = nullptr;

			if ((m_Flags >> 14) & 1)
				return nullptr;

			if ((m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1)
					return nullptr;

				if ((m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(VehiclePropertiesComponent_TypeUID);
				else
					m_Component = GetComponentOfType(VehiclePropertiesComponent_TypeUID);
			}
			else
				m_Component = m_Components.p[3].m_pComponent;

			return reinterpret_cast<CSimObjectVehiclePropertiesComponent*>(m_Component);
		}

		CBaseAnimationComponent* GetAnimation()
		{
			CSimComponent* m_Component = nullptr;

			if ((m_Flags >> 14) & 1)
				return nullptr;

			if ((m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1)
					return nullptr;

				if ((m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(CharacterAnimationComponent_TypeUID);
				else
					m_Component = GetComponentOfType(CharacterAnimationComponent_TypeUID);
			}
			else
				m_Component = m_Components.p[9].m_pComponent;

			return reinterpret_cast<CBaseAnimationComponent*>(m_Component);
		}

		CTargetingSystemVehicleComponent* GetTargetingSystemVehicle()
		{
			CSimComponent* m_Component = nullptr;

			if ((m_Flags >> 14) & 1)
				return nullptr;

			if ((m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1)
					return nullptr;

				if ((m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(0xA0000041);
				else
					m_Component = GetComponentOfType(0xA0000041);
			}
			else
				m_Component = m_Components.p[20].m_pComponent;

			return reinterpret_cast<CTargetingSystemVehicleComponent*>(m_Component);
		}
		
		CVehicleOccupantComponent* GetOccupant()
		{
			CSimComponent* m_Component = nullptr;

			if ((m_Flags >> 14) & 1)
				return nullptr;

			if ((m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1)
					return nullptr;

				if ((m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(0xDE000001);
				else
					m_Component = GetComponentOfType(0xDE000001);
			}
			else
				m_Component = m_Components.p[30].m_pComponent;

			return reinterpret_cast<CVehicleOccupantComponent*>(m_Component);
		}

		CVehicleEffectsComponent* GetEffects()
		{
			CSimComponent* m_Component = nullptr;

			if ((m_Flags >> 14) & 1)
				return nullptr;

			if ((m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1)
					return nullptr;

				if ((m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(0xE2000001);
				else
					m_Component = GetComponentOfType(0xE2000001);
			}
			else
				m_Component = m_Components.p[32].m_pComponent;

			return reinterpret_cast<CVehicleEffectsComponent*>(m_Component);
		}

		CPhysicsMoverInterface* GetPhysicsMover()
		{
			CSimComponent* m_Component = nullptr;

			if ((m_Flags >> 14) & 1)
				return nullptr;

			if ((m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1)
					return nullptr;

				if ((m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(0xE4000001);
				else
					m_Component = GetComponentOfType(0xE4000001);
			}
			else
				m_Component = m_Components.p[34].m_pComponent;

			return reinterpret_cast<CPhysicsMoverInterface*>(m_Component);
		}

		CRigidBodyComponent* GetRigidBody()
		{
			CPhysicsMoverInterface* PhysicsMover = GetPhysicsMover();
			if (PhysicsMover && PhysicsMover->mPhysicsVehicle)
				return PhysicsMover->mPhysicsVehicle->mRigidBody;

			return nullptr;
		}
	};

	class TSVehicle
	{
	public:
		UFG_PAD(0x128);

		CPhysicsMoverInterface* mMoverComponent;

		CRigidBodyComponent* GetRigidBody()
		{
			if (mMoverComponent && mMoverComponent->mPhysicsVehicle && mMoverComponent->mPhysicsVehicle->mRigidBody)
				return mMoverComponent->mPhysicsVehicle->mRigidBody;

			return nullptr;
		}

		void UnlockDoors(bool enable) { reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x65EDB0))(this, enable); }
	};
}