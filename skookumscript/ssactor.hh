#pragma once

class SSActor : public SSDataInstance, public ANamed
{
public:
	u32 i_actor_flags;
	APArray<class SSInvokedCoroutine> i_icoroutines_to_update;
	APArray<class SSInvokedCoroutine> i_icoroutines_pending;
};
