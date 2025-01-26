#pragma once

namespace UFG
{
	enum FollowCameraContext
	{
		eFOLLOW_CONTEXT_WALK,
		eFOLLOW_CONTEXT_SPRINT,
		eFOLLOW_CONTEXT_WALK_SLOW,
		eFOLLOW_CONTEXT_SOCIAL,
		eFOLLOW_CONTEXT_AIM,
		eFOLLOW_CONTEXT_AIM_PHONE,
		eFOLLOW_CONTEXT_AIM_SNIPER,
		eFOLLOW_CONTEXT_AIM_AIRBORNE,
		eFOLLOW_CONTEXT_WALK_TARGETED,
		eFOLLOW_CONTEXT_WALK_WGUN,
		eFOLLOW_CONTEXT_SPRINT_WGUN,
		eFOLLOW_CONTEXT_OVERRIDE_TOW,
		eFOLLOW_CONTEXT_COUNT_NON_OVERRIDES = eFOLLOW_CONTEXT_OVERRIDE_TOW,
		eFOLLOW_CONTEXT_OVERRIDE_AIM,
		eFOLLOW_CONTEXT_OVERRIDE_FOCUS,
		eFOLLOW_CONTEXT_OVERRIDE_GRAPPLE,
		eFOLLOW_CONTEXT_COUNT
	};

	enum FollowCameraType
	{
		eFOLLOW_CAMERA_TYPE_TOW,
		eFOLLOW_CAMERA_TYPE_AIM,
		eFOLLOW_CAMERA_TYPE_FOCUS,
		eFOLLOW_CAMERA_TYPE_GRAPPLE,
		NUM_FOLLOW_CAMERA_TYPES
	};

	class FollowCameraComponent : public GameCameraComponent, public qNode<FollowCameraComponent>
	{
	public:
		enum { _TypeUID = 0x1E000025 };

		struct FollowParams
		{
			f32 mTweakFov;
			f32 mTweakFovMax;
			f32 mTweakOrbitDownRadius;
			f32 mTweakEyeRise;
			f32 mTweakOrbitSpeed;
			f32 mTweakLatitudeMin;
			f32 mTweakLatitudeMax;
			f32 mTweakRadiusMin;
			f32 mTweakRadiusMax;
			f32 mTweakVaultLow;
			f32 mTweakNoiseFrequency;
			f32 mTweakAimWobbleRadiusMin;
			f32 mTweakAimWobbleRadiusMax;
			f32 mTweakAimWobbleRadiusPeriod;
			f32 mTweakAimWobbleFreq;
			f32 mTweakAimWobbleAxisWeight;
			f32 mTweakNoiseEyeMagnitude;
			f32 mTweakNoiseLookMagnitude;
			f32 mTweakAimRadius;
			f32 mTweakFocusRadius;
			f32 mTweakTargetedDistance;
			CharacterSubjectComponent::SrcTransform mSrcOrientation;
			CharacterSubjectComponent::SrcTransform mSrcPosition;
			bool mTweakUseSyncBase;
			bool mTweakBlendDurations;
			f32 mTweakVelocityDuration;
			f32 mTweakLookDurationH;
			f32 mTweakLookDurationV;
			f32 mTweakEyeDurationH;
			f32 mTweakEyeDurationV;
			f32 mTweakFovDuration;
			qVector3 mTweakLookOffset;
			qVector3 mTweakCamThru;
			qVector3 mTweakAimThru;
			qVector3 mTweakBaseOffset;
			f32 mTweakSmoothRatePos;
			f32 mTweakSmoothRateRot;
			bool mUseInitRise;
			f32 mInitRise;
			f32 mInitRiseRate;
			f32 mInitRisePatience;
			bool mUseInitRadius;
			f32 mInitRadius;
			f32 mInitRadiusRate;
			f32 mInitRadiusPatience;
			bool mUseInitAngle;
			f32 mInitAngle;
			f32 mInitAngleRate;
			f32 mInitAnglePatience;
			bool mInitAngleWorldSpace;
			bool mInitAngleUseSecond;
			f32 mInitAngleSecond;
			bool mYawRestrict;
			f32 mYawConstrainRate;
			f32 mYawMin;
			f32 mYawMax;
			bool mUseLookUpDown;
			bool mHorizCompUseDirection;
			f32 mHorizCompOffsetScale;
			f32 mHorizCompSpeedWindowTimespan;
			f32 mHorizCompSpeedMin;
			f32 mHorizCompSpeedMax;
			f32 mHorizCompDurationAttack;
			f32 mHorizCompDurationDecay;
			f32 mDesaturation;
			f32 mDamageMultiplier;
			f32 mMotionblurMagnitude;
			bool mUseDofParameters;
			f32 mDofInFocusRange;
			f32 mDofNearRange;
			f32 mDofNearBlurRadius;
			f32 mDofFarRange;
			f32 mDofFarBlurRadius;
			f32 mCollisionRise;
		};

		int mNumMeleeAttackers;
		qVector3 mMeleeAttackerPositions[16];
		f32 mDofFarFocalDist;
		RebindingComponentHandle<CharacterSubjectComponent> mTarget;
		RebindingComponentHandle<CameraSubject> mEnemyTarget;
		FollowCameraType mType;
		FollowCameraContext mContext;
		FollowCameraType mPreviousType;
		FollowCameraContext mPreviousContext;
		FollowParams mContextParameters[15];
		bool mFreeAiming;
		bool mSoftLocked;
		bool mFocusLocked;
		bool bResetFromTarget;
		bool bUpdateFromAimComp;
		bool mSnapNext;
		bool mSniperEnabled;
		bool bAllowTargeted;
		bool bAllowDesaturation;
		HomerCubic<f32> mFov;
		HomerCubic<qVector3> mEye;
		HomerCubic<qVector3> mLook;
		qVector3 mUpFrom;
		HomerCubic<qVector3> mVelocity;
		__declspec(align(16)) qMatrix44 mTargetWorld;
		HomerCubic<qVector3> mOffsetLook;
		HomerCubic<qVector3> mOffsetEye;
		bool mMaxRadiusOverrideEnabled;
		f32 mMaxRadiusOverrideParam;
		f32 mMaxRadiusOverride;
		bool mRiseOverrideEnabled;
		f32 mRiseOverrideParam;
		f32 mRiseOverride;
		bool mAutoFrameEnabled;
		bool mAutoFrameActive;
		f32 mAutoFrameFarthestAttackerDist;
		bool mAutoFrameSnapNextAttackerDist;
		f32 mRecoilAngle;
		f32 mRecoilAngleDesired;
		HomerCubic<qVector3> mRecoilEye;
		qNoise<qVector3> mEyeNoise;
		qNoise<qVector3> mLookNoise;
		qVector3 mAimOrigin;
		qVector3 mControllerForward;
		f32 mOrbitSquish;
		f32 mLatitudeMin;
		f32 mHeightAboveGround;
		f32 mBlend;
		f32 mBlendRate;
		FollowParams mOldParams;
		FollowParams mBlendedParams;
		f32 mPassThroughTimer1;
		f32 mPassThroughTimer2;
		qVector3 mAimDeadZoneCentre;
		f32 mAimDeadZoneRadius;
		f32 mAimDeadZoneTimer;
		const f32 mHorizCompTargetSpeedWindowMaxTimespan;
		qAverageWindow<f32> mHorizCompTargetSpeedWindow;
		f32 mHorizCompTargetSpeedSubmittedTimespan;
		HomerCubic<f32> mHorizCompOffset;
		f32 mGotoRiseElaspedTime;
		f32 mGotoRisePatience;
		f32 mGotoRiseRate;
		f32 mGotoRise;
		bool mGotoAngleCollisionQueued;
		f32 mGotoAngleCollisionQueuedWallDist;
		f32 mGotoAngleElaspedTime;
		bool mGotoAngleLocalSpace;
		f32 mGotoAnglePatience;
		f32 mGotoAngleRate;
		f32 mGotoAngle;
		f32 mGotoRadiusElaspedTime;
		f32 mGotoRadiusPatience;
		f32 mGotoRadiusRate;
		f32 mGotoRadius;
		bool mConstrainYaw;
		f32 mConstrainYawMin;
		f32 mConstrainYawMax;
		f32 mConstrainYawRate;
		bool bAimUseEyeLook;
		f32 rAimParameter;
		HomerCubic<qVector3> mAimEye;
		HomerCubic<qVector3> mAimLook;
		f32 mAimDurationSupplimentary;
		f32 mMouseBucketX;
		f32 mMouseBucketY;
		f32 mTransitionTimeOverride;
		f32 mTransitionParamRateEye;
		f32 mTransitionParamRateOrient;
		f32 mTransitionParamEye;
		f32 mTransitionParamOrient;
		f32 mTransitionParamRateSuppEye;
		f32 mTransitionParamRateSuppLook;
		f32 mTransitionParamSuppEye;
		f32 mTransitionParamSuppLook;
		f32 mTransitionParamDutch;
		f32 mTransitionSupplimentaryDuration;
		qVector3 mTransitionFromEye;
		qQuaternion mTransitionFromOri;
		f32 mTransitionFromLen;
		bool mEnableCharacterSpaceSmoothing;
		qVector4 mCharacterSpacePos;
		f32 mTimeShouldBeInVehicleCamButAreNot;
		bool mMouseBoomSet;
		qVector3 mMouseBoom;

		/* Functions */

		bool BoomClamp(qVector3& boom) { return SDK_CALL_FUNC(bool, 0x3C0950, void*, qVector3&)(this, boom); }
		bool BoomClamp(qVector3& boom_in, f32 radius, f32 radius_up, f32 radius_down, bool keep_out) {
			return SDK_CALL_FUNC(bool, 0x3C0A00, void*, qVector3&, f32, f32, f32, bool)(this, boom_in, radius, radius_up, radius_down, keep_out);
		}
		qVector3 BoomClamp(const qVector3& boom, f32 radius, const qVector3& ray) {
			return SDK_CALL_FUNC(qVector3, 0x3C07C0, void*, const qVector3&, f32, const qVector3&)(this, boom, radius, ray);
		}
		f32 GetClosestAngle(f32 angleA, f32 angleB, bool worldSpace, bool returnFarthestAngle) {
			return SDK_CALL_FUNC(f32, 0x3C29D0, void*, f32, f32, bool, bool)(this, angleA, angleB, worldSpace, returnFarthestAngle);
		}
		void GotoAngle(f32 angle, f32 rate, f32 patience, bool worldSpace) { SDK_CALL_FUNC(void, 0x3C43D0, void*, f32, f32, f32, bool)(this, angle, rate, patience, worldSpace); }
		void GotoAngleCollision(f32 wallDist, const qVector3& eye, const qVector3& look, const qVector3& up) {
			SDK_CALL_FUNC(void, 0x3C4410, void*, f32, const qVector3&, const qVector3&, const qVector3&)(this, wallDist, eye, look, up);
		}
		void GotoAngleCollisionQueue(f32 wallDist) { SDK_CALL_FUNC(void, 0x3C4980, void*, f32)(this, wallDist); }
		void GotoAngleSnap(f32 radians, bool worldSpace) { SDK_CALL_FUNC(void, 0x3C4B80, void*, f32, bool)(this, radians, worldSpace); }
		void GotoRadius(f32 radius, f32 rate, f32 patience) { SDK_CALL_FUNC(void, 0x3C4D60, void*, f32, f32, f32)(this, radius, rate, patience); }
		void GotoRise(f32 rise, f32 rate, f32 patience) { SDK_CALL_FUNC(void, 0x3C4D90, void*, f32, f32, f32)(this, rise, rate, patience); }
		void GotoRiseSnap(f32 rise) { SDK_CALL_FUNC(void, 0x3C4DC0, void*, f32)(this, rise); }
		void InitBlendedParams() { SDK_CALL_FUNC(void, 0x3C5B10, void*)(this); }
		void LoadContextParameters(FollowParams& context_parameters, const qSymbol& context_symbol) {
			SDK_CALL_FUNC(void, 0x3C5FD0, void*, FollowParams&, const qSymbol&)(this, context_parameters, context_symbol);
		}
		void LoadContextParameters() { SDK_CALL_FUNC(void, 0x3C6960, void*)(this); }
		bool NeedConstrainYaw(f32& yawConstraintAngle, f32& yawConstraintRate) { return SDK_CALL_FUNC(bool, 0x3C7340, void*, f32&, f32&)(this, yawConstraintAngle, yawConstraintRate); }
		void NewTargetPosition(const qVector3& position, f32 angle) { SDK_CALL_FUNC(void, 0x3C7660, void*, const qVector3&, f32)(this, position, angle); }
		void ResetFromTarget(bool snap) { SDK_CALL_FUNC(void, 0x3C8E00, void*, bool)(this, snap); }
		void Rotate(f32 delta_latitude, f32 delta_longitude) { SDK_CALL_FUNC(void, 0x3C9160, void*, f32, f32)(this, delta_latitude, delta_longitude); }
		void SafetyDetectInconsistentCameraMode(f32 dt) { SDK_CALL_FUNC(void, 0x3C9340, void*, f32)(this, dt); }
		void SetAimDeadZone(f32 fraction_fov) { SDK_CALL_FUNC(void, 0x3C97A0, void*, f32)(this, fraction_fov); }
		void SetContext(FollowCameraContext context, char force_set) { SDK_CALL_FUNC(void, 0x3C9FA0, void*, FollowCameraContext, char)(this, context, force_set); }
		void SetCurrent(bool current) { SDK_CALL_FUNC(void, 0x3CAFF0, void*, bool)(this, current); }
		void SetOverrideMaxRadius(f32 maxRadius) { SDK_CALL_FUNC(void, 0x3CCF80, void*, f32)(this, maxRadius); }
		void SetOverrideRise(f32 rise) { SDK_CALL_FUNC(void, 0x3CCFC0, void*, f32)(this, rise); }
		void TransitionFromBlendOrientation(BaseCameraComponent* fromCamera, f32 eyeRateMin, f32 eyeRateMax, f32 orientRateMin, f32 orientRateMax) {
			SDK_CALL_FUNC(void, 0x3CEE00, void*, BaseCameraComponent*, f32, f32, f32, f32)(this, fromCamera, eyeRateMin, eyeRateMax, orientRateMin, orientRateMax);
		}
		void TransitionFromSuppDuration(BaseCameraComponent* fromCamera, bool withVelocity) { SDK_CALL_FUNC(void, 0x3CF390, void*, BaseCameraComponent*, bool)(this, fromCamera, withVelocity); }
	};
	SDK_ASSERT_SIZEOF(FollowCameraComponent, 0x21C0);
}