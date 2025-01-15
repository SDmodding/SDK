#pragma once

namespace UFG
{
	enum eHDD_SAVE_FILE_TYPE : i32
	{
		HDD_FILE_TYPE_FIRST = 0,
		HDD_FILE_TYPE_PROTECTED = 0,
		HDD_FILE_TYPE_UNPROTECTED = 1,
		HDD_FILE_TYPE_LAST = 1
	};

	class HddSaveFile : public qNode<HddSaveFile>
	{
	public:
		bool mAdjustFileSize;
		qString mFileName;
		qString mReferenceFileName;
		u32 mFileSize;
		eHDD_SAVE_FILE_TYPE mFileType;
		void* mData;
		int mUserData[2];
		qString mDescription;
		qString mTitle;
	};
	SDK_ASSERT_SIZEOF(HddSaveFile, 0xD0);

	class HddFileContainer
	{
	public:
		u32 TotalFileSize;
		u32 ContainerCount;
		qList<HddSaveFile> FileList;
		HddSaveFile* currentFile;
	};
}