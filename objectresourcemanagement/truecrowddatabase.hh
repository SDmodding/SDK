#pragma once

namespace UFG
{
	class PedSpawningInfo;
	class TrueCrowdModelPart;
	class TrueCrowdTextureSet;

	struct ModelTextureCombination
	{
		u32 mModelIndex;
		u32 mTextureSetIndex;
		qColour* mColourTint;
	};

	class TrueCrowdLOD
	{
	public:
		u32 mNumModelParts;
		qOffset64<TrueCrowdModelPart*> mModelParts;
	};

	class TrueCrowdResource
	{
	public:
		enum EntityType : s32
		{
			Invalid = -1,
			Character = 0,
			Vehicle,
			Prop,
			NumEntityTypes,
		};

		qOffset64<char*> mName;
		ResourceRequest* mRequest;
		u32 mModelSize;
		u32 mTextureSize;
		qEnum<EntityType, u32> mType;
		qSymbol mPathSymbol;
		qSymbol mPropSetName;
		u32 mNonDefraggable;
		qPropertySet* mPropSet;
		qOffset64<TrueCrowdResource*> mHighResolutionResource;
	};
	SDK_ASSERT_SIZEOF(TrueCrowdResource, 0x38);

	class TrueCrowdModel : public TrueCrowdResource
	{
	public:
		u16 mNumLODs;
		u16 mNumTextureSets;
		u32 mComponentTypeSymbolUC;
		qOffset64<TrueCrowdLOD*> mLODModel;
		qOffset64<qOffset64<TrueCrowdTextureSet*>*> mTextureSets;
	};
	SDK_ASSERT_SIZEOF(TrueCrowdModel, 0x50);

	class TrueCrowdSet : public qNode<TrueCrowdSet>
	{
	public:
		struct ComponentDetails
		{
			s8 mbSpecificModel;
			s8 mbTextureSetIndexValid;
			s8 mbColourTintIndexValid;
			u32 mTextureSetIndex;
			u32 mColourTintIndex;
		};

		struct Instance
		{
			TrueCrowdSet* mSet;
			u32 mNumParts;
			float mMorphWeights[2];
			ModelTextureCombination mPart[16];

			SDK_INLINE void AddProxyReference(PedSpawningInfo& proxy) { SDK_CALL_FUNC(void, 0x438600, void*, PedSpawningInfo&)(this, proxy); }
			SDK_INLINE void RemoveProxyReference(PedSpawningInfo& proxy) { SDK_CALL_FUNC(void, 0x442350, void*, PedSpawningInfo&)(this, proxy); }
			SDK_INLINE bool IsEqual(const Instance& rhs) { return SDK_CALL_FUNC(bool, 0x43F0C0, void*, const Instance&)(this, rhs); }
			SDK_INLINE bool IsLoaded() { return SDK_CALL_FUNC(char, 0x43F180, void*)(this); }
		};


		BitFlags128 mKey;
		qSymbol mResourceFilename;
		u32 mEntityIndex;
		u32 mCurrentInstances;
		qArray<TrueCrowdModel*> mFiles[16];
		ComponentDetails mComponentDetails[16];
	};
	SDK_ASSERT_SIZEOF(TrueCrowdSet, 0x1F0);
}