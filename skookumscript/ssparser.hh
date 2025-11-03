#pragma once

enum eSSMember
{
	SSMember_method,
	SSMember_method_func,
	SSMember_method_mthd,
	SSMember_coroutine,
	SSMember_coroutine_func,
	SSMember_coroutine_mthd,
	SSMember__disassembly,
	SSMember_data,
	SSMember_strategy,
	SSMember_class_meta,
	SSMember_object_ids,
	SSMember_object_ids_defer,
	SSMember__length,
	SSMember__invalid,
	SSMember__error
};

struct AFlagSet32
{
	u32 i_flagset;
};

class SSParser : public AString
{
public:
	enum eResult
	{
		Result_ok,
		Result_ok_deferred,
		Result__implicit_this,
		Result_warn__start,
		Result_warn_ident_too_long = Result_warn__start,
		Result_warn_scripts_disabled,
		Result_warn_empty_script_block,
		Result_warn_expr_no_effect,
		Result_warn_expr_sub_effect,
		Result_err__start,
		Result_err_unimplemented = Result_err__start,
		Result_err_expected_big_digit,
		Result_err_expected_binding,
		Result_err_expected_block,
		Result_err_expected_cast_op,
		Result_err_expected_char,
		Result_err_expected_char_number,
		Result_err_expected_class,
		Result_err_expected_class_desc,
		Result_err_expected_class_list_item,
		Result_err_expected_class_list_end,
		Result_err_expected_class_instance,
		Result_err_expected_class_meta,
		Result_err_expected_class_meta_end,
		Result_err_expected_class_union,
		Result_err_expected_class_union_end,
		Result_err_expected_clause_block,
		Result_err_expected_code_block,
		Result_err_expected_comment_close,
		Result_err_expected_conversion_op,
		Result_err_expected_data_defn,
		Result_err_expected_digit,
		Result_err_expected_expression,
		Result_err_expected_group_param,
		Result_err_expected_instance,
		Result_err_expected_int,
		Result_err_expected_invoke_apply,
		Result_err_expected_invoke_args,
		Result_err_expected_invoke_args_next,
		Result_err_expected_invoke_args_return,
		Result_err_expected_invoke_cascade,
		Result_err_expected_invoke_cascades,
		Result_err_expected_invoke_selector,
		Result_err_expected_invoke_select_op,
		Result_err_expected_literal_char,
		Result_err_expected_literal_list,
		Result_err_expected_literal_list_end,
		Result_err_expected_literal_string,
		Result_err_expected_literal_symbol,
		Result_err_expected_literal_symbol_end,
		Result_err_expected_loop_block,
		Result_err_expected_loop_exit,
		Result_err_expected_meta_key,
		Result_err_expected_meta_value,
		Result_err_expected_method_ctor_name,
		Result_err_expected_method_name,
		Result_err_expected_named_arg,
		Result_err_expected_operator,
		Result_err_expected_obj_id,
		Result_err_expected_parameters,
		Result_err_expected_param_name,
		Result_err_expected_race_block,
		Result_err_expected_real_end,
		Result_err_expected_script_name,
		Result_err_expected_scope_op,
		Result_err_expected_string_close,
		Result_err_expected_strategy_name,
		Result_err_expected_symbol_close,
		Result_err_expected_temporary,
		Result_err_expected_sync_block,
		Result_err_expected_whitespace,
		Result_err_unexpected_argument,
		Result_err_unexpected_bind_expr,
		Result_err_unexpected_branch_expr,
		Result_err_unexpected_cdtor,
		Result_err_unexpected_char,
		Result_err_unexpected_class_class,
		Result_err_unexpected_class_pattern,
		Result_err_unexpected_concurrency,
		Result_err_unexpected_cpp,
		Result_err_unexpected_deprecated,
		Result_err_unexpected_divert_expr,
		Result_err_unexpected_else,
		Result_err_unexpected_else_statement,
		Result_err_unexpected_eof,
		Result_err_unexpected_exit,
		Result_err_unexpected_implicit_this,
		Result_err_unexpected_named_spec,
		Result_err_unexpected_obj_identifier,
		Result_err_unexpected_parameter,
		Result_err_unexpected_parameter_return,
		Result_err_unexpected_reserved,
		Result_err_unexpected_statement,
		Result_err_size_class_union,
		Result_err_size_group_param,
		Result_err_size_radix_large,
		Result_err_size_radix_small,
		Result_err_size_identifier,
		Result_err_size_symbol,
		Result_err_context_case_compare,
		Result_err_context_conversion_params,
		Result_err_context_duped_data,
		Result_err_context_duped_data_super,
		Result_err_context_duped_data_sub,
		Result_err_context_duped_param_name,
		Result_err_context_duped_rparam_name,
		Result_err_context_duped_variable,
		Result_err_context_invoke_arg_end,
		Result_err_context_invoke_arg_missing,
		Result_err_context_invoke_arg_misnamed,
		Result_err_context_invoke_arg_preexist,
		Result_err_context_invoke_arg_skipped,
		Result_err_context_invoke_arg_unnamed,
		Result_err_context_invoke_ctor_args,
		Result_err_context_non_class,
		Result_err_context_non_identifier,
		Result_err_context_non_ident_member,
		Result_err_context_non_method,
		Result_err_context_non_coroutine,
		Result_err_context_object_id_bad_class,
		Result_err_context_object_id_invalid,
		Result_err_context_immediate,
		Result_err_context_deferred,
		Result_err_context_concurrent_redundant,
		Result_err_typecheck_actor,
		Result_err_typecheck_actor_scope,
		Result_err_typecheck_return_type,
		Result_err_typecheck_rparam_type,
		Result_err_typecheck_case,
		Result_err_typecheck_cast,
		Result_err_typecheck_closure_generics,
		Result_err_typecheck_conditional,
		Result_err_typecheck_conversion,
		Result_err_typecheck_default_param,
		Result_err_typecheck_invoke_arg,
		Result_err_typecheck_invoke_apply_recv,
		Result_err_typecheck_list,
		Result_err_typecheck_list_item,
		Result_err_typecheck_operand,
		Result_err_typecheck_retype,
		Result_err_typecheck_scope,
		Result_err_typecheck_union_trivial,
		Result__max
	};

	enum eResultDesired
	{
		ResultDesired_false,
		ResultDesired_true
	};

	struct Args
	{
		u32 i_start_pos = 0;
		u32 i_flags = 1;
		eResult i_result = Result_ok;
		u32 i_end_pos = 0;
		SSClassDescBase* i_type_p = 0;
	};

	AFlagSet32 i_flags;
	eSSMember i_member_type;
	SSTypeContext i_context;

	~SSParser() { SDK_CALL_FUNC(void, 0x107680, void*)(this); }
	SSParser(const AString& str) { SDK_CALL_FUNC(void, 0x1063F0, void*, const AString&)(this, str); }

	/* Functions */

	void set_class_scope(SSClass* scope_p) { SDK_CALL_FUNC(void, 0x13C360, void*, SSClass*)(this, scope_p); }

	SSCode* parse_code_block(Args& args, eSSInvokeTime desired_exec_time, eResultDesired result) {
		return SDK_CALL_FUNC(SSCode*, 0x128BF0, void*, Args&, eSSInvokeTime, eResultDesired)(this, args, desired_exec_time, result);
	}

	SSExpressionBase* parse_expression(Args& args, eSSInvokeTime desired_exec_time) { return SDK_CALL_FUNC(SSExpressionBase*, 0x129D10, void*, Args&, eSSInvokeTime)(this, args, desired_exec_time); }
};