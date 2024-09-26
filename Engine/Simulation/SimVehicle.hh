#pragma once

namespace UFG
{
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

	class CVehicleInstance : public hkpVehicleInstance
	{
	public:
		hkQuaternionf mAxleFixup;
	};

	class CVehicleParams
	{
	public:
		UFG_PAD(0x18);

		SimObject* mSimObject;
	};

	class CPhysicsVehicle : public CBasePhysicsObject
	{
	public:
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

		UFG_INLINE void ApplyTorque(float p_DeltaTime, const qVector3& p_Torque)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, const qVector3&, const char*)>(UFG_RVA(0x482B30))(this, p_DeltaTime, p_Torque, nullptr);
		}

		UFG_INLINE void ApplyTorque(float p_DeltaTime, const hkVector4f& p_Torque)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, const hkVector4f&, const char*)>(UFG_RVA(0x482AE0))(this, p_DeltaTime, p_Torque, nullptr);
		}

		UFG_INLINE uint32_t GetNumWheelsOnGround()
		{
			return reinterpret_cast<uint32_t(__fastcall*)(void*)>(UFG_RVA(0x466BF0))(this);
		}

		UFG_INLINE void FlipVehicle(float p_TorqueFactor, qVector3* p_CollisionPoint)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, qVector3*)>(UFG_RVA(0x4654C0))(this, p_TorqueFactor, p_CollisionPoint);
		}

		UFG_INLINE void SetMass(float p_Mass)
		{ 
			mRigidBody->SetMass(p_Mass);
		}

		UFG_INLINE float GetMass()
		{ 
			return mRigidBody->GetMass(); 
		}

		UFG_INLINE void SetMassScaleForCollisions(float scaleMass, float scaleRotMass)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, float)>(UFG_RVA(0x475170))(this, scaleMass, scaleRotMass);
		}

		UFG_INLINE void ClearMassScaleForCollisions()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x45A630))(this);
		}
	};
	UFG_ASSERT_CLASS(CPhysicsVehicle, 608);

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
	UFG_ASSERT_CLASS(CPhysicsWheeledVehicle, 1104);

	class CPhysicsCar : public CPhysicsWheeledVehicle
	{
	public:

	};

	// Components
	class CTargetingSystemVehicleComponent : public CTargetingSystemBaseComponent
	{
	public:
		UFG_INLINE void SetTargetLock(eTargetTypeEnum eTargetType, bool bLock, bool bModifyCollision)
		{
			reinterpret_cast<void(__fastcall*)(void*, eTargetTypeEnum, bool, bool, float, const char*, void*, void*)>(UFG_RVA(0x54F130))(this, eTargetType, bLock, bModifyCollision, 0.f, nullptr, nullptr, nullptr);
		}
	};

	class CVehicleAudioComponent : public SimComponent
	{
	public:
		UFG_PAD(0x23E);

		bool m_bHornOn : 1;
		bool m_bHornOnFlag : 1;
		bool m_bHornHasStimulus : 1;
		bool m_bSirenOn : 1;
		bool m_bSirenOnFlag : 1;
		bool m_bUnloadBanksFlag : 1;
		bool m_bShutdownOnExit : 1;

		UFG_INLINE void DoStopHorn(bool p_Stimulus)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x677130))(this, p_Stimulus);
		}
	};

	class CRoadSpaceComponent : public SimComponent
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

	class CAiDriverComponent : public SimComponent
	{
	public:
		UFG_PAD(0x130 - sizeof(SimComponent));
		// TODO:
		// - Parent class is VehicleDriverInterface rather than SimComponent...

		qNode<CAiDriverComponent> mNode;
		RebindingComponentHandle<CRoadSpaceComponent> m_pRoadSpace;
		RebindingComponentHandle<void*> m_pVehicleSubject;
		qSafePointer<void*> m_pChaseVehicleSubject;
		qSafePointer<void*> m_pEscortEnemyVehicleSubject;
		qSafePointer<void*> m_pEscortObjectiveVehicleSubject;

		UFG_PAD(0x160);
		/*
		UFG::qPidControllerCore m_SteeringPid;
		UFG::qPidControllerCore m_ThrottlePid;
		UFG::DrivingTargetOffsetMover m_OffsetMover;
		UFG::LinearGraph<float> *m_BrakingGraph;
		UFG::LinearGraph<float> *m_CarGapGraph;
		AIdPtr<SSInvokedCoroutine> m_DriveToCoroutine;
		*/

		AiDriverComponent::eDriverMode m_DrivingMode;
		AiDriverComponent::eDriverRole m_DrivingRole;
		qPropertySet* m_DriverProfile;
		qSafePointer<SimObject> m_CatchupTarget;

		UFG_PAD(0x98);
		// UFG::qPidControllerCore m_CatchupPid;

		float m_CatchupRangeBehind;
		float m_CatchupRangeAhead;
		float m_CatchupMaxSpeedUp;
		float m_CatchupMaxSlowDown;
		float m_CatchupOffset;
		float m_fDesiredSpeed;
		float m_fCurrentForwardSpeed;
		float m_fPreviousGasBrakes;
		float m_RoadSpeedLimit;
		qVector3 m_vSteerToPosition;
		float m_fSteeringScale;
		bool m_FollowDebug;
		bool m_AvoidanceDebug;
		CarCombat::Position m_DesiredOffset;
		CarCombat::Side m_Side;
		qVector3 m_vFollowOffsetActual;
		qVector3 m_vFollowOffsetDesired;
		float m_fFollowOffsetBlend;
		float m_fFollowOffsetTolerance;
		float m_fFollowDistance;
		float m_fTimeNearOffset;
		float m_fAttackTime;
		uint64_t m_iLastHighSpeedCollisionTimestamp;

		UFG_PAD(0x20);
		// UFG::qNoise<float,float> m_SteeringNoise;

		float m_fSteeringNoiseTimer;
		float m_fSteeringNoiseAmplitude;
		float m_fSteeringNoiseAmplitudeMin;
		bool mModeSteeringLockEnabled;
		float mModeSteeringLock;
		bool mModeGasBrakeLockEnabled;
		float mModeGasBrakeLock;
		bool m_bSteeringLock;
		float m_fSteeringLock;
		bool m_bGasBrakeLock;
		float m_fGasBrakeLock;
		float m_fReactionTime;

		UFG_PAD(0x20);
		// UFG::HistoryBuffer<UFG::qVector2> m_SteeringGasBrakeHistory;

		float m_fAvoidSteerLimit;
		float m_fAvoidStopTimer;
		float m_fBrakeTimer;
		float m_fStuckTimer;
		float m_fReverseTimer;
		qVector3 m_vStuckPosition;
		float m_GettingUnstuckTimer;
		float m_BeenUnstuckTimer;
		float m_fPassingTimer;
		float m_fPassingBias;
		void* m_AvoidableSensor;
		int m_NumAvoidableOverlaps;
		qSafePointer<SimObject> m_CurrentAvoidable;
		bool m_BlockedByAvoidable;
		void* m_pCastingSphere;
		void* m_pCastingPhantom;

		struct VehicleCombatStats_t
		{
			float mLastAttack[7];
			unsigned int mNumAttacks[7];
		};
		VehicleCombatStats_t m_CombatStats;

		CarCombat::Attack m_CurrentAttack;

		struct EscortInfo_t
		{
			CarAI::EEscortMode eEscortMode;
			float fDistanceSqrEnemyToObjectiveEnterAttackMode;
			float fDistanceSqrEnemyToObjectiveEnterEscortMode;
		};
		EscortInfo_t m_EscortInfo;

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
		qSafePointer<SimObject> m_PathingTarget;
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

	class CRemoteDriverComponent
	{
	public:
		UFG_PAD(0x30);

		CPhysicsMoverInterface* mMoverComponent;

		UFG_PAD(0x28);

		CVehicleEffectsComponent* mRenderComponent;
	};

	// Main
	class SimVehicle : public SimObject
	{
	public:
		UFG_INLINE CBaseAnimationComponent* GetAnimation()
		{
			return GetComponentOfType<CBaseAnimationComponent>(CharacterAnimationComponent_TypeUID);
		}

		UFG_INLINE CSimVehiclePropertiesComponent* GetVehicleProperties()
		{
			return GetComponentOfType<CSimVehiclePropertiesComponent>(VehiclePropertiesComponent_TypeUID);
		}

		UFG_INLINE CTargetingSystemVehicleComponent* GetTargetingSystemVehicle()
		{
			return GetComponentOfType<CTargetingSystemVehicleComponent>(VehicleTargetingSystemComponent_TypeUID);
		}

		UFG_INLINE CAiDriverComponent* GetAiDriver()
		{
			return GetComponentOfType<CAiDriverComponent>(VehicleAiDriverComponent_TypeUID);
		}

		UFG_INLINE CVehicleAudioComponent* GetAudio()
		{
			return GetComponentOfType<CVehicleAudioComponent>(VehicleAudioComponent_TypeUID);
		}

		UFG_INLINE CRoadSpaceComponent* GetRoadSpace()
		{
			return GetComponentOfType<CRoadSpaceComponent>(VehicleRoadSpaceComponent_TypeUID);
		}

		UFG_INLINE CVehicleOccupantComponent* GetVehicleOccupant()
		{
			return GetComponentOfType<CVehicleOccupantComponent>(VehicleOccupantComponent_TypeUID);
		}

		UFG_INLINE CVehicleEffectsComponent* GetVehicleEffects()
		{
			return GetComponentOfType<CVehicleEffectsComponent>(VehicleEffectsComponent_TypeUID);
		}

		UFG_INLINE CPhysicsMoverInterface* GetPhysicsMover()
		{
			return GetComponentOfType<CPhysicsMoverInterface>(VehiclePhysicsMoverInterface_TypeUID);
		}

		CRigidBodyComponent* GetRigidBody()
		{
			CPhysicsMoverInterface* PhysicsMover = GetPhysicsMover();
			if (PhysicsMover && PhysicsMover->mPhysicsVehicle) {
				return PhysicsMover->mPhysicsVehicle->mRigidBody;
			}

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

		UFG_INLINE void UnlockDoors(bool p_Unlock)
		{ 
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x65EDB0))(this, p_Unlock);
		}
	};
}