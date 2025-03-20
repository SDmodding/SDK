#pragma once

namespace UFG
{
	class CharacterAnimationComponent : public BaseAnimationComponent, public qNode<CharacterAnimationComponent>
	{
	public:
		enum { _TypeUID = 0xC6000003 };

		bool mEnableUpdateTransforms;
		CharacterDamageRig* mDamageRig;

		/* Functions */

		void ApplyBluntForceDamage(Creature* creature, const qVector4& hitPositionWS, const qVector4& invHitNormal, f32 damage) {
			SDK_CALL_FUNC(void, 0x57F060, void*, Creature*, const qVector4&, const qVector4&, f32)(this, creature, hitPositionWS, invHitNormal, damage);
		}

		void ApplyBulletDamage(const RayCastData& bulletRay) { SDK_CALL_FUNC(void, 0x57F150, void*, const RayCastData&)(this, bulletRay); }
		void ApplyCharredEffect(f32 amt) { SDK_CALL_FUNC(void, 0x57F270, void*, f32)(this, amt); }
		void ApplyPaintEffect(bool enable, f32 r, f32 g, f32 b) { SDK_CALL_FUNC(void, 0x57F280, void*, bool, f32, f32, f32)(this, enable, r, g, b); }
		void Clone(const CharacterAnimationComponent* source) { SDK_CALL_FUNC(void, 0x57F7B0, void*, const CharacterAnimationComponent*)(this, source); }
		void CreateDamageRig() { SDK_CALL_FUNC(void, 0x580570, void*)(this); }
		void Restore() { SDK_CALL_FUNC(void, 0x58B510, void*)(this); }
		void SetVisualDamage(u32 bone_uid, f32 damageAmount, f32 duration) { SDK_CALL_FUNC(void, 0x58BBC0, void*, u32, f32, f32)(this, bone_uid, damageAmount, duration); }
	};
}