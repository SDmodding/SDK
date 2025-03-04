#pragma once

namespace UFG
{
	class UIHKActionHijackWidget
	{
	public:
		bool mChanged;
		bool mVisible;
		f32 mDistance;
		qVector3 mScreenPos;
		bool mCanHijack;
	};
}