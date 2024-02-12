#pragma once

namespace SDK
{
	namespace Utils
	{
        namespace ActionNode
        {
#ifndef SDK_SD_MINIMAL_BUILD
            const char* GetName(uint32_t m_Hash)
            {
                static std::unordered_map<uint32_t, const char*> m_Map;
                if (m_Map.empty())
                {
                    for (const char* m_Key : UFG::g_ActionNodesDictionary)
                        m_Map[UFG::HashUpper32(m_Key)] = m_Key;
                }

                auto m_It = m_Map.find(m_Hash);
                if (m_It == m_Map.end())
                {
                    static char m_Format[12];
                    sprintf_s(m_Format, sizeof(m_Format), "0x%08X", m_Hash);
                    return m_Format;
                }

                return (*m_It).second;
            }

            std::string ResolvePath(UFG::CActionNode* m_Node)
            {         
                std::string m_Path;

                while (1)
                {
                    m_Path.insert(0, std::string("\\") + GetName(m_Node->mID));
                    m_Node = m_Node->mParent.GetPointer();
                    if (!m_Node)
                        break;
                }

                return m_Path;
            }
#endif
        }

        // Integrity check if SDK can be used on game executable.
        bool IsValidExecutable()
        {
            return (*reinterpret_cast<uint32_t*>(UFG_RVA(0x201D59C)) == 0x201E094); // Export directory (name) - sdhdship.exe
        }
	}
}