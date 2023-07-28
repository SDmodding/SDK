#pragma once

namespace UFG
{
	class CAnimationGroup
	{
	public:
		UFG_PAD(0x68);

		void* mStreamHandle;
		qOffset64<const char> mName;
		/*BinPtrArray<SkeletalAnimation, 0, 0> mAnimations;
		BinString mCategory;
		BinString mMode;
		UFG::qList<AnimationGroupHandle, AnimationGroupList, 0, 0> mAnimGroupHandles;
		unsigned int mMemorySize;
		UFG::qSymbolUC mNameSymbol;
		UFG::qSymbolUC mFallbackAnimSymbol;
		unsigned int mRefCount;
		unsigned int mAnimRefCount;
		unsigned int mRefCountTotal;
		unsigned int mAnimRefCountTotal;
		unsigned __int16 mCurrentAnimationSubPriority;
		qEnum<enum UFG::eAnimationPriorityEnum, signed char> mCurrentAnimationPriority;
		qEnum<enum UFG::eAnimationPriorityEnum, signed char> mDefaultAnimationPriority;
		qEnum<enum UFG::eAnimationPriorityEnum, signed char> mHighestBudgetedPriority;
		char mDefaultCompression;
		char mDefaultBlendMode;
		char mDoFrameReduction;
		char mSourceABKFromSingleHKX;*/

		const char* GetName()
		{
			return reinterpret_cast<const char*(__fastcall*)(void*)>(UFG_RVA(0x297280))(this);
		}
	};


	class CAnimationDataBase
	{
	public:
		UFG_PAD(0x10);

		UFG::qTreeRB mAnimGroups;
		UFG::qTreeRB mAnimations;

		/*AnimationGroupHandleContainer mDefaultReferenceContainers[17];
		UFG::qList<AnimationGroup, AnimationGroupBudgetedList, 0, 0> mBudgetedAnimationGroups;
		UFG::qList<AnimationGroup, AnimationGroupUpdateList, 0, 0> mQueuedUpdateGroups;
		UFG::qFixedArray<AnimationDataBase::PriorityBudget, 17> mPriorityBudgets;
		UFG::qString mGlobalFallbackAnimation;
		bool mUseFallbackAnimations;
		UFG::StreamPrioritySystem* m_pStreamPrioritySystem;*/
	};

	namespace AnimationBase
	{
		CAnimationDataBase* Get()
		{
			return *reinterpret_cast<CAnimationDataBase**>(UFG_RVA(0x23CE050));
		}
	}
}