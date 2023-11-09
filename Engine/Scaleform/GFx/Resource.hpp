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
			ResourceLibBase* pLib;
		};
	}
}