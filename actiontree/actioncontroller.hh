#pragma once

class IFinishUpdate;

class ActionController : public Expression::IMemberMap
{
public:
	ActionNodePlayable* m_currentNode;
	ActionContext* m_Context;
	f32 m_ActionNodePlayTime;
	char mUpdating;
	char mKeepAlive;
	char mOverRideNode;
	char m_BankTracksEnabled;
	char m_OnEnterExitCallbacksEnabled;
	ActionNodePlayable* m_previousNode;
	ActionNodePlayable* m_SequenceNode;
	UFG::qList<ITask> m_RunningTasks;
	u64 m_RunningSpawnTasksTmp[2];
	UFG::qList<ITask> m_SequencedTasks;
	f32 mRunningMasterRate;
	UFG::qList<IFinishUpdate> m_FinishUpdateTasks;
	u64 m_PlayingMostUsedMask;
	u32 m_NumPlayingNodes;
	ActionID m_PlayingNodeUID[32];
	int m_SequencePriority;
};
SDK_ASSERT_SIZEOF(ActionController, 0x118);