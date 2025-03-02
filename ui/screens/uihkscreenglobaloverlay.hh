#pragma once

namespace UFG
{
	class UIHKScreenGlobalOverlay : public UIScreen
	{
	public:
		qProxy<UIHKTextOverlay> TextOverlay;
		qProxy<UIHK_NISOverlay> NISOverlay;
		qProxy<UIHKMessageOverlay> MessageOverlay;
		qProxy<UIHKSaveLoadOverlay> SaveLoadOverlay;
		qProxy<UIHKLoadingOverlay> LoadingOverlay;
		qProxy<UIHKPopUpNotifier> PopUpOverlay;
		qProxy<UIHKTutorialOverlay> TutorialOverlay;
		UIHKHelpBarWidget HelpBar;
		UIHKTimeOfDayWidget TimeOfDay;
		bool m_skookum_dialog_active;
		bool m_skookum_dialog_finished;
		u32 m_skookum_dialog_result;
		bool m_bIsInactive;
		int m_iPreviousRichPresenceIndex;

		/* Static Functions */

		SDK_SINLINE UIHKScreenGlobalOverlay* Instance() { return SDK_VAR_GET(UIHKScreenGlobalOverlay*, 0x2430D38); }

		/* Impl Functions */

		SDK_INLINE void FinishSkookumDialog() { m_skookum_dialog_active = 0; }
		SDK_INLINE void StartSkookumDialog() { m_skookum_dialog_active = 1; m_skookum_dialog_finished = 0; }

		/* Functions */

		void QueueInvoke(UIScreenInvoke* cmd) { SDK_CALL_FUNC(void, 0x5FECC0, UIScreenInvoke*)(cmd); }
	};
	SDK_ASSERT_SIZEOF(UIHKScreenGlobalOverlay, 0x548);
}