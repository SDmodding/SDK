#pragma once

namespace UFG
{
	class CaseInfo
	{
	public:
		enum Status
		{
			InPlace,
			Floating,
			DockedTop,
			DockedBottom,
			Closed
		};

		qSymbol mPropertySetName;
		qFixedArray<GameSlice*, 7> mDependents;
		Status mStatus;
	};

	class CaseTracker
	{
	public:
		qFixedArray<CaseInfo, 20> mCases;

		/* Functions */

		CaseInfo* GetCase(GameSlice* pGameSlice) { return SDK_CALL_FUNC(CaseInfo*, 0x4A1E40, void*, GameSlice*)(this, pGameSlice); }
	};
}