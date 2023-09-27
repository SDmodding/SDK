#pragma once

namespace UFG
{
	namespace StreamResourceLoader
	{
		class CLoadedFile
		{
		public:
			UFG_PAD(0x20);

			DataStreamer::STREAM_STATE meState;
			void* mfnCallback;
			void* mCallbackParam;
			qString mFilename;
			void* mData;
			unsigned int mDataSize;
			unsigned int mAllocFlags;
			void* mpPool;
			void* mfnChunkFilter;

			CLoadedFile() { }
			CLoadedFile(const char* m_FileName)
			{
				reinterpret_cast<void(__fastcall*)(CLoadedFile*, const char*)>(UFG_RVA(0x226DF0))(this, m_FileName);
			}

			bool LoadInternal()
			{
				return reinterpret_cast<bool(__fastcall*)(CLoadedFile*)>(UFG_RVA(0x22ACF0))(this);
			}

			void UnloadInternal()
			{
				reinterpret_cast<void(__fastcall*)(CLoadedFile*)>(UFG_RVA(0x22EB60))(this);
			}
		}; 
		
		bool LoadResourceFile(const char* p_FileName, CMemoryPool* p_MemoryPool = nullptr, uint32_t p_AllocFlags = 0, void* p_Filter = nullptr, void* p_Callback = nullptr, void** p_CallbackParam = nullptr)
		{
			return reinterpret_cast<bool(__fastcall*)(const char*, CMemoryPool*, uint32_t, void*, void*, void**)>(UFG_RVA(0x22ADA0))(p_FileName, p_MemoryPool, p_AllocFlags, p_Filter, p_Callback, p_CallbackParam);
		}
	}
}