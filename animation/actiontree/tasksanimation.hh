#pragma once

class AnimationTrack;
class AnimationLockHighLODTrack;

class AnimationTask : public Task<AnimationTrack>
{
public:
	ActionContext* mContext;
	UFG::qSafePointer<AnimationNode> mController;
	UFG::qSafePointer<PoseNode> mSplitBodyBlend;
	bool mFinished;
	UFG::qVector3 mStartFacingVector;
};

class AnimationLockHighLODTask : public Task<AnimationLockHighLODTrack>, public UFG::qNode<AnimationLockHighLODTask>
{
public:
	ActionContext* m_pActionContext;
};