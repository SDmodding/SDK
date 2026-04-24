#pragma once

namespace UFG
{
	enum eAIObjectEnum : i32
	{
		eAIOBJECTTYPE_UNKNOWN,
		eAIOBJECTTYPE_DOOR,
		eAIOBJECTTYPE_SLIDNG_GATE,
		eAIOBJECTTYPE_SHUTTER_GATE
	};

	enum eHighlightModeEnum : i32
	{
		eHIGHLIGHT_MODE_NONE,
		eHIGHLIGHT_MODE_EXPLODABLE
	};

	enum CollisionGeomFlags : i32
	{
		CGF_STATIC = (1 << 0),
		CGF_DYNAMIC = (1 << 1),
		CGF_ANIMATED = (1 << 2),
		CGF_BOX_INERTIA = (1 << 3),
	};

	enum CollisionGeomType : i32
	{
		CGT_MOPP,
		CGT_CONVEX_VERTS,
		CGT_RUNTIME,
		CGT_SHAPELIST_MOPP,
		CGT_SHAPELIST,
		CGT_BOX,
		CGT_CYLINDER,
		CGT_SPHERE,
		CGT_CAPSULE
	};

	class PhysicsSurfaceProperties : public qReflectObjectType<PhysicsSurfaceProperties>
	{
	public:
		f32 mFriction;
		f32 mRestitution;
		f32 mBulletsPassThrough;
		f32 mBulletDamageMultiplier;
		bool mDisableFreeRunning;
		bool mCanSeeThrough;
		bool mGlass;
		bool mHasSurfaceVelocity;
		bool mIsStairs;
		bool mExplosionsPassThrough;
		bool mGrenadesPassThrough;
		bool mDeprecated;
		qWiseSymbol mAudioProperty;
		qSymbolUC mEffectProperty;
		qSymbolUC mSkidEffectUID;
		qSymbolUC mSlipEffectUID;
		qSymbolUC mBurnoutEffectUID;
		qSymbolUC mDriftEffectUID;
		qSymbolUC mAISkidEffectUID;
		qSymbolUC mAISlipEffectUID;
		qSymbolUC mAIBurnoutEffectUID;
		qSymbolUC mAIDriftEffectUID;
		qSymbolUC mTerrainType;
		char* debugName;
		u32 mNameUid;
	};
	SDK_ASSERT_SIZEOF(PhysicsSurfaceProperties, 0xA8);

	class PhysicsObjectProperties : public qReflectObjectType<PhysicsObjectProperties>
	{
	public:
		enum ActiveRegionMode : u32
		{
			ARM_ENABLE,
			ARM_DISABLE,
			ARM_USE_POWER_MANAGEMENT_COMPONENT
		};

		struct AudioProperty
		{
			qWiseSymbol mKey;
			qWiseSymbol mValue;
		};

		struct ConstraintProperty
		{
			qSymbol mName;
			qVector3 mConstraintPivot1;
			qVector3 mConstraintPivot2;
			qVector3 mHingeAxis;
			qVector3 mNormal;
			f32 mHingeLimitMin;
			f32 mHingeLimitMax;
			f32 mStrength;
			bool mBallSocketConstraint;
			bool mHingeConstraint;
			bool mStiffSpringConstraint;
			bool mPointInPlaneConstraint;
			int mBodyA;
			int mBodyB;
		};

		struct UserProperty
		{
			qSymbolUC mKey;
			u32 mValue;
		};

		f32 mass;
		f32 mGravityFactor;
		f32 linearDamping;
		f32 angularDamping;
		f32 mAttackVelocity;
		f32 shearImpulse;
		f32 shearImpulseAlternate;
		f32 inertiaFudgeFactor;
		f32 maxInertiaRatio;
		f32 mBuoyancyFactor;
		f32 mWindFactor;
		f32 mWaterLinearDamping;
		f32 mWaterAngularDamping;
		f32 mBulletImpulseMultiplier;
		f32 mConvexRadius;
		bool mStaticWorldDestructable;
		bool mDisableFreeRunning;
		bool mPreventStaticWorldMerge;
		bool mPreventShapeShrink;
		bool mForceLibraryObject;
		bool mDisablePhysicsPackerSettling;
		bool mAttackShootCombo;
		bool mDeprecated;
		bool mCreateWaterPhantom;
		bool mCollidesWithCamera;
		bool mCanOccludeCamera;
		bool mDrivesBoneTransform;
		bool mBuildIntoAiMesh;
		bool mIgnoredByAi;
		bool mEnableVeryLowLOD;
		bool mShearedByBullets;
		bool mShearedByExplosions;
		bool mAffectedByWind;
		bool mBlocksAttackCollision;
		bool mFadesAway;
		bool mCanVaultThrough;
		bool mOneWayCameraCollision;
		bool mSlowButAccurateCollisionDisabling;
		bool mDodgeable;
		bool mMeleeAttackable;
		bool mNoHitReactionsOnWorldCollisions;
		qReflectString mActFileName;
		CollisionLayers collisionLayer;
		hkpCollidableQualityType collisionQuality;
		CollisionGeomFlags mMotionType;
		CollisionGeomType mModelType;
		ActiveRegionMode mActiveRegionManagement;
		eAIObjectEnum mAIObjectType;
		eHighlightModeEnum mHighlightMode;
		eFractureConnectivity mFractureConnectivity;
		u32 mFreemanIdentifier;
		qVector3 mSurfaceVelocity;
		qVector3 mCentreOfMassOffset;
		qReflectArray<UserProperty> mUserProperties;
		qReflectArray<AudioProperty> mAudioProperties;
		qReflectArray<ConstraintProperty> mConstraintProperties;
		qReflectHandle<PhysicsSurfaceProperties> mDefaultSurfaceProperties;
		qSymbol mScriptEnumSym;
		qSymbol mNameUid;

		/* Functions */

		const qWiseSymbol& GetAudioProperty(const qWiseSymbol& key) { return SDK_CALL_FUNC(const qWiseSymbol&, 0xA95B0, void*, const qWiseSymbol&)(this, key); }
	};
	SDK_ASSERT_SIZEOF(PhysicsObjectProperties, 0x158);
}