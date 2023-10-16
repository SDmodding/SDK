#pragma once

namespace UFG
{
	class CCharacterOccupantComponent;
	class CRacePosition;
	class CRaceTrail;
	class CRoadNetworkLane;

	// PhysicsDefs
	class CBaseVehiclePhysicsDef : public qReflectObject
	{
	public:
		qReflectString chassis_physicsProperties;
		uint32_t numWheels;
		float mass;
		float collision_friction;
		float collision_restitution;
		float highSpeedGovernor;
		float reverseSpeedGovernor;
		float superStop_Drag;
		float other_airSteerYawRate;
		float other_verticalVelocityDampingUp;
		float other_verticalVelocityDampingDown;
		float rollStability;
		float pitchStability;
		float dollarValue;
		float steering_SensitivityLo;
		float steering_SensitivityHi;
		float steering_SensitivityMinSpeed;
		float steering_SensitivityMaxSpeed;
		float steering_SteeringModelExponent;

		UFG_PAD_ALIGN(0x8);
	};

	class CWheeledVehiclePhysicsDef : public CBaseVehiclePhysicsDef
	{
	public:
		qReflectArray<float> torqueTable;
		qReflectArray<float> drivetrain_gearRatioTable;
		qReflectArray<float> drivetrain_upshiftTable;
		qReflectArray<float> drivetrain_downshiftTable;
		qVector3 suspension_hardpointOffsetFront;
		qVector3 suspension_hardpointOffsetRear;
		float engine_clutchSlipRPM;
		float drivetrain_downshiftRPM;
		float drivetrain_upshiftRPM;
		float drivetrain_clutchDelayTime;
		float drivetrain_gearRatio1;
		float drivetrain_gearRatio2;
		float drivetrain_gearRatio3;
		float drivetrain_gearRatio4;
		float drivetrain_gearRatio5;
		float drivetrain_reverseGearRatio;
		float drivetrain_finalDriveRatio;
		float engine_minRPM;
		float engine_optRPM;
		float engine_maxRPM;
		float engine_maxTorque;
		float engine_torqueFactorAtMinRPM;
		float engine_torqueFactorAtMaxRPM;
		float engine_resistanceMin;
		float engine_resistanceMax;
		float engine_resistanceMinSpeed;
		float engine_resistanceMaxSpeed;
		float suspension_frontSpringLength;
		float suspension_rearSpringLength;
		float suspension_frontSpringRate;
		float suspension_rearSpringRate;
		float suspension_frontShockDampingCompression;
		float suspension_rearShockDampingCompression;
		float suspension_frontShockDampingExtension;
		float suspension_rearShockDampingExtension;
		float suspension_frontUpTravelLimit;
		float suspension_rearUpTravelLimit;
		float suspension_frontDownTravelLimit;
		float suspension_rearDownTravelLimit;
		float suspension_angle_front;
		float suspension_angle_rear;
		float brakes_maxTorqueFront;
		float brakes_maxTorqueRear;
		float drivetrain_frontWheelTorqueRatio;
		float drivetrain_rearWheelTorqueRatio;
		float wheels_radius_front;
		float wheels_radius_rear;
		float wheels_frictionFront;
		float wheels_frictionRear;
		float steering_maxAngle;
		float aerodynamics_frontalArea;
		float aerodynamics_dragCoefficient;
		float aerodynamics_liftCoefficient;
		float other_extraGravity;
		float other_frictionEqualizer;
		float other_torqueRollFactor;
		float other_torquePitchFactor;
		float other_torqueYawFactor;
		float other_extraTorqueFactor;
		float other_normalClippingAngle;
		float other_chassisUnitInertiaYaw;
		float other_chassisUnitInertiaRoll;
		float other_chassisUnitInertiaPitch;
		float brakes_minTimeToBlock;
		float brakes_timeToMaxPedal;
		float brakes_frontMinPedalInputToBlock;
		float brakes_rearMinPedalInputToBlock;
		float wheels_mass;
		float wheels_viscosityFriction;
		float wheels_slipAngle;
		float wheels_forceFeedbackMultiplier;
		float aerodynamics_airDensity;
		float damping_normalSpinDamping;
		float damping_collisionSpinDamping;
		float damping_collisionThreshold;
		float other_cruiseControlPID_p;
		float other_cruiseControlPID_i;
		float other_cruiseControlPID_d;
		float steering_CenteringRate;
		float steering_DeadZone;
		float steering_FrontWheelMultiplier;
		float steering_RearWheelMultiplier;
		float burnout_MinSpeed;
		float burnout_MaxSpeed;
		float burnout_SpinTorqueAtLowSpeed;
		float burnout_SpinTorqueAtHighSpeed;
		float burnout_SpinFrontTireFrictionAtLowSpeed;
		float burnout_SpinFrontTireFrictionAtHighSpeed;
		float burnout_SpinRearTireFrictionAtLowSpeed;
		float burnout_SpinRearTireFrictionAtHighSpeed;
		float burnout_TorqueFactor_LowSpeed;
		float burnout_FwdThrustFactor_LowSpeed;
		float burnout_SideThrustFactor_LowSpeed;
		float burnout_TorqueFactor_HighSpeed;
		float burnout_FwdThrustFactor_HighSpeed;
		float burnout_SideThrustFactor_HighSpeed;
		float jturn_SpinTorque;
		float jturn_SpinFrontTireFriction;
		float jturn_SpinRearTireFriction;
		float blownTire_WobbleMagnitude;
		float blownTire_WobbleFrequency;
		float blownTire_Drag;
		float blownTire_FrictionMultiplier;
		float lodHeightFixupFront;
		float lodHeightFixupRear;
		float suspension_frontSpringRestingLength;
		float suspension_rearSpringRestingLength;
		float other_maxVelocityForPositionalFriction;
		bool burnout_UseNewMethod;

		UFG_PAD_ALIGN(0x7);
	};

	class CBikePhysicsDef : public CWheeledVehiclePhysicsDef
	{
	public:
		float aerodynamics_tuckDragBoost;
		float lean_DesiredLo;
		float lean_DesiredHi;
		float lean_MinSpeed;
		float lean_MaxSpeed;
		float lean_PID_p;
		float lean_PID_i;
		float lean_PID_d;
		float wheelie_SteeringRate;
		float wheelie_TorqueBoost;
		float wheelie_TorqueBoostTime;
		float wheelie_PID_p;
		float wheelie_PID_i;
		float wheelie_PID_d;
		float wheelie_Angle;
		float wheelie_BrakingAngle;
		float wheelie_BrakingYaw;
	};

	class CBoatPhysicsDef : public CBaseVehiclePhysicsDef
	{
	public:
		qVector3 pontoon0;
		qVector3 pontoon1;
		qVector3 pontoon2;
		qVector3 pontoon3;
		float rudderForceMultiplier;
		float rudderOffsetX;
		float rudderOffsetZ;
		float keelTorque;
		float maxRudderAngle;
		float maxEngineThrust;
		float engineThrustAngle;
		float viscousDrag;
		float viscousDrag2;
		float quadraticDragLateralVelocityLimit;
		float torqueDamping;
		float torqueDampingBowScale;
		float leanFactor;
		float COMShift;
		float bowThrusterCutoffSpeed;
		float bowThrusterPower;
		float bowThrusterOffsetX;
		float bowThrusterOffsetZ;
		float pontoon0Buoyancy;
		float pontoon1Buoyancy;
		float pontoon2Buoyancy;
		float pontoon3Buoyancy;
		float pontoon0DragZ;
		float pontoon1DragZ;
		float pontoon2DragZ;
		float pontoon3DragZ;
	};

	class CCarPhysicsDef : public CWheeledVehiclePhysicsDef
	{
	public:
		bool disableDoorL02;
		bool disableDoorR02;
		bool disableDoorL03;
		bool disableDoorR03;
		bool disableTrunk;
	};

	// ...
	class CBrakes : public hkpVehicleDefaultBrake
	{
	public:
		float mTimeToMaxPedal;
		float mTimePedalDown;
	};

	class CEngine : public hkpVehicleDefaultEngine
	{
	public:
		qArray<float> mTorqueTable;
		float mDamage;
		float mTorqueBoost;
		float mGovernorSpeedKPH;
		float mEngineResistanceMaxSpeed;
		float mEngineResistanceMinSpeed;
		float mEngineResistanceMin;
		float mEngineResistanceMax;
	};

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

	class CTransmission : public hkpVehicleDefaultTransmission
	{
	public:
		hkArray<float> mUpshiftRPM;
		hkArray<float> mDownshiftRPM;
		uint32_t mForceNeutral : 1;
	};


	class CVehicleAerodynamics : public hkpVehicleDefaultAerodynamics
	{
	public:
		float mDragBoost;
		float mExtraGravityMultiplier;
	};

	class CVehicleAction : public hkpUnaryAction
	{
	public:
		class CPhysicsWheeledVehicle* mVehicle;
		float mFlatTireDistance;
	};

	class CVehicleInput
	{
	public:
		float mSteering;
		float mForwardWeightShift;
		float mGasBrakes;
		float mRawGasBrakes;
		uint32_t mInReverse : 1;
		uint32_t mForceNeutral : 1;
		uint32_t mHandBrakeSet : 1;
		uint32_t mDoWheelie : 1;
		uint32_t mDoOneEighty : 1;
		uint32_t mDoBurnout : 1;
		uint32_t mFreemanStopTask : 1;
		uint32_t mFreemanSteerTask : 1;
		uint32_t mFreemanPreventWheelie : 1;
		uint32_t mHasHumanDriver : 1;
		uint32_t mHasAiDriver : 1;
	};

	class CVehicleInstance : public hkpVehicleInstance
	{
	public:
		hkQuaternionf mAxleFixup;
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
		UFG_PAD_ALIGN(0x8);

		void* mWaterFloatingTrackerComponent;
		CVehicleParams* mParams;

		UFG_PAD(0x28);

		CRigidBodyComponent* mRigidBody;
		hkpRigidBody* mBulletCollider;
		hkpRigidBody* mVolumeRigidBody;
		
		UFG_PAD(0x30);
		//UFG::PhysicsResourceHandle mCollisionMeshBundle;

		CCollisionMeshData* mBodyCollisionMesh;
		CCollisionMeshData* mBulletCollisionMesh;

		UFG_PAD_ALIGN(0x8);

		qMatrix44 mLastGoodPosition;
		qMatrix44 mBodyTransform;
		qMatrix44 mVolumeOffset;
		qMatrix44 mTargetTransform;
		qVector4 mLastFixupPosition;
		float mLastGoodPositionSampleTimer;
		class CVehicleCollisionListener* mCollisionListener;
		hkpReorientAction* mReorientActionRoll;
		hkpReorientAction* mReorientActionPitch;
		qSafePointer<class CParkourComponent> mParkourComponent;
		qSafePointer<class CDynamicCoverComponent> mCoverComponent;
		PhysicsVehicle::Lod mDesiredLod;
		PhysicsVehicle::Lod mCurrentLod;
		bool mIsProxy;
		float mAirSteerYawRate;
		float mVerticalVelocityDampingDown;
		float mVerticalVelocityDampingUp;
		float mHighSpeedGovernor;
		float mReverseSpeedGovernor;
		float mSuperStopDrag;
		float mPitchStability;
		float mRollStability;
		float mSpeedKPH;
		float mDollarValue;
		float mRotMassScaleForCollisions;
		int16_t mSystemId;
		uint32_t mNumWheels : 3;
		uint32_t mSuperStop : 1;
		uint32_t mIsAIControlled : 1;

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
		hkpVehicleWheelCollide* mWheelCollider;
		CVehicleInstance* mHavokVehicle;
		CVehicleAction* mVehicleAction;
		CEngine* mEngine;
		CTransmission* mTransmission;
		CBrakes* mBrakes;
		CSteering* mSteering;
		CVehicleAerodynamics* mAerodynamics;
		qVector4 mHardPointChassisSpace[4];
		qVector4 mSuspensionDirChassisSpace[4];
		qSafeArray<float, 4> mCurrentSuspensionLength;
		qSafeArray<float, 4> mSkidStrength;
		qSafeArray<float, 4> mForwardSkidStrength;
		qSafeArray<float, 4> mLateralSkidStrength;
		qSafeArray<float, 4> mWheelSpinAngle;
		qSafeArray<qVector3, 4> mGroundPoints;
		qSafeArray<bool, 4> mGroundHits;
		qSafeArray<float, 4> mRestingSuspensionLength;
		qSafeArray<float, 4> mSuspensionUpTravelLimit;
		qSafeArray<float, 4> mSuspensionDownTravelLimit;
		qSafeArray<float, 4> mTireDamage;
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
		uint32_t mGroundFixupRaysRecieved : 3;
		uint32_t mAllWheelsOffGround : 1;
		uint32_t mAllWheelsOnGround : 1;
		uint32_t mUseNewBurnoutMethod : 1;
		uint32_t mWheelFrictionMultiplierOverriddenByFreeman : 1;
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
		UFG_PAD(0x568);

		bool m_bAvoidPeds;
		bool m_bAllowedToPass;
		bool m_bStayOffSidewalk;
		bool m_bRespectSpeedLimit;
		bool m_ObeyTrafficLights;
		bool m_bCanTurnAround;
		bool m_bSavedAvoidPeds;
		bool m_bTemporaryAllowedToPass;
		bool m_RoadRuleFlagsLocked;
		bool m_AiAttackEnabled;
		bool m_AiScriptControlled;
		uint32_t m_TempPassLaneChangeDirectionCode;
		bool m_bIgnoreArrivalDirection;
		bool m_bIsParked;
		bool m_IsAmbient;
		uint32_t m_AmbientDriverType;
		float m_fSearchTimer;
		float mTargetWaitTimer;
		float m_RoadSpeedLimitScale;
		float m_DesiredSpeedLimit;
		bool m_AvoidObjectsEnabled;
		bool m_AvoidGeoEnabled;
		bool m_GoToSlowDownForDestination;
		bool m_GoToStopAtEnabled;
		qSafePointer<CSimObject> m_PathingTarget;
		float m_FacingTargetAngle;
		float m_StopAtDist;
		bool m_StopAtUseDestinationDirection;

		struct StopInfo_t
		{
			uint32_t eStopStyle;
			float fSteeringOverride;
			bool bHasSteeringOverride;
		};
		StopInfo_t m_StopInfo;

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

		void SetChaseTarget(CSimVehicle* m_Target)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimVehicle*)>(UFG_RVA(0x6587A0))(this, m_Target);
		}

		void SetDrivingMode(AiDriverComponent::eDriverMode p_Mode)
		{
			reinterpret_cast<void(__fastcall*)(void*, AiDriverComponent::eDriverMode)>(UFG_RVA(0x658B90))(this, p_Mode);
		}

		void SetDrivingRole(AiDriverComponent::eDriverRole p_Role)
		{
			reinterpret_cast<void(__fastcall*)(void*, AiDriverComponent::eDriverRole)>(UFG_RVA(0x658C90))(this, p_Role);
		}

		void SetFollowDistance(float p_Distance)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x6591E0))(this, p_Distance);
		}

		void StartRacing(float m_SpeedLimit, bool m_WanderAtEnd)
		{
			SetDrivingMode(AiDriverComponent::eDRIVER_MODE_RACE);
			SetDrivingRole(AiDriverComponent::eDRIVER_ROLE_RACER);

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

		// To reset use nullptr for m_Target
		void SetChaseTarget(CSimVehicle* m_Target)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimVehicle*)>(UFG_RVA(0x6588B0))(this, m_Target);
		}

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