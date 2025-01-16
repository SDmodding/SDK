#pragma once

namespace Scaleform
{
	struct ArrayDefaultPolicy
	{
		u64 Capacity;
	};

	template<class T, class SizePolicy>
	struct ArrayDataBase
	{
		T* Data;
		u64 Size;
		SizePolicy Policy;
	};

	template <class T, class SizePolicy>
	struct ArrayData : ArrayDataBase<T, SizePolicy>
	{

	};

	template <class ArrayData> 
	class ArrayBase
	{
	public:
		ArrayData Data;
	};

	template<class T, int SID = Stat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>
	class ArrayLH : public ArrayBase<ArrayData<T, SizePolicy>>
	{
	public:
	};
}