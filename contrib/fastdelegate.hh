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

	template <typename... Types>
	class FastDelegate
	{
	public:
		typedef typename void RetType;
		typedef RetType(*StaticFunctionPtr)();
		typedef RetType(*UnvoidStaticFunctionPtr)();
		typedef RetType(detail::GenericClass::* GenericMemFn)();
		typedef detail::ClosurePtr<GenericMemFn, StaticFunctionPtr, UnvoidStaticFunctionPtr> ClosureType;
		ClosureType m_Closure;

		FastDelegate() { m_Closure.clear(); }
		FastDelegate(void* pthis, void* function_to_bind)
		{
			m_Closure.m_pthis = pthis;
			m_Closure.m_pFunction = function_to_bind;
		}
	};

	template <typename... Types>
	using FastDelegate0 = FastDelegate<Types...>;
	template <typename... Types>
	using FastDelegate1 = FastDelegate<Types...>;
	template <typename... Types>
	using FastDelegate2 = FastDelegate<Types...>;
	template <typename... Types>
	using FastDelegate3 = FastDelegate<Types...>;
	template <typename... Types>
	using FastDelegate4 = FastDelegate<Types...>;
	template <typename... Types>
	using FastDelegate5 = FastDelegate<Types...>;
	template <typename... Types>
	using FastDelegate6 = FastDelegate<Types...>;
	template <typename... Types>
	using FastDelegate7 = FastDelegate<Types...>;
	template <typename... Types>
	using FastDelegate8 = FastDelegate<Types...>;

	/*template<class RetType = void>
	class FastDelegate0
	{
	public:
		typedef typename void DesiredRetType;
		typedef DesiredRetType(*StaticFunctionPtr)();
		typedef RetType(*UnvoidStaticFunctionPtr)();
		typedef RetType(detail::GenericClass::* GenericMemFn)();
		typedef detail::ClosurePtr<GenericMemFn, StaticFunctionPtr, UnvoidStaticFunctionPtr> ClosureType;
		ClosureType m_Closure;

		FastDelegate0() { m_Closure.clear(); }
		FastDelegate0(void* pthis, void* function_to_bind)
		{
			m_Closure.m_pthis = pthis;
			m_Closure.m_pFunction = function_to_bind;
		}
	};

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
	};*/
}