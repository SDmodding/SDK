#pragma once

namespace UFG
{
	class CProgressionTracker
	{
	public:
		UFG_PAD(0x1A00);

		qSymbol mActiveFlowId;
		bool mIsPossessedPedsEnabled;

		static UFG_INLINE CProgressionTracker* Instance()
		{
			return reinterpret_cast<CProgressionTracker*>(UFG_RVA(0x240A0E0));
		}

		UFG_INLINE CGameSlice* Find(qSymbol p_NameUID, bool p_SearchDisabledSlices)
		{
			return reinterpret_cast<CGameSlice*(__fastcall*)(void*, qSymbol*, bool)>(UFG_RVA(0x4A0380))(this, &p_NameUID, p_SearchDisabledSlices);
		}

		UFG_INLINE void ForceProgress(CGameSlice* p_GameSlice, bool p_SimulateRewards)
		{
			reinterpret_cast<void(__fastcall*)(void*, CGameSlice*, bool)>(UFG_RVA(0x4A11F0))(this, p_GameSlice, p_SimulateRewards);
		}

		UFG_INLINE void ForceSliceChange(CGameSlice* p_GameSlice, bool p_SimulateRewards)
		{
			reinterpret_cast<void(__fastcall*)(void*, CGameSlice*, bool)>(UFG_RVA(0x4A1390))(this, p_GameSlice, p_SimulateRewards);
		}

		UFG_INLINE qSymbol GetFlowByID(int p_Index)
		{
			switch (p_Index)
			{
				case 0: default: return 0xAA1CA048; // Main
				case 1: return 0x1CA34841; // Nightmare in North Point
				case 2: return 0x5703AF69; // Year of the snake
			}
		}

		UFG_INLINE qSymbol* GetActiveFlow()
		{
			return reinterpret_cast<qSymbol*(__fastcall*)(void*)>(UFG_RVA(0x4A1920))(this);
		}

		UFG_INLINE void MoveAllSlicesInDisabledList()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x4B1070))(this);
		}

		UFG_INLINE void SetActiveFlow(qSymbol p_FlowID)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*)>(UFG_RVA(0x4BB850))(this, &p_FlowID);
		}

		UFG_INLINE void SetActiveMaster(CGameSlice* p_ActiveMaster, CGameSlice* p_Checkpoint, bool p_ForceSave)
		{
			reinterpret_cast<void(__fastcall*)(void*, CGameSlice*, CGameSlice*, bool)>(UFG_RVA(0x4BB8B0))(this, p_ActiveMaster, p_Checkpoint, p_ForceSave);
		}
	};
}