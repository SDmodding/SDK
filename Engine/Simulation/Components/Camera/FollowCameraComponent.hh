#pragma once

namespace UFG
{
	enum eFollowCameraContext : uint32_t
	{
		eFOLLOW_CONTEXT_WALK = 0x0,
		eFOLLOW_CONTEXT_SPRINT = 0x1,
		eFOLLOW_CONTEXT_WALK_SLOW = 0x2,
		eFOLLOW_CONTEXT_SOCIAL = 0x3,
		eFOLLOW_CONTEXT_AIM = 0x4,
		eFOLLOW_CONTEXT_AIM_PHONE = 0x5,
		eFOLLOW_CONTEXT_AIM_SNIPER = 0x6,
		eFOLLOW_CONTEXT_AIM_AIRBORNE = 0x7,
		eFOLLOW_CONTEXT_WALK_TARGETED = 0x8,
		eFOLLOW_CONTEXT_WALK_WGUN = 0x9,
		eFOLLOW_CONTEXT_SPRINT_WGUN = 0xA,
		eFOLLOW_CONTEXT_OVERRIDE_TOW = 0xB,
		eFOLLOW_CONTEXT_OVERRIDE_AIM = 0xC,
		eFOLLOW_CONTEXT_OVERRIDE_FOCUS = 0xD,
		eFOLLOW_CONTEXT_OVERRIDE_GRAPPLE = 0xE,
		eFOLLOW_CONTEXT_COUNT = 0xF,
		eFOLLOW_CONTEXT_COUNT_NON_OVERRIDES = 0xB,
	};

	//================================================================================================================================

	class CFollowCameraComponent : public CGameCameraComponent
	{
	public:
		UFG_PAD(0xD4);

		float mDofFarFocalDist;

		RebindingComponentHandle<CCharacterSubjectComponent> mTarget;
		RebindingComponentHandle<void> mEnemyTarget;
		uint32_t mType;
		eFollowCameraContext mContext;
		uint32_t mPreviousType;
		eFollowCameraContext mPreviousContext;

		UFG_PAD(0x1438);

		qMatrix44 mTargetWorld;

		UFG_INLINE bool IsUsingHighZoom()
		{
			return (this->mContext == eFOLLOW_CONTEXT_AIM_SNIPER);
		}

		UFG_INLINE void Reset()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x3C8890))(this);
		}

		UFG_INLINE void GotoAngleSnap(float p_Radians, bool p_WorldSpace)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, bool)>(UFG_RVA(0x3C4B80))(this, p_Radians, p_WorldSpace);
		}

		UFG_INLINE void SetTarget(CSimObject* m_Target)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimObject*)>(UFG_RVA(0x3CD570))(this, m_Target);
		}
	};
}