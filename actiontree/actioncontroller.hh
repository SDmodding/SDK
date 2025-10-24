#pragma once

class IFinishUpdate;

class ActionController : public qProxy<Expression::IMemberMap>
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

	/* Functions */

	Expression::IMemberMap* GetChild2(int priority) { return SDK_CALL_FUNC(Expression::IMemberMap*, 0x26E100, void*, int)(this, priority); }
	bool IsPlaying(const ActionID& node_id, u32 mostUsedIndex = -1, const bool recurseOnSpawns = false) { 
		return SDK_CALL_FUNC(bool, 0x26F170, void*, const ActionID&, u32, const bool)(this, node_id, mostUsedIndex, recurseOnSpawns); 
	}
	bool IsPlaying(ActionNode* node) { return SDK_CALL_FUNC(bool, 0x26F310, void*, ActionNode*)(this, node); }
	ITrack* IsPlaying(ITrack* track) { return SDK_CALL_FUNC(ITrack*, 0x26F130, void*, ITrack*)(this, track); }
	bool IsPlayingFullPath(ActionNode* testNode, const bool recurseOnSpawns) { return SDK_CALL_FUNC(bool, 0x26F400, void*, ActionNode*, const bool)(this, testNode, recurseOnSpawns); }
	bool IsPlayingFullPath(const ActionPath& animPath, bool recurseOnSpawns) { return SDK_CALL_FUNC(bool, 0x26F350, void*, const ActionPath&, bool)(this, animPath, recurseOnSpawns); }
	void Play(ActionNode* node, bool forcePlay) { SDK_CALL_FUNC(void, 0x270140, void*, ActionNode*, bool)(this, node, forcePlay); }
	void Play(ActionNodePlayable* node) { SDK_CALL_FUNC(void, 0x270360, void*, ActionNodePlayable*)(this, node); }
	void Play() { SDK_CALL_FUNC(void, 0x270730, void*)(this); }
	void PlayTracks(ActionNode* node, bool offsetTimeBeginAndEnd, f32 offsetTime) { SDK_CALL_FUNC(void, 0x270740, void*, ActionNode*, bool, f32)(this, node, offsetTimeBeginAndEnd, offsetTime); }
	void PlayTracks(ActionNodePlayable* node, bool offsetTimeBeginAndEnd, f32 offsetTime) {
		SDK_CALL_FUNC(void, 0x2707F0, void*, ActionNodePlayable*, bool, f32)(this, node, offsetTimeBeginAndEnd, offsetTime);
	}
	void PlayTracks(ITrack* track, bool offsetTimeBeginAndEnd, f32 offsetTime) { SDK_CALL_FUNC(void, 0x2709B0, void*, ITrack*, bool, f32)(this, track, offsetTimeBeginAndEnd, offsetTime); }
	void PlayTracks(TrackGroup* group, bool offsetTimeBeginAndEnd, f32 offsetTime) { SDK_CALL_FUNC(void, 0x270B10, void*, TrackGroup*, bool, f32)(this, group, offsetTimeBeginAndEnd, offsetTime); }
	void Sequence(ActionNodePlayable* node, int priority, bool override) { SDK_CALL_FUNC(void, 0x272290, void*, ActionNodePlayable*, int, bool)(this, node, priority, override); }
	void Stop() { SDK_CALL_FUNC(void, 0x272A80, void*)(this); }
	void Update(f32 timeDelta) { SDK_CALL_FUNC(void, 0x272E40, void*, f32)(this, timeDelta); }
	bool WasPlaying(const ActionID& animID, bool recurseOnSpawns) { return SDK_CALL_FUNC(bool, 0x273AB0, void*, const ActionID&, bool)(this, animID, recurseOnSpawns); }
	char WasPlayingFullPath(ActionNode* testNode) { return SDK_CALL_FUNC(char, 0x273B90, void*, ActionNode*)(this, testNode); }
};
SDK_ASSERT_SIZEOF(ActionController, 0x118);