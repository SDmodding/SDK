#pragma once

namespace UFG
{
	enum eInteractionPointUpdateEnum
	{
		eINTERACTION_POINT_UPDATE_INVALID,
		eINTERACTION_POINT_UPDATE_ROOT,
		eINTERACTION_POINT_UPDATE_DISTANCE,
		eINTERACTION_POINT_UPDATE_BONE,
		eINTERACTION_POINT_UPDATE_PROJECTED,
		eINTERACTION_POINT_UPDATE_OBJECT_XFORM,
		eINTERACTION_POINT_UPDATE_HACK_MIX_0_1_AND_2,
		NUM_INTERACTION_POINT_UPDATE_TYPES
	};

	class InteractionPoint : public qSafePointerNode<InteractionPoint>
	{
	public:
		InteractableComponent* m_OwnerInteractableComponent;
		qArray<InteractorComponent*> m_InteractorList;
		eInteractionPointUpdateEnum m_eInteractionPointUpdate;
		qSafePointer<SimObject> m_pSimObject;
		f32 m_fDistance;
		qSymbolUC m_uBoneUID;
		eTargetTypeEnum m_eOffsetTarget;
		bool m_bIsActive;
		qMatrix44 m_xform;
	};

	class InteractableComponent : public SimComponent, public qNode<InteractableComponent>
	{
	public:
		enum { _TypeUID = 0xBC000001 };

		f32 m_fUntargetedCountdownTimer;
		InteractionPoint m_InteractionPoints[6];
		RebindingComponentHandle<TargetingSystemBaseComponent> m_pTSBC;

		/* Functions */

		void CreateInteractionPoints() { SDK_CALL_FUNC(void, 0x5248C0, void*)(this); }
		void DestroyInteractionPoints() { SDK_CALL_FUNC(void, 0x525400, void*)(this); }
		InteractionPoint* FindBestInteractionPoint(SimObject* pInteractingSO, const qStaticBitField<6>& bfTestIP, const bool bIgnoreMeshTest) {
			return SDK_CALL_FUNC(InteractionPoint*, 0x527DD0, void*, SimObject*, const qStaticBitField<6>&, const bool)(this, pInteractingSO, bfTestIP, bIgnoreMeshTest);
		}
		InteractionPoint* FindInteractionPoint(SimObject* pInteractingSO, eTargetTypeEnum eInteractionPointTargetType, const bool bIgnoreMeshTest) { 
			return SDK_CALL_FUNC(InteractionPoint*, 0x5286F0, void*, SimObject*, eTargetTypeEnum, const bool)(this, pInteractingSO, eInteractionPointTargetType, bIgnoreMeshTest);
		}
		component_Interactable* GetDataPtr(SceneObjectProperties* pSceneObj) { return SDK_CALL_FUNC(component_Interactable*, 0x52C7B0, SceneObjectProperties*)(pSceneObj); }
		void InitFromData(const component_Interactable* dataPtr) { SDK_CALL_FUNC(void, 0x536660, void*, const component_Interactable*)(this, dataPtr); }
		void SetIsActive(eTargetTypeEnum eTargetType, bool bIsActive) { SDK_CALL_FUNC(void, 0x54D930, void*, eTargetTypeEnum, bool)(this, eTargetType, bIsActive); }
		void UpdateInteractionPoints(TransformNodeComponent* pInteractorTNC) { SDK_CALL_FUNC(void, 0x560380, void*, TransformNodeComponent*)(this, pInteractorTNC); }
	};
	SDK_ASSERT_SIZEOF(InteractableComponent, 0x448);

	class InteractorComponent : public SimComponent
	{
	public:
		enum { _TypeUID = 0xBA000001 };

		qSafePointer<InteractionPoint> m_pBestInteractionPoint;
		InteractionPoint* m_pInteractionPoint;

		/* Functions */

		void SetBestInteractionPoint(InteractionPoint* pIP, bool bUpdateBestInteractionPointTarget) { 
			SDK_CALL_FUNC(void, 0x54BD50, void*, InteractionPoint*, bool)(this, pIP, bUpdateBestInteractionPointTarget);
		}
		void StartInteraction(InteractionPoint* pIP, bool bNotifyInteractionPoint) { SDK_CALL_FUNC(void, 0x54FF90, void*, InteractionPoint*, bool)(this, pIP, bNotifyInteractionPoint); }
		void StopInteraction(bool bNotifyInteractionPoint) { SDK_CALL_FUNC(void, 0x5527F0, void*, bool)(this, bNotifyInteractionPoint); }
	};
	SDK_ASSERT_SIZEOF(InteractorComponent, 0x60);
}