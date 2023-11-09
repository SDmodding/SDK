#pragma once

namespace UFG
{
	class CUIScreenRenderable
	{
	public:
		void* vfptr;
		Illusion::CTarget* m_offscreenTarget;
		bool m_ownsOffscreenTarget;
		char m_fileName[256];
		Scaleform::GFx::MovieInfo m_movieInfo;
		Scaleform::GFx::MovieDef* m_movieDef;
		Scaleform::GFx::Movie* m_movie;
		Scaleform::GFx::Loader* mLoader;
		int m_x;
		int m_y;
		int m_width;
		int m_height;
		bool m_shouldRender;
		volatile bool mIsLoaded;
	};

	class CUIScreen
	{
	public:
		void* vfptr;
		qNode<CUIScreen> mNode;
		char m_screenName[64];
		uint32_t m_screenNameHash;
		CUIScreenRenderable* mRenderable;
		void* mLoadThread;
		unsigned int mScreenUID;
		int mControllerMask;
		int mInputEnabled;
		int mPriority;
		uint32_t mDimType;
		uint32_t mDimToApplyType;
		float mCurDimValue;
		float mCurDimDirection;
	};

	class CUIScreenDialogBox : public CUIScreen
	{
	public:
		struct Data_t
		{
			void* mCommandData;
			CUIScreen* mOwner;
			uint32_t mNumOptions;
			uint32_t mDefaultButton;
			qString mTitleText;
			qString mBodyText;
			uint32_t mOption1Msg;
			uint32_t mOption2Msg;
			uint32_t mOption3Msg;
			qString mOption1Text;
			qString mOption2Text;
			qString mOption3Text;
			uint32_t mIcon;
			bool mFullScreen;
			qString mFlashFile;
			uint32_t mHorizontalResolution;
			uint32_t mVerticalResolution;
		};
		Data_t mData;
		uint32_t mState;
	};

	class CUIHKScreenPauseMenu : public CUIScreen
	{
	public:
		UFG_PAD(0x18);
		// public: UFG::OnlineManagerObserver

		uint32_t mState;
		bool mInfoTickerSet;
	};
}