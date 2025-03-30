#pragma once

namespace UFG
{
	class SceneObjectProperties : public SimComponent, public qNode<SceneObjectProperties, SceneObjectProperties>
	{
	public:
		qSafePointer<SimObject> mpOwner;
		SceneLayerResource* mpLayerResource;
		SceneObjectProperties* mpParent;
		qSetLogical<SceneObjectProperties, qSymbol> mChildren;
		bool mDeleteChildSimObjectOnDestruct;
		u32 mLastTeleportFrame;
		qPropertySet* mpWritableProperties;
		qPropertySet* mpConstProperties;
		u32 mPrevNameHash;
		u32 mChildIndex;

		/* Static Functions */

		SDK_INLINE SceneObjectProperties* Create(u32 prevNameUID, qPropertySet* parentSet, u32 child_index) {
			return SDK_CALL_FUNC(SceneObjectProperties*, 0x23A580, u32, qPropertySet*, u32)(prevNameUID, parentSet, child_index);
		}

		SDK_INLINE SceneObjectProperties* Create(const qSymbol& objName, SceneLayer* pOwnerLayer, const qSymbol& parentSetName) {
			return SDK_CALL_FUNC(SceneObjectProperties*, 0x23A420, const qSymbol&, SceneLayer*, const qSymbol&)(objName, pOwnerLayer, parentSetName);
		}

		SDK_INLINE SceneObjectProperties* Create(const qSymbol& objName, SceneLayer* pOwnerLayer, qPropertySet* parentSet) {
			return SDK_CALL_FUNC(SceneObjectProperties*, 0x23A450, const qSymbol&, SceneLayer*, qPropertySet*)(objName, pOwnerLayer, parentSet);
		}

		/* Impl Functions */

		SDK_INLINE qPropertySet* GetWritablePersistentProperties() { return (mpConstProperties ? mpConstProperties : mpWritableProperties); }
		SDK_INLINE SceneLayer* GetLayer() { return (mpLayerResource ? reinterpret_cast<SceneLayer*>(mpLayerResource->mpRuntimeSceneLayer) : 0); }
		SDK_INLINE SimObject* GetChildAsSimObject(u32 index) { return (mChildren.mCount > index ? mChildren.mppArray[index]->m_pSimObject : 0); }
		SDK_INLINE SceneObjectProperties* GetChildAsSceneObject(u32 index) { return (mChildren.mCount > index ? mChildren.mppArray[index] : 0); }

		/* Functions */

		void UninstantiateChildObjects() { SDK_CALL_FUNC(void, 0x2464C0, void*)(this); }
		void SetParent(SceneObjectProperties* pParent) { SDK_CALL_FUNC(void, 0x245540, void*, SceneObjectProperties*)(this, pParent); }
		u32 InstantiateChildObjects(u32 prevNameUID) { return SDK_CALL_FUNC(u32, 0x23EA50, void*, u32)(this, prevNameUID); }
		qPropertySet* GetWritableProperties() { return SDK_CALL_FUNC(qPropertySet*, 0x23E2F0, void*)(this); }
		const qSymbol& GetArchetypePropertiesName() { return SDK_CALL_FUNC(const qSymbol&, 0x23C030, void*)(this); }
		qPropertySet* GetArchetypeProperties() { return SDK_CALL_FUNC(qPropertySet*, 0x23BFE0, void*)(this); }
		SceneObjectProperties* GetAncestor(u32 ancestorLevel) { return SDK_CALL_FUNC(SceneObjectProperties*, 0x23BFB0, void*, u32)(this, ancestorLevel); }
		SceneLayer* FindOwnerLayer() { return SDK_CALL_FUNC(SceneLayer*, 0x23BD00, void*)(this); }
		void DeactivateDeferred() { SDK_CALL_FUNC(void, 0x23AE00, void*)(this); }
		void Deactivate() { SDK_CALL_FUNC(void, 0x23ACC0, void*)(this); }
		void Deactivate(char createObjectFlags) { SDK_CALL_FUNC(void, 0x23AB70, void*, char)(this, createObjectFlags); }
		u32 ActivateChildObjects() { return SDK_CALL_FUNC(u32, 0x239BC0, void*)(this); }

		SimObject* Activate(u32 instantiateFlags, const qMatrix44* pXFormOverride, TransformNodeComponent* parentTransform) {
			return SDK_CALL_FUNC(SimObject*, 0x239AA0, void*, u32, const qMatrix44*, TransformNodeComponent*)(this, instantiateFlags, pXFormOverride, parentTransform);
		}
	};
	SDK_ASSERT_SIZEOF(SceneObjectProperties, 0xA8);
}