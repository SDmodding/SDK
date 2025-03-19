#pragma once

namespace UFG
{
	class qChunkFileSystem
	{
	public:
		/* Static Functions */

		SDK_SINLINE void AddExternalResourceFileReference(u32 filename_uid, qVRAMemoryHandle& handle, void* user_data) {
			SDK_CALL_FUNC(void, 0x166120, u32, qVRAMemoryHandle&, void*)(filename_uid, handle, user_data);
		}

		SDK_SINLINE void AddExternalResourceFileReference(u32 filename_uid, void* memory_location, u64 location_size, void* user_data) {
			SDK_CALL_FUNC(void, 0x166130, u32, void*, u64, void*)(filename_uid, memory_location, location_size, user_data);
		}
	};
}