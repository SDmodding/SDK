#pragma once

namespace UFG
{
	class ObjectiveIndicator : public qNodeRB<ObjectiveIndicator>
	{
	public:
		qSymbol mIdentifier;
		qSharedString mBlipType;
		qSafePointer<TransformNodeComponent> mpEffectTransform;
		int mCoronaType;
		u32 mEffectId;
		bool mEnabled;
		bool mTemporary;

		virtual ~ObjectiveIndicator() = 0;

		void SetEnabled(bool enabled) { SDK_CALL_FUNC(void, 0x4BC1A0, void*, bool)(this, enabled); }
	};

	class Objective : public qNodeRB<Objective>
	{
	public:
		enum Status
		{
			STATUS_INACTIVE,
			STATUS_ACTIVE,
			STATUS_HIGHLIGHT,
			STATUS_COMPLETED,
			STATUS_FAILED
		};

		GameSlice* mpGameSlice;
		qString mIdentifier;
		qString mCaption;
		qSharedString mLocationCaption;
		qSharedString mLog;
		qSharedString mGPSMarker;
		bool mAutoflash;
		bool mTextUnlockable;
		bool mSecondary;
		bool mUsesPDA;
		qTreeRB<ObjectiveIndicator> mIndicators;
		u32 mDisplayPriority;
		u32 mLoadId;
		Status mStatus;

		/* Virtual Functions */

		virtual ~Objective() = 0;

		/* Functions */

		void AddIndicator(const qSymbol& identifier, const qString& blip, const qString& corona, bool temporary) {
			SDK_CALL_FUNC(void, 0x492DB0, void*, const qSymbol&, const qString&, const qString&, bool)(this, identifier, blip, corona, temporary);
		}

		ObjectiveIndicator* GetFirstIndicator() { return SDK_CALL_FUNC(ObjectiveIndicator*, 0x4A28D0, void*)(this); }
		ObjectiveIndicator* GetNextIndicator(ObjectiveIndicator* pPrevious) { return SDK_CALL_FUNC(ObjectiveIndicator*, 0x4A54B0, void*, ObjectiveIndicator*)(this, pPrevious); }
		Status MapSymbolToStatus(const ASymbol& symbol) { return SDK_CALL_FUNC(Status, 0x4B0CD0, const ASymbol&)(symbol); }
		void RemoveIndicator(const qSymbol& name, bool removeTemporaryOnly) { SDK_CALL_FUNC(void, 0x4B6430, void*, const qSymbol&, bool)(this, name, removeTemporaryOnly); }
		void UpdateIndicators() { SDK_CALL_FUNC(void, 0x4C7810, void*)(this); }
	};

	class ObjectiveHint : public qNodeRB<ObjectiveHint>
	{
	public:
		qString mCaption;

		virtual ~ObjectiveHint() = 0;
	};

	class ObjectiveTracker
	{
	public:
		qArray<Objective*> mLoadedOrderObjectives;
		qTreeRB<Objective> mObjectives;
		qTreeRB<ObjectiveHint> mObjectiveHints;
		bool mDirty;
		Objective* mpFlashObjective;
		u32 mLastLoadId;

		/* Functions */

		Objective* AddObjective(const char* identifier, const char* caption, const char* locationCaption, const char* log, const char* gpsMarker, GameSlice* pGameSlice) {
			return SDK_CALL_FUNC(Objective*, 0x4936B0, void*, const char*, const char*, const char*, const char*, const char*, GameSlice*)(this, identifier, caption, locationCaption, log, gpsMarker, pGameSlice);
		}

		void Clear() { SDK_CALL_FUNC(void, 0x497950, void*)(this); }
		void EnableObjectiveIndicatorCorona(const qSymbol& name, bool isEnable) { SDK_CALL_FUNC(void, 0x49DCC0, void*, const qSymbol&, bool)(this, name, isEnable); }
		Objective* FindObjective(const qString& identifier) { return SDK_CALL_FUNC(Objective*, 0x4A0730, void*, const qString&)(this, identifier); }
		ObjectiveHint* FindObjectiveHint(const qString& identifier) { return SDK_CALL_FUNC(ObjectiveHint*, 0x4A0790, void*, const qString&)(this, identifier); }
		Objective* GetFirstObjective() { return SDK_CALL_FUNC(Objective*, 0x4A2900, void*)(this); }
		Objective* GetNextObjective(Objective* pPrevious) { return SDK_CALL_FUNC(Objective*, 0x4A54E0, void*, Objective*)(this, pPrevious); }
		void OnFail() { SDK_CALL_FUNC(void, 0x4B1750, void*)(this); }
		void OnGameSliceCleanup(GameSlice* pGameSlice) { SDK_CALL_FUNC(void, 0x4B1AD0, void*, GameSlice*)(this, pGameSlice); }
		void OnRestore() { SDK_CALL_FUNC(void, 0x4B1BE0, void*)(this); }

		void UpdateCaption(const qString& identifier, const qString& caption, GameSlice* pGameSlice) {
			SDK_CALL_FUNC(void, 0x4C5890, void*, const qString&, const qString&, GameSlice*)(this, identifier, caption, pGameSlice);
		}

		void UpdateStatus(Objective* pObjective, Objective::Status status, GameSlice* pGameSlice, bool updateFlash) {
			SDK_CALL_FUNC(void, 0x4C88A0, void*, Objective*, Objective::Status, GameSlice*, bool)(this, pObjective, status, pGameSlice, updateFlash);
		}

		void UpdateStatus(Objective* pObjective, bool refreshFlash) { SDK_CALL_FUNC(void, 0x4C8A00, void*, Objective*, bool)(this, pObjective, refreshFlash); }

		void UpdateStatus(const qString& identifier, Objective::Status status, GameSlice* pGameSlice) {
			SDK_CALL_FUNC(void, 0x4C8930, void*, const qString&, Objective::Status, GameSlice*)(this, identifier, status, pGameSlice);
		}
	};
}