#pragma once

namespace UFG
{
	class CLinearAllocator
	{
	public:
		void* Malloc(uint32_t p_Size, uint32_t p_Alignment)
		{
			return reinterpret_cast<void*(__fastcall*)(void*, uint32_t, uint32_t)>(UFG_RVA(0x1775D0))(this, p_Size, p_Alignment);
		}
	};
}