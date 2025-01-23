#pragma once

class SkeletalAnimationHandle : public UFG::qNode<SkeletalAnimationHandle>
{
public:
	UFG::qSymbolUC m_SkeletalAnimationName;
	UFG::qSafePointer<SkeletalAnimation, SkeletalAnimation> m_SkeletalAnimation;
};

class SkeletalAnimation : public Expression::IMemberMap, public UFG::qSafePointerNode<SkeletalAnimation>, public UFG::qNodeRB<SkeletalAnimation>, public UFG::qNode<SkeletalAnimation>
{
public:
	UFG::AnimationResourceHandle m_AnimationResourceHandle;
	SkeletalAnimation* m_pFallbackAnimation;
	UFG::qList<SkeletalAnimationHandle> m_SkeletalAnimationHandles;
	UFG::qOffset64<AnimationGroup*> m_pAnimationGroup;
	UFG::qSymbolUC mNameSymbol;
	UFG::qSymbolUC mFallbackAnimSymbol;
	UFG::qOffset64<TrackGroup*> mTracks;
	UFG::qOffset64<MotionPhaseChannel*> mMotionPhaseChannel;
	u16 mRefCount;
	u16 mRefCountTotal;
	i16 mNumReferencesByAct;
	i8 mIsAdditivelyBlended;
	i8 mCompression;
	i8 mBlendMode;
	i8 mDisgardAdditiveRestPoseFrame;
	u16 mAdditiveRestPoseFrame;
	u32 mSize;
	f32 mDurationCached;
};