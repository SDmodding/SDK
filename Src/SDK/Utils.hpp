#pragma once

namespace SDK
{
	namespace Utils
	{
        long long m_SkookumBinarySize = 0;
        void* m_SkookumScriptBinary = nullptr;
        void* GetSkookumScriptBinary()
        {
            if (!m_SkookumScriptBinary)
                m_SkookumScriptBinary = UFG::StreamFileWrapper::ReadEntireFile("Data\\Scripts\\Classes.skoo-bin", &m_SkookumBinarySize);

            return m_SkookumScriptBinary;
        }

        long long m_GlobalPropertiesSize = 0;
        void* m_GlobalProperties = nullptr;
        void* GetGlobalProperties()
        {
            if (!m_GlobalProperties)
                m_GlobalProperties = UFG::StreamFileWrapper::ReadEntireFile("Data\\Global\\PropertySets\\globalproperties.bin", &m_GlobalPropertiesSize);

            return m_GlobalProperties;
        }

        std::map<uint32_t, std::string> GetListOfObjects(uint32_t m_ObjectTypeHash)
        {
            std::map<uint32_t, std::string> m_List;

            std::vector<UFG::qPropertySetResource*> m_PropertyResources = UFG::ResourceInventory::GetContents(UFG::ResourceInventory::Get());

            for (UFG::qPropertySetResource* m_PropertyResource : m_PropertyResources)
            {
                UFG::qPropertySet* m_PropertySet = m_PropertyResource->GetPropertySet();
                UFG::qSymbol* m_ObjectType = m_PropertySet->GetSymbol(UFG::Hash32("ObjectType"));
                if (!m_ObjectType || *m_ObjectType != m_ObjectTypeHash)
                    continue;

                const char* m_ObjectDescription = m_PropertySet->GetString(UFG::Hash32("Description"));
                if (!m_ObjectDescription)
                    continue;

                if (m_ObjectDescription[0] == '$')
                {
                    const char* m_Translation = UFG::UI::GetTranslator()->Translate(&m_ObjectDescription[1]);
                    if (m_Translation)
                        m_ObjectDescription = m_Translation;
                }

                m_List[m_PropertySet->mName] = m_ObjectDescription;
            }

            return m_List;
        }

        void DumpCharacters()
        {
            FILE* m_File = nullptr;
            fopen_s(&m_File, "dbg\\characters.txt", "w");
            if (!m_File)
                return;

            std::map<uint32_t, std::string> m_List = GetListOfObjects(UFG::Hash32("Character"));
            for (auto& m_Pair : m_List)
            {
                char m_FileOutput[128];
                fwrite(m_FileOutput, 1, sprintf_s(m_FileOutput, sizeof(m_FileOutput), "0x%X - '%s'\n", m_Pair.first, &m_Pair.second[0]), m_File);
            }

            fclose(m_File);
        }

        void DumpProps()
        {
            FILE* m_File = nullptr;
            fopen_s(&m_File, "dbg\\props.txt", "w");
            if (!m_File)
                return;

            std::map<uint32_t, std::string> m_List = GetListOfObjects(UFG::Hash32("Prop"));
            for (auto& m_Pair : m_List)
            {
                char m_FileOutput[128];
                fwrite(m_FileOutput, 1, sprintf_s(m_FileOutput, sizeof(m_FileOutput), "0x%X - '%s'\n", m_Pair.first, &m_Pair.second[0]), m_File);
            }

            fclose(m_File);
        }

        void DumpVehicles()
        {
            FILE* m_File = nullptr;
            fopen_s(&m_File, "dbg\\vehicles.txt", "w");
            if (!m_File)
                return;

            std::map<uint32_t, std::string> m_List = GetListOfObjects(UFG::Hash32("Vehicle"));
            for (auto& m_Pair : m_List)
            {
                char m_FileOutput[128];
                fwrite(m_FileOutput, 1, sprintf_s(m_FileOutput, sizeof(m_FileOutput), "0x%X - '%s'\n", m_Pair.first, &m_Pair.second[0]), m_File);
            }

            fclose(m_File);
        }

        void DumpWeapons()
        {
            FILE* m_File = nullptr;
            fopen_s(&m_File, "dbg\\weapons.txt", "w");
            if (!m_File)
                return;

            std::map<uint32_t, std::string> m_List = GetListOfObjects(UFG::Hash32("Weapon"));
            for (auto& m_Pair : m_List)
            {
                char m_FileOutput[128];
                fwrite(m_FileOutput, 1, sprintf_s(m_FileOutput, sizeof(m_FileOutput), "0x%X - '%s'\n", m_Pair.first, &m_Pair.second[0]), m_File);
            }

            fclose(m_File);
        }

        void DumpWardrobeItems()
        {
            std::map<int, std::map<uint32_t, std::string>> m_Data;

            UFG::StoreFrontTracker->LoadStoreData(0);
            UFG::StoreFrontTracker->mProperties.Bind();

            UFG::qPropertyList* m_List = UFG::PropertySet::GetList(UFG::StoreFrontTracker->mProperties.mpPropSet, 0x23C60283);
            for (uint32_t i = 0; m_List->mNumElements > i; ++i)
            {
                uintptr_t* m_Item = reinterpret_cast<uintptr_t*>(m_List->GetValuePtr(0x1A, i));
                if (!m_Item || !*m_Item)
                    continue;

                UFG::qPropertySet* m_ItemSet = reinterpret_cast<UFG::qPropertySet*>(reinterpret_cast<uintptr_t>(m_Item) + *m_Item);

                UFG::qSymbol* m_ItemCategory    = m_ItemSet->GetSymbol(0x543E920D);
                const char* m_ItemName          = m_ItemSet->GetString(0xBEBEBF75);

                const char* m_ItemTranslated    = UFG::UI::GetTranslator()->Translate(&m_ItemName[1]);

                int m_ItemCategoryID    = reinterpret_cast<int(__fastcall*)(UFG::qSymbol*)>(UFG_RVA(0x4B0C00))(m_ItemCategory);

                m_Data[m_ItemCategoryID][m_ItemSet->mName] = (m_ItemTranslated ? m_ItemTranslated : "");
            }

            m_Data = m_Data;

            FILE* m_File = nullptr;
            fopen_s(&m_File, "dbg\\items.h", "w");
            if (m_File)
            {
                char m_FileOutput[128];

                for (auto& m_Category : m_Data)
                {
                    fwrite(m_FileOutput, 1, sprintf_s(m_FileOutput, sizeof(m_FileOutput), "{ %d, {\n", m_Category.first), m_File);

                    for (auto& m_Clothes : m_Category.second)
                    {
                        fwrite(m_FileOutput, 1, sprintf_s(m_FileOutput, sizeof(m_FileOutput), "\t{ 0x%X, \"%s\" },\n", m_Clothes.first, m_Clothes.second.c_str()), m_File);
                    }

                    fwrite(m_FileOutput, 1, sprintf_s(m_FileOutput, sizeof(m_FileOutput), "}},\n"), m_File);
                }
                fclose(m_File);
            }
        }
	}
}