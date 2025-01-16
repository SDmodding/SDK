#pragma once

namespace Scaleform
{
	template <class C>
	class AtomicValueBase
	{
	public:
		volatile C Value;
	};

	template <class C>
	class AtomicInt : AtomicValueBase<C>
	{
	public:
	};

	template <class C>
	class AtomicPtr : AtomicValueBase<C*>
	{
	public:
	};

	//----------------------------
	//	Lock
	//----------------------------

	class Lock
	{
	public:
		struct Locker
		{
			Lock* pLock;
		};

		_RTL_CRITICAL_SECTION cs;
	};

}