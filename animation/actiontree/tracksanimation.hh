#pragma once

class AnimationTrack : public Track<AnimationTask>
{
public:
	SkeletalAnimation* mAnimation;
	f32 mStartFrame;
	f32 mEndFrame;
	f32 mBlendInTime;
	f32 mBlendOutTime;
	f32 mPlayRate;
	int mPlayPriority;
	UFG::qSymbolUC mWeightSetName;
	UFG::qSymbolUC mAnimationName;
	qEnum<AnimationPlayMode, u8> mAnimationPlayMode;
	qEnum<AnimationBlendMode, u8> mAnimationBlendMode;
	qEnum<FloatInputSignal, u8> mFloatInputSignal;
	bool mPlayAnimtionTracks;
	bool mPhaseIn;
	bool mPreserveMotion;
	bool mResetMotionIntentionToFacing;

	/* Static Functions */

	SDK_SINLINE AnimationTrack* Create() { return SDK_CALL_FUNC(AnimationTrack*, 0x3152C0)(); }
};

class AnimationLockHighLODTrack : public Track<AnimationLockHighLODTask>
{
public:
};