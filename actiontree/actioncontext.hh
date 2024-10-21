#pragma once

class ActionController;

class ActionContext
{
public:
	UFG::qSafePointer<UFG::SimObject> mSimObject;
	ActionNode* m_OpeningBranch;
	ActionController* mActionController;
	ActionContext* mParentContext;
	bool mDebugBreak;
	u64 mSignals;
	qEnum<UFG::eActionTreeType, u16> m_ActionTreeType;
	UFG::ActionTreeComponentBase* mActionTreeComponentBase[4];
	char mMostUsedPlayCount[64];
	char mProbabilitiesValid;
	f32 mProbabilitys[10];
};
SDK_ASSERT_SIZEOF(ActionContext, 0xD8);