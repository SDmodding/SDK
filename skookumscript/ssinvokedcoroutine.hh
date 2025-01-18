#pragma once

class SSInvokedCoroutine : public SSInvokedContextBase
{
public:
	enum eFlag
	{
		Flag_none,
		Flag_tracked_updating,
		Flag_tracked_pending,
		Flag_tracked_mask,
		Flag_suspended,
		Flag__default = 0
	};

	u32 i_update_count;
	f32 i_update_interval;
	long double i_update_next;
	SSCoroutineBase* i_coroutine_p;
	SSCoroutineCall* i_coroutine_call_p;
	AIdPtr<SSActor> i_updater_p;
	u32 i_flags;
};
