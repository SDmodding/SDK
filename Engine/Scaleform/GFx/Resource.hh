#pragma once

namespace Scaleform
{
	namespace GFx
	{
		class ResourceLibBase : public RefCountBase<ResourceLibBase, 2>
		{
		public:

		};

		class ResourceLib : public RefCountBase<ResourceLib, 2>
		{
		public:
			class ResourceWeakLib* pWeakLib;
			HashSetBase* PinSet;
			bool DebugFlag;
		};

		class ResourceWeakLib : public ResourceLibBase
		{
		public:
			ResourceLib* pStrongLib;
			Lock ResourceLock;
			HashSetBase* Resources;
			MemoryHeap* pImageHeap;
		};

		class Resource
		{
		public:
			void* vfptr;
			int RefCount;

			UFG_PAD_ALIGN(0x4);

			ResourceLibBase* pLib;

			UFG_INLINE void AddRef()
			{
				_InterlockedIncrement(reinterpret_cast<volatile long*>(&RefCount));
			}

			UFG_INLINE void Release()
			{
				reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x8FE6A0))(this);
			}
		};
		UFG_ASSERT_CLASS(Resource, 0x18);
	}
}