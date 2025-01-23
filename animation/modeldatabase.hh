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
};
