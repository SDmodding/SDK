#pragma once

namespace SDK
{
	/* Base Address to main executable 'sdhdship.exe'. */
	inline uptr gBaseAddress = *reinterpret_cast<uptr*>(static_cast<uptr>(__readgsqword(0x60)) + 0x10); // Read ImageBaseAddress from PEB
}