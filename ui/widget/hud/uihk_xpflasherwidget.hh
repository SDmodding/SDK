#pragma once

namespace UFG
{
	class UIHK_XPFlasherData
	{
	public:
		int Total;
		int ChainMax;
		f32 ChainMaxTimer;
		qString Caption;
		bool Changed;
	};

	class UIHK_XPFlasherWidget
	{
	public:
		enum eState
		{
			STATE_INIT,
			STATE_IDLE,
			STATE_ACTIVE
		};

		enum eXPTypes
		{
			XP_TYPE_NONE,
			XP_TYPE_COP,
			XP_TYPE_TRIAD,
			NUM_XP_TYPES
		};

		eState mState;
		f32 mStateElapsed;
		UIHK_XPFlasherData mData[NUM_XP_TYPES];

		/* Static Functions */

		SDK_SINLINE UIHK_XPFlasherWidget* Instance() { return SDK_VAR_GET(UIHK_XPFlasherWidget*, 0x2430C50); }

		/* Functions */

		void AddXP(int points, eXPTypes type, const char* caption) { SDK_CALL_FUNC(void, 0x5D3150, void*, int, eXPTypes, const char*)(this, points, type, caption); }
		void Flash_HideCopXP(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5DBCF0, void*, UIScreen*)(this, screen); }
		void Flash_HideTriadXP(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5DBEC0, void*, UIScreen*)(this, screen); }
		void Flash_ShowCopXP(UIScreen* screen, int points, const char* caption) { SDK_CALL_FUNC(void, 0x5E4670, void*, UIScreen*, int, const char*)(this, screen, points, caption); }
		void Flash_ShowTriadXP(UIScreen* screen, int points, const char* caption) { SDK_CALL_FUNC(void, 0x5E4E40, void*, UIScreen*, int, const char*)(this, screen, points, caption); }
		void Update(UIScreen* screen, f32 elapsed) { SDK_CALL_FUNC(void, 0x619A50, void*, UIScreen*, f32)(this, screen, elapsed); }
	};
}