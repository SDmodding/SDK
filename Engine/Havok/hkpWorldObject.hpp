#pragma once

class hkpWorldObject
{
public:
	UFG_PAD(0x10);

	void* m_world;
	uintptr_t m_userData;

	UFG_PAD(0xA8);

	template <typename T, uintptr_t O>
	T* GetUserDataPointer()
	{
		if (!m_userData)
			return nullptr;

		return *reinterpret_cast<T**>(m_userData + O);
	}
};