#pragma once

namespace UFG
{
	class GameSetup
	{
	public:
		char mConfig[32];
		char mLocationDir[32];
		char mInitMenu[32];
		bool mMultiplayer;
		char mDebugSaveGame[32];
		char mProgressionFlowType[32];

		/* Virtual Functions */

		virtual ~GameSetup() = 0;
		virtual void Initialize() = 0;
		virtual void LoadConfig(const qSymbol& config) = 0;

		/* Functions */

		void SetDebugSaveGame(const char* debugSaveGame) { SDK_CALL_FUNC(void, 0x13F7B0, void*, const char*)(this, debugSaveGame); }
		void SetInitMenu(const char* initMenu) { SDK_CALL_FUNC(void, 0x13F800, void*, const char*)(this, initMenu); }
		void SetLocationDir(const char* loc_directory) { SDK_CALL_FUNC(void, 0x13F850, void*, const char*)(this, loc_directory); }
	};
}