#pragma once

class BlendNode;
class PoseNodeParent;
class NetAnimationState;

class PoseNode : public Expression::IMemberMap, public UFG::qSafePointerNode<PoseNode>, public UFG::qNode<PoseNode>
{
public:
	struct NetState
	{
		u16 mType;
		u16 mSequence;
		f32 mLocalTime;
	};

	UFG::qOffset64<PoseNodeParent*> mParent;
	int mPriority;
	UFG::qSymbolUC mName;
	int mNetPoseSequence;
	bool mBreakPoint;
	bool mDebugDraw;
	UFG::qColour mDebugPoseColour;

	/* Functions */

	BlendNode* BlendIn(PoseNode* newNode, BlendNode* blendIn, bool syncStart) { return SDK_CALL_FUNC(BlendNode*, 0x3A2E10, void*, PoseNode*, BlendNode*, bool)(this, newNode, blendIn, syncStart); }
	BlendNode* BlendIn(PoseNode* newNode, f32 blendInTime, bool syncStart) { return SDK_CALL_FUNC(BlendNode*, 0x3A2D60, void*, PoseNode*, f32, bool)(this, newNode, blendInTime, syncStart); }
	bool NetSerialize(NetAnimationState& state, Creature* creature) { return SDK_CALL_FUNC(bool, 0x3ABC40, void*, NetAnimationState&, Creature*)(this, state, creature); }
	void writeDebugDisplayToString(UFG::qStringBuilder& debugStringBuilder, int indentSpaces, const char* parentInfo) {
		SDK_CALL_FUNC(void, 0x3B9BE0, void*, UFG::qStringBuilder&, int, const char*)(this, debugStringBuilder, indentSpaces, parentInfo);
	}
};

class PoseNodeParent : public PoseNode
{
public:
	BinPtrArray<PoseNode> mChildrenSerialized;
	UFG::qList<PoseNode> mChildren;
	f32 mLocalTime;
	int mPad;

	/* Functions */

	void AddChild(PoseNode* node) { SDK_CALL_FUNC(void, 0x2AF140, void*, PoseNode*)(this, node); }
	void ChangeChildPriority(PoseNode* childMove, bool increase) { SDK_CALL_FUNC(void, 0x2AF1A0, void*, PoseNode*, bool)(this, childMove, increase); }
	PoseNodeParent* Clone() { return SDK_CALL_FUNC(PoseNodeParent*, 0x2AF5A0, void*)(this); }
	PoseNodeParent* Create() { return SDK_CALL_FUNC(PoseNodeParent*, 0x2AF5E0, )(); }
	void DeleteChild(PoseNode* child) { SDK_CALL_FUNC(void, 0x2BD3C0, void*, PoseNode*)(this, child); }
	void DeleteChildren() { SDK_CALL_FUNC(void, 0x2BD400, void*)(this); }
	PoseNode* Find(const UFG::qSymbolUC& name) { return SDK_CALL_FUNC(PoseNode*, 0x2BD4F0, void*, const UFG::qSymbolUC&)(this, name); }
	PoseNode* FindFirstAtPriority(int priority) { return SDK_CALL_FUNC(PoseNode*, 0x2BD580, void*, int)(this, priority); }
	PoseNode* GetChild(int priority) { return SDK_CALL_FUNC(PoseNode*, 0x2BD700, void*, int)(this, priority); }
	int GetChildCount() { return SDK_CALL_FUNC(int, 0x2BD730, void*)(this); }
	void HoldLastFrame() { SDK_CALL_FUNC(void, 0x3AA7B0, void*)(this); }
	bool IsFinished(f32 inTimeDelta) { return SDK_CALL_FUNC(bool, 0x3AB220, void*, f32)(this, inTimeDelta); }
	bool NetSerialize(NetAnimationState& state, Creature* creature) { return SDK_CALL_FUNC(bool, 0x3ABCE0, void*, NetAnimationState&, Creature*)(this, state, creature); }
	void Pause() { SDK_CALL_FUNC(void, 0x3AC5A0, void*)(this); }
	void PreserveMotion(bool tf) { SDK_CALL_FUNC(void, 0x2DC490, void*, bool)(this, tf); }
	void RemoveChild(PoseNode* child) { SDK_CALL_FUNC(void, 0x2DC820, void*, PoseNode*)(this, child); }
	void Replace(PoseNode* currentChild, PoseNode* newChild) { SDK_CALL_FUNC(void, 0x2DC850, void*, PoseNode*, PoseNode*)(this, currentChild, newChild); }
	void Resume() { SDK_CALL_FUNC(void, 0x3AE4B0, void*)(this); }
	void SetActiveDirection(f32 activeDirection, bool force) { SDK_CALL_FUNC(void, 0x2DCAE0, void*, f32, bool)(this, activeDirection, force); }
	void SetContext(ActionContext* context) { SDK_CALL_FUNC(void, 0x2DCB00, void*, ActionContext*)(this, context); }
	void SetLocalTime(f32 localTime) { SDK_CALL_FUNC(void, 0x2DCB60, void*, f32)(this, localTime); }
	void SetParametricPlayTime(f32 parametric) { SDK_CALL_FUNC(void, 0x2DCBF0, void*, f32)(this, parametric); }
	void SetPlayMode(AnimationPlayMode mode) { SDK_CALL_FUNC(void, 0x3AF5C0, void*, AnimationPlayMode)(this, mode); }
	void SetPlayPriority(int playPriority) { SDK_CALL_FUNC(void, 0x2DCC80, void*, int)(this, playPriority); }
	void writeDebugDisplayToString(UFG::qStringBuilder* debugStringBuilder, int indentSpaces, const char* parentInfo) { 
		SDK_CALL_FUNC(void, 0x3B9C70, void*, UFG::qStringBuilder*, int, const char*)(this, debugStringBuilder, indentSpaces, parentInfo); 
	}

	void operator=(const PoseNodeParent& __that) { SDK_CALL_FUNC(void, 0x3A0210, void*, const PoseNodeParent&)(this, __that); }
};

class PoseNodeRoot : public PoseNodeParent
{
public:
};

class AnimationNode : public PoseNode, public UFG::qSafePointerNode<AnimationNode>
{
public:
	ActionContext* mpContext;
	UFG::qList<ITask> m_RunningTasks;
	void* mJobData;
	SkeletalAnimationHandle mSkeletalAnimationHandle;
	AnimationGroupHandle mAnimationGroupHandle;
	f32 mLocalTime;
	f32 mLastPlayTime;
	f32 mPlayStartTime;
	f32 mPlayEndTime;
	f32 mPlayRate;
	int mLoops;
	f32 mDuration;
	f32 mCurrentExtractedMotionSpeed;
	f32 mPercentComplete;
	ActionNode* mDebugPlayingFromActionNode;
	qProxy<MotionPhase2> mMotionPhase;
	qEnum<AnimationPlayMode, u8> mPlayMode;
	bool mPreserveMotionOnHoldLastFrame;
	bool mPause;
	bool mPlayTracks;
	bool mFirstPlay;
	bool mPoseOnFrameBoundaries;
	bool mFinished;
};

class BlendNode : public PoseNodeParent
{
public:
	Weightset* mWeightSet;
	Weightset* mWeightSetMask;
	bool mStarted;
	bool mSyncOnStart;
	bool mPauseBlend;
	bool mKeepBlend;
	f32 mBlendRate;
	f32 mBlendParam;
	UFG::qSymbolUC mWeightSetName;
	UFG::qSymbolUC mWeightSetMaskName;
};