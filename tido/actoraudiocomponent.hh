#pragma once

namespace UFG
{
	class AmbientContextNode
	{
	public:
		qWiseSymbol m_context;
		u16 m_lastIdx;
		u16 m_age;
	};

	class AmbientContextManager
	{
	public:
		qArray<AmbientContextNode> m_nodes;
	};

	class ActorAudioComponent : public HkAudioEntityComponent, public qNode<ActorAudioComponent>
	{
	public:
		enum { _TypeUID = 0xD2000003 };

		AudioDialogEventController m_controller;
		AudioEntity* m_SFXEntity;
		VoiceProfile* m_voiceProfile;
		u32 m_curPlayingPriority;
		f32 m_interiorCheckTimer;
		f32 m_distance2ToListener;
		u32 m_activeAmbientConversationId;
		u32 m_subtitleId;
		int m_isSpeakingCnt;
		OneShotHandle m_leftFootstep;
		OneShotHandle m_rightFootstep;
		AmbientContextManager m_ambientContexts;
		qSafePointer<HealthComponent> m_healthComponent;
		qSafePointer<TransformNodeComponent> m_transformNodeComponent;
		qSafePointer<SimObjectCharacterPropertiesComponent> m_simObjectCharacterPropertiesComponent;
		bool m_isSpeakingInConversation : 1;
		bool m_isListeningInAConversation : 1;
		bool m_isNearby : 1;
		bool m_enableTaggedDialogue : 1;
		bool m_enableInCarReactions : 1;
		bool m_charcterIsAmbient : 1;
		bool m_forceInitialize : 1;
		bool m_forceDisable : 1;
		bool m_failedSpeechCondition : 1;
		bool m_debugActor : 1;
		bool m_inCar : 1;
		bool m_isPlayer : 1;
		bool m_inConversationButTooFarToPlay : 1;
		bool m_inConversationWithActionRequests : 1;
		bool m_isMale : 1;
		bool m_highHeel : 1;
		bool m_isPossessed : 1;

		/* Static Functions */

		SDK_SINLINE u32 LookupAndShowSubtitleFromPropertySet(u32 uid) { return SDK_CALL_FUNC(u32, 0x5A3040, u32)(uid); }

		/* Impl Functions */

		SDK_INLINE qWiseSymbol GetVoiceId() { return (m_voiceProfile ? m_voiceProfile->m_wwiseVoiceUid : -1); }

		/* Functions */

		void AddGenderArgument(SimObject* simObject, DialogArgList* args) { SDK_CALL_FUNC(void, 0x596220, void*, SimObject*, DialogArgList*)(this, simObject, args); }
		void AddListenerArgument(SimObject* simObject, DialogArgList* args) { SDK_CALL_FUNC(void, 0x5964D0, void*, SimObject*, DialogArgList*)(this, simObject, args); }
		bool CanApplyEnvironment(const qWiseSymbol& envType) { return SDK_CALL_FUNC(bool, 0x597570, void*, const qWiseSymbol&)(this, envType); }
		void CheckInitialize() { SDK_CALL_FUNC(void, 0x597C50, void*)(this); }
		void ClearDataMembers() { SDK_CALL_FUNC(void, 0x598A20, void*)(this); }
		f32 Distance2ToActor(ActorAudioComponent* target) { return SDK_CALL_FUNC(f32, 0x59B0E0, void*, ActorAudioComponent*)(this, target); }
		u32 GetFootwearType() { return SDK_CALL_FUNC(u32, 0x59CE60, void*)(this); }

		qWiseSymbol GetVoiceProfile(SimObject* target)
		{
			qProxy<qWiseSymbol> res;
			SDK_CALL_FUNC(void, 0x59DAD0, void*, qWiseSymbol*, SimObject*)(this, &res, target);
			return res;
		}

		bool IsAlive(bool instant) { return SDK_CALL_FUNC(bool, 0x5A03C0, void*, bool)(this, instant); }
		bool IsInWater(f32 depth) { return SDK_CALL_FUNC(bool, 0x5A0530, void*, f32)(this, depth); }
		void PlayFightImpact(u32 attack, u32 target, u32 intensity) { SDK_CALL_FUNC(void, 0x5A5DE0, void*, u32, u32, u32)(this, attack, target, intensity); }
		void PlayFightRumble(u32 attack, u32 target, u32 intensity) { SDK_CALL_FUNC(void, 0x5A6040, void*, u32, u32, u32)(this, attack, target, intensity); }
		void PlayFootstep(u32 stepID, const OneShotHandle& oneShot) { SDK_CALL_FUNC(void, 0x5A6120, void*, u32, const OneShotHandle&)(this, stepID, oneShot); }
		void PlayFootstepLeft(u32 stepId) { SDK_CALL_FUNC(void, 0x5A6310, void*, u32)(this, stepId); }
		void PlayFootstepRight(u32 stepId) { SDK_CALL_FUNC(void, 0x5A63B0, void*, u32)(this, stepId); }
		bool PlayPanic() { return SDK_CALL_FUNC(bool, 0x5A6AC0, void*)(this); }
		bool PlayScreamPain() { return SDK_CALL_FUNC(bool, 0x5A7360, void*)(this); }

		bool PlaySpeech(DialogArgList& args, AudioEventCallbackObject* audioCallbacks, u32 priority, bool subtitle) {
			return SDK_CALL_FUNC(bool, 0x5A7880, void*, DialogArgList&, AudioEventCallbackObject*, u32, bool)(this, args, audioCallbacks, priority, subtitle);
		}

		bool PlaySpeechExternal(u32 eventId, u32 priority, AudioEventCallbackObject* audioCallbacks, AudioEventExternalSourceInfo* info, bool subtitle) {
			return SDK_CALL_FUNC(bool, 0x5A7AE0, void*, u32, u32, AudioEventCallbackObject*, AudioEventExternalSourceInfo*, bool)(this, eventId, priority, audioCallbacks, info, subtitle);
		}

		bool QueueSpeech(DialogArgList& args, AudioEventCallbackObject* audioCallbacks, u32 priority, bool force, bool subtitle) {
			return SDK_CALL_FUNC(bool, 0x5A88A0, void*, DialogArgList&, AudioEventCallbackObject*, u32, bool, bool)(this, args, audioCallbacks, priority, force, subtitle);
		}

		bool QueueSpeechExternalAmbient(u32 eventId, const char* context, AudioEventCallbackObject* audioCallbacks, u32 priority, bool force, bool subtitle) {
			return SDK_CALL_FUNC(bool, 0x5A8930, void*, u32, const char*, AudioEventCallbackObject*, u32, bool, bool)(this, eventId, context, audioCallbacks, priority, force, subtitle);
		}

		bool QueueSpeechExternalMission(u32 eventID, const char* context, AudioEventCallbackObject* audioCallbacks, u32 priority, bool subtitle) {
			return SDK_CALL_FUNC(bool, 0x5A8F60, void*, u32, const char*, AudioEventCallbackObject*, u32, bool)(this, eventID, context, audioCallbacks, priority, subtitle);
		}

		bool QueueSpeechExternalMission(u32 eventID, u32 fileId, AudioEventCallbackObject* audioCallbacks, u32 priority, bool subtitle) {
			return SDK_CALL_FUNC(bool, 0x5A8E20, void*, u32, u32, AudioEventCallbackObject*, u32, bool)(this, eventID, fileId, audioCallbacks, priority, subtitle);
		}

		void Reset() { SDK_CALL_FUNC(void, 0x5AA3F0, void*)(this); }
		void SetupTaggedDialog(DialogArgList* args) { SDK_CALL_FUNC(void, 0x5AC470, void*, DialogArgList*)(this, args); }
		void StopCurrentlyPlaying(bool force) { SDK_CALL_FUNC(void, 0x5AC9F0, void*, bool)(this, force); }
		const char* TrySetupBeaconDialog(const char* ctx) { return SDK_CALL_FUNC(const char*, 0x5AD060, void*, const char*)(this, ctx); }
		void TrySetupPanicDialog(DialogArgList* args) { SDK_CALL_FUNC(void, 0x5AD430, void*, DialogArgList*)(this, args); }

		void TrySetupPoliceDialog(u32 eventId, u32 contextHash, const char** outContext, const char** outVoice) {
			SDK_CALL_FUNC(void, 0x5AD4C0, void*, u32, u32, const char**, const char**)(this, eventId, contextHash, outContext, outVoice);
		}

		void TrySetupPurchaseDialog(DialogArgList* args) { SDK_CALL_FUNC(void, 0x5ADAB0, void*, DialogArgList*)(this, args); }
		const char* TrySetupSafehouseItemDialog(const char* context) { return SDK_CALL_FUNC(const char*, 0x5ADC70, void*, const char*)(this, context); }
		void TrySetupSocialDialog(DialogArgList* args) { SDK_CALL_FUNC(void, 0x5AE4A0, void*, DialogArgList*)(this, args); }
		void UpdateAmbienceCounts() { SDK_CALL_FUNC(void, 0x5AFAA0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(ActorAudioComponent, 0x230);
}