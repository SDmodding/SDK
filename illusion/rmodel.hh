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

}