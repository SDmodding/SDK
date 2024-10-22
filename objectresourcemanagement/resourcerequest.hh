#pragma once

namespace UFG
{
	class MeshResourceLoader;
	class PreloadRequest;
	class PedSpawningInfo;
	class TrueCrowdResource;

	class ResourceRequest : public qNode<ResourceRequest>
	{
	public:
		enum eLoadStatus : s32 {};

		enum Type : s32
		{
			Texture,
			Model,
			NumTypes
		};

		qSymbol mAssetSymbol;
		eLoadStatus mLoadStatus;
		Type mType;
		TrueCrowdResource* mResource;
		qArray<MeshResourceLoader*> mInstances;
		qArray<PreloadRequest*> mPreloads;
		qArray<PedSpawningInfo*> mProxies;
		qSymbolUC* mModelNames;
		u32 mNumModels;
		u32 mPriorityRefCounts[5];
		u32 mLastReferencedFrame;
		DataStreamer::Handle mDataStreamerHandle;
		char mAssetName[48];
	};
	SDK_ASSERT_SIZEOF(ResourceRequest, 0xE0);
}