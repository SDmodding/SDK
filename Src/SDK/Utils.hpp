#pragma once

namespace SDK
{
	namespace Utils
	{
        long long m_GlobalPropertiesSize = 0;
        void* m_GlobalProperties = nullptr;
        void* GetGlobalProperties()
        {
            if (!m_GlobalProperties)
                m_GlobalProperties = UFG::StreamFileWrapper::ReadEntireFile("Data\\Global\\PropertySets\\globalproperties.bin", &m_GlobalPropertiesSize);

            return m_GlobalProperties;
        }

        void DumpCharacters()
        {
            struct Dump_t
            {
                std::string m_Name;
                unsigned int m_Hash;

                Dump_t(std::string name, unsigned int hash)
                {
                    m_Name = name;
                    m_Hash = hash;
                }
            };

            std::vector<Dump_t> m_Dump;

            GetGlobalProperties();
            for (long long a = 0; m_GlobalPropertiesSize > a; ++a)
            {
                char* m_Name = &reinterpret_cast<char*>(m_GlobalProperties)[a];

                char* m_Find = strstr(m_Name, "object-physical-character");
                if (!m_Find || m_Find[-1] == 'T') continue;

                for (long long x = a - 5; x != 0; --x)
                {
                    char* m_ShorterName = &reinterpret_cast<char*>(m_GlobalProperties)[x];
                    if (!strstr(m_ShorterName, "Tobject")) continue;

                    bool m_ContainsType = false;
                    std::string m_Type = "-character";
                    int m_TypeSizeMax = static_cast<int>(m_Type.size()) - 3;
                    for (int y = 0; m_TypeSizeMax > y; ++y)
                    {
                        if (strstr(m_ShorterName, &m_Type[0]))
                        {
                            m_ContainsType = true;
                            break;
                        }

                        m_Type.pop_back();
                    }
                    if (!m_ContainsType) break;

                    unsigned int m_Hash = *reinterpret_cast<unsigned int*>(reinterpret_cast<uintptr_t>(m_ShorterName) - 0x1B);

                    bool m_HashExist = false;
                    for (auto i : m_Dump)
                    {
                        if (i.m_Hash == m_Hash)
                        {
                            m_HashExist = true;
                            break;
                        }
                    }

                    if (!m_HashExist)
                        m_Dump.emplace_back(Dump_t(m_Find, m_Hash));
                    break;
                }
            }

            std::sort(m_Dump.begin(), m_Dump.end(), [](const Dump_t& lhs, const Dump_t& rhs) { return lhs.m_Name < rhs.m_Name; });

            FILE* m_File = nullptr;
            fopen_s(&m_File, "dbg\\characters.h", "w");
            if (m_File)
            {
                char m_FileOutput[128];

                for (auto i : m_Dump)
                {
                    if (26 > i.m_Name.size()) continue;

                    int m_Size = sprintf_s(m_FileOutput, sizeof(m_FileOutput), "#define Character_%s 0x%X\n", &i.m_Name[26], i.m_Hash);
                    if (strstr(m_FileOutput, "-")) continue;

                    fwrite(m_FileOutput, 1, m_Size, m_File);
                }

                // Array
                fwrite(m_FileOutput, 1, sprintf_s(m_FileOutput, sizeof(m_FileOutput), "unsigned int m_IDs[] = { "), m_File);

                for (auto i : m_Dump)
                {
                    if (26 > i.m_Name.size()) continue;

                    int m_Size = sprintf_s(m_FileOutput, sizeof(m_FileOutput), "Character_%s, ", &i.m_Name[26]);
                    if (strstr(m_FileOutput, "-")) continue;

                    fwrite(m_FileOutput, 1, m_Size, m_File);
                }

                fwrite(m_FileOutput, 1, sprintf_s(m_FileOutput, sizeof(m_FileOutput), "static_cast<unsigned int>(-1) };"), m_File);

                fclose(m_File);
            }
        }

        void DumpVehicles()
        {
            struct Dump_t
            {
                std::string m_Name;
                unsigned int m_Hash;

                Dump_t(std::string name, unsigned int hash)
                {
                    m_Name = name;
                    m_Hash = hash;
                }
            };

            std::vector<Dump_t> m_Dump;

            GetGlobalProperties();
            for (long long a = 0; m_GlobalPropertiesSize > a; ++a)
            {
                char* m_Name = &reinterpret_cast<char*>(m_GlobalProperties)[a];

                char* m_Find = strstr(m_Name, "object-physical-vehicle");
                if (!m_Find || m_Find[-1] == 'T') continue;

                for (long long x = a - 5; x != 0; --x)
                {
                    char* m_ShorterName = &reinterpret_cast<char*>(m_GlobalProperties)[x];
                    if (!strstr(m_ShorterName, "Tobject")) continue;

                    bool m_ContainsType = false;
                    std::string m_Type = "-vehicle";
                    int m_TypeSizeMax = static_cast<int>(m_Type.size()) - 3;
                    for (int y = 0; m_TypeSizeMax > y; ++y)
                    {
                        if (strstr(m_ShorterName, &m_Type[0]))
                        {
                            m_ContainsType = true;
                            break;
                        }

                        m_Type.pop_back();
                    }
                    if (!m_ContainsType) break;

                    unsigned int m_Hash = *reinterpret_cast<unsigned int*>(reinterpret_cast<uintptr_t>(m_ShorterName) - 0x1B);
                   
                    bool m_HashExist = false;
                    for (auto i : m_Dump)
                    {
                        if (i.m_Hash == m_Hash)
                        {
                            m_HashExist = true;
                            break;
                        }
                    }

                    if (!m_HashExist)
                        m_Dump.emplace_back(Dump_t(m_Find, m_Hash));
                    break;
                }
            }

            std::sort(m_Dump.begin(), m_Dump.end(), [](const Dump_t& lhs, const Dump_t& rhs) { return lhs.m_Name < rhs.m_Name; });

            FILE* m_File = nullptr;
            fopen_s(&m_File, "dbg\\vehicles.h", "w");
            if (m_File)
            {
                char m_FileOutput[128];

                for (auto i : m_Dump)
                {
                    if (24 > i.m_Name.size()) continue;

                    int m_Size = sprintf_s(m_FileOutput, sizeof(m_FileOutput), "#define Vehicle_%s 0x%X\n", &i.m_Name[24], i.m_Hash);
                    if (strstr(m_FileOutput, "-")) continue;

                    fwrite(m_FileOutput, 1, m_Size, m_File);
                }

                // Array
                fwrite(m_FileOutput, 1, sprintf_s(m_FileOutput, sizeof(m_FileOutput), "unsigned int m_IDs[] = { "), m_File);

                for (auto i : m_Dump)
                {
                    if (24 > i.m_Name.size()) continue;

                    int m_Size = sprintf_s(m_FileOutput, sizeof(m_FileOutput), "Vehicle_%s, ", &i.m_Name[24]);
                    if (strstr(m_FileOutput, "-")) continue;

                    fwrite(m_FileOutput, 1, m_Size, m_File);
                }

                fwrite(m_FileOutput, 1, sprintf_s(m_FileOutput, sizeof(m_FileOutput), "static_cast<unsigned int>(-1) };"), m_File);

                fclose(m_File);
            }
        }

        void DumpWeapons()
        {
            struct Dump_t
            {
                std::string m_Name;
                unsigned int m_Hash;

                Dump_t(std::string name, unsigned int hash)
                {
                    m_Name = name;
                    m_Hash = hash;

                    for (size_t i = 0; m_Name.size() > i; ++i)
                    {
                        if (m_Name[i] == '-')
                            m_Name[i] = '_';
                    }
                }
            };

            std::vector<Dump_t> m_Dump;

            GetGlobalProperties();
            for (long long a = 0; m_GlobalPropertiesSize > a; ++a)
            {
                char* m_Name = &reinterpret_cast<char*>(m_GlobalProperties)[a];

                char* m_Find = strstr(m_Name, "object-physical-weapon");
                if (!m_Find || m_Find[-1] == 'T') continue;

                for (long long x = a - 5; x != 0; --x)
                {
                    char* m_ShorterName = &reinterpret_cast<char*>(m_GlobalProperties)[x];
                    if (!strstr(m_ShorterName, "Tobject")) continue;

                    bool m_ContainsType = false;
                    std::string m_Type = "-weapon";
                    int m_TypeSizeMax = static_cast<int>(m_Type.size()) - 3;
                    for (int y = 0; m_TypeSizeMax > y; ++y)
                    {
                        if (strstr(m_ShorterName, &m_Type[0]))
                        {
                            m_ContainsType = true;
                            break;
                        }

                        m_Type.pop_back();
                    }
                    if (!m_ContainsType) break;

                    unsigned int m_Hash = *reinterpret_cast<unsigned int*>(reinterpret_cast<uintptr_t>(m_ShorterName) - 0x1B);

                    bool m_HashExist = false;
                    for (auto i : m_Dump)
                    {
                        if (i.m_Hash == m_Hash)
                        {
                            m_HashExist = true;
                            break;
                        }
                    }

                    if (!m_HashExist)
                        m_Dump.emplace_back(Dump_t(m_Find, m_Hash));
                    break;
                }
            }

            std::sort(m_Dump.begin(), m_Dump.end(), [](const Dump_t& lhs, const Dump_t& rhs) { return lhs.m_Name < rhs.m_Name; });

            FILE* m_File = nullptr;
            fopen_s(&m_File, "dbg\\weapon.h", "w");
            if (m_File)
            {
                char m_FileOutput[128];

                for (auto i : m_Dump)
                {
                    if (23 > i.m_Name.size()) continue;

                    int m_Size = sprintf_s(m_FileOutput, sizeof(m_FileOutput), "#define Weapon_%s 0x%X\n", &i.m_Name[23], i.m_Hash);
                    fwrite(m_FileOutput, 1, m_Size, m_File);
                }

                // Array
                fwrite(m_FileOutput, 1, sprintf_s(m_FileOutput, sizeof(m_FileOutput), "unsigned int m_IDs[] = { "), m_File);

                for (auto i : m_Dump)
                {
                    if (23 > i.m_Name.size()) continue;

                    int m_Size = sprintf_s(m_FileOutput, sizeof(m_FileOutput), "Weapon_%s, ", &i.m_Name[23]);
                    fwrite(m_FileOutput, 1, m_Size, m_File);
                }

                fwrite(m_FileOutput, 1, sprintf_s(m_FileOutput, sizeof(m_FileOutput), "static_cast<unsigned int>(-1) };"), m_File);

                fclose(m_File);
            }
        }
	}
}