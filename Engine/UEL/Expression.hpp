#pragma once

namespace UEL
{
	class CExpression
	{
		void* vfptr;

		enum Type
		{
			Unary = 0x0,
			Binary = 0x1,
			Constant = 0x2,
			Invocation = 0x3,
			Parameter = 0x4,
			Fragment = 0x5,
			Argument = 0x6,
			FragmentInvocation = 0x7,
			ArgumentUsage = 0x8,
		};
		Type mType;
		CValue::Type_t mValueType;
		uint16_t mResolved;
		uint16_t mNeedsRuntimeResolve;
	};

	class CExpressionParameterFloat
	{
	public:
		UFG::BinString text;
		UFG::qOffset64<CExpression> expression;
		float value;
	};

	class CExpressionParameterInt
	{
	public:
		UFG::BinString text;
		UFG::qOffset64<CExpression> expression;
		int value;
	};

}