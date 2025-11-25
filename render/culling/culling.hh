#pragma once

class CullInfo;
class CullInfoFull;

class CullResults
{
public:
	s8 mViewResult[16];
	f32 mDistance[6];
	f32 mPixelCoverage[6];
};

class CullBucket : public UFG::qNode<CullBucket, CullBucket>
{
public:
	CullInfo* mCullInfos;
	CullInfoFull* mFullCullInfos;
	CullResults* mResults;
	u32 mType;
	u32 mMax;
	u32 mCullInfosAlloced;
	i8 mPad[12];
};
SDK_ASSERT_SIZEOF(CullBucket, 0x40);

class CullResultBucket : public UFG::qSNode<CullResultBucket>
{
public:
	u32 mNumResults;
	i8 mCullFlags[7];
	i8 pad0;
	void* mParams0[7];
	void* mParams1[7];
	f32 mPixelCoverages[7];
	f32 mDistances[7];
};
SDK_ASSERT_SIZEOF(CullResultBucket, 0xC0);

class __declspec(align(64)) CullLayer : public UFG::qNode<CullLayer, CullLayer>
{
	enum CullLayerType : i32
	{
		TYPE_CULL,
		TYPE_OCCLUSION,
		NUM_TYPES
	};

	CullLayerType mType;
	const char* mName;
	bool mDrawEnabled;
	u32 pad0;
	u32 pad1;
	u32 pad2;
	UFG::qList<CullBucket> mFrameCullBuckets;
	UFG::qList<CullBucket> mPersistentCullBuckets;
	UFG::qSList<CullResultBucket> mCullResultBuckets[16];
};
SDK_ASSERT_SIZEOF(CullLayer, 0x100);

class CullManager
{
public:
	enum ViewSlotStatus
	{
		VIEW_SLOT_AVAILABLE = 0,
		VIEW_SLOT_ALLOCATED = 2
	};

	struct CullSettings
	{
		UFG::qMatrix44 mWorldViewProjection;
		f32 mNearPlane;
		f32 mFarPlane;
		f32 mPixelDensityThreshold;
		f32 mPixelDistanceBias;
		u32 mViewFlags;
		u32 mViewUserFilter;
		UFG::qVector3 mViewWorldPos;
	};

	ViewSlotStatus mViewSlots[16];
	CullSettings mViewSettings[16];
	UFG::qList<CullLayer> mCullLayers[2];
	UFG::qTaskGroup* mFinalTasks[16];
	UFG::qTask* mPrevOcclusionTask;
	UFG::qTaskGroup* mPrevCullingTask;
	Render::RasterizeZ mRasterizers[16];
	Render::OcclusionMap mOcclusionMaps[16];
	void* mZbuffer1;
	void* mZbuffer2;
	void* mZbuffer3;
	void* mZbuffer4;
	Illusion::Texture* mOcclusionDebugTexture;
	f32 mDoCullingTiming;
	u32 mNumCullLayers;
	u32 mNumCullBuckets;
	u32 mNumOcclusionBuckets;
	int mPixelDensityDynamicBias;
	bool mEnableOcclusionCulling;
	bool mDrawOcclusionMap;
	int mDrawOcclusionMapScale;
	f32 mDrawOcclusionMapOpacity;
	int mDrawCullInfoNum;
	int mDrawOcclusionInfoNum;
	int mDetailedCullInfoIndex;
	bool mDetailedCullInfoLocked;

	/* Static Functions */

	SDK_SINLINE CullManager* Instance() { return SDK_VAR(CullManager*, 0x2133FA0); }

	/* Functions */

	CullInfo* AllocFrameCullInfos(int num_infos) { return SDK_CALL_FUNC(CullInfo*, 0x25B40, void*, int)(this, num_infos); }

	void AllocPersistentCullInfo(CullResults** cull_result, CullInfo** cull_info, CullLayer* cull_layer, void* cull_info_param0, void* cull_info_param1) {
		SDK_CALL_FUNC(void, 0x25B90, void*, CullResults**, CullInfo**, CullLayer*, void*, void*)(this, cull_result, cull_info, cull_layer, cull_info_param0, cull_info_param1);
	}

	void AllocPersistentOcclusionInfo(CullInfoFull** occlusion_info, CullLayer* cull_layer) { SDK_CALL_FUNC(void, 0x25CC0, void*, CullInfoFull**, CullLayer*)(this, occlusion_info, cull_layer); }

	void AllocPrebuiltFrameCullInfos(CullResults** cull_results, int num_infos, CullInfo* prebuilt_cull_infos, CullLayer* cull_layer) {
		SDK_CALL_FUNC(void, 0x25E70, void*, CullResults**, int, CullInfo*, CullLayer*)(this, cull_results, num_infos, prebuilt_cull_infos, cull_layer);
	}

	void AllocPrebuiltFrameOcclusionInfos(int num_infos, CullInfoFull* prebuilt_occlusion_infos, CullLayer* cull_layer) {
		SDK_CALL_FUNC(void, 0x25FF0, void*, int, CullInfoFull*, CullLayer*)(this, num_infos, prebuilt_occlusion_infos, cull_layer);
	}

	void BeginFrame() { SDK_CALL_FUNC(void, 0x26110, void*)(this); }

	bool BeginView(int view_index, class UFG::qTaskGroup* dependent) { return SDK_CALL_FUNC(bool, 0x262B0, void*, int, UFG::qTaskGroup*)(this, view_index, dependent); }

	//void SetFromViewSettings(const Render::ViewSettings& view_settings) { SDK_CALL_FUNC(void, 0x27380, void*, const Render::ViewSettings&)(this, view_settings); }

	void DeregisterAllViews() { SDK_CALL_FUNC(void, 0x26A60, void*)(this); }

	void DeregisterView(int view_index) { SDK_CALL_FUNC(void, 0x26AE0, void*, int)(this, view_index); }

	void EndFrame() { SDK_CALL_FUNC(void, 0x26C80, void*)(this); }

	void EndView(int view_index) { SDK_CALL_FUNC(void, 0x26D10, void*, int)(this, view_index); }

	void FreePersistentCullInfo(CullResults* cull_result, CullInfo* cull_info) { SDK_CALL_FUNC(void, 0x26D40, void*, CullResults*, CullInfo*)(this, cull_result, cull_info); }

	void FreePersistentOcclusionInfo(CullInfoFull* occlusion_info) { SDK_CALL_FUNC(void, 0x26E70, void*, CullInfoFull*)(this, occlusion_info); }

	int RegisterView(const CullSettings& view_settings) { return SDK_CALL_FUNC(int, 0x272A0, void*, const CullSettings&)(this, view_settings); }
};
SDK_ASSERT_SIZEOF(CullManager, 0xD08);