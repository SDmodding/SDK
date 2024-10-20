#pragma once

namespace fastdelegate
{
	namespace detail
	{
		class GenericClass {};
	}

	class DelegateMemento
	{
	public:
		typedef void (detail::GenericClass::* GenericMemFuncType)(); // arbitrary MFP.

		detail::GenericClass* m_pthis;
		GenericMemFuncType m_pFunction;
	};

	namespace detail
	{
		template <class GenericMemFunc, class StaticFuncPtr, class UnvoidStaticFuncPtr>
		class ClosurePtr : public DelegateMemento
		{
		public:
		};
	}

	template <class Param1, class RetType = void>
	class FastDelegate1
	{
	public:
		typedef typename void DesiredRetType;
		typedef DesiredRetType(*StaticFunctionPtr)();
		typedef RetType(*UnvoidStaticFunctionPtr)();
		typedef RetType(detail::GenericClass::* GenericMemFn)();
		typedef detail::ClosurePtr<GenericMemFn, StaticFunctionPtr, UnvoidStaticFunctionPtr> ClosureType;
		ClosureType m_Closure;
	};
}