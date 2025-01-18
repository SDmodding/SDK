#pragma once

namespace UFG
{
	class MeshInfo
	{
		qReflectString mMaterialName;
		qReflectHandle<Illusion::rMaterial> mMaterial;
		qReflectHandle<PhysicsSurfaceProperties> mSurface;
	};

	class ModelInfo
	{
	public:
		enum eFreeRunBuildMode
		{
			NoFreeRun,
			UseSourceArt,
			AutoGenerate,
			AutoGenerateParkourOnly,
			AutoGenerateCoverOnly
		};

		qReflectString mModelName;
		Illusion::rModel::eType mModelType;
		qReflectArray<MeshInfo> mMeshInfo;
		qReflectHandle<PhysicsObjectProperties> mObjectProperty;
		qReflectArray<qReflectHandle<qReflectObject> > mCustomDataSlots;
		eFreeRunBuildMode mFreeRunBuildMode;
	};

	class ModelAsset : public qReflectObjectType<ModelAsset>
	{
	public:
		enum eDebugOutput
		{
			Off,
			Performance,
			CullingResults
		};

		enum eFreeRunBuildMode
		{
			NoFreeRun,
			UseSourceArt,
			AutoGenerate,
			Custom
		};

		enum eModelBuildMode
		{
			None,
			MergeModels
		};

		qReflectString mFilePath;
		qReflectArray<ModelInfo> mModelInfo;
		qReflectArray<qReflectArray<qReflectHandle<qReflectObject>>> mCustomDataSlotArray;
		qReflectArray<qReflectHandle<qReflectObject>> mCustomDataSlots;
		eModelBuildMode mModelBuildMode;
		bool mGenerateRig;
		qReflectString mRigFile;
		qReflectString mRigName;
		qReflectString mRigBone;
		eFreeRunBuildMode mFreeRunBuildMode;
		bool mMergeFreeRunData;
		bool mMergeCoverData;
		eDebugOutput mDebugOutput;
		Illusion::eCastShadow::Enum mCastShadow;
		qReflectArray<ModelAssetData*> mData;
	};

}