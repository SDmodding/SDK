#pragma once

namespace SDK
{
	/* Base Address to main executable 'sdhdship.exe'. */
	inline uptr gBaseAddress = reinterpret_cast<uptr>(GetModuleHandleA(0));
}