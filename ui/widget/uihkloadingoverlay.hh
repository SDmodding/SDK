#pragma once

namespace UFG
{
	class UIHKLoadingOverlay
	{
	public:
		/* Virtual Functions */

		virtual ~UIHKLoadingOverlay() = 0;
		virtual bool handleMessage(UIScreen* screen, u32 msgId, UIMessage* msg) = 0;
		virtual void update(UIScreen* screen, f32 elapsed) = 0;
	};
}