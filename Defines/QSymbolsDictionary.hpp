#pragma once

namespace UFG
{
	// FilePath to 'QSymbolsDictionary.txt'
	bool LoadQSymbolsDictionary(const char* p_FilePath, std::unordered_map<qSymbol, std::string>& p_Map)
	{
		FILE* m_File = fopen(p_FilePath, "r+");
		if (!m_File)
			return false;

		char m_Line[512] = { '\0' };
		while (fgets(m_Line, sizeof(m_Line), m_File))
		{
			if (m_Line[1] != 'x' || m_Line[10] != ' ')
				continue;

			qSymbol m_Symbol = static_cast<qSymbol>(strtoul(m_Line, 0, 0x10));
			char* m_Name = &m_Line[11];
			size_t m_NameLength = strlen(m_Name);
			if (m_Name[m_NameLength - 1] == '\n')
				m_Name[m_NameLength - 1] = '\0';

			p_Map[m_Symbol] = m_Name;
		}

		return true;
	}
}