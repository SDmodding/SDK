#pragma once

class WheelState
{
public:
	bool mBlown;
};

class DamageRig
{
public:
	struct DamageMarker
	{
		u32 mBoneIndex;
		f32 mValue;
		f32 mSignal;
		f32 mTransferredDamage;
		UFG::qVector3 mPosition;
		u32 mNameUID;
		f32 mDamageScalar;
	};

	struct TriggeredMarker
	{
		u32 mBoneIndex;
		f32 mValue;
		f32 mSignal;
		UFG::qVector3 mPosition;
		u32 mNameUID;
		u32 mNumTriggers;
		u32* mTriggerIndices;
		f32 mDamageScalar;
	};

	u32 mNumDamageMarkers;
	u32 mNumTriggeredMarkers;
	DamageMarker* mDamageMarkers;
	TriggeredMarker* mTriggeredMarkers;
	f32 mAggregateDamage;
	f32 mWeightCache[256];
	u32 mWeightCacheCount;
	f32 mDamageOverride;
	bool mBurnedOut;
	s8 mDetachableBoneArray[256];
	f32 mGrimeFactor;
	WheelState mWheelModelBindingState[4];

	/* Functions */

	void ActivateTriggerMarker(const UFG::qVector3& position, UFG::VehicleEffectsComponent* const vehicle, bool bHighLODPlayFX) {
		SDK_CALL_FUNC(void, 0x3A0870, void*, const UFG::qVector3&, UFG::VehicleEffectsComponent* const, bool)(this, position, vehicle, bHighLODPlayFX);
	}

	void ActivateTriggerMarker(const u32 name_uid, UFG::VehicleEffectsComponent* const vehicle, bool bHighLODPlayFX) {
		SDK_CALL_FUNC(void, 0x3A08D0, void*, const u32, UFG::VehicleEffectsComponent* const, bool)(this, name_uid, vehicle, bHighLODPlayFX);
	}

	void ActivateTriggerMarkerByIndex(const u32 index, f32 damage, UFG::VehicleEffectsComponent* const vehicle, bool bHighLODPlayFX) {
		SDK_CALL_FUNC(void, 0x3A0920, void*, const u32, f32, UFG::VehicleEffectsComponent* const, bool)(this, index, damage, vehicle, bHighLODPlayFX);
	}

	void ApplyDamageForce(const UFG::qVector3& force_position, const f32 force, f32 estImpulse, UFG::VehicleEffectsComponent* const vehicle) {
		SDK_CALL_FUNC(void, 0x3A1EE0, void*, const UFG::qVector3&, const f32, f32, UFG::VehicleEffectsComponent* const)(this, force_position, force, estImpulse, vehicle);
	}

	void ApplyTriggerMarkerDamageByIndex(u32 index, f32 damage, UFG::VehicleEffectsComponent* const vehicle, bool bHighLODPlayFX) {
		SDK_CALL_FUNC(void, 0x3A2470, void*, u32, f32, UFG::VehicleEffectsComponent* const, bool)(this, index, damage, vehicle, bHighLODPlayFX);
	}

	f32 GetDamageAtPosition(const UFG::qVector3& pos) { return SDK_CALL_FUNC(f32, 0x3A7EA0, void*, const UFG::qVector3&)(this, pos); }
	bool GetDamageMarkerIndex(u32 name_uid, u32& index) { return SDK_CALL_FUNC(bool, 0x3A81A0, void*, u32, u32&)(this, name_uid, index); }
	bool GetTriggerMarkerHealth(const UFG::qVector3& position, f32& health_output) { return SDK_CALL_FUNC(bool, 0x3A9740, void*, const UFG::qVector3&, f32&)(this, position, health_output); }
	bool GetTriggerMarkerHealth(u32 name_uid, f32& health_output) { return SDK_CALL_FUNC(bool, 0x3A9970, void*, u32, f32&)(this, name_uid, health_output); }
	bool GetTriggerMarkerIndex(const UFG::qVector3& position, u32& index) { return SDK_CALL_FUNC(bool, 0x3A99B0, void*, const UFG::qVector3&, u32&)(this, position, index); }

	void GetWeightList(f32* remapped_array, int num_remapped_bones, const char* bone_remap_array) {
		SDK_CALL_FUNC(void, 0x3A9F20, void*, f32*, int, const char*)(this, remapped_array, num_remapped_bones, bone_remap_array);
	}

	void PlayDamageSfx(TriggeredMarker* marker) { SDK_CALL_FUNC(void, 0x3ACE10, void*, TriggeredMarker*)(this, marker); }
	void RemoveSignal(u32 name_uid, f32 value) { SDK_CALL_FUNC(void, 0x3AE0A0, void*, u32, f32)(this, name_uid, value); }

	void SetAllDamageMarkers(UFG::VehicleEffectsComponent* const vehicle, f32 damage, bool triggers_only, bool suppress_effects) {
		SDK_CALL_FUNC(void, 0x3AEDD0, void*, UFG::VehicleEffectsComponent* const, f32, bool, bool)(this, vehicle, damage, triggers_only, suppress_effects);
	}

	void SetDamageMarker(UFG::VehicleEffectsComponent* const vehicle, const u32 name_uid, f32 damage, bool affect_triggers, bool suppress_effects) {
		SDK_CALL_FUNC(void, 0x3AF020, void*, UFG::VehicleEffectsComponent* const, const u32, f32, bool, bool)(this, vehicle, name_uid, damage, affect_triggers, suppress_effects);
	}

	void SetDetachableBones(Skeleton* skeleton) { SDK_CALL_FUNC(void, 0x3AF1A0, void*, Skeleton*)(this, skeleton); }
	void SetSignal(u32 name_uid, f32 value) { SDK_CALL_FUNC(void, 0x3AF7E0, void*, u32, f32)(this, name_uid, value); }

	void UpdateTriggerMarkers(UFG::VehicleEffectsComponent* const vehicle, f32 estImpulse, bool suppressEffects) {
		SDK_CALL_FUNC(void, 0x3B4DE0, void*, UFG::VehicleEffectsComponent* const, f32, bool)(this, vehicle, estImpulse, suppressEffects);
	}
};
SDK_ASSERT_SIZEOF(DamageRig, 0x530);

class CharacterDamageRig
{
public:
	struct CharacterMarker
	{
		u32 mBoneIndex;
		i8 mValue[6];
		UFG::qVector3 mPosition;
		u32 mNameUID;
	};

	struct VisualDamageTarget
	{
		int boneID;
		f32 elapsedTime;
		f32 duration;
		i8 initialDamage[6];
		i8 targetDamage;
	};

	CharacterMarker mCharacterMarkers[26];
	f32 mPaintEffectApplied;
	UFG::qVector3 mPaintEffect;
	f32 mCharredEffectAmount;
	f32 mCharredEffectInitialAmount;
	f32 mCharredEffectElapsedTime;
	bool mDamaged;
	f32 mDamageScale;
	UFG::qArray<VisualDamageTarget> mVisualDamageTargets;

	/* Functions */

	void ApplyBluntForceDamageToBone(Creature* creature, const UFG::qVector4& hitPositionWS, const UFG::qVector4& invHitNormal, f32 damage, f32 health) {
		SDK_CALL_FUNC(void, 0x3A1E40, void*, Creature*, const UFG::qVector4&, const UFG::qVector4&, f32, f32)(this, creature, hitPositionWS, invHitNormal, damage, health);
	}

	void ApplyCharredEffect(f32 amount) { SDK_CALL_FUNC(void, 0x3A1EA0, void*, f32)(this, amount); }

	void ApplyDamageVector(Creature* creature, const UFG::qVector4& hitPositionWS, const UFG::qVector4& hitNormalWS, f32 damageAmount, f32 health) {
		SDK_CALL_FUNC(void, 0x3A2070, void*, Creature*, const UFG::qVector4&, const UFG::qVector4&, f32, f32)(this, creature, hitPositionWS, hitNormalWS, damageAmount, health);
	}

	void ApplyPaintEffect(bool enable, f32 r, f32 g, f32 b) { SDK_CALL_FUNC(void, 0x3A2430, void*, bool, f32, f32, f32)(this, enable, r, g, b); }
	void Clone(const CharacterDamageRig* source) { SDK_CALL_FUNC(void, 0x3A4F00, void*, const CharacterDamageRig*)(this, source); }

	void GetCharacterWeightList(f32* remapped_array, u32 num_remapped_bones, const char* bone_remap_array) {
		SDK_CALL_FUNC(void, 0x3A7C30, void*, f32*, u32, const char*)(this, remapped_array, num_remapped_bones, bone_remap_array);
	}

	void InitCharacterBoneNormals() { SDK_CALL_FUNC(void, 0x3AAE10, void*)(this); }
	void ResetDamage() { SDK_CALL_FUNC(void, 0x3AE110, void*)(this); }
	void SetVisualDamage(u32 bone_uid, f32 damage, f32 duration) { SDK_CALL_FUNC(void, 0x3AF920, void*, u32, f32, f32)(this, bone_uid, damage, duration); }
	void Update(f32 delta_sec) { SDK_CALL_FUNC(void, 0x3B1160, void*, f32)(this, delta_sec); }
};
SDK_ASSERT_SIZEOF(CharacterDamageRig, 0x310);