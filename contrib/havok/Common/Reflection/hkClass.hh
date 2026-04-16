#pragma once

class hkClass
{
public:
	enum FlagValues
	{
		FLAGS_NONE = 0,
		FLAGS_NOT_SERIALIZABLE = 1
	};

	const char* m_name;
	hkClass* m_parent;
	int m_objectSize;
	int m_numImplementedInterfaces;
	class hkClassEnum* m_declaredEnums;
	int m_numDeclaredEnums;
	class hkClassMember* m_declaredMembers;
	int m_numDeclaredMembers;
	const void* m_defaults;
	class hkCustomAttributes* m_attributes;
	hkFlags<FlagValues, u32> m_flags;
	int m_describedVersion;
};