#pragma once

namespace Render
{
	class SkinClipInfo
	{
	public:
		struct ClipOutputVertex
		{
			i8 s0_data[24];
			i8 s1_data[8];
			i8 morph_data[8];
			UFG::qHalfFloat uv[2];
		};

		struct ClipResult
		{
			ClipOutputVertex mVerts[32];
			bool mResultReady;
			u32 mResultVertNum;
		};

		ClipResult* mResults[8];
		UFG::qMatrix44 mDecalWorld;
		UFG::qMatrix44 mModelLocalWorld;
		UFG::qVector4 mModelAABBMin;
		UFG::qVector4 mModelAABBMax;
		f32 mDecalCutoff;
		f32 mDecalDepth;
		f32 mRadius;
		bool mQueryReady;
		bool mQueryInProcess;
		u32 mMaxResults;
	};

	class SkinningParams
	{
	public:
		View* view;
		Illusion::ModelProxy* skin_model_proxy;
		UFG::qMatrix44* local_transform;
		u32 instance_uid;
		UFG::qMatrix44* bone_inverse_array;
		char* bone_remap_array;
		void* transform_array;
		u32 bone_matrix_count;
		u32 transform_count;
		Illusion::Model* simple_morph_target;
		f32 simple_morph_weight;
		f32* morph_weights_array;
		u32 morph_weights_count;
		void* user_data_0;
		void* user_data_1;
		bool no_override;
		SkinClipInfo* clip_info;
		Illusion::Material* mDecalMaterial;
		SkinClipInfo::ClipOutputVertex* mDecalVerts;
		u32 mDecalVertNum;
		u32 mDecalTaskUID;
		UFG::qMatrix44* mRigidTransform;
		bool mHasSoftbody;
		bool mUsePersistentCache;
	};

}