#pragma once

namespace Illusion
{
	namespace eCastShadow
	{
		enum Enum
		{
			NoShadows,
			SunShadows,
			SpotShadows,
			SunAndSpotShadows
		};
	}

	class rMesh
	{
	public:
		UFG::qReflectString mMaterialName;
		UFG::qReflectHandle<rMaterial> mMaterial;
		VertexDeclHandle mVertexDeclHandle;
		BufferHandle mIndexBufferHandle;
		BufferHandle mVertexBufferHandles[4];
		int mPrimType;
		int mIndexStart;
		u32 mNumPrims;
		const char* mDescription;
	};

	class rModel
	{
	public:
		enum eType
		{
			LOD_A,
			LOD_B,
			LOD_C,
			LOD_D,
			OccluderAABB,
			OccluderModel,
			OccluderModelDoubleSided,
			Shadow,
			NonDrawable,
			Physics = NonDrawable
		};

		UFG::qReflectString mModelName;
		UFG::qReflectArray<Illusion::rMesh> mMeshes;
		eType mModelType;
		BonePaletteHandle mBonePaletteHandle;
		UFG::qVector3 mAABBMin;
		u32 mNumPrims;
		UFG::qVector3 mAABBMax;
		u32 mLastUsedFrameNum;
		UFG::qMemoryPool* mMemoryPool;
	};

	class ModelProxy
	{
	public:
		ModelHandle mModelHandle;
		rModel* mRModel;

		ModelProxy() { SDK_CALL_FUNC(void, 0x1C19E0, void*)(this); }
		~ModelProxy() { SDK_CALL_FUNC(void, 0x27F0, void*)(this); }

		/* Functions */

		u32 GetNumMeshes() { return SDK_CALL_FUNC(u32, 0x1DFD0, void*)(this); }
		void Init(u32 model_uid) { SDK_CALL_FUNC(void, 0x3C70, void*, u32)(this, model_uid); }
	};
}