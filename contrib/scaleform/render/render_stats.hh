#pragma once

namespace Scaleform
{
	enum GStatRenderer
	{
		StatRender_Default = 0x40,
		StatRender_Mem,
		StatRender_MeshStaging_Mem,
		StatRender_RenderPipeline_Mem,
		StatRender_MeshCacheMgmt_Mem,
		StatRender_Context_Mem,
		StatRender_NodeData_Mem,
		StatRender_TreeCache_Mem,
		StatRender_TextureManager_Mem,
		StatRender_MatrixPool_Mem,
		StatRender_Text_Mem,
		StatRender_Font_Mem
	};
}