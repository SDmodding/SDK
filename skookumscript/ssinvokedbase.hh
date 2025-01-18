#pragma once

class SSInvokedBase : public SSObjectBase, public AListNode<SSInvokedBase>
{
public:
	AIdPtr<SSObjectBase> i_scope_p;
	AIdPtr<SSInvokedBase> i_caller_p;
	AList<SSInvokedBase, SSInvokedBase> i_calls;
	u32 i_pending_count;
};

class SSInvokedContextBase : public SSInvokedBase
{
public:
	APArrayLogical<SSData, ASymbol> i_data;
};