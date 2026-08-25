#pragma once

class VisibilityCommand : public UFG::qNode<VisibilityCommand>
{
public:
	u32 bone_name_uid;
	bool visible;
};

class ModelType : public UFG::qNode<ModelType>
{
public:
	struct ModelBindingRigid : UFG::qNode<ModelBindingRigid>
	{
		u32 mModelUID;
		Illusion::ModelProxy mModelProxy;
		u32 mMorphModelUID;
		Illusion::ModelHandle mMorphModelHandle;
		u32 mNumMappedBones;
		u32 mModelIndex;
		u16 mBoneID;
		u16 mVisible;
	};

	struct SimpleMorphTargets
	{
		Illusion::ModelHandle mModelHandles[2];
		f32 mMorphWeights[2];
		u32 mNumModelBindings;
	};

	struct SkinnedDecalLayer
	{
		u32* mDecalVertSeries;
		Render::SkinClipInfo* mClipQuery;
		Render::SkinClipInfo::ClipOutputVertex* mDecalVerts;
		u32 mDecalSeriesCount;
		u32 mDecalVertCount;
		Illusion::MaterialHandle mDecalMaterialHandle;
		u32 mDecalTaskUID;
		u32 mMaxResults;
	};

	struct ModelBindingSkin : UFG::qNode<ModelBindingSkin>
	{
		u32 mNumMappedBones;
		char* mSkeletonToModelBoneMap;
		u32 mModelUID;
		u32 mModelIndex;
		Illusion::ModelProxy mModelProxy;
		SimpleMorphTargets* mMorphTargets;
		SkinnedDecalLayer* mDecalLayer;
		Render::Softbody* mSoftbody;
	};

	UFG::RigHandle mRigHandle;
	UFG::qList<ModelBindingSkin> mModelBindingSkinTable;
	UFG::qList<ModelBindingRigid> mModelBindingRigidTable;
	UFG::qList<VisibilityCommand> mQueuedVisibilityCommands;
	UFG::qVector3 mAABBMin;
	UFG::qVector3 mAABBMax;
	u32 mLastInventoryQueryTransactionNum;

	/* Functions */

	void AddModelBinding(const Illusion::ModelProxy& model_proxy, u32 model_index = 0, u32 lod = 0) {
		SDK_CALL_FUNC(void, 0x1BF470, void*, const Illusion::ModelProxy&, void*, u32, u32)(this, model_proxy, 0, model_index, lod);
	}

	ModelBindingRigid* AddRigidModelBinding(const Illusion::ModelProxy& model_proxy, u32 bone_index, u32 model_index = 0) {
		return SDK_CALL_FUNC(ModelBindingRigid*, 0x1BF600, void*, const Illusion::ModelProxy&, u32, void*, u32)(this, model_proxy, bone_index, 0, model_index);
	}

	ModelBindingSkin* AddSkinModelBinding(const Illusion::ModelProxy& model_proxy, u32 model_index = 0, u32 lod = 0) {
		return SDK_CALL_FUNC(ModelBindingSkin*, 0x1BF700, void*, const Illusion::ModelProxy&, void*, u32, u32)(this, model_proxy, 0, model_index, lod);
	}

	ModelBindingRigid* FindRigidModelBinding(u32 model_name_uid, u32 bone_name_uid, u32 model_index) {
		return SDK_CALL_FUNC(ModelBindingRigid*, 0x1BFC90, void*, u32, u32, u32)(this, model_name_uid, bone_name_uid, model_index);
	}

	void RemoveAllSkinModelBindings() { SDK_CALL_FUNC(void, 0x1BFDB0, void*)(this); }
	void RemoveModelBinding(const Illusion::ModelProxy& model_proxy) { SDK_CALL_FUNC(void, 0x1BFE10, void*, const Illusion::ModelProxy&)(this, model_proxy); }
	void SetRigHandle(u32 rig_uid, UFG::RigResource* rig) { SDK_CALL_FUNC(void, 0x4120, void*, u32, UFG::RigResource*)(this, rig_uid, rig); }
	void SetRigidModelVisibilityOnBone(u32 bone_name_uid, char visible) { SDK_CALL_FUNC(void, 0x1BFF00, void*, u32, char)(this, bone_name_uid, visible); }
};
