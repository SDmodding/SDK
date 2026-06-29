#pragma once

namespace UFG
{
	class ComponentIDDesc;
	class SceneObjectProperties;

	enum eSimObjectFlagEnum
	{
		eSIM_OBJ_FLAG_UNTARGETABLE,
		eSIM_OBJ_FLAG_CAN_REGEN_HEALTH,
		NUM_SIM_OBJECT_FLAGS
	};

	enum eSimObjectTypeEnum
	{
		eSIM_OBJ_TYPE_INVALID,
		eSIM_OBJ_TYPE_CHARACTER,
		eSIM_OBJ_TYPE_PICKUP,
		eSIM_OBJ_TYPE_WEAPON,
		eSIM_OBJ_TYPE_VEHICLE,
		eSIM_OBJ_TYPE_INTERACTIVE_PROP,
		NUM_SIM_OBJECT_TYPES
	};

	SDK_SINLINE qMemoryPool* GetSimulationPool() { return SDK_VAR(qMemoryPool*, 0x23E5650); }

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
		virtual void OnDetatch(SimObject*) = 0;
		virtual void NotifyProxyModeChanged(int proxyMode) = 0;
		virtual void _UnkVFunc12() = 0;
		virtual void _UnkVFunc13() = 0;

		/* Functions */

		template <typename T = SimComponent>
		T* GetComponentOfType(u32 type_uid = T::_TypeUID) { return m_pSimObject ? SDK_CALL_FUNC(T*, 0x190AD0, void*, u32)(m_pSimObject, type_uid) : nullptr; }
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

		enum eProxyMode
		{
			ePM_LOCAL,
			ePM_PROXY_LOCAL_PHYSICS,
			ePM_PROXY_REMOTE_PHYSICS
		};

		qSymbol m_Name;
		u16 m_Flags;
		s8 m_ReservedComponentSlots;
		s8 m_ResolveRefCount;
		SceneObjectProperties* m_pSceneObj;
		TransformNodeComponent* m_pTransformNodeComponent;
		qArray<SimComponentHolder> m_Components;
		qList<RebindingComponentHandleBase> m_UnboundComponentHandles;

		/* Virtual Functions */

		virtual void Attach(SimComponent* component, u32 index) = 0;
		virtual void Detach(SimComponent* component) = 0;

		/* Functions */

		SimComponent* GetComponentOfType(u32 type_uid) { return SDK_CALL_FUNC(SimComponent*, 0x190AD0, void*, u32)(this, type_uid); }

		template <typename T>
		SDK_INLINE T* GetComponentOfType() { return static_cast<T*>(GetComponentOfType(T::_TypeUID)); }

		void Destroy() { SDK_CALL_FUNC(void, 0x1905C0, void*)(this); }
		int Restore() { return SDK_CALL_FUNC(int, 0x1911F0, void*)(this); }
		int Suspend() { return SDK_CALL_FUNC(int, 0x1916D0, void*)(this); }

		/* Helpers */

		SDK_INLINE bool IsProp() { return m_Flags & Flag_is_prop; }
		SDK_INLINE bool IsCharacter() { return m_Flags & Flag_is_character; }
		SDK_INLINE bool IsVehicle() { return m_Flags & Flag_is_vehicle; }
	};
	SDK_ASSERT_SIZEOF(SimObject, 0x80);

	class SimObjectPointer : public qNode<SimObjectPointer>
	{
	public:
		SimObject* pObject;
	};
}