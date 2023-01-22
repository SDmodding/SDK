#pragma once

struct SkookumPwnerFile_t
{
	unsigned char* m_FileData = 0;
	uintptr_t m_FileOffset = 0;
	uint32_t m_FileSize = 0;

	struct ScriptData_t
	{
		uint32_t m_NumberOfTypedClasses = 0;
		uint32_t m_NumberOfInvokableClasses = 0;
		uint32_t m_NumberOfUnionClasses = 0;
	};
	ScriptData_t ScriptData;

	SkookumPwnerFile_t(unsigned char* file_data, uint32_t file_size)
	{
		m_FileData = file_data;
		m_FileOffset = reinterpret_cast<uintptr_t>(file_data);
		m_FileSize = file_size;
	}

#pragma pack(push)
#pragma pack(1)
	struct FileHeader_t
	{
		uint32_t m_AllocBuffer;				// 0x0
		uint32_t m_CompileBinaryID;			// 0x4
		uint32_t m_FolderChecksum;			// 0x8
		uint32_t m_FileChecksum;			// 0xC
		uint32_t m_LinearAllocBytes;		// 0x10
		uint32_t m_DebugLinearAllocBytes;	// 0x14
		uint32_t m_NumberOfClasses;			// 0x18
	};

	struct ClassHierData_t
	{
		uint32_t m_ClassNameID;			// 0x0
		uint32_t m_ClassFlags;			// 0x4
		uint16_t m_NumberOfSubclasses;	// 0x8
	};
#pragma pack(pop)

	FileHeader_t* GetScriptHeader()
	{
		return reinterpret_cast<FileHeader_t*>(m_FileData);
	}

	bool SetClassHierOffset()
	{
		if (!m_FileData)
			return false;

		m_FileOffset = reinterpret_cast<uintptr_t>(m_FileData) + sizeof(FileHeader_t);
		return true;
	}

	void AssignClassHier()
	{
		ClassHierData_t* m_ClassHier = reinterpret_cast<ClassHierData_t*>(m_FileOffset);
		m_FileOffset += sizeof(ClassHierData_t);

		for (uint16_t i = 0; m_ClassHier->m_NumberOfSubclasses > i; ++i)
			AssignClassHier();
	}

	bool Initialize()
	{
		if (!SetClassHierOffset())
			return false;

		AssignClassHier();

		ScriptData.m_NumberOfInvokableClasses	= *reinterpret_cast<uint32_t*>(m_FileOffset); m_FileOffset += sizeof(uint32_t);
		ScriptData.m_NumberOfTypedClasses		= *reinterpret_cast<uint32_t*>(m_FileOffset); m_FileOffset += sizeof(uint32_t);
		ScriptData.m_NumberOfUnionClasses		= *reinterpret_cast<uint32_t*>(m_FileOffset); m_FileOffset += sizeof(uint32_t);

		// Need to parse those classes to get at another step of decompilation...

		return true;
	}
};