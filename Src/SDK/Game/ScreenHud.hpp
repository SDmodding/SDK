#pragma once

namespace UFG
{
	class CActionButton
	{
	public:
		void Hide() { reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x5EC990))(this); }

		void Show(const char* actionText, unsigned int button, const char* actionType) { reinterpret_cast<void(__fastcall*)(void*, const char*, unsigned int, const char*)>(UFG_RVA(0x60CA80))(this, actionText, button, actionType); }
	};

	enum MissionProgressState : unsigned int
	{
		MISSIONPROGRESS_INVALID = 0x0,
		MISSIONPROGRESS_NORMAL = 0x1,
		MISSIONPROGRESS_DANGER = 0x2,
		MISSIONPROGRESS_COMPLETE = 0x3,
		MISSIONPROGRESS_INCOMPLETE = 0x4,
		MISSIONPROGRESS_ANIMATE_COMPLETE = 0x5,
	};

	class CMissionProgress
	{
	public:
		void Clear() { reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x5D50D0))(this); }

		void SetState(unsigned int state, unsigned int slot) { reinterpret_cast<void(__fastcall*)(void*, unsigned int, unsigned int)>(UFG_RVA(0x609040))(this, state, slot); }

		void SetText(const char* text, unsigned int slot) { reinterpret_cast<void(__fastcall*)(void*, const char*, unsigned int)>(UFG_RVA(0x609FF0))(this, text, slot); }
	};

	class CInfoPopup
	{
	public:
		void Show(const char* caption, qSymbol* type, float duration, int position = 0) { reinterpret_cast<void(__fastcall*)(void*, const char*, qSymbol*, float, int)>(UFG_RVA(0x60D100))(this, caption, type, duration, position); }
	};

	class CMissionHealth
	{
	public:
		bool mChanged;
		bool mVisible;
		bool mVisibleChanged;
		bool mSuccess;
		float mHealth;
		qString mCaption;

		void SetCaption(const char* caption) { reinterpret_cast<void(__fastcall*)(void*, const char*)>(UFG_RVA(0x605610))(this, caption); }

		void SetHealth(float value) 
		{
			if (mHealth == value) return;

			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x606230))(this, value); 
		}

		void SetSuccess(bool success) { reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x609F80))(this, success); }

		void SetVisible(bool visible) { reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x60C630))(this, visible); }
	};

	class CRaceTimer
	{
	public:
		void SetVisible(bool visible) { reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x60C650))(this, visible); }

		void SetTime(unsigned int minutes, unsigned int seconds, unsigned int thousandths) 
		{ 
			reinterpret_cast<void(__fastcall*)(void*, unsigned int, unsigned int, unsigned int)>(UFG_RVA(0x60A0C0))(this, minutes, seconds, thousandths);
		}

		void StartCountdown() { reinterpret_cast<void(__fastcall*)()>(UFG_RVA(0x4F2480))(); }
	};

	class CRacePath
	{
	public:
		UFG_PAD(0x28);

		uint32_t m_MarkerPositionsSize;
		uint32_t m_MarkerPositionsCapacity;
		qVector3* m_MarkerPositionsPointer;

		void SetVisible(bool m_Enable) { *reinterpret_cast<bool*>(UFG_RVA(0x2173F01)) = m_Enable; }

		void GenerateSpline(qVector3* m_Array, uint32_t m_Size)
		{
			m_MarkerPositionsPointer	= m_Array;
			m_MarkerPositionsSize		= m_Size;

			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0xC0910))(this);

			m_MarkerPositionsPointer	= nullptr;
			m_MarkerPositionsSize		= 0;
		}

		void Clear() 
		{ 
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0xBE980))(this); 
			SetVisible(false);
		}
	};

	class CHintText
	{
	public:
		void Show(const char* text, float displayTime, bool repeat = false, float repeatTime = 0.f) { reinterpret_cast<void(__fastcall*)(void*, const char*, float, bool, float)>(UFG_RVA(0x63AFD0))(this, text, displayTime, repeat, repeatTime); }

		void Hide() { reinterpret_cast<void(__fastcall*)(void*)> (UFG_RVA(0x62FBF0))(this); }
	};

	class CScreenHud
	{
	public:
		void* MapLines;
		CActionButton* ActionButton;
		void* CombatMeter;
		void* ObjectiveDistance;
		CMissionProgress* MissionProgress;
		CInfoPopup* InfoPopup; // Basically HintText + special SFX
		CMissionHealth* MissionHealth;
		void* TurnHint;
		CRaceTimer* RaceTimer;
		void* RacePosition;

		UFG_PAD(0x8);

		void* RacePercentage;
		void* MissionRewards;
		void* RegionIndicator; // Top animated movie with region change (North Point, Central, ...)

		UFG_PAD(0x8);

		CRacePath* RacePath;
		void* ShortcutButton;

		UFG_PAD(0x8);

		CHintText* HintText;
		void* GameplayHelp;
		void* XPFlasher;
		void* SecondaryTutorial;

		void SetVisible(bool value)
		{
			reinterpret_cast<void(__fastcall*)(bool)>(UFG_RVA(0x60C670))(value);
		}
	};
	CScreenHud* ScreenHud = reinterpret_cast<CScreenHud*>(UFG_RVA(0x2430BB0));
}