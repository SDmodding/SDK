#pragma once

namespace UFG
{
	class __declspec(align(16)) UIHKScreenHud : public UIScreen
	{
	public:
		enum eState
		{
			STATE_NONE,
			STATE_MINIMAP_LOADING,
			STATE_INTRO,
			STATE_NORMAL,
			STATE_EXIT
		};

		UITiledMapWidget Minimap;
		UIHK_PDAWidget* PDA;
		UIHKHealthMeterWidget HealthMeter;
		UIHKWeaponAmmoWidget WeaponAmmo;
		UIHKRadioStationWidget RadioStationWidget;
		UIHKActionHijackWidget ActionHijack;
		UIHKMoneyPopupWidget MoneyPopup;
		UIHKBuffWidget Buffs;
		UIHKSocialActionManager SocialActionManager;
		UIHKSecondaryObjectivesWidget SecondaryObjectives;
		UIHKObjectiveFlasherWidget ObjectiveFlasher;
		eState mState;
		f32 mMinimapAlpha;
		f32 mMinimapFadeTimeout;
		bool mMinimapVisibleChanged;
		UIHKReticleWidget Reticle;
		UIHKDirectionalDamageWidget DirectionalDamage;
		UIHKHeatLevelWidget HeatLevel;
		UIHKTimeOfDayWidget TimeOfDay;
		qProxy<UIHKSniperWidget> SniperWidget;
		f32 mStatInfoTimer;
		bool mStatSocialAwardActive;
		bool mStatGameInfoActive;
		bool mUpdateStatGamePosition;
		bool mHudEnable;

		/* Static Members */

		SDK_VINLINE qGlobalVar<bool, 0x208E330> mShouldRender;
		SDK_VINLINE qGlobalVar<const char*, 0x208E808> gTexturePackFilename;
		SDK_VINLINE qGlobalVar<bool, 0x2430C01> mHandleSigninChange;
		SDK_VINLINE qGlobalVar<bool, 0x2430C02> mOnDemandTexturesLoaded;
		SDK_VINLINE qGlobalVar<int, 0x2430D00> mOnDemandTextureLoadRefCounter;

		/* Static Functions */

		SDK_SINLINE UIHKScreenHud* Instance() { return SDK_VAR_GET(UIHKScreenHud*, 0x2430CC8); }
		SDK_SINLINE void ClearPDACache() { SDK_CALL_FUNC(void, 0x5D57F0)(); }
		SDK_SINLINE void HandleMinimapInteriorTextureLoaded() { SDK_CALL_FUNC(void, 0x5EB530)(); }
		SDK_SINLINE void PingMinimap() { SDK_CALL_FUNC(void, 0x5F3A60)(); }
		SDK_SINLINE void Pop() { SDK_CALL_FUNC(void, 0x5F4290)(); }
		SDK_SINLINE void RaceClear() { SDK_CALL_FUNC(void, 0x5FF0D0)(); }
		SDK_SINLINE void ResetWidgetVisibility() { SDK_CALL_FUNC(void, 0x602A00)(); }
		SDK_SINLINE void ResetWidgets() { SDK_CALL_FUNC(void, 0x602AE0)(); }
		SDK_SINLINE void SetReticleHighlightMode(eHighlightModeEnum highlightMode) { SDK_CALL_FUNC(void, 0x606F70, eHighlightModeEnum)(highlightMode); }
		SDK_SINLINE void SetReticlePosition(f32 screen_x, f32 screen_y) { SDK_CALL_FUNC(void, 0x606FA0, f32, f32)(screen_x, screen_y); }
		SDK_SINLINE void SetReticleScreenSpaceRadius(f32 radius) { SDK_CALL_FUNC(void, 0x606FE0, f32)(radius); }
		SDK_SINLINE void SetReticleSize(f32 fCurrent, f32 fMin, f32 fMax) { SDK_CALL_FUNC(void, 0x607020, f32, f32, f32)(fCurrent, fMin, fMax); }
		SDK_SINLINE void SetReticleState(UIHKReticleWidget::eState state) { SDK_CALL_FUNC(void, 0x607050, UIHKReticleWidget::eState)(state); }
		SDK_SINLINE void SetReticleTargetFaction(eFactionStandingEnum faction) { SDK_CALL_FUNC(void, 0x607080, eFactionStandingEnum)(faction); }
		SDK_SINLINE void SetReticleType(u32 eWeaponReticleEnum, bool bIsExplosive) { SDK_CALL_FUNC(void, 0x6070B0, u32, bool)(eWeaponReticleEnum, bIsExplosive); }
		SDK_SINLINE void SetTexturePackForFlow(const char* flowPostfix) { SDK_CALL_FUNC(void, 0x60A030, const char*)(flowPostfix); }
		SDK_SINLINE void SetVisible(bool value) { SDK_CALL_FUNC(void, 0x60C670, bool)(value); }
		SDK_SINLINE void SetWidgetVisible(const qSymbol& widget, bool visible) { SDK_CALL_FUNC(void, 0x60C720, const qSymbol&, bool)(widget, visible); }

		/* Impl Functions */

		SDK_INLINE f32 GetMapZoomFactor() { return Minimap.m_mapGeo.scale; }
		SDK_INLINE bool IsStatGameShowingFinalScore() { return mStatInfoTimer > 0.f && !mStatSocialAwardActive; }

		/* Functions */

		void AddWitness(const qVector3& pos, bool isCop) { SDK_CALL_FUNC(void, 0x5D2FD0, const qVector3&, bool)(pos, isCop); }
		void EmergencyInputModeRecovery() { SDK_CALL_FUNC(void, 0x5D6F50, void*)(this); }
		void Flash_Update() { SDK_CALL_FUNC(void, 0x5E57D0, void*)(this); }
		void HideStatGameInfo() { SDK_CALL_FUNC(void, 0x5ED170, void*)(this); }
		void LeadUnlocked(const qSymbol& assetID) { SDK_CALL_FUNC(void, 0x5F08B0, void*, const qSymbol&)(this, assetID); }
		void LoadTutorialHudTexturePack() { SDK_CALL_FUNC(void, 0x5F1B40, void*)(this); }
		void PopulatePDACache() { SDK_CALL_FUNC(void, 0x5F9F10, void*)(this); }
		void QueueInvoke(UIScreenInvoke* cmd) { SDK_CALL_FUNC(void, 0x5FECD0, UIScreenInvoke*)(cmd); }
		void SetMinimapHighlight(bool highlight) { SDK_CALL_FUNC(void, 0x6062E0, void*, bool)(this, highlight); }

		void SetSocialAwardMedal(int medal, const char* socialaward, const char* myname, const char* myscore) {
			SDK_CALL_FUNC(void, 0x6081F0, void*, int, const char*, const char*, const char*)(this, medal, socialaward, myname, myscore);
		}

		void SetStatGameBeatHim(const char* hisname, const char* score) { SDK_CALL_FUNC(void, 0x6084C0, void*, const char*, const char*)(this, hisname, score); }
		void SetStatGameFinalScore(int popup_id, const char* statDescr, u32 rank) { SDK_CALL_FUNC(void, 0x6086A0, void*, int, const char*, u32)(this, popup_id, statDescr, rank); }

		void SetStatGameInfo(const char* statInfo, const char* myname, const char* myscore, const char* leader, const char* leaderscore) {
			SDK_CALL_FUNC(void, 0x608960, void*, const char*, const char*, const char*, const char*, const char*)(this, statInfo, myname, myscore, leader, leaderscore);
		}

		void SetStatMakingNewRecord() { SDK_CALL_FUNC(void, 0x608C50, void*)(this); }
		void SetWidgetHighlight(const qSymbol& widget, bool highlight) { SDK_CALL_FUNC(void, 0x60C6C0, void*, const qSymbol&, bool)(this, widget, highlight); }
		void UnHideAmmoOverlay() { SDK_CALL_FUNC(void, 0x613120, void*)(this); }
		void UnloadTutorialHudTexturePack() { SDK_CALL_FUNC(void, 0x6131D0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(UIHKScreenHud, 0xCF0);
}