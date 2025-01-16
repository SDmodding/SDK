#pragma once

namespace Scaleform
{
	template <class C>
	class Ptr
	{
	public:
		C* pObject;

		SF_INLINE C* operator->() const { return pObject; }
	};

	//----------------------------
	//	RefCount
	//----------------------------

	class RefCountImplCore
	{
	public:
		volatile int RefCount;

		virtual ~RefCountImplCore() = 0;
	};

	class RefCountImpl : public RefCountImplCore
	{
	public:
		void Release() { SDK_CALL_FUNC(void, 0x9A7C60, void*)(this); }
	};

	template <class Base, int StatType>
	class RefCountBaseStatImpl : public Base
	{
	public:
	};

	template <class C, int Stat>
	class RefCountBase : public RefCountBaseStatImpl<RefCountImpl, Stat>
	{
	public:
	};

}