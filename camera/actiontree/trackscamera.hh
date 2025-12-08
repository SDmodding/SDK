#pragma once

class CameraAnimationTrack : public Track<class CameraAnimationTask>
{
public:
	qEnum<enum AnimationPlayMode, u8> mAnimationPlayMode;
	f32 mStartFrame;
	f32 mEndFrame;
	f32 mFov;
	f32 mFocalDistance;
	f32 mInFocusRange;
	f32 mNearRange;
	f32 mNearBlurRadius;
	f32 mFarRange;
	f32 mFarBlurRadius;
	f32 mExitRateEyeMin;
	f32 mExitRateEyeMax;
	f32 mExitRateOrientMin;
	f32 mExitRateOrientMax;
	f32 mExitGotoAngle;
	f32 mExitGotoRise;
	UFG::qSymbolUC mAnimationName;
	bool mPreserveMotion;
	bool mTargetSpace;
	bool mSmoothExit;
	bool mAnimateParams;
	bool bMarkerRelative;
	bool bSingleBone;
	bool bAllowPostEffects;
	bool mSmoothExitUseVel;
	bool mSmoothExitGoto;
	bool bAllowSlowMotion;
};