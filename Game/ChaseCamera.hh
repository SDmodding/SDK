#pragma once

namespace UFG
{
	enum ChaseCameraContext
	{
		eCHASE_CONTEXT_AIM = 0x0,
		eCHASE_CONTEXT_FLEE = 0x1,
		eCHASE_CONTEXT_RACE = 0x2,
		eCHASE_CONTEXT_DRIVE = 0x3,
		eCHASE_CONTEXT_BURNOUT = 0x4,
		eCHASE_CONTEXT_PASSENGER = 0x5,
		eCHASE_CONTEXT_HIJACK_BACK = 0x6,
		eCHASE_CONTEXT_HIJACK_SIDE = 0x7,
		eCHASE_CONTEXT_HIJACK_FRONT = 0x8,
		eCHASE_CONTEXT_HIJACK_TOP = 0x9,
		eCHASE_CONTEXT_LOOKBACK = 0xA,
		eCHASE_CONTEXT_LOOKSIDE = 0xB,
		eCHASE_CONTEXT_LOOKUP = 0xC,
		eCHASE_CONTEXT_COUNT = 0xD,
	};

	class CChaseCameraContextBlend
	{
	public:
		ChaseCameraContext mToContext;
		ChaseCameraContext mFromContext;
		float mBlendSeconds;
	};

	class CChaseCameraParameters
	{
	public:
		const char* mName;
		qSymbol mNameSymbol;
		ChaseCameraContext mContext;
		qVector4 mVelocityBlendRamp;
		qVector4 mNoiseMagnitudeRamp;
		float mNoiseAmplitude;
		float mNoiseFrequency;
		int mNoiseOctaves;
		float mNoiseDecay;
		float mYawAngVelTimespan;
		float mLookOffsetMax;
		float mLookOffsetAngVelMin;
		float mLookOffsetAngVelMax;
		float mPitchOffsetMax;
		float mPitchOffsetLookFactorUp;
		float mPitchOffsetLookFactorDown;
		float mPitchOffsetEyeFactorUp;
		float mPitchOffsetEyeFactorDown;
		float mAimWobbleRadiusMin;
		float mAimWobbleRadiusMax;
		float mAimWobbleRadiusPeriod;
		float mAimWobbleFreq;
		float mAimWobbleAxisWeight;
		float mAimFreeDuration;
		float mAimLockedDuration;
		qVector4 mTargetOffsetLo;
		qVector4 mTargetOffsetMed;
		qVector4 mTargetOffsetHi;
		qVector4 mEyeOffsetLo;
		qVector4 mEyeOffsetMed;
		qVector4 mEyeOffsetHi;
		qVector4 mFovRamp;
		float mCenteringSpeedMin;
		float mCenteringSpeedMax;
		float mReverseSpeed;
		float mDutch;
		float mLurch;
		float mTilt;
		float mOrbitSpeed;
		float mDesaturation;
		float mMotionblurMagnitude;
		float mDofNearRange;
		float mDofNearBlur;
		float mDofFarRange;
		float mDofFarBlur;
		float mDof;
		float mOrbitLatitudeMin;
		float mOrbitLatitudeMax;
		float mOrbitHeightMinOffset;
		float mInAirEyeZOffset;
		float mInAirLookZOffset;
	};
}