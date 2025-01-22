#pragma once

namespace UEL
{
	class ParametersBase
	{
	public:
	};
}

class AimingUELParameters : public UEL::ParametersBase
{
public:
	UFG::qVector3* AimIntention;
};

class CharacterUELParameters : public UEL::ParametersBase
{
public:
	fastdelegate::FastDelegate0<UEL::Value> VelocityUELGetter;
};

class GangMemberUELParameters : public UEL::ParametersBase
{
public:
	const float* LocoSpeed;
	const float* GrappleDamage;
	const float* MitigateWorldCollision;
	const float* MitigateExplosive;
	const float* MitigateBallistic;
	const float* MitigateUnarmedMelee;
	const float* MitigateArmedMelee;
	const float* MitigateGrapple;
	const float* MaxHP;
	const float* MinHP;
	const float* HpBoost;
	const float* KoChance;
	const float* CritChance;
};

class HealthUELParameters : public UEL::ParametersBase
{
public:
	const f32* Current;
	const f32* Max;
};

class IntentionUELParameters : public UEL::ParametersBase
{
public:
	UFG::qVector3* Motion;
	const f32* MotionSpeed;
	UFG::qStaticBitField<548>* ActionRequests;
};

class ItemUELParameters : public UEL::ParametersBase
{
public:
	fastdelegate::FastDelegate0<UEL::Value> OwnerUELGetter;
};

class MeleeWeaponUELParameters : public UEL::ParametersBase
{
public:
	const f32* Damage;
	const f32* AttackSpeed;
	const f32* Durability;
	const f32* CritChance;
};

class RangedWeaponUELParameters : public UEL::ParametersBase
{
public:
	const f32* ReloadSpeed;
	const f32* Accuracy;
	const f32* AimRecover;
};

class TargetingUELParameters : public UEL::ParametersBase
{
public:
	fastdelegate::FastDelegate0<UEL::Value> GrappleUELGetter;
};

class ThrownWeaponUELParameters : UEL::ParametersBase
{
	const f32* Radius;
	const f32* Duration;
	const f32* Damage;
};

class UELParameters : public UEL::ParametersBase
{
public:
	fastdelegate::FastDelegate1<UFG::qSymbol const&, UEL::Value> PropertiesUELLookup;
	fastdelegate::FastDelegate0<UEL::Value> GangMember2UELGetter;
	fastdelegate::FastDelegate0<UEL::Value> MeleeWeapon2UELGetter;
	fastdelegate::FastDelegate0<UEL::Value> RangedWeapon2UELGetter;
	fastdelegate::FastDelegate0<UEL::Value> ThrownWeapon2UELGetter;
	HealthUELParameters* Health;
	AimingUELParameters* Aiming;
	IntentionUELParameters* Intention;
	CharacterUELParameters* Character;
	ItemUELParameters* Item;
	TargetingUELParameters* Targeting;
	GangMemberUELParameters* GangMember;
	MeleeWeaponUELParameters* MeleeWeapon;
	RangedWeaponUELParameters* RangedWeapon;
	ThrownWeaponUELParameters* ThrownWeapon;
};