#pragma once

namespace Render
{
	class FXOverride;
}

namespace FX
{
	template <typename T>
	class SharedPointerBase
	{
	public:
		int mReferenceCount;
	};

	template <typename T>
	class SharedPointer
	{
	public:
		T* m_pPointer;

		template <typename T>
		void Set(T* pointer);

		template<>
		void Set(Render::FXOverride* pointer) { SDK_CALL_FUNC(void, 0x1D6220, void*, Render::FXOverride*)(this, pointer); }
	};
}