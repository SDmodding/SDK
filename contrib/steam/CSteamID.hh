#pragma once

class CSteamID
{
public:
	union SteamID_t
	{
		struct SteamIDComponent_t
		{
			u32 m_unAccountID : 32;
			u32 m_unAccountInstance : 20;
			u32 m_EAccountType : 4;
			int m_EUniverse : 8;
		} m_comp;

		u64 m_unAll64Bits;
	} m_steamid;
};