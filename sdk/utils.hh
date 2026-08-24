#pragma once

namespace SDK
{
	/* Checks if the current executable is valid 'sdhdship.exe' that SDK was written for. */
	SDK_SINLINE bool IsValidExecutable() 
	{
		/* Export directory (name) */
		return *reinterpret_cast<u32*>(SDK_RVA(0x201D59C)) == 0x201E094; 
	}
}

#ifdef D3D_COMPILER_VERSION
	#define SDK_D3DCompile() reinterpret_cast<decltype(&D3DCompile)>(GetProcAddress(GetModuleHandleA(SDK_VAR(const char*, 0x201CAD2)), "D3DCompile"))
#endif