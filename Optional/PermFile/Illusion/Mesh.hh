#pragma once

namespace Illusion
{
	struct Mesh_t
	{
		UFG::ResourceHandle_t m_MaterialHandle;
		UFG::ResourceHandle_t m_VertexDeclHandle;
		UFG::ResourceHandle_t m_IndexBufferHandle;
		UFG::ResourceHandle_t m_VertexBufferHandles[4];
		int m_PrimType = 0;
		int m_IndexStart = 0;
		uint32_t m_NumPrims = 0;

		UFG_PAD(0x4);

		const char* m_Description = nullptr;
	};
}