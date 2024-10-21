#pragma once

class ActionContext;

class ITask : public UFG::qNode<ITask>
{
public:
	ITrack* m_Track;
	f32 m_TimeBegin;
	f32 m_TimeEnd;

	virtual ~ITask() = 0;
	virtual void Begin(ActionContext*) = 0;
	virtual void Update(ActionContext*, float) = 0;
	virtual void End() = 0;
};
SDK_ASSERT_SIZEOF(ITask, 0x28);