#pragma once

// Move this to appropriate file.
namespace UFG
{
	enum GameStatEventType
	{
		GameStatEvent_None,
		GameStatEvent_Bike_BackSideShoot,
		GameStatEvent_Bike_Wheelie_End,
		GameStatEvent_Bike_Wheelie_Start,
		GameStatEvent_Continuous_DriveCar,
		GameStatEvent_Continuous_ExitCar,
		GameStatEvent_Cop_ArrestAttempt,
		GameStatEvent_Cover_End,
		GameStatEvent_Cover_Start,
		GameStatEvent_EquipSlot_01,
		GameStatEvent_EquipSlot_02,
		GameStatEvent_EquipSlot_03,
		GameStatEvent_EquipSlot_04,
		GameStatEvent_EquipSlot_05,
		GameStatEvent_EquipSlot_06,
		GameStatEvent_EquipSlot_07,
		GameStatEvent_EquipSlot_08,
		GameStatEvent_EquipSlot_09,
		GameStatEvent_EquipSlot_10,
		GameStatEvent_FSR_AttackPropInteract,
		GameStatEvent_FSR_Berserk,
		GameStatEvent_FSR_BlindfireKill,
		GameStatEvent_FSR_Block_Attack,
		GameStatEvent_FSR_CarWrecked,
		GameStatEvent_FSR_ChargeKickFollowUp,
		GameStatEvent_FSR_Counter,
		GameStatEvent_FSR_Counter_Failed,
		GameStatEvent_FSR_DamageAlly,
		GameStatEvent_FSR_DamageCivilian,
		GameStatEvent_FSR_DamageCop,
		GameStatEvent_FSR_Disarm,
		GameStatEvent_FSR_DisarmFail,
		GameStatEvent_FSR_DoorRunningOpenFail,
		GameStatEvent_FSR_DoorRunningOpenSuccess,
		GameStatEvent_FSR_EnemyKnockdown,
		GameStatEvent_FSR_EnvironmentalKill,
		GameStatEvent_FSR_EnvironmentAttack,
		GameStatEvent_FSR_ExplosionKill,
		GameStatEvent_FSR_Fake_Enemy,
		GameStatEvent_FSR_FallOnFace,
		GameStatEvent_FSR_FallStart,
		GameStatEvent_FSR_FastTalkSuccess,
		GameStatEvent_FSR_FlipOver,
		GameStatEvent_FSR_Flourish,
		GameStatEvent_FSR_GetUpKick,
		GameStatEvent_FSR_Grapple,
		GameStatEvent_FSR_GrappleThrow,
		GameStatEvent_FSR_Healing_Skill,
		GameStatEvent_FSR_HeavyAttack,
		GameStatEvent_FSR_Intimidate_Enemy,
		GameStatEvent_FSR_Intimidate_Group,
		GameStatEvent_FSR_Kidnap,
		GameStatEvent_FSR_KO_Enemy,
		GameStatEvent_FSR_LandFailed,
		GameStatEvent_FSR_LandRoll,
		GameStatEvent_FSR_LandSuccess,
		GameStatEvent_FSR_LightAttack,
		GameStatEvent_FSR_LimbBroken,
		GameStatEvent_FSR_MurderAlly,
		GameStatEvent_FSR_MurderCivilian,
		GameStatEvent_FSR_MurderCop,
		GameStatEvent_FSR_MurderHostile,
		GameStatEvent_FSR_MurderHostile_Explosion,
		GameStatEvent_FSR_MurderHostile_HeadShot,
		GameStatEvent_FSR_PalmStrike,
		GameStatEvent_FSR_Player_Hit,
		GameStatEvent_FSR_Player_Shot,
		GameStatEvent_FSR_PlayerKnockdown,
		GameStatEvent_FSR_Punch_Enemy,
		GameStatEvent_FSR_RunJumpKick,
		GameStatEvent_FSR_Sharpshooter,
		GameStatEvent_FSR_SneakKill,
		GameStatEvent_FSR_SprintPush,
		GameStatEvent_FSR_SprintPushCrash,
		GameStatEvent_FSR_StunElbow,
		GameStatEvent_FSR_StunFinisher,
		GameStatEvent_FSR_StunKnee,
		GameStatEvent_FSR_Tackle,
		GameStatEvent_FSR_TackleStrike,
		GameStatEvent_FSR_Taunt_Enemy,
		GameStatEvent_FSR_ThrownOverRailing,
		GameStatEvent_FSR_ThrownWeaponKill,
		GameStatEvent_FSR_Vault_BigClimbUpFail,
		GameStatEvent_FSR_Vault_BigClimbUpSuccess,
		GameStatEvent_FSR_Vault_ClimbUpFail,
		GameStatEvent_FSR_Vault_ClimbUpSuccess,
		GameStatEvent_FSR_Vault_Attack,
		GameStatEvent_FSR_VaultFail,
		GameStatEvent_FSR_VaultShoot,
		GameStatEvent_FSR_VaultSuccess,
		GameStatEvent_FSR_Weapon_EnemyKnockdown,
		GameStatEvent_FSR_Weapon_HeavyAttack,
		GameStatEvent_FSR_Weapon_LightAttack,
		GameStatEvent_Social_ActionFail,
		GameStatEvent_Social_ActionSuccess,
		GameStatEvent_Social_Greet,
		GameStatEvent_Vehicle_ActionHijack,
		GameStatEvent_Vehicle_ActionHijackHostile,
		GameStatEvent_Vehicle_CollideObject,
		GameStatEvent_Vehicle_CruisingDamaged,
		GameStatEvent_Vehicle_CruisingUndamaged,
		GameStatEvent_Vehicle_ExitDamaged,
		GameStatEvent_Vehicle_ExitUndamaged,
		GameStatEvent_Vehicle_Hijack,
		GameStatEvent_Vehicle_HijackFail,
		GameStatEvent_Vehicle_Purchase,
		GameStatEvent_Vehicle_Steal,
		GameStatEvent_Max
	};

}

namespace UFG
{
	class ScoreAffector
	{
	public:
		f32 mPoints;
		f32 mCurrentMultiplier;
		f32 mMultiplierReplenishRate;
		f32 mMultiplierReduction;
		f32 mMultiplierResetTimer;
		u64 mTimestamp;
		bool mIsActive;
		qString mCaption;

		/* Impl Functions */

		SDK_INLINE void Reset() { mIsActive = 0; mCurrentMultiplier = 1.f; }

		/* Functions */

		f32 Trigger() { return SDK_CALL_FUNC(f32, 0x556DC0, void*)(this); }
		f32 Update(f32 deltaTime) { return SDK_CALL_FUNC(f32, 0x55C510, void*, f32)(this, deltaTime); }
	};

	class FaceEventParameters
	{
	public:
		enum FaceEventParameterType
		{
			FaceEventParameter_Unknown = GameStatEvent_Max,
			FaceEventParameter_FSR_Damage_SimObject,
			FaceEventParameter_FSR_Murder_SimObject
		};

		int mType;
		SimObject* mpSimObject;
		qPropertySet* mpPropertySet;
		bool mIsApply;
	};

	class FaceMeterComponent : public SimComponent, public qNode<FaceMeterComponent>
	{
	public:
		enum { _TypeUID = 0x9A000001 };

		ScoreAffector mAffectors[GameStatEvent_Max];
		u64 mLastActionPerformedTimestamp;
		bool mFaceMeterEnabled;
		bool mFaceMeterActivated;
		PropertySetHandle mProperties;

		/* Virtual Functions */

		virtual void Update(f32 deltaTime) = 0;

		/* Functions */

		bool ApplyEvent(const FaceEventParameters& parameters) { return SDK_CALL_FUNC(bool, 0x521E80, void*, const FaceEventParameters&)(this, parameters); }
		void HandleGameStatEvent(Event* e) { SDK_CALL_FUNC(void, 0x534200, void*, Event*)(this, e); }
		void Reset() { SDK_CALL_FUNC(void, 0x549660, void*)(this); }
		void SetFaceMeterActivated(bool bFaceMeterActivated) { SDK_CALL_FUNC(void, 0x54C900, void*, bool)(this, bFaceMeterActivated); }
		bool _ApplyEvent(GameStatEventType eventType) { return SDK_CALL_FUNC(bool, 0x563750, void*, GameStatEventType)(this, eventType); }
		bool _ApplyEvent(GameStatEventType eventType, qPropertySet* pPropertySet) { return SDK_CALL_FUNC(bool, 0x563840, void*, int, qPropertySet*)(this, eventType, pPropertySet); }
		void _HandleInVehicleReplenish(f32 deltaTime) { SDK_CALL_FUNC(void, 0x563BA0, void*, f32)(this, deltaTime); }
		bool _UnapplyEvent(GameStatEventType eventType, qPropertySet* pPropertySet) { return SDK_CALL_FUNC(bool, 0x563DC0, void*, int, qPropertySet*)(this, eventType, pPropertySet); }
	};
}