#pragma once

namespace UFG
{
	class CLoadingLogic
	{
	public:
		void* mLoadingImages;
		uint32_t mLoadingImageCount;

		enum LoadType
		{
			UnDecided = 0x0,
			BlackScreen = 0x1,
			Spinner = 0x2,
			LoadScreen = 0x3,
		};
		LoadType mLoadType;

		uint32_t mLastGenericLoadingScreen;
		uint32_t mTotalLoadBytes;
		uint64_t mLoadStartTime;
		uint64_t mLoadEndTime;
		float mCurrentLoadTimeWithoutQueue;
		uint32_t mPredictedBytesRemaining;
		float mPredictedLoadTime;
		float mTimeBeforeSpinner;
		float mTimeBeforeLoadScreen;
		float mRunningBandwidthBytesPerSecond;
		bool mEnableLoadingScreenAudio;
		bool mClearPedsOnNextUpdate;
		qWiseSymbol mOnLoadMixEvent;
		qWiseSymbol mOnLoadEndMixEvent;
		bool mIsLoadScreenUp;
		bool mForceLoadTypeToLoadScreen;
		bool mAllowLoadScreen;
		void* mDeferredTimeSettings;
		qString mLoadScreenTexturePack;

		static CLoadingLogic* Instance()
		{
			return reinterpret_cast<CLoadingLogic*>(UFG_RVA(0x207B220));
		}

		void StartLoadScreen(uint32_t p_Flags, void* p_Images, uint32_t p_NumImages)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint32_t, void*, uint32_t)>(UFG_RVA(0x417860))(this, p_Flags, p_Images, p_NumImages);
		}
	};
}