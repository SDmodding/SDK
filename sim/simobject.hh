#pragma once

namespace UFG
{
	class SceneObjectProperties;
	class SimObject;
	class TransformNodeComponent;

	//-------------------------------------------------------------------
	// Component
	//-------------------------------------------------------------------

	class SimComponent : public qSafePointerNode<SimComponent>
	{
	public:
		u32 m_TypeUID;
		u32 m_NameUID;
		u16 m_Flags;
		s16 m_SimObjIndex;
		SimObject* m_pSimObject;
		qList<RebindingComponentHandleBase> m_BoundComponentHandles;
	};
	SDK_ASSERT_SIZEOF(SimComponent, 0x40);

	class SimComponentHolder
	{
	public:
		SimComponent* m_pComponent;
		u32 m_TypeUID;
	};

	//-------------------------------------------------------------------
	// Object
	//-------------------------------------------------------------------

	class SimObject : public qSafePointerNodeWithCallbacks<SimObject>, public qNodeRB<SimObject>
	{
	public:
		qSymbol m_Name;
		unsigned __int16 m_Flags;
		char m_ReservedComponentSlots;
		char m_ResolveRefCount;
		SceneObjectProperties* m_pSceneObj;
		TransformNodeComponent* m_pTransformNodeComponent;
		qArray<SimComponentHolder> m_Components;
		qList<RebindingComponentHandleBase> m_UnboundComponentHandles;

		virtual void Attach(SimComponent* component, u32 index) = 0;
		virtual void Detach(SimComponent* component) = 0;
	};
	SDK_ASSERT_SIZEOF(SimObject, 0x80);
}