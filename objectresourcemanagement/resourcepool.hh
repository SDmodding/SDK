#pragma once

namespace UFG
{
	class EntityTypeState;

	class ResourceUser
	{
	public:
		enum Type
		{
			MeshLoader,
			Preload,
			Proxy
		};

		Type mType;

		union
		{
			MeshResourceLoader* mMeshLoader;
			PreloadRequest* mPreload;
			PedSpawningInfo* mProxy;
		};
	};


	class ResourcePriorityBucket
	{
	public:
		qSymbol mName;
		u32 mPriority;
		int mReserveSize[2];
		int mMaxSize[2];
		u32 mMemoryUsage[3][2];
		ResourcePriorityBucket* mpParent;
		qArray<ResourcePriorityBucket*> mChildren;
		qArray<ResourceRequest*> mResourceRequests;
	};

	class ResourcePool
	{
	public:
		enum ExpansionReason
		{
			InitialInstance,
			MoreParts,
			NoExpansion
		};

		struct ContractionSortData
		{
			PreloadRequest* mResourceRequest;
			bool mExpanded;
			bool mHasReducableModels;
			f32 mVarietyRatio;
			u32 mSpawnedReferences;
			u32 mProxyReferences;
			u32 mPreloadReferences;
			u32 mTextureMemory;
			u32 mMeshMemory;
		};

		qArray<ResourceRequest*> mQueued;
		qArray<ResourceRequest*> mLoading;
		qArray<ResourceRequest*> mLoaded;
		ResourcePriorityBucket* mMasterBucket;
		ResourcePriorityBucket* mUnReferencedBucket;
		ResourcePriorityBucket* mReservedBucket;
		ResourcePriorityBucket* mCriticalBucket;
		ResourcePriorityBucket* mHighBucket;
		ResourcePriorityBucket* mLowBucket;
		qList<ResourceRequest> mRequestList;
		qArray<EntityTypeState*> mEntityStates;
		u32 mNumPreloadBuckets;
		qArray<PreloadRequest*>* mPreloadBuckets;
		qList<PreloadRequest> mEmptyRequestList;
		u32 mMaxModelMemory;
		u32 mMaxTextureMemory;
		u32 mAmbientModelMemoryLimit;
		u32 mAmbientTextureMemoryLimit;
		f32 mFragmentationReservePercentage;
		bool mResourceUsageStable;
		bool mStreamerStalled;
		bool mDirty;
		StreamingMemory::DATA_TYPE mStreamingPoolId;
		StreamingMemory::DATA_TYPE mStreamingPoolIdVRam;

		/* Functions */

		bool BasicAmbienceLoaded() { return SDK_CALL_FUNC(bool, 0x438D20, void*)(this); }
		bool CanSpawnAmbient(TrueCrowdSet* trueCrowdSet, bool preloadedOnly) { return SDK_CALL_FUNC(bool, 0x4398A0, void*, TrueCrowdSet*, bool)(this, trueCrowdSet, preloadedOnly); }
		bool ContractAmbientModel(TrueCrowdModel* model) { return SDK_CALL_FUNC(bool, 0x43A7C0, void*, TrueCrowdModel*)(this, model); }
		void ContractAmbientModels(u32 numModels) { SDK_CALL_FUNC(void, 0x43AAB0, void*, u32)(this, numModels); }
		bool ExpandAmbience() { return SDK_CALL_FUNC(bool, 0x43C300, void*)(this); }
		void FlushResources(bool forceFlush) { SDK_CALL_FUNC(void, 0x43CE40, void*, bool)(this, forceFlush); }

		bool GetContractableAmbientOptions(u32 pool, ContractionSortData* candidates, u32& candidateCount) {
			return SDK_CALL_FUNC(bool, 0x43D530, void*, u32, ContractionSortData*, u32&)(this, pool, candidates, candidateCount);
		}

		void GetExpansionCandidate(u32 preloadBucketIndex, PreloadRequest*& candidate, ExpansionReason& reason) {
			SDK_CALL_FUNC(void, 0x43D990, void*, u32, PreloadRequest*&, ExpansionReason&)(this, preloadBucketIndex, candidate, reason);
		}

		void Init(StreamingMemory::DATA_TYPE streamingPool, StreamingMemory::DATA_TYPE streamingPoolVRam, qArray<EntityTypeState*>& resourceDescriptorList) {
			SDK_CALL_FUNC(void, 0x43E2D0, void*, StreamingMemory::DATA_TYPE, StreamingMemory::DATA_TYPE, qArray<EntityTypeState*>&)(this, streamingPool, streamingPoolVRam, resourceDescriptorList);
		}

		void InitPriorityBuckets() { SDK_CALL_FUNC(void, 0x43EE10, void*)(this); }
		void PreloadInstance(PreloadRequest* request, TrueCrowdSet::Instance& instance) { SDK_CALL_FUNC(void, 0x43FC60, void*, PreloadRequest*, TrueCrowdSet::Instance&)(this, request, instance); }
		void QueueRequest(ResourceRequest* pRequest) { SDK_CALL_FUNC(void, 0x441020, void*, ResourceRequest*)(this, pRequest); }
		void ReleaseAllAmbientPreloads() { SDK_CALL_FUNC(void, 0x4415D0, void*)(this); }
		void ReleaseAllUnReferencedPreloads(u32 preloadBucketIndex, bool forceUnload) { SDK_CALL_FUNC(void, 0x4416A0, void*, u32, bool)(this, preloadBucketIndex, forceUnload); }
		void ReleaseAmbientPreloads(TrueCrowdResource::EntityType type) { SDK_CALL_FUNC(void, 0x4417C0, void*, TrueCrowdResource::EntityType)(this, type); }

		void ReleasePreload(TrueCrowdSet* resourceSet, u32 preloadBucketIndex, bool directRequest) {
			SDK_CALL_FUNC(void, 0x441950, void*, TrueCrowdSet*, u32, bool)(this, resourceSet, preloadBucketIndex, directRequest);
		}

		void ReleaseResourceSetFiles(PreloadRequest* request) { SDK_CALL_FUNC(void, 0x441A60, void*, PreloadRequest*)(this, request); }
		void RemovePreloadReferences(ResourceRequest* request) { SDK_CALL_FUNC(void, 0x442250, void*, ResourceRequest*)(this, request); }

		ResourceRequest* RequestLoadResource(TrueCrowdResource* resource, bool isTexture, int* priority, const ResourceUser& user) {
			return SDK_CALL_FUNC(ResourceRequest*, 0x442600, void*, TrueCrowdResource*, bool, int*, const ResourceUser&)(this, resource, isTexture, priority, user);
		}

		PreloadRequest* RequestPreload(TrueCrowdSet::Instance& instance, u32 preloadBucketIndex, bool directRequest) {
			return SDK_CALL_FUNC(PreloadRequest*, 0x4428A0, void*, TrueCrowdSet::Instance&, u32, bool)(this, instance, preloadBucketIndex, directRequest);
		}

		void RequestUnLoadResource(TrueCrowdResource* resource, int* priority, const ResourceUser& user) {
			SDK_CALL_FUNC(void, 0x442C10, void*, TrueCrowdResource*, int*, const ResourceUser&)(this, resource, priority, user);
		}

		void ResourceHasBeenLoaded(DataStreamer::Handle* handle, void* callbackParam) { SDK_CALL_FUNC(void, 0x442EA0, DataStreamer::Handle*, void*)(handle, callbackParam); }
		void ResourceLoadNotification(ResourceRequest* pRequest) { SDK_CALL_FUNC(void, 0x442ED0, void*, ResourceRequest*)(this, pRequest); }
		bool UpdateAmbientPreloads() { return SDK_CALL_FUNC(bool, 0x445670, void*)(this); }
		void UpdateBuckets() { SDK_CALL_FUNC(void, 0x4459D0, void*)(this); }
		void UpdateRequests() { SDK_CALL_FUNC(void, 0x447110, void*)(this); }
		void UpdateVarietyRatios() { SDK_CALL_FUNC(void, 0x447320, void*)(this); }
	};
}