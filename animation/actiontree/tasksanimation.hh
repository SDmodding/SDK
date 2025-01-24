#pragma once

class AnimationLockHighLODTrack;

class AnimationLockHighLODTask : public Task<AnimationLockHighLODTrack>, public UFG::qNode<AnimationLockHighLODTask>
{
public:
	ActionContext* m_pActionContext;
};