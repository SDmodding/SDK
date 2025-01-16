#pragma once

namespace Scaleform::Render
{
	class Image;
	class MappedTextureBase;
	class TextureFormat;
	class TextureManager;
	class DepthStencilSurface;

	class ImageBase : public RefCountBaseV<Image, 3>
	{
	public:
	};

	class ImageUpdateSync
	{
	public:
		virtual ~ImageUpdateSync() = 0;
	};

	class ImageUpdateQueue
	{
	public:
		ArrayLH<u64, StatRender_TextureManager_Mem> Queue;
	};


	// TODO: Implement commented code
	class TextureManagerLocks : public RefCountBase<TextureManagerLocks, StatRender_TextureManager_Mem>
	{
	public:
		TextureManager* pManager;
		Lock ImageLock;
		//Mutex TextureMutex;
		//WaitCondition TextureInitWC;
	};

	class Texture : public RefCountBase<Texture, StatRender_TextureManager_Mem>, public ListNode<Texture>
	{
	public:
		enum CreateState : i32
		{
			State_PreCapture,
			State_Valid,
			State_Dead
		};

		Ptr<TextureManagerLocks> pManagerLocks;
		ImageBase* pImage;
		Size<u32> ImgSize;
		CreateState State;
		i8 MipLevels;
		i8 TextureCount;
		u16 Use;
		i8 TextureFlags;
		MappedTextureBase* pMap;
		TextureFormat* pFormat;
	};

	class TextureManager : public RefCountBase<TextureManager, StatRender_TextureManager_Mem>, public ImageUpdateSync
	{
	public:
		struct ServiceCommand : public ThreadCommand
		{
			TextureManager* pManager;
		};

		ServiceCommand ServiceCommandInstance;
		void* RenderThreadId;
		ThreadCommandQueue* pRTCommandQueue;
		Ptr<TextureCache> pTextureCache;
		Ptr<TextureManagerLocks> pLocks;
		ImageUpdateQueue ImageUpdates;
		ArrayLH<TextureFormat*> TextureFormats;
		List<Texture> Textures;
		List<Texture> TextureInitQueue;
		List<DepthStencilSurface> DepthStencilInitQueue;
	};
}