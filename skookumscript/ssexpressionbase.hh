#pragma once

class SSExpressionBase
{
public:
	virtual ~SSExpressionBase() = 0;
	/*
  SSExpressionBase *(__fastcall *find_expr_last_no_side_effect)(SSExpressionBase *this) __declspec(align(16));
  eSSSideEffect (__fastcall *get_side_effect)(SSExpressionBase *this);
  SSInvokedBase *(__fastcall *invoke)(SSExpressionBase *this, SSObjectBase *, SSInvokedBase *, SSInstance **);
  void (__fastcall *null_receiver)(SSExpressionBase *this, SSExpressionBase *);
  void (__fastcall *track_memory)(SSExpressionBase *this, AMemoryStats *);
  eSSExprType (__fastcall *get_type)(SSExpressionBase *this);
  bool (__fastcall *is_loop)(SSExpressionBase *this, ASymbol *);
  bool (__fastcall *is_immediate)(SSExpressionBase *this, unsigned int *);
  bool (__fastcall *is_nil)(SSExpressionBase *this);
  SSActor *(__fastcall *get_updater)(SSExpressionBase *this, SSInvokedExpression *);
  bool (__fastcall *invoke_iterate)(SSExpressionBase *this, SSInvokedExpression *, SSInstance **);
  void (__fastcall *invoke_exit)(SSExpressionBase *this, SSInvokedExpression *, SSInvokedExpression *);
	*/
};
