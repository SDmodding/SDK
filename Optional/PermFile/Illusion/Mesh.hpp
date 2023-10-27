#pragma once

namespace Illusion
{
	struct Mesh_t
	{
		struct Handle_t
		{
			UFG_PAD(0x18);

			uint32_t m_NameUID = 0x0;

			UFG_PAD(0x4);
		};

		Handle_t m_MaterialHandle;
		Handle_t m_VertexDeclHandle;
		Handle_t m_IndexBufferHandle;
		Handle_t m_VertexBufferHandles[4];
		int m_PrimType = 0;
		int m_IndexStart = 0;
		uint32_t m_NumPrims = 0;
		uint32_t m_Pad = 0;
		const char* m_Description = nullptr;
	};
}