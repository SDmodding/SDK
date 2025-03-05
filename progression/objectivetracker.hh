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
}