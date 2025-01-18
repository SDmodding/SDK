#pragma once

class SSCoroutineBase : public SSInvokableBase
{
public:
};

class SSCoroutine : public SSCoroutineBase
{
public:
	SSExpressionBase* i_expr_p;
};

class SSCoroutineCall : public SSInvokeBase
{
public:
};
