#pragma once

namespace UFG
{
	class CCharacterOccupantComponent;
	class CRacePosition;
	class CRaceTrail;
	class CRoadNetworkLane;

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

		void FlipVehicle(float torqueFactor, qVector3* collisionPoint)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, qVector3*)>(UFG_RVA(0x4654C0))(this, torqueFactor, collisionPoint);
		}

		void SetMass(float m) { mRigidBody->SetMass(m); }
		float GetMass() { return mRigidBody->GetMass(); }

		void SetMassScaleForCollisions(float scaleMass, float scaleRotMass)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, float)>(UFG_RVA(0x475170))(this, scaleMass, scaleRotMass);
		}

		void ClearMassScaleForCollisions()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x45A630))(this);
		}
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
		int mAxleBoneId[4];
		int mWheelBoneId[4];
		int mMotorBoneId[2];
		int mPropellerBoneId[2];
		int mNumWheels;
		int mLockAtHighLODMode;
		float mLockAtHighLODTime;
		float mVehicleCollisionMinImpulseRequiredToTakeDamage;
		float mVehicleCollisionDamageDealtAtMinImpulse;
		float mVehicleCollisionDamageDealtAtMaxImpulse;
		float mVehicleCollisionDamageDealtAtMinRamImpulse;
		float mVehicleCollisionDamageDealtAtMaxRamImpulse;
		float mVehicleCollisionExtraDamageMultiplier;
		float mVehicleCollisionMinImpulseRequiredToDealDamage;
		float mVehicleCollisionMaxImpulseForDealingDamage;
		float mVehicleCollisionMinRamImpulseRequiredToDealDamage;
		float mVehicleCollisionMaxRamImpulseForDealingDamage;
		float mSecondsSinceAppliedSpeedBoostRewardFromVehicleTakedown;
		float mSecondsEngineHasBeenDeteriorating;
		qVector3 mRamVelocity;
		unsigned __int32 mLockedAtLowLOD : 1;
		unsigned __int32 mSuspended : 1;
		unsigned __int32 mNotMoving : 1;
		unsigned __int32 mNisMode : 1;
		unsigned __int32 mCannotExplode : 1;
		__int8 mVehicleCollisionForceDamageDealer : 1;
		__int8 mIsRoofSliding : 1;
		__int8 mLastEngineDamageCouldBeATakedown : 1;
		__int8 mRamming : 1;
		__int8 mCollisionShouldTriggerExplosion : 1;
		__int8 mbWasEngineDeteriorating : 1;
		float mDistanceToHighLod;
		float mDistanceToMedLod;
		bool mDoorsLocked;
		bool mUntargetable;
		bool mCreatedWithTemporaryRig;
		eVehicleTrunkTypeEnum mTrunkType;

		void SetLOD(PhysicsVehicle::Lod lod)
		{
			reinterpret_cast<void(__fastcall*)(void*, PhysicsVehicle::Lod)>(UFG_RVA(0x68A9B0))(this, lod);
		}

		void RepairDamage()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x6899D0))(this);
		}

		float GetEngineDamage()
		{
			return reinterpret_cast<float(__fastcall*)(void*)>(UFG_RVA(0x67A630))(this);
		}

		void SetEngineDamage(float damage)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x68A5C0))(this, damage);
		}

		void SetCannotExplode(bool cannotExplode)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x68A470))(this, cannotExplode);
		}

		bool AreAllWheelsOnGround()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x670840))(this);
		}
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
		UFG_PAD(0x10);

		unsigned int mDamageTransferUID;

		UFG_PAD(0x52C);
		/*UFG::qSafeArray<UFG::WheelModelsBinding, 4> mWheelModelBindings;
		UFG::EffectStatus mEffectStatusTable[39];
		UFG::RebindingComponentHandle<UFG::WaterFloatingTrackerComponent, 0> mWaterFloatingTrackerComponent;
		UFG::RebindingComponentHandle<UFG::CompositeDrawableComponent, 0> mDrawableComponent;
		UFG::RebindingComponentHandle<Render::FXSimComponent, 0> mFXComponent;
		UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface, 0> mMoverComponent;
		UFG::RebindingComponentHandle<UFG::RoadSpaceComponent, 0> mRoadSpaceComponent;
		UFG::RebindingComponentHandle<UFG::VehicleDriverInterface, 0> mVehicleDriverComponent;*/

		unsigned long mSkidEmitters[4];
		CTransformNodeComponent* mTransformNodes[16];
		unsigned long mWheelBoneId[4];
		unsigned long mBumperBoneId[4];
		unsigned long mSkidEffect[4];
		unsigned long mRimSparksEffect[4];
		unsigned long mBumperSparksEffect[4];
		unsigned long mWetSurfaceEffect[4];
		void* mLastPhysicsSurfacProperty[4];

		UFG_PAD(0x50);
		//UFG::HullSprayEffects mSprayEffects[2];

		qVector3 mSprayVector;
		qSymbol mEffectGroup;
		unsigned int mLevelOfDetail;
		unsigned int mNumWheels;
		unsigned int mNumQueuedHeadlightChanges;

		UFG_PAD(0x4);
		CRoadNetworkLane* mPreTurnLane;

		float mSpeedLevelThreshold[4];
		unsigned int mSpeedLevel;
		unsigned int mRigUID;
		unsigned int mVandalizedDamage;
		CDamageRig* mDamageRig;
		float mInitialGrimePercentage;
		float mInitialGrimeFactor;
		float mExtinguishFireCountdown;
		float mAirTime;
		float mSignalTimer;
		float mHeadlightFlashesLength;
		float mHeadlightFlashesTimer;
		float mHeadlightFlareOnTime;
		float mHeadlightFlareOffTime;
		bool mIsOffGround;
		unsigned int mFramesOffGround;
		unsigned __int32 mOnFire : 1;
		unsigned __int32 mBlownOutWindows : 1;
		unsigned __int32 mInWater : 1;
		unsigned __int32 mUsesHeadlightsInRain : 1;
		unsigned __int32 mScriptLightsEnabled : 1;
		unsigned __int32 mHeadlightsAlwaysOn : 1;
		unsigned __int32 mHeadlightsAlwaysOff : 1;
		unsigned __int32 mAreEffectMarkersResolved : 1;

		void TurnOnCopLights()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x68E020))(this);
		}

		void TurnOffCopLights()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x68D7F0))(this);
		}

		void TurnOnLightEffects(UFG::VehicleEffectId id)
		{
			reinterpret_cast<void(__fastcall*)(void*, UFG::VehicleEffectId)>(UFG_RVA(0x68E850))(this, id);
		}

		void TurnOffLightEffects(UFG::VehicleEffectId id)
		{
			reinterpret_cast<void(__fastcall*)(void*, UFG::VehicleEffectId)>(UFG_RVA(0x68DD20))(this, id);
		}

		void SetAllDamageMarkers(float damage, bool triggers_only, bool suppress_soundeffects)
		{
			if (mDamageRig)
				reinterpret_cast<void(__fastcall*)(void*, void*, float, bool, bool)>(UFG_RVA(0x3AEDD0))(mDamageRig, this, damage, triggers_only, suppress_soundeffects);
		}
	};

	class CAiDriverComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x518);

		float m_StopDist;
		float m_fDelayedStopDecel;
		bool m_ResetStopDistOnStop;
		float m_fChaseSpeedLimit;
		float m_fRaceSpeedLimit;
		bool m_RaceWanderAtEnd;
		bool m_bDeniesHijack;
		bool m_bCreepingTowardEscortEnemy;
		bool m_CappingSpeedForStopPoint;
		bool m_CappingSpeedForNextGuide;

		void SetDrivingMode(uint32_t mode)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x658B90))(this, mode);
		}

		void SetDrivingRole(uint32_t role)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x658C90))(this, role);
		}

		void StartRacing(float m_SpeedLimit, bool m_WanderAtEnd)
		{
			SetDrivingMode(6);
			SetDrivingRole(1);

			m_fRaceSpeedLimit = m_SpeedLimit;
			m_RaceWanderAtEnd = m_WanderAtEnd;
		}
	};
	
	class CRoadSpaceComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x630);

		qVector3 mDestinationPosition;
		qVector3 mDestinationDirection;
		CRacePosition* m_pRacePosition;
		CRacePosition* m_pRacePositionSteer;

		void SetRaceTrail(CRaceTrail* race_trail)
		{
			reinterpret_cast<void(__fastcall*)(void*, CRaceTrail*)>(UFG_RVA(0x659740))(this, race_trail);
		}

		void SetRaceTrailSteer(CRaceTrail* race_trail)
		{
			reinterpret_cast<void(__fastcall*)(void*, CRaceTrail*)>(UFG_RVA(0x6597F0))(this, race_trail);
		}

		void FlushRaceTrails()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x64D630))(this);
		}

		float GetFractionRaceComplete()
		{
			return reinterpret_cast<float(__fastcall*)(void*)>(UFG_RVA(0x64E760))(this);
		}
	};

	class CVehicleOccupantComponent : public CSimComponent
	{
	public:
		qNode<CVehicleOccupantComponent> mNode;
		void* mpParkingSpot;
		qSafePointer<CSimCharacter> mpDriver;
		qList<CCharacterOccupantComponent> mPassengers;
		qSafePointer<CSimObject> mpReservations[10];
		uint32_t mSeatCount;

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
			if (mpDriver.m_pPointer == m_Character) 
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

		CAiDriverComponent* GetAiDriver()
		{
			CSimComponent* m_Component = m_Components.p[23].m_pComponent;

			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(VehicleAiDriverComponent_TypeUID);
				else
					m_Component = GetComponentOfType(VehicleAiDriverComponent_TypeUID);
			}

			return reinterpret_cast<CAiDriverComponent*>(m_Component);
		}
		
		CRoadSpaceComponent* GetRoadSpace()
		{
			CSimComponent* m_Component = m_Components.p[24].m_pComponent;

			if (!((m_Flags >> 14) & 1) && (m_Flags & 0x8000) == 0)
			{
				if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(VehicleRoadSpaceComponent_TypeUID);
				else
					m_Component = GetComponentOfType(VehicleRoadSpaceComponent_TypeUID);
			}

			return reinterpret_cast<CRoadSpaceComponent*>(m_Component);
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
					m_Component = GetComponentOfTypeHK(VehicleOccupantComponent_TypeUID);
				else
					m_Component = GetComponentOfType(VehicleOccupantComponent_TypeUID);
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
					m_Component = GetComponentOfTypeHK(VehicleEffectsComponent_TypeUID);
				else
					m_Component = GetComponentOfType(VehicleEffectsComponent_TypeUID);
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
					m_Component = GetComponentOfTypeHK(VehiclePhysicsMoverInterface_TypeUID);
				else
					m_Component = GetComponentOfType(VehiclePhysicsMoverInterface_TypeUID);
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

	namespace PhysicsMoverInterface
	{
		// This can be used to itter through all in - game vehicles, just make sure to break out the loop when nullptr is hit to prevent infite - loop.
		CPhysicsMoverInterface* Itter(CPhysicsMoverInterface* m_This = nullptr)
		{
			static const uintptr_t m_List = UFG_RVA(0x2091350);

			uintptr_t m_Next = *reinterpret_cast<uintptr_t*>((m_This ? reinterpret_cast<uintptr_t>(m_This) : m_List) + 0x50) - 0x48;
			if (m_Next == m_List)
				return nullptr;

			return reinterpret_cast<CPhysicsMoverInterface*>(m_Next);
		}
	}
}