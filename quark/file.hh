#pragma once

namespace UFG
{
	enum qFileAccessType
	{
		QACCESS_READ = 1,
		QACCESS_WRITE = 2,
		QACCESS_READ_WRITE = (QACCESS_READ | QACCESS_WRITE),
		QACCESS_APPEND = 4,
		QACCESS_WRITE_EXISTING = 8,
		QACCESS_SEQUENTIAL = 16,
		QACCESS_READ_SEQUENTIAL = (QACCESS_READ | QACCESS_SEQUENTIAL),
		QACCESS_WRITE_SEQUENTIAL = (QACCESS_WRITE | QACCESS_SEQUENTIAL)
	};

	enum qFileSeekType
	{
		QSEEK_SET,
		QSEEK_CUR,
		QSEEK_END
	};

	class qFileDevice;
	class qFileOp;
	class qFileSystem;

	class qFile : public qNode<qFile>
	{
	public:
		enum State
		{
			STATE_NONE,
			STATE_OPENING,
			STATE_OPENED,
			STATE_CLOSING,
			STATE_CLOSED
		};

		qFileDevice* mDevice;
		qFileAccessType mAccessType;
		qMutex mFileHandleMutex;
		void* mFileHandle;
		qMutex mStateMutex;
		State mOpenState;
		State mCloseState;
		int mNumAsyncOps;
		qFileOp* mAsyncCloseOp;
		char mFilename[260];
	};

	class qFileOpList : public qNode<qFileOpList>
	{
	public:
		qFileSystem* mFileSystem;
		qEvent mEvent;
		qMutex mMutex;
		qList<qFileOp> mQueuedOps[3];
		qList<qFileOp> mExecutingOps;
		qList<qFileOp> mDoneOps;

		/* Constructor, Destructor */

		qFileOpList(const char* name) { SDK_CALL_FUNC(void, 0x161300, void*, const char*)(this, name); }
		~qFileOpList() { SDK_CALL_FUNC(void, 0x163AB0, void*)(this); }

		/* Functions */

		qFileOp* Completed(qFileOp* file_op) { return SDK_CALL_FUNC(qFileOp*, 0x169A70, void*, qFileOp*)(this, file_op); }
		void Queue(qFileOp* file_op, int priority) { SDK_CALL_FUNC(void, 0x1795F0, void*, qFileOp*, int)(this, file_op, priority); }
	};

	class qFileDevice : public qNode<qFileDevice>
	{
	public:
		enum Casing
		{
			CASE_INSENSITIVE,
			CASE_SENSITIVE
		};

		qFileSystem* mFileSystem;
		const char* mName;
		u32 mNameHash;
		int mSupportedAccessModes;
		int mMaxOpenFiles;
		Casing mCaseSensitive;
		qList<qFileOpList> mFileOpLists;
		qMutex mMutex;
		qList<qFile> mOpenFiles;
		qList<qFile> mClosedFiles;

		/* Virtual Functions */

		virtual ~qFileDevice() {}
		virtual void Mount() = 0;
		virtual void Unmount() = 0;
		virtual void QueueFileOp(qFileOp* file_op, int priority) = 0;
		virtual s64 GetFreeDiskSpace(const char* base_directory) = 0;
		virtual s64 FindFilesAndDirs(qList<qString>* files, const char* initial_directory, bool recursive, qList<qString>* file_patterns, qList<qString>* dir_patterns) = 0;
		virtual bool DirectoryExists(const char* directory) = 0;
		virtual bool CreateDirectoryA(const char* directory) = 0;
		virtual bool DeleteDirectory(const char* directory) = 0;
		virtual bool FilenameExists(const char* filename) = 0;
		virtual s64 GetFilenameSize(const char* filename) = 0;
		virtual u64 GetFilenameTime(const char* filename) = 0;
		virtual bool SetFilenameTime(const char* filename, u64 modification_time) = 0;
		virtual bool GetFilenameReadOnly(const char* filename) = 0;
		virtual bool SetFilenameReadOnly(const char* filename, bool make_read_only) = 0;
		virtual bool DeleteFilename(const char* filename) = 0;
		virtual bool RenameFilename(const char* src_filename, const char* dest_filename) = 0;
		virtual bool FileOpen(qFile* file, bool warn_if_fail) = 0;
		virtual bool FileClose(qFile* file) = 0;
		virtual s64 GetFilePosition(qFile* file) = 0;
		virtual s64 GetFileSize(qFile* file) = 0;
		virtual s64 FileGetDiskPosSortKey(qFile* file) = 0;
		virtual bool FileFlush(qFile* file) = 0;
		virtual bool FileSeek(qFile* file, qFileSeekType type, s64 offset) = 0;
		virtual s64 FileRead(qFile* file, void* buffer, s64 num_bytes) = 0;
		virtual s64 FileWrite(qFile* file, const void* buffer, s64 num_bytes, bool* not_enough_space) = 0;
	};

	//-------------------------------------------------------------------
	// File Functions
	//-------------------------------------------------------------------

	SDK_SINLINE qFile* qOpen(const char* filename, qFileAccessType access_type, bool warn_if_fail = 0) {
		return SDK_CALL_FUNC(qFile*, 0x188440, const char*, qFileAccessType, bool)(filename, access_type, warn_if_fail);
	}

	SDK_SINLINE void qClose(qFile* file) { SDK_CALL_FUNC(void, 0x182160, qFile*)(file); }

	SDK_SINLINE s64 qGetFileSize(qFile* file) { return SDK_CALL_FUNC(s64, 0x184510, qFile*)(file); }

	SDK_SINLINE s64 qRead(qFile* file, void* buffer, s64 num_bytes, s64 seek_offset = 0, qFileSeekType seek_type = QSEEK_CUR) {
		return SDK_CALL_FUNC(s64, 0x1896B0, qFile*, void*, s64, s64, qFileSeekType)(file, buffer, num_bytes, seek_offset, seek_type);
	}

	SDK_SINLINE char* qReadEntireFile(const char* filename, s64* loaded_size = 0, qMemoryPool* memory_pool = 0, u64 allocation_params = 0, char* name = 0) {
		return SDK_CALL_FUNC(char*, 0x189D50, const char*, s64*, qMemoryPool*, u64, char*)(filename, loaded_size, memory_pool, allocation_params, name);
	}

	SDK_SINLINE s64 qWrite(qFile* file, const void* buffer, s64 num_bytes, s64 seek_offset = 0, qFileSeekType seek_type = QSEEK_CUR, bool* not_enough_space = 0) {
		return SDK_CALL_FUNC(s64, 0x18CE50, qFile*, const void*, s64, s64, qFileSeekType, bool*)(file, buffer, num_bytes, seek_offset, seek_type, not_enough_space);
	}

	SDK_SINLINE void qDeleteFile(const char* filename) { SDK_CALL_FUNC(void, 0x183250, const char*)(filename); }
}