#pragma once

namespace UFG
{
	class CScreen
	{
	public:
		void* vfptr;
		
		void* m_Pad0x8[0x2];

		char m_screenName[64];
		unsigned int m_screenNameHash;
		void* mRenderable;
		void* mLoadThread;
		unsigned int mScreenUID;
		int mControllerMask;
		int mInputEnabled;
		int mPriority;
		unsigned int mDimType;
		unsigned int mDimToApplyType;
		float mCurDimValue;
		float mCurDimDirection;
	};

	class CScreenDialogBoxData
	{
	public:
		void* mCommandData;
		CScreen* mOwner;
		unsigned int mNumOptions;
		unsigned int mDefaultButton;
		qString mTitleText;
		qString mBodyText;
		unsigned int mOption1Msg;
		unsigned int mOption2Msg;
		unsigned int mOption3Msg;

		char m_Pad0x74[0x4];

		qString mOption1Text;
		qString mOption2Text;
		qString mOption3Text;
		unsigned int mIcon;
		bool mFullScreen;

		char m_Pad0xF5[0x3];

		qString mFlashFile;
		unsigned int mHorizontalResolution;
		unsigned int mVerticalResolution;
	};

	class CScreenDialogBox : public CScreen
	{
	public:
		CScreenDialogBoxData mData;
		unsigned int mState;
	};

	class CScreenPauseMenu : public CScreen
	{
	public:
		UFG_PAD(0x18);

		unsigned int mState;
		bool mInfoTickerSet;
	};
}