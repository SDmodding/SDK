#pragma once

namespace UFG
{
	class StreamResourceLoader
	{
	public:
		struct LoadedFile : public qNodeRB<LoadedFile>
		{
			enum STATE
			{
				STATE_LOADING,
				STATE_LOADED,
				STATE_UNKNOWN,
				STATE_ERROR
			};

			STATE meState;
			void(__fastcall* mfnCallback)(const char*, bool, void*);
			void* mCallbackParam;
			qString mFilename;
			void* mData;
			u32 mDataSize;
			u32 mAllocFlags;
			qMemoryPool* mpPool;
			bool(__fastcall* mfnChunkFilter)(qChunk*);

			LoadedFile(const char* filename) { SDK_CALL_FUNC(void, 0x226DF0, void*, const char*)(this, filename); }
		};

		/* Static Functions */

		SDK_SINLINE u32 Load(void* buffer, u32 num_bytes, const char* debug_identifier = 0, StreamerMetrics::DATA_TYPE end_data_type = StreamerMetrics::DATA_UNKNOWN, bool(__fastcall* fnFilter)(qChunk*) = 0) {
			return SDK_CALL_FUNC(u32, 0x22A8C0, void*, u32, const char*, StreamerMetrics::DATA_TYPE, decltype(fnFilter))(buffer, num_bytes, debug_identifier, end_data_type, fnFilter);
		}

		SDK_SINLINE bool LoadInternal(LoadedFile* loaded_file) { return SDK_CALL_FUNC(bool, 0x22ACF0, LoadedFile*)(loaded_file); }

		SDK_SINLINE bool LoadResourceFile(const char* filename, qMemoryPool* pool = 0, u32 alloc_flags = 0, bool(__fastcall* filter)(qChunk*) = 0, void(__fastcall* callback)(const char*, bool, void*) = 0, void* callbackParam = 0) {
			return SDK_CALL_FUNC(bool, 0x22ADA0, const char*, qMemoryPool*, u32, decltype(filter), decltype(callback), void*)(filename, pool, alloc_flags, filter, callback, callbackParam);
		}

		SDK_SINLINE void OnVRAMMove(void* buffer, u32 num_bytes) { SDK_CALL_FUNC(void, 0x22BB60, void*, u32)(buffer, num_bytes); }

		SDK_SINLINE void PostMove(void* buffer, u32 num_bytes) { SDK_CALL_FUNC(void, 0x22C240, void*, u32)(buffer, num_bytes); }
		SDK_SINLINE void PreMove(void* buffer, u32 num_bytes) { SDK_CALL_FUNC(void, 0x22C2D0, void*, u32)(buffer, num_bytes); }

		SDK_SINLINE void ResetResourceTimings() { SDK_CALL_FUNC(void, 0x22CEF0)(); }

		SDK_SINLINE void UnloadInternal(LoadedFile* loaded_file) { SDK_CALL_FUNC(void, 0x22EB60, LoadedFile*)(loaded_file); }

		SDK_SINLINE bool UnloadResourceFile(const char* filename) { return SDK_CALL_FUNC(bool, 0x22EC60, const char*)(filename); }
	};
}