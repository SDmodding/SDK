#pragma once

namespace UFG
{
	class UIHK_NISElement
	{
	public:
		enum eState
		{
			STATE_CURTAIN_HIDDEN,
			STATE_CURTAIN_FADINGTOBLACK,
			STATE_CURTAIN_SHOWING,
			STATE_CURTAIN_FADINGFROMBLACK
		};

		eState m_state;
		bool m_mutingAudio;
	};

	class UIHK_NISOverlay
	{
	public:
		UIHK_NISFrameCounterWidget FrameCounter;
		bool mActive;
		bool mSkipButtonPromptShowing;
		bool mShouldHideSkipButtonPrompt;
		f32 mSkipButtonTimer;

		/* Static Members */

		SDK_VINLINE qGlobalVar<UIHK_NISElement*, 0x2431F00> m_curtains;
		SDK_VINLINE qGlobalVar<void(__fastcall*)(), 0x2430F98> sCurtainsShownCallback;
		SDK_VINLINE qGlobalVar<void(__fastcall*)(), 0x2430FA0> sCurtainsHiddenCallback;

		/* Virtual Functions */

		virtual ~UIHK_NISOverlay() = 0;
		virtual void update(UIScreen* screen, f32 elapsed) = 0;
		virtual bool handleMessage(UIScreen* screen, u32 msgId, UIMessage* msg) = 0;

		/* Static Functions */

		SDK_SINLINE void FadeToLight() { SDK_CALL_FUNC(void, 0x5D8130)(); }
		SDK_SINLINE void FirePostNISAudioEventQueue() { SDK_CALL_FUNC(void, 0x5D8A50)(); }
		SDK_SINLINE void HideCurtains(f32 fadeOutTime, bool bUseNonLinearFade) { SDK_CALL_FUNC(void, 0x5ECCA0, f32, bool)(fadeOutTime, bUseNonLinearFade); }
		SDK_SINLINE void HideLetterBox() { SDK_CALL_FUNC(void, 0x5ED0B0)(); }
		SDK_SINLINE bool IsCurtainHidden() { return m_curtains->m_state == UIHK_NISElement::STATE_CURTAIN_HIDDEN; }
		SDK_SINLINE bool IsCurtainStable() { return m_curtains->m_state == UIHK_NISElement::STATE_CURTAIN_SHOWING || m_curtains->m_state == UIHK_NISElement::STATE_CURTAIN_FADINGFROMBLACK; }
		SDK_SINLINE bool IsCurtainVisible() { return m_curtains->m_state == UIHK_NISElement::STATE_CURTAIN_SHOWING; }

		SDK_SINLINE void SetCurtainStateCallbacks(void(__fastcall* showCallback)(), void(__fastcall* hideCallback)()) { 
			sCurtainsShownCallback = showCallback; sCurtainsHiddenCallback = hideCallback;
		}

		SDK_SINLINE void SetPostNISHideCurtainsAudioEvent(u32 event, bool waitForNextCurtain) { SDK_CALL_FUNC(void, 0x606F10, u32, bool)(event, waitForNextCurtain); }
		SDK_SINLINE void ShowCurtains(f32 fadeInTime, bool bMuteAudio) { SDK_CALL_FUNC(void, 0x60D3C0, f32, bool)(fadeInTime, bMuteAudio); }
		SDK_SINLINE void ShowLetterBox() { SDK_CALL_FUNC(void, 0x610B70)(); }
		SDK_SINLINE void StopAllSubtitles() { SDK_CALL_FUNC(void, 0x6124D0)(); }
		SDK_SINLINE void UpdateAudioMuteState() { SDK_CALL_FUNC(void, 0x61A060)(); }

		/* Functions */

		void Flash_ForceHide(UIScreen* screen, bool hide) { SDK_CALL_FUNC(void, 0x5DAA00, void*, UIScreen*, bool)(this, screen, hide); }
		void Flash_SetSkipButtonPromptVisible(UIScreen* screen, bool visible) { SDK_CALL_FUNC(void, 0x5E0C40, void*, UIScreen*, bool)(this, screen, visible); }
		f32 GetCurtainAlpha(UIScreen* screen) { return SDK_CALL_FUNC(f32, 0x5E72C0, UIScreen*)(screen); }

		void HideElement(UIScreen* screen, UIHK_NISElement* element, f32 fadeOutTime, bool bUseNonLinearFade) {
			SDK_CALL_FUNC(void, 0x5ECCE0, void*, UIScreen*, UIHK_NISElement*, f32, bool)(this, screen, element, fadeOutTime, bUseNonLinearFade);
		}

		void SetActive(bool active) { SDK_CALL_FUNC(void, 0x6050E0, void*, bool)(this, active); }

		void ShowElement(UIScreen* screen, UIHK_NISElement* element, f32 fadeInTime, bool muteAudio) {
			SDK_CALL_FUNC(void, 0x60D410, void*, UIScreen*, UIHK_NISElement*, f32, bool)(this, screen, element, fadeInTime, muteAudio);
		}
	};
	SDK_ASSERT_SIZEOF(UIHK_NISOverlay, 0x40);
}