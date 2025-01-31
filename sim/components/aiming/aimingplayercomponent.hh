#pragma once

namespace UFG
{
	class AimingPlayerComponent : public AimingBaseComponent, public qNode<AimingPlayerComponent>
	{
	public:
		enum { _TypeUID = 0xA2000003 };

		enum eAimBlendMode
		{
			eAIM_BLEND_MODE_NONE,
			eAIM_BLEND_MODE_FREEAIM,
			eAIM_BLEND_MODE_FREEAIM_TARGET,
			eAIM_BLEND_MODE_SUBTARGETING
		};

		enum eReticleMode
		{
			eReticleMode_First,
			eReticleMode_Centered = eReticleMode_First,
			eReticleMode_FollowAP,
			eReticleMode_FollowAITP,
			eReticleMode_FollowAITPCollOnly,
			eReticleMode_Last = eReticleMode_FollowAITPCollOnly,
			eReticleMode_NumModes
		};

		enum eSoftLockTypeEnum
		{
			eSOFT_LOCK_NONE,
			eSOFT_LOCK_ABSOLUTE,
			eSOFT_LOCK_RELATIVE_LOCAL,
			eSOFT_LOCK_RELATIVE_LOCAL_ORIENTED_TO_ORIGIN,
			NUM_SOFT_LOCK_TYPES
		};

		RebindingComponentHandle<TargetingSystemPedPlayerComponent> m_pTSPPC;
		bool m_bFocusTargetProbed;
		bool m_bFocusTargetObstructed;
		bool m_bCameraZoomMode;
		bool m_bUsingCover;
		bool m_bSupressReticle;
		bool m_bPreventFreeAimSpeedModifier;
		bool m_bAimingControlsCamera;
		f32 m_fBlendedReticleSize;
		f32 m_fBlendedReticleRadius;
		f32 m_fOverrideReticleSize;
		f32 m_fAxisXSpeed;
		f32 m_fAxisYSpeed;
		f32 m_fDampenedAxisXSpeed;
		f32 m_fDampenedAxisYSpeed;
		f32 m_fAimObstructedDuration;
		qVector3 m_vFreeAimLastFramePosition;
		qVector3 m_vFreeAimCastOrigin;
		bool m_bFreeAimRootDirty;
		qVector3 m_vFreeAimRootPosSS;
		qQuaternion m_qFreeAimRootOriSS;
		bool m_bFreeAimRootMovementLock;
		qVector3 m_vFreeAimOrigin;
		qVector3 m_vFreeAimBaseOffset;
		qVector3 m_vFreeAimIntention;
		qVector3 m_vFreeAimTargetPosition;
		qSafePointer<SimObject> m_FreeAimSimObject;
		qReflectHandle<PhysicsObjectProperties> m_FreeAimPhysicsObjectProperties;
		int m_iFreeAimOriginBoneID;
		int m_iFreeAimSyncBoneID;
		f32 m_fReticleBlend;
		f32 m_fReticleBlendRate;
		qVector2 m_vReticleLockedOnCoordsScreen;
		qVector2 m_vReticleBlendedCoordsScreen;
		qVector3 m_vFocusTargetSegA;
		qVector3 m_vFocusTargetSegB;
		qVector3 m_vFocusTargetClosestPos;
		qVector3 m_vFocusTargetSegClosestPos;
		f32 m_fFocusTargetRadius;
		f32 m_fFocusTargetDistanceSeg;
		bool m_bResetSoftLockOffset;
		eSoftLockTypeEnum m_eSoftLockType;
		qVector3 m_vSoftLockOffset;
		f32 m_fFreeAimSpeedModifier;
		f32 m_fInterpolatedFreeAimConeClamp;
		eTargetTypeEnum m_eSnapFreeAimIntentionToTarget;
		qList<AimingSoftLockTask> m_AimingSoftLockTaskList;
		qList<AimingFreeAimConeClampTask> m_AimingFreeAimConeClampTaskList;
		bool m_bPerformAimObscuredCheck : 1;
		f32 m_fUnobscuredAimCheckDistance;
		f32 m_fUnobscuredAimTargetPositionPadDistance;
		f32 m_fUnobscuredAimNewPositionPadDistance;
		qSafePointer<SimObject> m_pAimTargetPositionSimObject;
		qSafePointer<TransformNodeComponent> m_pAimTargetPositionTNC;
		eAimBlendMode m_eAimBlendMode;

		/* Functions */

		void AddAimingFreeAimConeClampTask(AimingFreeAimConeClampTask* pAimingFreeAimConeClampTask) {
			SDK_CALL_FUNC(void, 0x520820, void*, AimingFreeAimConeClampTask*)(this, pAimingFreeAimConeClampTask);
		}
		void AddAimingSoftLockTask(AimingSoftLockTask* pAimingSoftLockTask) { SDK_CALL_FUNC(void, 0x520860, void*, AimingSoftLockTask*)(this, pAimingSoftLockTask); }
		f32 ComputeRenderReticleRadius(bool screenSpace) { return SDK_CALL_FUNC(f32, 0x523160, void*, bool)(this, screenSpace); }
		qVector3 GetFreeAimFocusPosition() { return SDK_CALL_FUNC(qVector3, 0x52D900, void*)(this); }
		f32 GetReticleSize() { return SDK_CALL_FUNC(f32, 0x52FA40, void*)(this); }
		bool GetWeaponProjectileSpawnPositionUnobscured(const qVector3& vToPosition, qVector3& vPositionReturn) {
			return SDK_CALL_FUNC(bool, 0x533600, void*, const qVector3&, qVector3&)(this, vToPosition, vPositionReturn);
		}
		void ResetFreeAimIntention() { SDK_CALL_FUNC(void, 0x549DD0, void*)(this); }
		void SetFreeAimIntention(const qVector3& vDirection) { SDK_CALL_FUNC(void, 0x54D300, void*, const qVector3&)(this, vDirection); }
		void SnapAccuracy(f32 fAccuracy) { SDK_CALL_FUNC(void, 0x54FCE0, void*, f32)(this, fAccuracy); }
		f32 getDistanceFromFreeAimOriginToStartRaycast() { return SDK_CALL_FUNC(f32, 0x5683C0, void*)(this); }
	};
}