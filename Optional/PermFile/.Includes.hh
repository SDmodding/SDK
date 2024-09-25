//======================================================================================
// 
// Description:		This file contain all needed Perm File related structs and helpers.
// 
//======================================================================================
#pragma once

// UFG
#include "ResourceData.hh"
#include "PropertySet.hh"
#include "SceneryGroup.hh"
#include "UILocalization.hh"
#include "UIScreen.hh"

// Illusion
#include "Illusion/BonePalette.hh"
#include "Illusion/Buffer.hh"
#include "Illusion/Material.hh"
#include "Illusion/Mesh.hh"
#include "Illusion/ModelData.hh"
#include "Illusion/ModelUser.hh"
#include "Illusion/ShaderBinary.hh"
#include "Illusion/StateBlock.hh"
#include "Illusion/Texture.hh"

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
				if (!m_LoadedFromMemory) {
					delete[] m_Data;
				}

				m_Data = nullptr;
			}

			m_Size = 0;

			if (!m_Name.empty()) {
				m_Name.clear();
			}

			if (!m_Resources.empty()) {
				m_Resources.clear();
			}

			m_LoadedFromMemory = false;
		}

		~PermFile_t()
		{
			Cleanup();
		}

		PermFile_t() { }

		UFG::ResourceEntry_t* GetResourceByName(uint32_t p_NameUID)
		{
			for (auto pResource : m_Resources)
			{
				if (pResource->GetData()->m_NameUID == p_NameUID) {
					return pResource;
				}
			}

			return nullptr;
		}

		UFG::ResourceData_t* GetResourceDataByName(uint32_t p_NameUID)
		{
			auto pResource = GetResourceByName(p_NameUID);
			return (pResource ? pResource->GetData() : nullptr);
		}

		void ParseData()
		{
			size_t sOffset = 0;
			while (m_Size > sOffset)
			{
				auto pResourceEntry = reinterpret_cast<UFG::ResourceEntry_t*>(&m_Data[sOffset]);
				if (pResourceEntry->m_TypeUID && pResourceEntry->m_EntrySize[0]) {
					m_Resources.emplace_back(pResourceEntry);
				}

				sOffset += static_cast<size_t>(pResourceEntry->GetEntrySize());
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

			FILE* pFile = nullptr;
			fopen_s(&pFile, p_FilePath, "rb");
			if (!pFile) {
				return false;
			}

			m_Name = p_FilePath;
			{
				size_t sOffset = m_Name.find_last_of("/\\");
				if (sOffset && sOffset != std::string::npos) {
					m_Name.erase(0, sOffset + 1);
				}
				m_Name = m_Name.substr(0, m_Name.find_first_of('.'));
			}

			fseek(pFile, 0, SEEK_END);

			m_Size = static_cast<size_t>(ftell(pFile));
			m_Data = new uint8_t[m_Size];

			fseek(pFile, 0, SEEK_SET);

			size_t sReadSize = fread(m_Data, 1, m_Size, pFile);

			fclose(pFile);

			if (sReadSize != m_Size) {
				return false;
			}

			ParseData();
			return true;
		}
	};
}