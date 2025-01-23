#pragma once

namespace UFG
{
	class ActiveMultiMorphTarget
	{
	public:
		u32 mMorphUID;
		f32 mMorphWeight;
	};

	class CompositeDrawableComponent : public SimComponent, public Render::IDecalScenery, public qNode<CompositeDrawableComponent>
	{
	public:
		enum { _TypeUID = 0x04000001 };

		ICompositeLook* mCompositeLook;
		Illusion::MaterialModifierParams<10> mMaterialModifier;
		CB_SceneryInstance mSceneryInstance;
		bool mIsHidden;
		CullLayer* mCullLayer;
		CullResults* mCullResults;
		CullInfo* mCullInfo;
		__declspec(align(16)) qMatrix44 mPoseRootMatrix;
		SkeletalPose* mPose;
		RigHandle mRigHandle;
		u32 mNumModelTypeLODs;
		ModelType* mModelType[5];
		f32 mLODBiasMult;
		f32 mDrawScale;
		bool mHasSoftBody;
		bool mUsePersistentSkinningCache;
		qArray<ActiveMultiMorphTarget> mActiveMultiMorphTargets;

		/* Static Functions */

		SDK_SINLINE void ScalePixelCoverageToLOD(f32 scale) { SDK_CALL_FUNC(void, 0x3F90, f32)(scale); }

		/* Functions */

		void ClearLODs() { SDK_CALL_FUNC(void, 0x2C40, void*)(this); }
		ModelType* CreateModelType(bool create_rig_bindings) { return SDK_CALL_FUNC(ModelType*, 0x2CE0, void*, bool)(this, create_rig_bindings); }
		int GetLOD(f32 pixel_coverage) { return SDK_CALL_FUNC(int, 0x3A50, void*, f32)(this, pixel_coverage); }
		int GetMainViewLOD() { return SDK_CALL_FUNC(int, 0x3AC0, void*)(this); }
		bool GetTransform(Render::Decal& decal, qMatrix44& mat) { return SDK_CALL_FUNC(bool, 0x3B10, void*, Render::Decal&, qMatrix44&)(this, decal, mat); }
		void Reset() { SDK_CALL_FUNC(void, 0x3DC0, void*)(this); }
		void ResetModelType() { SDK_CALL_FUNC(void, 0x3F30, void*)(this); }
		void SetIsHidden(bool bIsHidden) { SDK_CALL_FUNC(void, 0x4000, void*, bool)(this, bIsHidden); }
		void SetLayer(CullLayer* cull_layer) { SDK_CALL_FUNC(void, 0x4030, void*, CullLayer*)(this, cull_layer); }
		void SetRig(u32 rig_uid) { SDK_CALL_FUNC(void, 0x443290, void*, u32)(this, rig_uid); }
	};
	SDK_ASSERT_SIZEOF(CompositeDrawableComponent, 0x5E0);
}