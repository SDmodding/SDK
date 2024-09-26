//=============================================================================
// 
// Description:		Main include file that includes all necessary
//					Illusion classes/structs/funcs...
// 
//=============================================================================
#pragma once

#include "Enums.hh"
#include "StateSystem.hh"

#include "VertexDecl/.VertexDecl.hh"
#include "Classes/.Classes.hh"

#include "Engine.hh"
#include "Factory.hh"
#include "RenderThreadManager.hh"
#include "Resources.hh"

// Functions
namespace Illusion
{
	UFG_STATIC_INLINE Target* CreateTarget(CreateTargetParams* p_Params)
	{
		return reinterpret_cast<Target*(__fastcall*)(CreateTargetParams*)>(UFG_RVA(0x8EA80))(p_Params);
	}

	UFG_STATIC_INLINE Texture* CreateTexture(const char* p_Name, int p_Width, int p_Height, Texture::eFormat p_Format, Texture::eFlags p_Flags, int p_NumMips)
	{
		return reinterpret_cast<Texture*(__fastcall*)(const char*, int, int, Texture::eFormat p_Format, Texture::eFlags, int, uint32_t, uint32_t)>(UFG_RVA(0x8EC20))(p_Name, p_Width, p_Height, p_Format, p_Flags, p_NumMips, 0, 0);
	}
}