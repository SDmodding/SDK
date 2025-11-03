#pragma once

class SSInstance : public SSObjectBase, public ARefCountMix<SSInstance>
{
public:
	SSClass* i_class_p;
	u64 i_user_data;
	u64 i_user_data2;

	/* Virtual Functions */

	virtual void _VFunc8() = 0;
	virtual ASymbol const& get_actor_name() = 0;
	virtual void pool_delete() = 0;
	virtual void as_code_append(AString* str_p, bool break_new_lines, SSInvokedBase* caller_p) = 0;
	virtual void method_invoke(const class SSMethodCall& mcall, SSObjectBase* scope_p, SSInvokedBase* caller_p, SSInstance** result_pp) = 0;
	virtual void method_call(const ASymbol& method_name, SSInstance** args_pp, u32 arg_count = 0, SSInstance** result_pp = 0, SSInvokedBase* caller_p = 0) = 0;
	virtual void on_no_references() = 0;

	/* Functions */

	void call_default_constructor() { SDK_CALL_FUNC(void, 0x1118A0, void*)(this); }

	class SSCoroutineBase* coroutine_call(const ASymbol& coroutine_name, SSInstance** args_pp, u32 arg_count = 0, bool immediate = 1, f32 update_interval = 0.f, SSInvokedBase* caller_p = 0, class SSActor* updater_p = 0) {
		return SDK_CALL_FUNC(SSCoroutineBase*, 0x1129C0, void*, const ASymbol&, SSInstance**, u32, bool, f32, SSInvokedBase*, SSActor*)(this, coroutine_name, args_pp, arg_count, immediate, update_interval, caller_p, updater_p);
	}
};

class SSInstanceUnreffed : public SSInstance
{
public:
};
