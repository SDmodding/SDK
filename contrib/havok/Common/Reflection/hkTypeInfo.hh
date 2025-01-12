#pragma once

class hkTypeInfo
{
public:
	const char* m_typeName;
	const char* m_scopedName;
	void(__fastcall* m_finishLoadedObjectFunction)(void*, int);
	void(__fastcall* m_cleanupLoadedObjectFunction)(void*);
	const void* m_vtable;
	u64 m_size;
};