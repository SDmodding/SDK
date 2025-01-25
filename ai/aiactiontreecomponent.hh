#pragma once

namespace UFG
{
	class AIActionTreeComponent : public StateComponentI<SimComponent>, public ActionTreeComponentBase, public qNode<AIActionTreeComponent>
	{
	public:
		enum { _TypeUID = 0x52000001 };

		bool m_DebugDisplay;
		bool mDebugRemote;
		qSharedString m_ActionTreeFileName;
		u32 m_ActionTreeFileNameStrippedHash;
		ActionContext* m_pActionContext;
		ActionController m_ActionController;
		u32 m_LastSimFrameUpdated;
		Ticket m_Ticket;
		eTicketBoothEnum m_TicketType;
		Intention m_LastFrameIntentions;
		eAIEmotion m_LastFrameEmotion;
		bool m_LastFrameHasDestination;
		bool m_PreserveLastFrameInformation;
		RebindingComponentHandle<AICharacterControllerBaseComponent> m_pAICharacterControllerBaseComponent;
		RebindingComponentHandle<NavComponent> m_pNavComponent;
		RebindingComponentHandle<ActiveAIEntityComponent> m_pActiveAIEntityComponent;
		RebindingComponentHandle<FaceActionComponent> m_pFaceActionComponent;
		RebindingComponentHandle<InterestPointUserComponent> m_pInterestPointUserComponent;

		/* Functions */

		void EnsureTicketBoothCriticalPriority() { SDK_CALL_FUNC(void, 0x355910, void*)(this); }
		void InactiveTicketUpdate() { SDK_CALL_FUNC(void, 0x365100, void*)(this); }
		void Init() { SDK_CALL_FUNC(void, 0x3651B0, void*)(this); }
		void InitActionTree() { SDK_CALL_FUNC(void, 0x366A20, void*)(this); }
		void ReleaseActionTree() { SDK_CALL_FUNC(void, 0x380B80, void*)(this); }
		void ResetDefaultTree() { SDK_CALL_FUNC(void, 0x382F90, void*)(this); }
		void SetActionTreeFileName(const char* filename) { SDK_CALL_FUNC(void, 0x384DD0, void*, const char*)(this, filename); }
	};
	SDK_ASSERT_SIZEOF(AIActionTreeComponent, 0x678);
}