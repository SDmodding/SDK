#pragma once

namespace UFG
{
	class GameCameraComponent : public BaseCameraComponent
	{
	public:
		enum { _TypeUID = 0x1E000005 };

		enum DOFOverridePriority
		{
			DOFOverridePriority_0,
			DOFOverridePriority_UI = DOFOverridePriority_0,
			DOFOverridePriority_1,
			DOFOverridePriority_Freeman = DOFOverridePriority_1,
			DOFOverridePriority_NumPriorities,
		};

		enum DynamicDofParamType
		{
			DynamicDofParamType_FocalDistance,
			DynamicDofParamType_FocusHalfRange,
			DynamicDofParamType_NearBlendRange,
			DynamicDofParamType_NearBlendRadius,
			DynamicDofParamType_FarBlendRange,
			DynamicDofParamType_FarBlendRadius,
			DynamicDofParamType_NumTypes
		};

		struct DofOverrideParams
		{
			bool bActive;
			f32 rFocalRange;
			f32 rNearRange;
			f32 rFarRange;
			f32 rNearBlur;
			f32 rFarBlur;
		};

		struct DynamicDofParam
		{
			HomerCubic<f32> mValue;
			f32 mDurationHigh;
			f32 mDeviationHigh;
			f32 mValueHigh;
			f32 mDurationLow;
			f32 mDeviationLow;
			f32 mValueLow;
			bool mIsHigh;
			f32 mDuration;
			f32 mElpasedTime;
		};

		int mResetNext;
		bool mInCollision;
		bool mLookModified;
		f32 mPushInOverrideRate;
		qVector3 mCollisionSurfaceNormal;
		qVector3 mCollisionContactPosition;
		qVector3 mCollisionLookOffset;
		f32 mSafeRadius;
		f32 mCollisionRise;
		f32 mCollisionBlend;
		f32 mCollisionPlateau;
		int mCollisionTargetPointsNum;
		qVector3 mCollisionTargetPoints[4];
		ShapeCasterCollector* pCollisionCollectorTargetPoints;
		ShapeCasterCollector* pCollisionCollector;
		f32 mCollisionTargetPointCastingRadiusSubmitted;
		f32 mCollisionCastingRadiusSubmitted;
		bool mAlternateLookValid;
		qVector3 mAlternateLook;
		bool mEyePushValid;
		f32 mEyePushPercent;
		f32 mEyePushRise;
		bool mAllowCanOccludeCamera;
		qVector3 mCandidateEye;
		SimObject* pSimObjectPassThru1;
		SimObject* pSimObjectPassThru2;
		qNoise<f32> mDofNoise;
		qNoise<qVector3, f32> mEyeImpactNoise;
		qNoise<qVector3, f32> mLookImpactNoise;
		qVector2 mAimWobble;
		f32 rAimWobbleRadiusMin;
		f32 rAimWobbleRadiusMax;
		f32 rAimWobbleRadiusPeriod;
		f32 rAimWobbleFreq;
		f32 rAimWobbleAxisWeight;
		bool bAimWobbleHoldingBreathInput;
		bool bAimWobbleHoldingBreath;
		f32 rAimWobbleOverallScale;
		f32 rAimWobbleElapsedTime;
		f32 rAimWobbleHoldBreathElapsedTime;
		f32 rAimWobbleBreathElapsedTime;
		f32 rAimWobbleHoldBreathMultiplier;
		HomerCubic<f32> cAimWobbleRadius;
		f32 mImpactShakeSeed;
		f32 mImpactShakeTimer;
		f32 mImpactShakeAmplitude;
		f32 mImpactShakeAmplitudeDecay;
		f32 mDofNoiseTimer;
		f32 mDofNoiseAmplitude;
		f32 mDofNoiseAmplitudeDecay;

		/* Static Functions */

		SDK_SINLINE bool GetSurfaceNormal(qVector3& surfNormal, hkpCollidable* collidable, u32 shapeKey) {
			return SDK_CALL_FUNC(bool, 0x3C39E0, qVector3&, hkpCollidable*, u32)(surfNormal, collidable, shapeKey);
		}
		SDK_SINLINE void StartDynamicDof() { SDK_CALL_FUNC(void, 0x3CE4E0)(); }
		SDK_SINLINE void StopDynamicDof() { SDK_CALL_FUNC(void, 0x3CE4F0)(); }

		/* Virtual Functions */

		virtual void SnapToCurrent() = 0;
		virtual void SnapToDesired() = 0;
		virtual void HandleDamage(float damage) = 0;
		virtual void HandleImpact(float magnitude) = 0;
		virtual const qVector3& MotionRelativeDirection() = 0;
		virtual const qVector3& GetStreamingPosition() = 0;
		virtual bool IsUsingHighZoom() = 0;
		virtual bool IsAiming() = 0;
		virtual bool IsMotionTowardsPlayer() = 0;
		virtual bool GetMotionCorrection() = 0;
		virtual void GunRecoil(f32 scaleKickup, f32 scaleKickback, f32 scaleSpeed) = 0;
		virtual TargetingSystemBaseComponent* GetTargetingSystem() = 0;
		virtual f32 GetDofDamageMultiplier() = 0;

		/* Functions */

		void AddShakeAmplitude(f32 shake) { SDK_CALL_FUNC(void, 0x3BF110, void*, f32)(this, shake); }
		bool AnyTargetPointVisible(const qVector3& eye) { return SDK_CALL_FUNC(bool, 0x3BF1C0, void*, const qVector3&)(this, eye); }
		void BeginDOFOverride(f32 focalRange, f32 nearRange, f32 farRange, f32 nearBlur, f32 farBlur, DOFOverridePriority priority) {
			SDK_CALL_FUNC(void, 0x3BFB40, f32, f32, f32, f32, f32, DOFOverridePriority)(focalRange, nearRange, farRange, nearBlur, farBlur, priority);
		}
		f32 ComputeNearOffset(const qVector3& eye, const qVector3& look, f32 dispFov) { return SDK_CALL_FUNC(f32, 0x3C0C20, void*, const qVector3&, const qVector3&, f32)(this, eye, look, dispFov); }
		void EndDOFOverride(DOFOverridePriority priority) { SDK_CALL_FUNC(void, 0x3C20F0, DOFOverridePriority)(priority); }
		ShapeCasterCollector::HitInfo* FindClosestCollidableHit(ShapeCasterCollector* collector, const qVector3& startPos, f32 safeRadius) {
			return SDK_CALL_FUNC(ShapeCasterCollector::HitInfo*, 0x3C2160, void*, ShapeCasterCollector*, const qVector3&, f32)(this, collector, startPos, safeRadius);
		}
		void ResetAimWobble() { SDK_CALL_FUNC(void, 0x3C8A00, void*)(this); }
		void ResetDutch(bool snap) { SDK_CALL_FUNC(void, 0x3C8D20, bool)(snap); }
		void SetCollisionIgnoreCharacters(bool enable) { SDK_CALL_FUNC(void, 0x3C9F80, bool)(enable); }
		void SetCollisionIgnoreVehicles(bool enable) { SDK_CALL_FUNC(void, 0x3C9F90, bool)(enable); }
		void SetDesiredEyeLookUp(f32 dt, const qVector3& desEye, const qVector3& desLook, const qVector3& desUp, bool collide, qVector3* newEye = 0, qVector3* newLook = 0) {
			SDK_CALL_FUNC(void, 0x3CB1C0, void*, f32, const qVector3&, const qVector3&, const qVector3&, bool, qVector3*, qVector3*)(this, dt, desEye, desLook, desUp, collide, newEye, newLook);
		}
		void SetDutch(f32 angle, bool snap) { SDK_CALL_FUNC(void, 0x3CC280, f32, bool)(angle, snap); }
		void SetDynamicDOFParam(DynamicDofParamType dofParamType, f32 duration_high, f32 deviation_high, f32 value_high, f32 duration_low, f32 deviation_low, f32 value_low) {
			SDK_CALL_FUNC(void, 0x3CC350, DynamicDofParamType, f32, f32, f32, f32, f32, f32)(dofParamType, duration_high, deviation_high, value_high, duration_low, deviation_low, value_low);
		}
		void SetDynamicDutch(f32 dur_high, f32 dur_dev_high, f32 ang_high, f32 ang_dev_high, f32 dur_low, f32 dur_dev_low, f32 ang_low, f32 ang_dev_low) {
			SDK_CALL_FUNC(void, 0x3CC3A0, f32, f32, f32, f32, f32, f32, f32, f32)(dur_high, dur_dev_high, ang_high, ang_dev_high, dur_low, dur_dev_low, ang_low, ang_dev_low);
		}
		void SetHoldingBreathInput(bool enable) { SDK_CALL_FUNC(void, 0x3CCBD0, void*, bool)(this, enable); }
		bool ShouldPassThru(ShapeCasterCollector::HitInfo* info, const qVector3& startPos) {
			return SDK_CALL_FUNC(bool, 0x3CD680, void*, ShapeCasterCollector::HitInfo*, const qVector3&)(this, info, startPos);
		}
	};
	SDK_ASSERT_SIZEOF(GameCameraComponent, 0x4E0);
}