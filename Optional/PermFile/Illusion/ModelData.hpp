#pragma once

namespace Illusion
{
	struct ModelData_t : UFG::ResourceData_t // TypeUID: 0x6DF963B3 || ChunkUID: 0xA2ADCD77
	{
		struct Handle_t
		{
			UFG_PAD(0x18);

			uint32_t m_NameUID = 0x0;

			UFG_PAD(0x4);
		};

		float m_AABBMin[3];
		uint32_t m_NumPrims;
		float m_AABBMax[3];

		UFG_PAD(0x4);

		Handle_t m_MaterialTableHandle;
		Handle_t m_BonePaletteHandle;

		int64_t m_MeshOffset;
		uint32_t m_NumMeshes;

		UFG_PAD(0x4);

		int64_t m_ModelUserOffset;

		UFG_PAD(0x4);

		uint32_t m_LastUsedFrameNum;

		UFG_PAD(0x4);

		void* m_MemoryPool = nullptr;
		Handle_t m_MorphTargetsHandle;
		Handle_t m_LocatorsHandle;

		Mesh_t* GetMesh(uint32_t p_Index)
		{
			uintptr_t* m_TableOffset = reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(&m_MeshOffset) + m_MeshOffset);
			uintptr_t m_MeshTable = (reinterpret_cast<uintptr_t>(m_TableOffset) + *m_TableOffset);
			return reinterpret_cast<Mesh_t*>(m_MeshTable + (static_cast<uintptr_t>(p_Index) * 0x110));
		}
	};
	typedef ModelData_t Model_t;
}