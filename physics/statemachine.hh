#pragma once

namespace UFG
{
	class StateMachineEffectNode
	{
	public:
		qMatrix44 mTransform;
		f32 mStartTime;
		f32 mEndTime;
		qSymbolUC mNameUid;
		bool mAttachToObject;
	};

	class StateMachineNode
	{
	public:
		enum MovementMode
		{
			MODE_FIXED = 0x40,
			MODE_SIMULATED = 0x80,
			MODE_ANIMATED_HARDKEYFRAME = 0x100,
			MODE_ANIMATED_SOFTKEYFRAME = 0x200
		};

		typedef CollisionLayers SelectableLayers;

		struct ConstraintNode
		{
			enum ConstraintType
			{
				BALL_AND_SOCKET,
				HINGE,
				STIFF_SPRING
			};

			qVector4 mConstraintPivot1;
			qVector4 mConstraintPivot2;
			qVector4 mHingeAxis;
			f32 mHingeLimitMin;
			f32 mHingeLimitMax;
			qSymbol mName;
			ConstraintType mType;
		};

		struct ExitCondition
		{
			enum Conditional
			{
				HEALTH_LESSTHAN_OR_EQUAL,
				ON_FRACTURE,
				ON_COLLISION_ANY,
				ON_COLLISION_WORLD,
				ON_COLLISION_VEHICLE,
				ON_COLLISION_CHARACTER,
				ON_TIMER_EXPIRED,
				ON_SPAWN,
				ON_NAMED_EVENT,
				RANDOM_BRANCH,
				BRANCH_ALWAYS
			};

			Conditional mConditional;
			f32 mFloatParameter;
			qSymbol mStringParameter;
			qSymbol mGotoNode;
		};

		struct FractureElementNode
		{
			enum State
			{
				ENABLE,
				DISABLE
			};

			qSymbolUC mElementUid;
			State mState;
		};

		struct FractureController
		{
			qSymbolUC mElementUid;
			qReflectArray<FractureElementNode> mFractureElements;
		};

		struct RiggedGeoNode
		{
			qSymbolUC mBoneNameUid;
			bool mEnabled;
			bool mRemoveDecals;
		};

		struct SpawnNode
		{
			qMatrix44 mTransform;
			qVector3 mLinearImpulse;
			qVector3 mAngularImpulse;
			qSymbol mSpawnPropertySet;
		};

		qReflectString mName;
		qReflectArray<StateMachineEffectNode> mEffectNodes;
		qReflectArray<SpawnNode> mSpawnNodes;
		qReflectArray<RiggedGeoNode> mRiggedGeoNodes;
		qReflectArray<ConstraintNode> mConstraintNodes;
		qReflectArray<FractureController> mFractureControllers;
		qReflectArray<ExitCondition> mExitConditions;
		qReflectString mActionPath;
		qReflectString mDebugPrintString;
		qVector4 mThrusterForce;
		qVector4 mThrusterOffset;
		qVector4 mPhantomOffset;
		qVector3 mExplosionOffset;
		qVector3 mStimulusOffset;
		qVector3 mPhantomBoxExtents;
		qVector3 mLinearImpulseDirection;
		qVector3 mLinearImpulsePosition;
		f32 mLinearImpulseMagnitude;
		qVector3 mAngularImpulseAxis;
		f32 mAngularImpulseMagnitude;
		qSymbol mExplosionType;
		qSymbol mStimulusType;
		qSymbol mStimulusEmissionType;
		qSymbol mKillConstraintByName;
		qSymbol mEnableConstraintByName;
		f32 mStimulusMaxDuration;
		f32 mStimulusEmitUntilSpeedLessThan;
		f32 mHealthThreshold;
		f32 mFracturePercentForDisableParkourHandle;
		f32 mFracturePercentForDisableCoverCorner;
		f32 mHealthDegradeRate;
		f32 mThrusterDuration;
		f32 mThrusterDecayRate;
		f32 mPhantomTimer;
		f32 mLifeSpan;
		qSymbolUC mPhantomVolume;
		qSymbolUC mRenderModelSwap;
		qSymbolUC mImpactEffectUid;
		qSymbol mVisualTreatmentUid;
		qReflectString mSoundEffectUid;
		bool mSetMovementMode;
		MovementMode mMovementMode;
		bool mChangeCollisionLayer;
		SelectableLayers mCollisionLayer;
		bool mDelete;
		bool mFractureObject;
		bool mHasThruster;
		bool mExecuteUponFracture;
		bool mExecuteUponSpawn;
		bool mKillEffects;
		bool mEnableAllConstraints;
		bool mDisableAllConstraints;
		bool mKillAllConstraints;
		bool mDisableCollision;
		bool mRemoveDecals;
		bool mDisableSelfIllumination;
		bool mDisableParkourHandle;
		bool mDisableCoverCorners;
		bool mDisableTrafficLightEffects;
		bool mEnableTrafficLightEffects;
		bool mExplosionEmitsStimulus;
		f32 mTimer;
		qSymbol mSendNamedEvent;
	};

	class StateMachineDefinition : public qReflectObjectType<StateMachineDefinition>
	{
	public:
		class LookupNode : public qNodeRB<LookupNode>
		{
		public:
			u64 dna_guid;
		};

		qReflectArray<StateMachineNode> mStateNodes;
		qSymbolUC name;
		f32 mBulletDamageMultiplier;
		f32 mExplosionDamageMultiplier;
		f32 mImpactDamageMultiplier;
		f32 mImpactDamageThreshold;
		f32 mAttackDamageMultiplier;
		bool mHasCollisionEventHandler;
		bool mHasNamedEventHandler;
		bool mHasOnSpawnNode;

		/* Static Functions */

		SDK_SINLINE u64 GetDnaUid(u32 nameGuid) { return SDK_CALL_FUNC(u64, 0x4664A0, u32)(nameGuid); }
	};
}