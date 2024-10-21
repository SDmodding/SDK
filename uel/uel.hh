#pragma once

namespace UEL
{
	class Runtime;

	class Value
	{
	public:
		enum BaseType : int {};

		struct Type
		{
			qEnum<BaseType, u16> mBaseType;
			UFG::qSymbol mDetailedType;
		};
	};

	class Expression
	{
	public:
		enum Type
		{
			Unary,
			Binary,
			Constant,
			Invocation,
			Parameter,
			Fragment,
			Argument,
			FragmentInvocation,
			ArgumentUsage
		};

		qEnum<Type, u16> mType;
		Value::Type mValueType;
		u16 mResolved;
		u16 mNeedsRuntimeResolve;

		/* Virtual Functions */

		virtual u32 GetClassSize() = 0;
		virtual const char* GetClassname() = 0;
		virtual bool Resolve(Runtime*) = 0;
		//virtual Value* Eval(Value*) = 0;
	};
	SDK_ASSERT_SIZEOF(Expression, 0x18);
}