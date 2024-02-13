#pragma once

class hkpWorldObject
{
public:
	UFG_PAD(0x10);

	void* m_world;
	uintptr_t m_userData;

	UFG_PAD(0xA8);

	// ~ Only use when you know what are you doing!
	template <typename T>
	T* GetSimComponent()
	{
		if (!m_userData) {
			return nullptr;
		}

		return *reinterpret_cast<T**>(m_userData + 0x18);
	}

	template <typename T, uintptr_t O>
	T* GetUserDataPointer()
	{
		if (!m_userData) {
			return nullptr;
		}

		return *reinterpret_cast<T**>(m_userData + O);
	}
};