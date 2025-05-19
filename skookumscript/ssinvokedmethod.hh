#pragma once

class SSInvokedMethod : public SSInvokedContextBase
{
public:
	SSMethodBase* i_method_p;
};

class SSInvokedDeferrableMethod : public SSInvokedMethod
{
public:
};

class SSIExternalMethodCallWrapper : public SSInvokedDeferrableMethod
{
public:
	bool* i_finished_p;
};