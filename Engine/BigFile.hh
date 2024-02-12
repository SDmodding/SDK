#pragma once

namespace UFG
{
	struct BIGFileSize
	{
		uint32_t load_offset;
		uint32_t compressed_size;
		uint32_t compressed_extra;
		uint32_t uncompressed_size;
	};
}