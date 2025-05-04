#pragma once

namespace UFG
{
	class DialogueAnimationComponent : public SimComponent, public qNode<DialogueAnimationComponent>
	{
	public:
		enum { _TypeUID = 0xD4000001 };

		f32 m_currentTime;
		bool m_parametricMode;
		bool m_DebugMode;
		u32 m_sampleNameHash;
		f32 m_sampleDuration;
		qSymbolUC m_animName;
		qSafePointer<PoseNode> m_splitBodyBlend;
		qSafePointer<AnimationNode> m_controller;
		f32 m_lastTime;
		ActionContext* mFacialContext;
		bool m_isDone : 1;
		bool m_isPlayer : 1;
		bool m_hasSpecificSpeechAnimation : 1;
		qStaticBitField<548> mActionRequests;

		/* Static Functions */

		SDK_SINLINE DialogueAnimationComponent* PropertiesOnActivateNew(SceneObjectProperties* pSceneObj, bool required = 1) {
			return SDK_CALL_FUNC(DialogueAnimationComponent*, 0x5A87D0, SceneObjectProperties*, bool)(pSceneObj, required);
		}

		/* Functions */

		void EndFacialAnim() { SDK_CALL_FUNC(void, 0x59B650, void*)(this); }
		void PlayFacialAnim(AnimationPlayMode mode) { SDK_CALL_FUNC(void, 0x5A5990, void*, AnimationPlayMode)(this, mode); }
		bool SetFacialActionContext() { return SDK_CALL_FUNC(bool, 0x5AAE60, void*)(this); }
		void Stop() { SDK_CALL_FUNC(void, 0x5AC870, void*)(this); }
		void Update(f32 delta_sec) { SDK_CALL_FUNC(void, 0x5AF130, void*, f32)(this, delta_sec); }
		bool UpdateAnim(f32 delta_sec) { return SDK_CALL_FUNC(bool, 0x5AFEA0, void*, f32)(this, delta_sec); }
	};
}