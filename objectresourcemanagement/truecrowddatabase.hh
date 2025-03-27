#pragma once

namespace UFG
{
	class PedSpawningInfo;
	class TrueCrowdModelPart;
	class TrueCrowdTextureSet;

	enum eTrueCrowdMorphType
	{
		eTCMT_None,
		eTCMT_Base,
		eTCMT_Target1,
		eTCMT_Target2
	};

	struct ModelTextureCombination
	{
		u32 mModelIndex;
		u32 mTextureSetIndex;
		qColour* mColourTint;
	};

	class TrueCrowdModelPart
	{
	public:
		qOffset64<char*> mModelName;
		u32 mModelNameHash;
		u16 mIsSkinned;
		qEnum<eTrueCrowdMorphType, s16> mMorphType;
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

	class TrueCrowdDataBase : public qResourceData
	{
	public:
		struct ResourceEntry
		{
			BitFlags128 mTagBitFlag;
			TrueCrowdModel mResource;
		};

		struct ComponentEntries
		{
			u32 mNumEntries;
			qOffset64<ResourceEntry*> mEntries;
		};

		TrueCrowdDefinition mDefinition;
		u32 mNumComponentEntries;
		qOffset64<ComponentEntries*> mComponentEntries;
		qList<TrueCrowdSet> mKnownRequests;

		/* Static Functions */

		SDK_SINLINE TrueCrowdDataBase* Instance() { return SDK_VAR_GET(TrueCrowdDataBase*, 0x24015E0); }

		/* Functions */

		TrueCrowdSet* QueryCharacterDataBase(u32 entityIndex, qPropertyList* query_tags, qPropertyList* componentList, qPropertyList* overrides, qPropertyList* textureSetList, qPropertySet* property_set) {
			return SDK_CALL_FUNC(TrueCrowdSet*, 0x43FFC0, void*, u32, qPropertyList*, qPropertyList*, qPropertyList*, qPropertyList*, qPropertySet*)(this, entityIndex, query_tags, componentList, overrides, textureSetList, property_set);
		}

		TrueCrowdSet* QueryDataBase(qPropertySet * property_set, component_StreamedResource* dataPtr = 0) {
			return SDK_CALL_FUNC(TrueCrowdSet*, 0x4408F0, void*, qPropertySet*, component_StreamedResource*)(this, property_set, dataPtr);
		}

		void QueryInstance(qPropertySet* property_set, TrueCrowdSet::Instance* instance) {
			SDK_CALL_FUNC(void, 0x4409E0, void*, qPropertySet*, TrueCrowdSet::Instance*)(this, property_set, instance);
		}

		TrueCrowdModel* QueryModelFromPath(u32 entityIndex, u32 componentIndex, const qSymbol& pathSymbol) {
			return SDK_CALL_FUNC(TrueCrowdModel*, 0x440B10, void*, u32, u32, const qSymbol&)(this, entityIndex, componentIndex, pathSymbol);
		}

		bool QueryPreloadedInstance(qPropertySet* property_set, TrueCrowdSet::Instance* instance) {
			return SDK_CALL_FUNC(bool, 0x440BB0, void*, qPropertySet*, TrueCrowdSet::Instance*)(this, property_set, instance);
		}
	};
	SDK_ASSERT_SIZEOF(TrueCrowdDataBase, 0x8240);
}