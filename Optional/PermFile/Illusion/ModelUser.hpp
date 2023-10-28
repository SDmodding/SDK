#pragma once

namespace Illusion
{
	struct __declspec(align(8)) ModelUser_t
	{
		int64_t m_SoftBodyDataOffset;
		uint32_t m_HasSoftBodyInfo;
	};
}