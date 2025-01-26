#pragma once

namespace UFG
{
	enum ChaseCameraContext
	{
		eCHASE_CONTEXT_AIM,
		eCHASE_CONTEXT_FLEE,
		eCHASE_CONTEXT_RACE,
		eCHASE_CONTEXT_DRIVE,
		eCHASE_CONTEXT_BURNOUT,
		eCHASE_CONTEXT_PASSENGER,
		eCHASE_CONTEXT_HIJACK_BACK,
		eCHASE_CONTEXT_HIJACK_SIDE,
		eCHASE_CONTEXT_HIJACK_FRONT,
		eCHASE_CONTEXT_HIJACK_TOP,
		eCHASE_CONTEXT_LOOKBACK,
		eCHASE_CONTEXT_LOOKSIDE,
		eCHASE_CONTEXT_LOOKUP,
		eCHASE_CONTEXT_COUNT
	};

	class ChaseCameraParameters
	{
	public:
		const char* mName;
		qSymbol mNameSymbol;
		ChaseCameraContext mContext;
		qVector4 mVelocityBlendRamp;
		qVector4 mNoiseMagnitudeRamp;
		f32 mNoiseAmplitude;
		f32 mNoiseFrequency;
		int mNoiseOctaves;
		f32 mNoiseDecay;
		f32 mYawAngVelTimespan;
		f32 mLookOffsetMax;
		f32 mLookOffsetAngVelMin;
		f32 mLookOffsetAngVelMax;
		f32 mPitchOffsetMax;
		f32 mPitchOffsetLookFactorUp;
		f32 mPitchOffsetLookFactorDown;
		f32 mPitchOffsetEyeFactorUp;
		f32 mPitchOffsetEyeFactorDown;
		f32 mAimWobbleRadiusMin;
		f32 mAimWobbleRadiusMax;
		f32 mAimWobbleRadiusPeriod;
		f32 mAimWobbleFreq;
		f32 mAimWobbleAxisWeight;
		f32 mAimFreeDuration;
		f32 mAimLockedDuration;
		qVector4 mTargetOffsetLo;
		qVector4 mTargetOffsetMed;
		qVector4 mTargetOffsetHi;
		qVector4 mEyeOffsetLo;
		qVector4 mEyeOffsetMed;
		qVector4 mEyeOffsetHi;
		qVector4 mFovRamp;
		f32 mCenteringSpeedMin;
		f32 mCenteringSpeedMax;
		f32 mReverseSpeed;
		f32 mDutch;
		f32 mLurch;
		f32 mTilt;
		f32 mOrbitSpeed;
		f32 mDesaturation;
		f32 mMotionblurMagnitude;
		f32 mDofNearRange;
		f32 mDofNearBlur;
		f32 mDofFarRange;
		f32 mDofFarBlur;
		f32 mDof;
		f32 mOrbitLatitudeMin;
		f32 mOrbitLatitudeMax;
		f32 mOrbitHeightMinOffset;
		f32 mInAirEyeZOffset;
		f32 mInAirLookZOffset;
	};

	class ChaseCameraComponent : public GameCameraComponent, public qNode<ChaseCameraComponent>
	{
	public:
		enum { _TypeUID = 0x1E000045 };

		bool mIsLookingAround;
		f32 mLookaroundJoyInput;
		f32 mLookupJoyInput;
		f32 mLookupMouse;
		f32 mLookaroundCenterTimer;
		f32 mLookaroundAngle;
		f32 mLookaroundAngleDesired;
		f32 mTilt;
		f32 mLurch;
		f32 mCenteringSpeedMin;
		f32 mCenteringSpeedMax;
		f32 mReverseSpeed;
		f32 mOrbitSpeed;
		f32 mYawAngVelTimespan;
		f32 mLookOffsetMax;
		f32 mLookOffsetAngVelMin;
		f32 mLookOffsetAngVelMax;
		f32 mPitchOffsetMax;
		f32 mPitchOffsetLookFactorUp;
		f32 mPitchOffsetLookFactorDown;
		f32 mPitchOffsetEyeFactorUp;
		f32 mPitchOffsetEyeFactorDown;
		qVector3 mEyeOffset;
		qVector3 mTargetOffset;
		f32 mAimFreeDuration;
		f32 mAimLockedDuration;
		f32 mEyeOffsetDomain[3];
		qVector3 mEyeOffsetRange[3];
		f32 mTargetOffsetDomain[3];
		qVector3 mTargetOffsetRange[3];
		qVector4 mVelocityBlendRamp;
		qVector4 mNoiseMagnitudeRamp;
		qVector4 mFovRamp;
		qVector3 mShakeVector;
		f32 mShakeAmplitude;
		__declspec(align(16)) qMatrix44 mTargetWorld;
		qMatrix44 mEyeWorld;
		qMatrix44 mWorldEye;
		bool mLookingBack;
		f32 mLookbackCorrectionAngle;
		HomerCubic<qVector3> mUp;
		HomerCubic<f32> mFov;
		HomerCubic<qVector3> mEye;
		HomerCubic<qVector3> mLook;
		HomerCubic<qVector3> mAimEye;
		HomerCubic<qVector3> mAimLook;
		f32 mForwardAngle;
		f32 mForwardAngleDesired;
		HomerCubicAngular mDutch;
		HomerCubic<f32> mTargetPitch;
		f32 mRecoilAngle;
		f32 mRecoilAngleDesired;
		HomerCubic<qVector3> mRecoilEye;
		const f32 mYawAngVelWindowMaxTimespan;
		qAverageWindow<f32> mYawAngVelWindow;
		f32 mYawAngVelSubmittedTimespan;
		qNoise<qVector3> mEyeNoise;
		qNoise<qVector3> mLookNoise;
		RebindingComponentHandle<VehicleSubjectComponent> mTarget;
		TargetingSystemPedPlayerComponent* mTargetingSystem;
		ChaseCameraParameters* pChaseParameters;
		bool mAllowDesaturation;
		bool mUpdateEyeOffset;
		bool mHijackerLeft;
		bool mSnapNext;
		bool mAimOrFocus;
		qVector3 mFocusPos;
		bool mLockEye;
		bool mLockLook;
		qVector3 mLockEyeVel;
		qVector3 mLockLookVel;
		qVector3 mLockEyePos;
		qVector3 mLockLookPos;
		f32 mLockEyeParam;
		f32 mLockLookParam;
		f32 mAimParam;
		f32 mTransitionParam;
		f32 mDesaturation;
		f32 mMotionblurMagnitude;
		Render::DepthOfField::Focus mDofParameters;
		f32 mOrbitLatitudeMin;
		f32 mOrbitLatitudeMax;
		f32 mOrbitHeightMinOffset;
		f32 mInAirEyeZOffset;
		f32 mInAirLookZOffset;
		ChaseCameraParameters mPreviousParameters;
		f32 mBlendPrevious;
		f32 mBlendSeconds;
		f32 mTransitionParamEye;
		f32 mTransitionParamOrient;
		qVector3 mTransitionFromEye;
		qQuaternion mTransitionFromOri;
		f32 mTransitionFromLen;

		/* Functions */

		f32 GetBlendSeconds(ChaseCameraContext from_context, ChaseCameraContext to_context) { return SDK_CALL_FUNC(f32, 0x3C2870, void*, ChaseCameraContext, ChaseCameraContext)(this, from_context, to_context); }
		void GotoAngleSnap(f32 radians, bool worldSpace) { SDK_CALL_FUNC(void, 0x3C4990, void*, f32, bool)(this, radians, worldSpace); }
		void LockEye(bool lock) { SDK_CALL_FUNC(void, 0x3C6AF0, void*, bool)(this, lock); }
		void RestrictOrbitHeight(qVector3& eye) { SDK_CALL_FUNC(void, 0x3C8FB0, void*, qVector3&)(this, eye); }
		void SetChaseParameters(const ChaseCameraParameters* parameters) { SDK_CALL_FUNC(void, 0x3C98C0, void*, const ChaseCameraParameters*)(this, parameters); }
		void TransitionFrom(BaseCameraComponent* fromCamera, bool withVelocity) { SDK_CALL_FUNC(void, 0x3CE860, void*, BaseCameraComponent*, bool)(this, fromCamera, withVelocity); }
		void TransitionFromBlendOrientation(BaseCameraComponent* fromCamera) { SDK_CALL_FUNC(void, 0x3CE8F0, void*, BaseCameraComponent*)(this, fromCamera); }
		void TransitionTarget(SimObject* target) { SDK_CALL_FUNC(void, 0x3CF730, void*, SimObject*)(this, target); }
	};
	SDK_ASSERT_SIZEOF(ChaseCameraComponent, 0xD60);
}