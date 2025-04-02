#pragma once

enum eSSExprType
{
	SSExprType__default,
	SSExprType_identifier,
	SSExprType_identifier_member,
	SSExprType_identifier_class_member,
	SSExprType_object_id,
	SSExprType_literal,
	SSExprType_literal_list,
	SSExprType_closure_method,
	SSExprType_closure_coroutine,
	SSExprType_closure_member,
	SSExprType_bind,
	SSExprType_cast,
	SSExprType_conversion,
	SSExprType_code,
	SSExprType_conditional,
	SSExprType_case,
	SSExprType_loop,
	SSExprType_loop_exit,
	SSExprType_invoke,
	SSExprType_invoke_sync,
	SSExprType_invoke_race,
	SSExprType_invoke_cascade,
	SSExprType_invoke_closure_method,
	SSExprType_invoke_closure_coroutine,
	SSExprType_instantiate,
	SSExprType_concurrent_sync,
	SSExprType_concurrent_race,
	SSExprType_concurrent_branch,
	SSExprType_divert
};

enum eSSSideEffect
{
	SSSideEffect_none,
	SSSideEffect_sub,
	SSSideEffect_present
};

class SSExpressionBase
{
public:
	virtual ~SSExpressionBase() = 0;
	virtual void _VFunc1() = 0;
	virtual SSExpressionBase* find_expr_last_no_side_effect() = 0;
	virtual eSSSideEffect get_side_effect() = 0;
	virtual SSInvokedBase* invoke(SSObjectBase* scope_p, SSInvokedBase* caller_p, SSInstance** result_pp) = 0;
	virtual void null_receiver(SSExpressionBase* receiver_p) = 0;
	virtual void track_memory(AMemoryStats* mem_stats_p) = 0;
	virtual eSSExprType get_type() = 0;
	virtual bool is_loop(const ASymbol& loop_name) = 0;
	virtual bool is_immediate(u32* durational_idx_p) = 0;
	virtual bool is_nil() = 0;
	virtual SSActor* get_updater(SSInvokedExpression* iexpr) = 0;
	virtual bool invoke_iterate(SSInvokedExpression* iexpr_p, SSInstance** result_pp) = 0;
	virtual void invoke_exit(SSInvokedExpression* iexpr_p, SSInvokedExpression* sub_exit_p) = 0;
};
