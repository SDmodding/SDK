//======================================================================================
// 
// Description:		This file contain all needed Perm File related structs and helpers.
// 
//======================================================================================
#pragma once

// UFG
#include "ResourceData.hpp"
#include "PropertySet.hpp"
#include "UILocalization.hpp"

// Illusion
#include "Illusion/BonePalette.hpp"
#include "Illusion/Buffer.hpp"
#include "Illusion/Material.hpp"
#include "Illusion/Mesh.hpp"
#include "Illusion/ModelData.hpp"
#include "Illusion/ModelUser.hpp"
#include "Illusion/Texture.hpp"

// Helpers
namespace SDK
{
	struct PermFile_t
	{
		bool m_LoadedFromMemory = false;
		uint8_t* m_Data = nullptr;
		size_t m_Size = 0;

		std::string m_Name; // When loaded from file it contains name of the file.
		std::vector<UFG::ResourceEntry_t*> m_Resources;

		void Cleanup()
		{
			if (m_Data)
			{
				if (!m_LoadedFromMemory)
					delete[] m_Data;

				m_Data = nullptr;
			}

			m_Size = 0;

			if (!m_Name.empty())
				m_Name.clear();

			if (!m_Resources.empty())
				m_Resources.clear();

			m_LoadedFromMemory = false;
		}

		~PermFile_t()
		{
			Cleanup();
		}

		PermFile_t() { }

		UFG::ResourceEntry_t* GetResourceByName(uint32_t p_NameUID)
		{
			for (UFG::ResourceEntry_t* m_Resource : m_Resources)
			{
				UFG::ResourceData_t* m_ResourceData = m_Resource->GetData();
				if (m_ResourceData->m_NameUID == p_NameUID)
					return m_Resource;
			}

			return nullptr;
		}

		UFG::ResourceData_t* GetResourceDataByName(uint32_t p_NameUID)
		{
			UFG::ResourceEntry_t* m_Resource = GetResourceByName(p_NameUID);
			if (m_Resource)
				return m_Resource->GetData();

			return nullptr;
		}

		void ParseData()
		{
			size_t m_Offset = 0;
			while (m_Size > m_Offset)
			{
				UFG::ResourceEntry_t* m_ResourceEntry = reinterpret_cast<UFG::ResourceEntry_t*>(&m_Data[m_Offset]);
				if (m_ResourceEntry->m_TypeUID && m_ResourceEntry->m_EntrySize[0])
					m_Resources.emplace_back(m_ResourceEntry);

				m_Offset += m_ResourceEntry->GetEntrySize();
			}
		}

		bool LoadFromMemory(uint8_t* p_Data, size_t p_Size)
		{
			Cleanup();

			m_LoadedFromMemory = true;
			m_Data = p_Data;
			m_Size = p_Size;
			ParseData();
			
			return (!m_Resources.empty());
		}

		bool LoadFile(const char* p_FilePath)
		{
			Cleanup();

			FILE* m_File = fopen(p_FilePath, "rb");
			if (!m_File)
				return false;

			m_Name = p_FilePath;
			{
				size_t m_Offset = m_Name.find_last_of("/\\");
				if (m_Offset && m_Offset != std::string::npos)
					m_Name.erase(0, m_Offset + 1);
				m_Name = m_Name.substr(0, m_Name.find_first_of('.'));
			}

			fseek(m_File, 0, SEEK_END);

			m_Size = static_cast<size_t>(ftell(m_File));
			m_Data = new uint8_t[m_Size];

			fseek(m_File, 0, SEEK_SET);

			size_t m_ReadRes = fread(m_Data, 1, m_Size, m_File);

			fclose(m_File);

			if (m_ReadRes != m_Size)
				return false;

			ParseData();
			return true;
		}
	};
}