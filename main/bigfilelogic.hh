#pragma once

namespace UFG
{
	struct BIGFileSize
	{
		u32 load_offset;
		u32 compressed_size;
		u32 compressed_extra;
		u32 uncompressed_size;
	};

	class BIGFileIndex : public qResourceData
	{
	public:
		struct Entry
		{
			u32 uid;
			u32 offset_div_4;
			BIGFileSize size;
		};

		i64 mSortKey;
		u32 mEntryCount;
		qOffset64<Entry*> mEntries;
		qFile* mpFile;
		u16 mState;
		u16 mMountIndex;
		u32 mPadding0;
		u32 mPadding1;
		char mBigFileName[32];
	};
}