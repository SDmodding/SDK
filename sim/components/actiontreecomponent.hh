#pragma once

class PostAnimUpdateTask;

namespace UFG
{

	class ActionTreeComponent : public SimComponent, public ActionTreeComponentBase, public qNode<ActionTreeComponent>
	{
	public:
		enum { _TypeUID = 0xC8000001 };

		bool mNisUpdated;
		const char* mActionTreeFileName;
		ActionContext* mpActionContext;
		ActionController mActionController;
		RebindingComponentHandle<ActiveAIEntityComponent> mActiveAIEntityComponent;
		qList<PostAnimUpdateTask> mPostAnimUpdateList;
		Intention m_Intention;

		/* Functions */

		void Reset() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x58B060))(this); }

		void PostAnimUpdate(f32 delta_sec) { reinterpret_cast<void(SDK_CALL*)(void*, f32)>(SDK_RVA(0x588770))(this, delta_sec); }

		void InitActionTree() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x582D80))(this); }

		void BeginFrame() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x57F450))(this); }
	};
	SDK_ASSERT_SIZEOF(ActionTreeComponent, 0x560);
}