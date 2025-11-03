#pragma once

class SSActor : public SSDataInstance, public ANamed
{
public:
	u32 i_actor_flags;
	APArray<class SSInvokedCoroutine> i_icoroutines_to_update;
	APArray<class SSInvokedCoroutine> i_icoroutines_pending;

	~SSActor() { SDK_CALL_FUNC(void, 0x106AB0, void*)(this); }

	SSActor(const ASymbol& name, class SSActorClass* class_p, bool add_to_instance_list) {
		SDK_CALL_FUNC(void, 0x104140, void*, const ASymbol&, SSActorClass*, bool)(this, name, class_p, add_to_instance_list);
	}

	/* Functions */

	void clear_coroutines() { SDK_CALL_FUNC(void, 0x111F20, void*)(this); }
	void enable_behavior(bool activate) { SDK_CALL_FUNC(void, 0x113E60, void*, bool)(this, activate); }
	void enable_on_update(bool activate) { SDK_CALL_FUNC(void, 0x113FB0, void*, bool)(this, activate); }
};
