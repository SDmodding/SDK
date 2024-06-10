#pragma once

namespace UFG
{
	class CPhysicsObjectProperties : public qReflectObject
	{
	public:
		float mass;
		float mGravityFactor;
		float linearDamping;
		float angularDamping;
		float mAttackVelocity;
		float shearImpulse;
		float shearImpulseAlternate;
		float inertiaFudgeFactor;
		float maxInertiaRatio;
		float mBuoyancyFactor;
		float mWindFactor;
		float mWaterLinearDamping;
		float mWaterAngularDamping;
		float mBulletImpulseMultiplier;
		float mConvexRadius;
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

		enum ActiveRegionMode
		{
			ARM_ENABLE = 0x0,
			ARM_DISABLE = 0x1,
			ARM_USE_POWER_MANAGEMENT_COMPONENT = 0x2,
		};
		ActiveRegionMode mActiveRegionManagement;

		eAIObjectEnum mAIObjectType;
		eHighlightModeEnum mHighlightMode;
		eFractureConnectivity mFractureConnectivity;
		uint32_t mFreemanIdentifier;
		qVector3 mSurfaceVelocity;
		qVector3 mCentreOfMassOffset;

		struct UserProperty
		{
			qSymbol mKey;
			uint32_t mValue;
		};
		qReflectArray<UserProperty> mUserProperties;

		struct AudioProperty
		{
			qWiseSymbol mKey;
			qWiseSymbol mValue;
		};
		qReflectArray<AudioProperty> mAudioProperties;

		struct ConstraintProperty
		{
			qSymbol mName;
			qVector3 mConstraintPivot1;
			qVector3 mConstraintPivot2;
			qVector3 mHingeAxis;
			qVector3 mNormal;
			float mHingeLimitMin;
			float mHingeLimitMax;
			float mStrength;
			bool mBallSocketConstraint;
			bool mHingeConstraint;
			bool mStiffSpringConstraint;
			bool mPointInPlaneConstraint;
			int mBodyA;
			int mBodyB;
		};
		qReflectArray<ConstraintProperty> mConstraintProperties;

		qReflectHandle<CPhysicsObjectProperties> mDefaultSurfaceProperties;
		qSymbol mScriptEnumSym;
		qSymbol mNameUid;
	};

	namespace PhysicsPropertyManager
	{
		UFG_INLINE qTreeRB* GetObjectPropertiesLookup()
		{
			return reinterpret_cast<qTreeRB*>(UFG_RVA(0x216DBA0));
		}
	}
}