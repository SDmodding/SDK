#pragma once

namespace Illusion
{
	class CStateParam
	{
	public:
		uint32_t mNameUID;
		uint32_t mTypeUID;
		int16_t mParamIndex;

		UFG_PAD_ALIGN(0x2);
	};

	class CStateSystem
	{
	public:
		UFG_PAD(0x2A04);

		static CStateSystem* Instance()
		{
			return reinterpret_cast<CStateSystem*>(UFG_RVA(0x2167B40));
		}

		uint32_t GetParam(uint32_t p_NameUID)
		{
			return reinterpret_cast<uint32_t(_fastcall*)(void*, uint32_t)>(UFG_RVA(0x923B0))(this, p_NameUID);
		}

		__inline uint32_t GetParam(const char* p_Name)
		{
			return GetParam(UFG::Hash32(p_Name));
		}
	};
}