#pragma once

namespace UFG
{
	class AICharacterControllerBaseComponent : public CharacterControllerInterface
	{
	public:
		Intention m_Intention;
		bool m_IntentionUpdated;
		qStaticBitField<548> m_ActionRequestMask;
		bool m_HoldMotionIntention;
		qVector3 m_HoldMotionIntentionDirection;
		f32 m_HoldMotionIntentionSpeed;
		f32 m_HoldBlend;
		f32 m_HoldBlendDelay;

		/* Functions */

		void UpdateHoldMotionIntention(const f32 fDeltaS) { SDK_CALL_FUNC(void, 0x396CA0, void*, const f32)(this, fDeltaS); }
		bool IsPerformingAction(const char* actionNode) { return SDK_CALL_FUNC(bool, 0x36B970, void*, const char*)(this, actionNode); }
		void HoldCurrentMotionIntention() { SDK_CALL_FUNC(void, 0x364FA0, void*)(this); }

		void DoParkour(const qVector3& direction, const char* vaultingActionNode, u32 check, Intention& intention, bool cleanVault) {
			SDK_CALL_FUNC(void, 0x352DE0, void*, const qVector3&, const char*, u32, Intention&, bool)(this, direction, vaultingActionNode, check, intention, cleanVault);
		}

		void ClearIntention() { SDK_CALL_FUNC(void, 0x34F4F0, void*)(this); }
	};

	class AICharacterControllerComponent : public AICharacterControllerBaseComponent, public qNode<AICharacterControllerComponent>
	{
	public:
		enum { _TypeUID = 0x44000007 };

		int m_ControllerID;
		bool m_ControllerID_Init;
		bool m_ResetMotionIntention;
		bool m_PlayerRelativeMotionIntention;

		/* Virtual Functions */

		virtual void Update(f32 delta_sec) = 0;

		/* Static Functions */

		SDK_SINLINE AICharacterControllerComponent* PropertiesOnActivateNew(SceneObjectProperties* pSceneObj, bool required = 1) {
			return SDK_CALL_FUNC(AICharacterControllerComponent*, 0x37E850, SceneObjectProperties*, bool)(pSceneObj, required);
		}
	};
}