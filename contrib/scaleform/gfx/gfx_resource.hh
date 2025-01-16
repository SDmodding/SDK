#pragma once

namespace Scaleform::GFx
{
	class Resource;

	class FileTypeConstants
	{
	public:
		enum FileFormatType
		{
			File_Unopened,
			File_Unknown,
			File_SWF,
			File_GFX,
			File_JPEG = 10,
			File_PNG = 11,
			File_GIF = 12,
			File_TGA = 13,
			File_DDS = 14,
			File_HDR = 15,
			File_BMP = 16,
			File_DIB = 17,
			File_PFM = 18,
			File_TIFF = 19,
			File_WAVE = 20,
			File_PVR = 21,
			File_ETC = 22,
			File_SIF = 23,
			File_GXT = 24,
			File_GTX = 25,
			File_GNF = 26,
			File_KTX = 27,
			File_NextAvail,
			File_DDSBC = 65533,
			File_MultiFormat = 65534,
			File_Original = 65535
		};
	};

	class ResourceLibBase : public RefCountBase<ResourceLibBase, Stat_Default_Mem>
	{
	public:
	}; 

	class ResourceLib : public RefCountBase<ResourceLib, Stat_Default_Mem>
	{
	public:
		class ResourceSlot;

		class ResourceWeakLib* pWeakLib;
		HashSetUncached<Resource*> PinSet;
		bool DebugFlag;
	};

	class ResourceWeakLib : public ResourceLibBase
	{
	public:
		struct ResourceNode
		{
			enum NodeType
			{
				Node_Resource,
				Node_Resolver
			};

			NodeType Type;

			union 
			{
				ResourceLib::ResourceSlot* pResolver;
				Resource* pResource;
			};
		};

		ResourceLib* pStrongLib;
		Lock ResourceLock;
		HashSet<ResourceNode> Resources;
		Ptr<MemoryHeap> pImageHeap;
	};

	class ResourceKey
	{
	public:
		class KeyInterface
		{
		public:
			virtual ~KeyInterface() = 0;
		};

		KeyInterface* pKeyInterface;
		void* hKeyData;
	};

	class ResourceReport
	{
	public:
		virtual ~ResourceReport() = 0;
	};

	class Resource : public NewOverrideBase<Stat_Default_Mem>
	{
	public:
		AtomicInt<long> RefCount;
		ResourceLibBase* pLib;

		virtual ~Resource() = 0;
		virtual ResourceKey GetKey() = 0;
		virtual u32 GetResourceTypeCode() = 0;
		virtual ResourceReport* GetResourceReport() = 0;
	};
}