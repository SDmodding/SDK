#pragma once

class ConditionCallback;

class ActionNode : public Expression::IMemberMap
{
public:
	UFG::qOffset64<ActionNode*> mParent;
	ConditionCallback* mFirstCallback;
	u32 mMostUsedIndex;
	u32 mUniqueID;
	ActionID mID;
	bool mBreakPoint;
	bool mDisable;
	u8 mPad0;
	u8 mPad1;
	u8 mPad2;

	/* Static Functions */

	SDK_SINLINE ActionNode* Find(ActionPath* absolutePath, ActionNode* absoluteRoot = 0) { return SDK_CALL_FUNC(ActionNode*, 0x26DBE0, ActionPath*, ActionNode*)(absolutePath, absoluteRoot); }
	SDK_SINLINE ActionNode* FindWithOldPath(const char* resourcePath) { return SDK_CALL_FUNC(ActionNode*, 0x26DE60, void*, const char*)(0, resourcePath); }
};
SDK_ASSERT_SIZEOF(ActionNode, 0x38);

class ActionNode_Iterator
{
public:
	ActionNode* mSearchStack[32];
	int mCurrentItem;

	SDK_INLINE ActionNode_Iterator() : mCurrentItem(-1) {}
	SDK_INLINE ActionNode_Iterator(ActionNode* startingRoot) { First(startingRoot); }

	SDK_INLINE bool IsDone() { return (0 > mCurrentItem); }

	SDK_INLINE void First(ActionNode* startingRoot) 
	{
		mCurrentItem = 0;
		mSearchStack[0] = startingRoot;
	}

	SDK_INLINE ActionNode* CurrentItem() { return (mCurrentItem >= 0 ? mSearchStack[mCurrentItem] : 0); }

	void Next() { SDK_CALL_FUNC(void, 0x26FE70, void*)(this); }
};

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
	/* Static Functions */

	SDK_SINLINE ActionNodePlayable* Create() { return SDK_CALL_FUNC(ActionNodePlayable*, 0x26C6C0)(); }
};

