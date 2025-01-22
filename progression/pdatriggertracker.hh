#pragma once

namespace UFG
{
	class PDATrigger : public qNodeRB<PDATrigger>
	{
	public:
		qSymbol mSymbol;
		GameSlice* mpGameSlice;
		bool mTriggered;

		virtual ~PDATrigger() = 0;
	};

	class PDATriggerTracker
	{
	public:
		qTreeRB<PDATrigger> mPDATriggers;

		/* Functions */

		PDATrigger* Add(const qSymbol& identifier, GameSlice* pGameSlice) { return SDK_CALL_FUNC(PDATrigger*, 0x492740, void*, const qSymbol&, GameSlice*)(this, identifier, pGameSlice); }
		PDATrigger* GetFirst() { return SDK_CALL_FUNC(PDATrigger*, 0x4A28B0, void*)(this); }
		PDATrigger* GetNext(PDATrigger* pPrevious) { return SDK_CALL_FUNC(PDATrigger*, 0x4A5480, void*, PDATrigger*)(this, pPrevious); }
		bool IsTriggered(const qSymbol& identifier) { return SDK_CALL_FUNC(bool, 0x4ACFC0, void*, const qSymbol&)(this, identifier); }
		void Remove(const qSymbol& identifier) { SDK_CALL_FUNC(void, 0x4B63A0, void*, const qSymbol&)(this, identifier); }
	};

	class PDATriggerParameters
	{
	public:
		qString mContactName;
		qSymbol mContactSymbol;
		qSymbol mVehicleFilter;
		qString mObjectiveName;
		bool mIncoming;
	};
}