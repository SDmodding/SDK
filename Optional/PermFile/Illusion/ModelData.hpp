#pragma once

namespace Illusion
{
	struct ModelData_t : UFG::ResourceData_t
	{
		float m_AABBMin[3];
		uint32_t m_NumPrims;
		float m_AABBMax[3];

		UFG_PAD(0x44);

		uint64_t m_MeshOffset;
		uint32_t m_NumMeshes;

		Mesh_t* GetMesh(uint32_t p_Index)
		{
			uintptr_t* m_TableOffset = reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(&m_MeshOffset) + m_MeshOffset);
			uintptr_t m_MeshTable = (reinterpret_cast<uintptr_t>(m_TableOffset) + *m_TableOffset);
			return reinterpret_cast<Mesh_t*>(m_MeshTable + (static_cast<uintptr_t>(p_Index) * 0x110));
		}
	};
}