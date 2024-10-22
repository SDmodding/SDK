#pragma once

namespace UFG
{
	class ComponentIDDesc;
	class SceneObjectProperties;

	//-------------------------------------------------------------------
	// Component
	//-------------------------------------------------------------------

	class SimComponent : public qSafePointerNode<SimComponent>
	{
	public:
		enum eFlag
		{
			Flag_attached = 1,
			Flag_skip_update = 2,
			Flag_active = 4,
			Flag_delete_on_simobj_destroy = 8,
			Flag_detaching = 16,

			Flag__none = 0,
			Flag__default = Flag_delete_on_simobj_destroy
		};

		u32 m_TypeUID;
		u32 m_NameUID;
		u16 m_Flags;
		s16 m_SimObjIndex;
		SimObject* m_pSimObject;
		qList<RebindingComponentHandleBase> m_BoundComponentHandles;

		/* Virtual Functions */

		virtual const char* GetTypeName() = 0;
		virtual u32 GetTypeSize() = 0;
		virtual ComponentIDDesc* GetDesc() = 0;
		virtual const char* GetDebugTypeName() = 0;
		virtual void _UnkVFunc5() = 0;
		virtual void OnAttach(SimObject*) = 0;
		virtual void _UnkVFunc7() = 0;
		virtual void Suspend() = 0;
		virtual void Restore() = 0;
		virtual void _UnkVFunc10() = 0;
		virtual void _UnkVFunc11() = 0;
		virtual void _UnkVFunc12() = 0;
		virtual void _UnkVFunc13() = 0;
		virtual void OnDetatch(SimObject*) = 0;
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
		enum eFlag
		{
			Flag_components_changed = (1 << 0),
			Flag_deinitializing = (1 << 1),
			Flag_defer_attachment = (1 << 4),
			Flag_is_proxy = (1 << 10),
			Flag_is_physics_proxy = (1 << 11),
			Flag_is_interest_point = (1 << 12),
			Flag_is_prop = (1 << 13),
			Flag_is_character = (1 << 14),
			Flag_is_vehicle = (1 << 15),

			Flag__none = 0,
			Flag__default = 0,
			Flag__update_list_check = 3
		};

		qSymbol m_Name;
		u16 m_Flags;
		char m_ReservedComponentSlots;
		char m_ResolveRefCount;
		SceneObjectProperties* m_pSceneObj;
		TransformNodeComponent* m_pTransformNodeComponent;
		qArray<SimComponentHolder> m_Components;
		qList<RebindingComponentHandleBase> m_UnboundComponentHandles;

		/* Virtual Functions */

		virtual void Attach(SimComponent* component, u32 index) = 0;
		virtual void Detach(SimComponent* component) = 0;

		/* Functions */

		template <typename T = SimComponent>
		T* GetComponentOfType(u32 type_uid) { return reinterpret_cast<T*(SDK_CALL*)(void*, u32)>(SDK_RVA(0x190AD0))(this, type_uid); }
	};
	SDK_ASSERT_SIZEOF(SimObject, 0x80);
}