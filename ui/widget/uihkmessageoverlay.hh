#pragma once

namespace UFG
{
	class UIHKMessageOverlay : public OnlineManagerObserver
	{
	public:
		bool m_bDisconnectedDialogUp;

		/* Virtual Functions */

		virtual bool handleMessage(UIScreen* screen, u32 msgId, UIMessage* msg) = 0;
	};
	SDK_ASSERT_SIZEOF(UIHKMessageOverlay, 0x20);
}