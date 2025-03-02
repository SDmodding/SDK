#pragma once

namespace UFG
{
	class UIHKSaveLoadOverlay
	{
	public:
		f32 m_fTimeToHideOverlay;
		bool m_bOverlayVisible;
		bool m_bRecievedStopSaveMsg;

		/* Virtual Functions */

		virtual ~UIHKSaveLoadOverlay() = 0;
		virtual bool handleMessage(UIScreen* screen, u32 msgId, UIMessage* msg) = 0;
		virtual void update(UIScreen* screen, f32 elapsed) = 0;
	};
}