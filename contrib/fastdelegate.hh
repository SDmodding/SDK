//===========================================================================================
// 
//		BASED ON:
//			https://github.com/dreamcat4/FastDelegate
// 
//		NOTE:
//			Don't implement something that's not needed, keep it simple.
// 
//===========================================================================================
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
		detail::GenericClass* m_pthis;
		void (__fastcall* m_pFunction)(detail::GenericClass*);

		DelegateMemento() : m_pthis(0), m_pFunction(0) {};
		void clear() { m_pthis = 0; m_pFunction = 0; }
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

		FastDelegate1() { m_Closure.clear(); }
		FastDelegate1(void* pthis, void* function_to_bind)
		{
			m_Closure.m_pthis = pthis;
			m_Closure.m_pFunction = function_to_bind;
		}
	};
}