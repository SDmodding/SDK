#pragma once

class SSInvokedBase : public SSObjectBase, public AListNode<SSInvokedBase>
{
public:
	AIdPtr<SSObjectBase> i_scope_p;
	AIdPtr<SSInvokedBase> i_caller_p;
	AList<SSInvokedBase> i_calls;
	u32 i_pending_count;
};

class SSInvokedExpression : public SSInvokedBase
{
public:
	u32 i_index;
	u64 i_data;
	SSExpressionBase* i_expr_p;
};

class SSInvokedContextBase : public SSInvokedBase
{
public:
	APArrayLogical<SSData, ASymbol> i_data;
};