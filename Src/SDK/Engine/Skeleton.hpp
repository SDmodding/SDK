#pragma once

namespace UFG
{
	class CSkeleton
	{
	public:
		int GetBoneID(unsigned int boneUID)
		{
			return reinterpret_cast<int(__fastcall*)(void*, unsigned int)>(UFG_RVA(0x1B9390))(this, boneUID);
		}
	};
}