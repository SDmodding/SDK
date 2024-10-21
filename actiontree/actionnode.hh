#pragma once

class ConditionCallback;

class ActionNode : public Expression::IMemberMap
{
public:
	UFG::qOffset64<ActionNode*> mParent;
	ConditionCallback* mFirstCallback;
	unsigned int mMostUsedIndex;
	unsigned int mUniqueID;
	ActionID mID;
	char mBreakPoint;
	char mDisable;
	char mPad0;
	char mPad1;
	char mPad2;
};
SDK_ASSERT_SIZEOF(ActionNode, 0x38);

class ActionNodeImplementation : public ActionNode
{
public:
	UFG::qOffset64<ConditionGroup*> mConditions;
	UFG::qOffset64<TrackGroup*> mTracks;
	BinPtrArray<ActionNode> mChildren;
};
SDK_ASSERT_SIZEOF(ActionNodeImplementation, 0x58);

class ActionNodePlayable : public ActionNodeImplementation
{
public:
};

