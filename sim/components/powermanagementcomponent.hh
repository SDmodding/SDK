#pragma once

namespace UFG
{
	class PowerManagedResource : public qNode<PowerManagedResource>
	{
	public:
		virtual void UnbindResources() = 0;
		virtual void RebindResources() = 0;
		virtual bool AreResourcesAvailable() = 0;
	};

	class PowerManagementComponent : public SimComponent, public qSafePointerNode<PowerManagementComponent>, public qNode<PowerManagementComponent>
	{
	public:
		enum { _TypeUID = 0xD0000001 };

		enum ePowerStateEnum
		{
			ePOWER_STATE_NORMAL,
			ePOWER_STATE_SUSPENDED,
			ePOWER_STATE_SUSPENDED_PERMANENTLY,
			ePOWER_STATE_RESUMING,
			NUM_POWER_STATES
		};

		ePowerStateEnum m_ePowerStateEnum;
		f32 m_fSuspendDistanceSquared;
		f32 m_fPreventSuspendTimeS;
		s8 m_cPreventSuspendRefCount;
		qList<PowerManagedResource, struct PowerManagedResourceList, 0> m_PowerManagedResourceList;

		/* Static Functions */

		SDK_SINLINE PowerManagementComponent* PropertiesOnActivate(SceneObjectProperties* pSceneObjectProperties) {
			return SDK_CALL_FUNC(PowerManagementComponent*, 0x58A400, SceneObjectProperties*)(pSceneObjectProperties);
		}

		/* Impl Functions */

		SDK_INLINE void AddPreventSuspendRefCount() { ++m_cPreventSuspendRefCount; }
		SDK_INLINE void AllowSuspend() { m_fPreventSuspendTimeS = -1.f; }

		SDK_INLINE void RemovePreventSuspendRefCount()
		{
			if (m_cPreventSuspendRefCount > 0) {
				--m_cPreventSuspendRefCount;
			}
		}

		/* Functions */

		void AddPowerManagedResource(PowerManagedResource* pPowerManagedResource) { SDK_CALL_FUNC(void, 0x57EF40, void*, PowerManagedResource*)(this, pPowerManagedResource); }
		void PermanentlySuspend() { SDK_CALL_FUNC(void, 0x5885F0, void*)(this); }
		void PreventSuspendIndefinitely() { SDK_CALL_FUNC(void, 0x588900, void*)(this); }
		void PreventSuspendTemporarily(f32 fTimeS) { SDK_CALL_FUNC(void, 0x588930, void*, f32)(this, fTimeS); }
		void Reset() { SDK_CALL_FUNC(void, 0x58B340, void*)(this); }
		bool areResourcesAvailable() { return SDK_CALL_FUNC(bool, 0x591BB0, void*)(this); }
		void gotoResumed() { SDK_CALL_FUNC(void, 0x591EE0, void*)(this); }
		void gotoSuspended() { SDK_CALL_FUNC(void, 0x592310, void*)(this); }
		void updatePowerStateNormal(const qVector3& posPlayer, f32 fDeltaS) { SDK_CALL_FUNC(void, 0x5926B0, void*, const qVector3&, f32)(this, posPlayer, fDeltaS); }
		void updatePowerStateSuspended(const qVector3& posPlayer) { SDK_CALL_FUNC(void, 0x592850, void*, const qVector3&)(this, posPlayer); }
	};
	SDK_ASSERT_SIZEOF(PowerManagementComponent, 0x88);
}