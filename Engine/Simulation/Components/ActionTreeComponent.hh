#pragma once

namespace UFG
{
	class CActionTreeComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x68);

		bool mNisUpdated;
		const char* mActionTreeFileName;
		CActionContext* mpActionContext;
		CActionController mActionController;
		RebindingComponentHandle<class CActiveAIEntityComponent> mActiveAIEntityComponent;
		qList<class PostAnimUpdateTask> mPostAnimUpdateList;
		CIntention m_Intention;

		UFG_INLINE void InitActionTree()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x582D80))(this);
		}

		UFG_INLINE void Reset()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x58B060))(this);
		}
	};
	UFG_ASSERT_CLASS(CActionTreeComponent, 0x560);
}