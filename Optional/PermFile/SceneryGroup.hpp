#pragma once

namespace UFG
{
	struct SceneryObject_t
	{
		uint32_t m_NameUID;
		uint32_t m_Flags;

		UFG_PAD(0x8);

		ResourceHandle_t m_ModelHandles[2];
		char m_Name[64];
	};

	struct SceneryInstance_t
	{
		uint32_t m_NameUID;
		uint16_t m_TintIndex;
		uint16_t m_HierarchySkip;
		char m_Flags;
		char m_TransparencyState[3];
		int64_t m_ObjectOffset;

		UFG_PAD(0x8);

		float m_LocalWorldMatrix[4][4];

		__inline SceneryObject_t* GetSceneryObject()
		{
			if (!m_ObjectOffset)
				return nullptr;

			return reinterpret_cast<SceneryObject_t*>(reinterpret_cast<uintptr_t>(&m_ObjectOffset) + m_ObjectOffset);
		}
	};

	struct SceneryTintEntry_t
	{
		float m_TintColour[4];
		float m_SITintColour[4];
	};

	struct SceneryGroup_t : ResourceData_t // TypeUID: 0x7480E00B || ChunkUID: 0xF0A07244
	{
		uint16_t m_NumObjects;
		uint16_t m_NumInstances;
		uint16_t m_NumOccluders;
		uint16_t m_NumColours;
		int64_t m_ObjectsOffset;
		int64_t m_InstancesOffset;
		int64_t m_CullInfoOffset;
		int64_t m_OccluderInfoOffset;
		int64_t m_InstanceColoursOffset;
		void* m_RenderComponent;
		float m_AABBMin[3];
		float m_AABBMax[3];
		uint16_t m_SectionCellIndex;
		uint16_t m_SectionVisIndex;
		uint16_t m_SceneryLayer;
		uint16_t m_Flags;

		__inline SceneryObject_t* GetSceneryObjects()
		{
			if (!m_ObjectsOffset)
				return nullptr;

			return reinterpret_cast<SceneryObject_t*>(reinterpret_cast<uintptr_t>(&m_ObjectsOffset) + m_ObjectsOffset);
		}

		__inline SceneryInstance_t* GetSceneryInstances()
		{
			if (!m_InstancesOffset)
				return nullptr;

			return reinterpret_cast<SceneryInstance_t*>(reinterpret_cast<uintptr_t>(&m_InstancesOffset) + m_InstancesOffset);
		}

		__inline SceneryTintEntry_t* GetSceneryTintEntries()
		{
			if (!m_InstanceColoursOffset)
				return nullptr;

			return reinterpret_cast<SceneryTintEntry_t*>(reinterpret_cast<uintptr_t>(&m_InstanceColoursOffset) + m_InstanceColoursOffset);
		}
	};
}