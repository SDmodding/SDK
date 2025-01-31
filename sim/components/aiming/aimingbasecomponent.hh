#pragma once

namespace UFG
{
	class AimingBaseComponent : public SimComponent, public UpdateInterface, public qNode<AimingBaseComponent>
	{
	public:
		enum { _TypeUID = 0xA2000001 };

		struct Accuracy
		{
			f32 m_fAccuracyUnclamped;
			f32 m_fAccuracyMinimum;
			f32 m_fAccuracyMaximum;
			f32 m_fAccuracyPenalty;
			f32 m_fAccuracyOverride;
			bool m_bEnsureMiss;

			void ApplyAccuracyModifiers(AimingBaseComponent* pABC, const bool bApplyToTargeter, f32& fAccuracyModifierInstant, f32& fAccuracyModifierContinuous) {
				SDK_CALL_FUNC(void, 0x521620, void*, AimingBaseComponent*, const bool, f32&, f32&)(this, pABC, bApplyToTargeter, fAccuracyModifierInstant, fAccuracyModifierContinuous);
			}
		};

		f32 m_fAimPositionDistance;
		f32 m_fAimTransitionRadPerS;
		f32 m_fAimTransitionMultiplier;
		int m_iAimOriginBoneID;
		qVector3 m_vAimOriginPosition;
		qVector3 m_vAimIntentionTargetPosition;
		qVector3 m_vAimPosition;
		qVector3 m_vAimIntention;
		qVector3 m_vAimDirectionLS;
		Accuracy m_Accuracy;
		qList<AccuracyModifierTask> m_AccuracyModifierTaskList;
		qList<AimingSoftLockDisableTask> m_AimingSoftLockDisableList;
		RebindingComponentHandle<TransformNodeComponent> m_TransformNodeComponent;
		RebindingComponentHandle<TargetingSystemPedBaseComponent> m_pTargetingSystemPedBaseComponent;
		RebindingComponentHandle<CharacterAnimationComponent> m_CharacterAnimationComponent;
		RebindingComponentHandle<CharacterOccupantComponent> m_CharacterOccupantComponent;

		/* Virtual Functions */

		virtual void _UnkVFunc14() = 0;
		virtual void _UnkVFunc15() = 0;
		virtual void _UnkVFunc16() = 0;
		virtual void _UnkVFunc17() = 0;
		virtual void _UnkVFunc18() = 0;
		virtual f32 GetAngularInaccuracyRad() = 0;
		virtual void GetFiringPositionAtAimPosition(qVector3& vFiringPositionAtAimPosition) = 0;
		virtual f32 GetRadialInaccuracyAtAimPosition() = 0;
		virtual void OnTargetChanged() = 0;

		/* Functions */

		void AddAccuracyModifierTask(AccuracyModifierTask* pAccuracyModifierTask) { SDK_CALL_FUNC(void, 0x520800, void*, AccuracyModifierTask*)(this, pAccuracyModifierTask); }
		void AddAimingSoftLockDisableTask(AimingSoftLockDisableTask* pAimingSoftLockDisableTask) { SDK_CALL_FUNC(void, 0x520840, void*, AimingSoftLockDisableTask*)(this, pAimingSoftLockDisableTask); }
		void ApplyAccuracyModifiers(bool bApplyToTargeter, f32* fAccuracyModifierInstant, f32* fAccuracyModifierContinuous) { SDK_CALL_FUNC(void, 0x521750, void*, bool, f32*, f32*)(this, bApplyToTargeter, fAccuracyModifierInstant, fAccuracyModifierContinuous); }
		bool CouldShootSomeoneUnintended(bool bIncludePedestrians, bool bIncludeHostages) { return SDK_CALL_FUNC(bool, 0x523CE0, void*, bool, bool)(this, bIncludePedestrians, bIncludeHostages); }
		void GetAimDirection(qVector3& vAimDirection, qMatrix44* pXform = 0) { SDK_CALL_FUNC(void, 0x52A750, void*, qVector3&, qMatrix44*)(this, vAimDirection, pXform); }
		f32 GetLocalAimDirectionXY() { return SDK_CALL_FUNC(f32, 0x52E290, void*)(this); }
		f32 GetLocalAimDirectionXYRelCover() { return SDK_CALL_FUNC(f32, 0x52E330, void*)(this); }
		f32 GetLocalAimDirectionXYRelSyncBone() { return SDK_CALL_FUNC(f32, 0x52E630, void*)(this); }
		f32 GetLocalAimDirectionXZ() { return SDK_CALL_FUNC(f32, 0x52E730, void*)(this); }
		void GetTargetNormalAimPosition(qVector3& vTargetNormalAimPosition, eTargetTypeEnum eTargetType, qMatrix44* pXform = 0) { 
			SDK_CALL_FUNC(void, 0x530470, void*, qVector3&, eTargetTypeEnum, qMatrix44*)(this, vTargetNormalAimPosition, eTargetType, pXform);
		}
		void GetWeaponProjectileDirection(qVector3& vWeaponProjectileDirection) { SDK_CALL_FUNC(void, 0x532FC0, void*, qVector3&)(this, vWeaponProjectileDirection); }
		void GetWeaponProjectileSpawnPosition(qVector3& vWeaponProjectileSpawnPosition) { SDK_CALL_FUNC(void, 0x5331B0, void*, qVector3&)(this, vWeaponProjectileSpawnPosition); }
		float GetWeaponProjectileSpeed() { return SDK_CALL_FUNC(float, 0x5338E0, void*)(this); }
		void UpdateLocalAimDirection(const qMatrix44& matToLocal, const qVector3& vAimAtPosition) {
			SDK_CALL_FUNC(void, 0x5605C0, void*, const qMatrix44&, const qVector3&)(this, matToLocal, vAimAtPosition);
		}
		void getPredictedPositionOffset(qVector3& vPredictedPositionOffset, SimObject* pSimObject, f32 fWeaponProjectileSpeed, f32 fAimIntentionTargetDistance) {
			SDK_CALL_FUNC(void, 0x569120, void*, qVector3&, SimObject*, f32, f32)(this, vPredictedPositionOffset, pSimObject, fWeaponProjectileSpeed, fAimIntentionTargetDistance);
		}
	};
	SDK_ASSERT_SIZEOF(AimingBaseComponent, 0x1A0);
}