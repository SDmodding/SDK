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

		void Reset()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x58B060))(this);
		}
	};
	UFG_ASSERT_CLASS(CActionTreeComponent, 0x560);
}