#pragma once

enum eSSInvokeTime
{
	SSInvokeTime_immediate = 1,
	SSInvokeTime_durational,
	SSInvokeTime_any
};

class SSInvokableClass : public SSContextClassBase
{
public:
	ARefPtr<SSParameters> i_params_p;
	eSSInvokeTime i_invoke_type;
};