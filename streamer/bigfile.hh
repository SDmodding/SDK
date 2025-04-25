#pragma once

namespace UFG
{
	class BigFileSystem
	{
	public:
		SDK_SINLINE bool LoadBigFileIndex(const char* index_filename, bool load_debug_names = 0) {
			return SDK_CALL_FUNC(char, 0x22AAD0, const char*, bool)(index_filename, load_debug_names);
		}
	};
}