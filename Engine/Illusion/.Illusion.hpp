//=============================================================================
// 
// Description:		Main include file that includes all necessary
//					Illusion classes/structs/funcs...
// 
//=============================================================================
#pragma once

#include "Enums.hpp"
#include "Classes.hpp"
#include "Engine.hpp"
#include "RenderThreadManager.hpp"
#include "Resources.hpp"
#include "StateSystem.hpp"

// Functions
namespace Illusion
{
	__inline CTarget* CreateTarget(CreateTargetParams_t* p_Params)
	{
		return reinterpret_cast<CTarget*(__fastcall*)(CreateTargetParams_t*)>(UFG_RVA(0x8EA80))(p_Params);
	}

	__inline CTexture* CreateTexture(const char* p_Name, int p_Width, int p_Height, CTexture::eFormat p_Format, CTexture::eFlags p_Flags, int p_NumMips)
	{
		return reinterpret_cast<CTexture*(__fastcall*)(const char*, int, int, CTexture::eFormat p_Format, CTexture::eFlags, int, uint32_t, uint32_t)>(UFG_RVA(0x8EC20))(p_Name, p_Width, p_Height, p_Format, p_Flags, p_NumMips, 0, 0);
	}
}