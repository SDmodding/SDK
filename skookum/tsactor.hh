#pragma once

namespace UFG
{
	class TSActor : public SSActor
	{
	public:
		RebindingComponentHandle<TransformNodeComponent> mTransformNodeComponent;
		TSActorComponent* mpComponent;
		AudioEventController m_audioController;
		qSafePointer<SimObject> mpSimObj;

		/* Static Functions */

		SDK_SINLINE TSActor* FromSimObject(SimObject* pSimObj) { return SDK_CALL_FUNC(TSActor*, 0x4E0BC0, SimObject*)(pSimObj); }
		SDK_SINLINE TSActor* SkookumObjFromSimObj(SimObject* pSimObj) { return SDK_CALL_FUNC(TSActor*, 0x510480, SimObject*)(pSimObj); }
		SDK_SINLINE TSActor* find_instance(const qSymbol& instance_name) { return SDK_CALL_FUNC(TSActor*, 0x511890, const qSymbol&)(instance_name); }

		/* Functions */

		void OnDeinit() { SDK_CALL_FUNC(void, 0x50E870, void*)(this); }
		void OnInit(SimObject* pSimObj) { SDK_CALL_FUNC(void, 0x50EAF0, void*, SimObject*)(this, pSimObj); }
		void OnTeleport() { SDK_CALL_FUNC(void, 0x50EEC0, void*)(this); }
		void TeleportToTransform(const qMatrix44& transform) { SDK_CALL_FUNC(void, 0x511350, void*, const qMatrix44&)(this, transform); }
		void TeleportToTransformPreserveVel(const qMatrix44& transform) { SDK_CALL_FUNC(void, 0x511430, void*, const qMatrix44&)(this, transform); }
		void TeleportToTransformRaw(const qMatrix44 & transform) { SDK_CALL_FUNC(void, 0x511710, void*, const qMatrix44&)(this, transform); }
	};

	class TSActorComponent : public SimComponent
	{
	public:
		enum { _TypeUID = 0x8A000001 };

		AIdPtr<TSActor> mpActor;
		SSActorClass* mpActorClass;
	};
	SDK_ASSERT_SIZEOF(TSActorComponent, 0x58);
}