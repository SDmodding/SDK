#pragma once

class SSTypeContext
{
public:
	struct CapturedVars : public AListNode<CapturedVars>
	{
		APSortedLogical<SSTypedName, ASymbol> i_vars;
		APSortedLogical<SSTypedName, ASymbol>* i_scope_p;
	};

	struct ScopeVars : public AListNode<ScopeVars>
	{
		APSortedLogical<SSTypedName, ASymbol> i_vars;
	};

	SSClassUnaryBase* i_obj_scope_p;
	ASymbol i_scope_name;
	ScopeVars i_top_scope;
	APSortedLogical<SSTypedName, ASymbol> i_top_scope_old;
	AList<ScopeVars> i_scope_stack;
	APSortedLogical<SSTypedName, ASymbol>* i_current_scope_p;
	AList<CapturedVars> i_capture_stack;
	CapturedVars* i_capture_current_p;
};