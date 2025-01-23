#pragma once

class AnimationGroup;
class SkeletalAnimation;

namespace UFG
{
	enum eAnimationPriorityEnum
	{
		eANIM_PRIORITY_INACTIVE_NIS,
		eANIM_PRIORITY_INACTIVE,
		eANIM_PRIORITY_INACTIVE_POI,
		eANIM_PRIORITY_INSTANCED_POI,
		eANIM_PRIORITY_PREDICTIVE_POI,
		eANIM_PRIORITY_ACTIVE_POI,
		eANIM_PRIORITY_SOCIAL_FLAVOUR,
		eANIM_PRIORITY_CHARACTER_FLAVOUR,
		eANIM_PRIORITY_NIS_PRELOAD,
		eANIM_PRIORITY_POI_CRITICAL,
		eANIM_PRIORITY_CHARACTER,
		eANIM_PRIORITY_ANIMATION_PLAYING,
		eANIM_PRIORITY_REQUIRED,
		eANIM_PRIORITY_SOCIAL,
		eANIM_PRIORITY_CORE,
		eANIM_PRIORITY_PLAYER,
		eANIM_PRIORITY_ACTIVE_NIS,
		NUM_ANIMATION_PRIORITIES
	};
}

enum AnimationPlayMode
{
	APM_NORMAL,
	APM_CYCLIC,
	APM_HOLDLASTFRAME,
	APM_PARAMETRIC,
	APM_ABSOLUTE,
	APM_PARAMETRIC_RATE,
	APM_PARAMETRIC_RATE_CYCLIC,
	APM_PARAMETRIC_RATE_ACTIVE,
	APM_COUNT
};

class AnimationGroupHandle : public UFG::qNode<AnimationGroupHandle>, public UFG::qNode<AnimationGroupHandle, class AnimationGroupHandleContainer>
{
public:
	struct ReferenceInfo
	{
		UFG::SimObject* m_pSimObject;
		UFG::qSharedString m_ReferenceText;
	};

	UFG::qSymbolUC m_AnimationGroupSymbol;
	UFG::qSafePointer<AnimationGroup> m_AnimationGroup;
	qEnum<UFG::eAnimationPriorityEnum, u16> m_eAnimationPriority;
	u16 m_AnimationSubPriority;
	i8 m_bHasBeenBound;
	ReferenceInfo* m_pReferenceInfo;
};

class AnimationGroupHandleContainer
{
public:
	UFG::qList<AnimationGroupHandle> m_AnimationGroupHandleList;
	bool m_bHasBeenBound;
};

class AnimationGroup : public Expression::IMemberMap, public UFG::qSafePointerNode<AnimationGroup>, public UFG::qNodeRB<AnimationGroup>, public UFG::qNode<AnimationGroup>, public UFG::qNode<AnimationGroup, class AnimationGroupUpdateList>
{
public:
	UFG::StreamPriorityHandle* mStreamHandle;
	BinString mName;
	BinPtrArray<SkeletalAnimation> mAnimations;
	BinString mCategory;
	BinString mMode;
	UFG::qList<AnimationGroupHandle> mAnimGroupHandles;
	u32 mMemorySize;
	UFG::qSymbolUC mNameSymbol;
	UFG::qSymbolUC mFallbackAnimSymbol;
	u32 mRefCount;
	u32 mAnimRefCount;
	u32 mRefCountTotal;
	u32 mAnimRefCountTotal;
	u16 mCurrentAnimationSubPriority;
	qEnum<UFG::eAnimationPriorityEnum, i8> mCurrentAnimationPriority;
	qEnum<UFG::eAnimationPriorityEnum, i8> mDefaultAnimationPriority;
	qEnum<UFG::eAnimationPriorityEnum, i8> mHighestBudgetedPriority;
	i8 mDefaultCompression;
	i8 mDefaultBlendMode;
	i8 mDoFrameReduction;
	i8 mSourceABKFromSingleHKX;

	/* Functions */

	bool IsStreamedIn() { return SDK_CALL_FUNC(bool, 0x3AB330, void*)(this); }
	void LoadInternal() { SDK_CALL_FUNC(void, 0x3AB490, void*)(this); }
	void UnloadInternal() { SDK_CALL_FUNC(void, 0x3B04E0, void*)(this); }
	void UpdatePriorityFromHandles() { SDK_CALL_FUNC(void, 0x3B49F0, void*)(this); }
};
