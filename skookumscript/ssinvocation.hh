#pragma once

class SSInvokeBase : public SSQualifier
{
public:
	APCompactArray<SSExpressionBase> i_arguments;
	APCompactArray<SSIdentifier> i_return_args;

	virtual ~SSInvokeBase() = 0;

	/*
	  eSSInvokeType (__fastcall *get_invoke_type)(SSInvokeBase *this);
  SSInvokedBase *(__fastcall *invoke_call)(SSInvokeBase *this, SSInstance *, SSObjectBase *, SSInvokedBase *, SSInstance **);
  void (__fastcall *track_memory)(SSInvokeBase *this, AMemoryStats *);
	*/
};