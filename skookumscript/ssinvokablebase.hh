#pragma once

class SSInvokableBase : public SSQualifier
{
public:
	ARefPtr<SSParameters> i_params_p;

	virtual ~SSInvokableBase() = 0;

	/*
	SSExpressionBase *(__fastcall *get_custom_expr)(SSInvokableBase *this);
  eSSInvokable (__fastcall *get_invoke_type)(SSInvokableBase *this);
  bool (__fastcall *is_bound)(SSInvokableBase *this);
  bool (__fastcall *is_class_member)(SSInvokableBase *this);
  bool (__fastcall *is_placeholder)(SSInvokableBase *this);
	*/
};
