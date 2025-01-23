#pragma once

namespace UFG
{
	class StreamedResourceComponent : public SimComponent, public qNode<StreamedResourceComponent>
	{
	public:
		enum { _TypeUID = 0x72000001 };

		bool mUseMeshLoader;
		MeshResourceLoader mMeshLoader;
		bool mResourcesBound;
		PartLoader mPartLoader;
		bool mPartsBound;
		bool mFirstResourceLoad;
		qColour mColourTints[16];
		qSymbol mActivePriority;
		qPropertySet* mPropertySet;
		u32 mSpawnPriorityReferenceCount[4];
		f32 mCameraDistance;
		eSimObjectTypeEnum mSimObjectType;

		/* Functions */

		void AddPart(PartDefinition* part, const qSymbolUC& textureSet) { SDK_CALL_FUNC(void, 0x4385F0, void*, PartDefinition*, const qSymbolUC&)(this, part, textureSet); }
		void ApplyTextureOverrideForPart(Illusion::MaterialModifierParams<10>* material_modifier, PartDefinition* part, const qSymbolUC& textureSet) { 
			SDK_CALL_FUNC(void, 0x438AB0, void*, Illusion::MaterialModifierParams<10>*, PartDefinition*, const qSymbolUC&)(this, material_modifier, part, textureSet);
		}
		bool AreResourcesBound() { return SDK_CALL_FUNC(bool, 0x438C90, void*)(this); }
		bool AreResourcesLoaded() { return SDK_CALL_FUNC(bool, 0x438CC0, void*)(this); }
		void BindAllModels(CompositeDrawableComponent* composite_drawable, bool using_temp_rig) { 
			SDK_CALL_FUNC(void, 0x438DD0, void*, CompositeDrawableComponent*, bool)(this, composite_drawable, using_temp_rig); 
		}
		void ClearResources() { SDK_CALL_FUNC(void, 0x43A790, void*)(this); }
		void DispatchPartEvent(PartRequest* request, bool loaded) { SDK_CALL_FUNC(void, 0x43B2B0, void*, PartRequest*, bool)(this, request, loaded); }
		void DispatchResourceEvent(ResourceRequest* request, bool loaded) { SDK_CALL_FUNC(void, 0x43B780, void*, ResourceRequest*, bool)(this, request, loaded); }
		void DowngradeResolution() { SDK_CALL_FUNC(void, 0x43C2C0, void*)(this); }
		qPropertySet* GetAssetPropertySet(const qSymbol& propName) { return SDK_CALL_FUNC(qPropertySet*, 0x43D0D0, void*, const qSymbol&)(this, propName); }
		const qSymbol& GetSpawnPriority(SpawnInfoInterface::SpawnPriority* priority) { return SDK_CALL_FUNC(const qSymbol&, 0x43DE60, void*, SpawnInfoInterface::SpawnPriority*)(this, priority); }
		void InitPriorityInfo(qPropertySet* propertySet) { SDK_CALL_FUNC(void, 0x43EFD0, void*, qPropertySet*)(this, propertySet); }
		bool IsLoadActive() { return SDK_CALL_FUNC(bool, 0x43F160, void*)(this); }
		void RefreshRenderState(CompositeDrawableComponent* composite_drawable) { SDK_CALL_FUNC(void, 0x441470, void*, CompositeDrawableComponent*)(this, composite_drawable); }
		void ResetPropertyPtr() { SDK_CALL_FUNC(void, 0x442D40, void*)(this); }
		void ResetResources() { SDK_CALL_FUNC(void, 0x442E90, void*)(this); }
		void SetResourceSignature(TrueCrowdSet::Instance* signature) { SDK_CALL_FUNC(void, 0x443200, void*, TrueCrowdSet::Instance*)(this, signature); }
		void SwapResource(u32 componentIndex, const qSymbol& modelPathSymbol, const qSymbol& textureSetPathSymbol, u32* colourTintIndex = 0) {
			SDK_CALL_FUNC(void, 0x443550, void*, u32, const qSymbol&, const qSymbol&, u32*)(this, componentIndex, modelPathSymbol, textureSetPathSymbol, colourTintIndex);
		}
		void SwapVehicleRig(SimObject* pUpgradingObject) { SDK_CALL_FUNC(void, 0x443880, SimObject*)(pUpgradingObject); }
		void UnbindAllModels(CompositeDrawableComponent* composite_drawable) { SDK_CALL_FUNC(void, 0x4440F0, void*, CompositeDrawableComponent*)(this, composite_drawable); }
		void UnbindModelResource(CompositeDrawableComponent* composite_drawable, TrueCrowdModel* model_resource) { 
			SDK_CALL_FUNC(void, 0x4441B0, void*, CompositeDrawableComponent*, TrueCrowdModel*)(this, composite_drawable, model_resource); 
		}
		void UpgradeResolution() { SDK_CALL_FUNC(void, 0x447980, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(StreamedResourceComponent, 0x630);
}