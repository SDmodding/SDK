#pragma once

class SSParameterBase : public ANamed
{
public:
	virtual ~SSParameterBase() = 0;

	/*
  bool (__fastcall *compare_less)(SSParameterBase *this, SSParameterBase *) __declspec(align(16));
  SSExpressionBase *(__fastcall *get_default_expr)(SSParameterBase *this);
  eSSParameter (__fastcall *get_kind)(SSParameterBase *this);
  bool (__fastcall *is_defaultable)(SSParameterBase *this);
  void (__fastcall *track_memory)(SSParameterBase *this, AMemoryStats *);
  SSParameterBase *(__fastcall *as_finalized_generic)(SSParameterBase *this, SSClassDescBase *);
  SSClassDescBase *(__fastcall *get_expected_type)(SSParameterBase *this);
  bool (__fastcall *is_generic)(SSParameterBase *this);
	*/
};
