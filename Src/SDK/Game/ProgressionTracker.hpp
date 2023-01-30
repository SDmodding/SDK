#pragma once

namespace UFG
{
	class CProgressionTracker
	{
	public:
		UFG_PAD(0x1A00);

		qSymbol mActiveFlowId;
		bool mIsPossessedPedsEnabled;

		qSymbol GetFlowByID(int m_Index)
		{
			switch (m_Index)
			{
				case 0: default: return 0xAA1CA048; // Main
				case 1: return 0x1CA34841; // Nightmare in North Point
				case 2: return 0x5703AF69; // Year of the snake
			}
		}

		qSymbol* GetActiveFlow()
		{
			return reinterpret_cast<qSymbol*(__fastcall*)(void*)>(UFG_RVA(0x4A1920))(this);
		}

		void SetActiveFlow(qSymbol flowId)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*)>(UFG_RVA(0x4BB850))(this, &flowId);
		}
	};
	CProgressionTracker* ProgressionTracker = reinterpret_cast<CProgressionTracker*>(UFG_RVA(0x240A0E0));
}