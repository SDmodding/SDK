#pragma once

namespace UFG
{
	class HitRecord;
	class HealthRegenerateTask;

	class HealthComponent : public SimComponent, public qNode<HealthComponent>
	{
	public:
		enum { _TypeUID = 0xAA000001 };

		bool m_bInitialized;
		f32 m_fHealth;
		f32 m_fMinHealth;
		f32 m_fMaxHealth;
		f32 m_fMaxUpgradedHealth;
		f32 m_NonPlayerDamageMultiplier;
		f32 m_ProjectileDamageMultiplier;
		f32 m_fHealthBoost;
		f32 m_fArmour;
		bool m_bIsKnockedOut;
		bool m_bIsInvulnerable;
		bool m_bIsTakingDamage;
		bool m_bRegenerativeHealthLossPenaltyAllowed;
		bool m_bHasDeathTouch;
		bool m_bHealthClampedToMinimum;
		f32 m_fRegenerativeHealthRate;
		f32 m_fRegenerativeHealthRatio;
		RebindingComponentHandle<HitReactionComponent> m_HitReactionComponent;
		RebindingComponentHandle<CharacterAnimationComponent> m_CharacterAnimationComponent;
		f32 m_fTimeOfDeath;
		f32 m_fRegenerationDelayS;
		f32 m_fTimeSinceDamagedS;
		qList<HealthRegenerateTask> m_HealthRegenerateTaskList;
		bool m_bAttackDir[4];

		/* Functions */

		void AddHealthRegenerateTask(HealthRegenerateTask* pHealthRegenerateTask) { 
			reinterpret_cast<void(SDK_CALL*)(void*, HealthRegenerateTask*)>(SDK_RVA(0x5209C0))(this, pHealthRegenerateTask); 
		}

		bool ApplyHealthDamage(const int iDamage, SimObject* pAttacker, HitRecord* pHitRecord, bool bProjectileDamage) { 
			return reinterpret_cast<bool(SDK_CALL*)(void*, const int, SimObject*, HitRecord*, bool)>(SDK_RVA(0x521F60))(this, iDamage, pAttacker, pHitRecord, bProjectileDamage); 
		}

		bool IsProjectileAttack() { return reinterpret_cast<bool(SDK_CALL*)(void*)>(SDK_RVA(0x53BF00))(this); }

		void LoadHealthSettings() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x53C950))(this); }

		void OnDeath(HitRecord* pReferenceHitRecord) { reinterpret_cast<void(SDK_CALL*)(void*, HitRecord*)>(SDK_RVA(0x53F4F0))(this, pReferenceHitRecord); }

		void ReplenishHealth() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x549620))(this); }

		void Reset(component_Health* data_ptr) { reinterpret_cast<void(SDK_CALL*)(void*, component_Health*)>(SDK_RVA(0x5496F0))(this, data_ptr); }

		void Reset() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x5497A0))(this); }

		void SetDirectionalDamage(SimObject* pAttacker) { reinterpret_cast<void(SDK_CALL*)(void*, SimObject*)>(SDK_RVA(0x54C6F0))(this, pAttacker); }

		bool SetHealth(const int uHealth, HitRecord* pReferenceHitRecord = 0) { 
			return reinterpret_cast<bool(SDK_CALL*)(void*, const int, HitRecord*)>(SDK_RVA(0x54D3D0))(this, uHealth, pReferenceHitRecord); 
		}

		void SetMaxHealth(const int iMaxHealth) { reinterpret_cast<void(SDK_CALL*)(void*, const int)>(SDK_RVA(0x54D980))(this, iMaxHealth); }

		void SetMinHealth(const int iMinHealth) { reinterpret_cast<void(SDK_CALL*)(void*, const int)>(SDK_RVA(0x54DA00))(this, iMinHealth); }

		void SetRegenerativeHealthRatio(f32 fRegenerativeHealthRatio, bool saveSnapshot = false) { 
			reinterpret_cast<void(SDK_CALL*)(void*, f32, bool)>(SDK_RVA(0x54E570))(this, fRegenerativeHealthRatio, saveSnapshot);
		}

		bool ShouldRegenerateHealth() { return reinterpret_cast<bool(SDK_CALL*)(void*)>(SDK_RVA(0x54FAE0))(this); }

		void Update(f32 delta_sec) { reinterpret_cast<void(SDK_CALL*)(void*, f32)>(SDK_RVA(0x55B3B0))(this, delta_sec); }

		/* Static Functions */

		SDK_SINLINE void UpdateAll(f32 sim_time_delta) { reinterpret_cast<void(SDK_CALL*)(f32)>(SDK_RVA(0x55E180))(sim_time_delta); }
	};
	SDK_ASSERT_SIZEOF(HealthComponent, 0x110);
}