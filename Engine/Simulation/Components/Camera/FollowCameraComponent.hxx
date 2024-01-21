#pragma once

namespace UFG
{
	class CFollowCameraComponent : public CGameCameraComponent
	{
	public:
		UFG_PAD(0xD4);

		float mDofFarFocalDist;

		RebindingComponentHandle<CCharacterSubjectComponent> mTarget;
		RebindingComponentHandle<void> mEnemyTarget;
		uint32_t mType;
		uint32_t mContext;
		uint32_t mPreviousType;
		uint32_t mPreviousContext;

		UFG_PAD(0x1438);

		qMatrix44 mTargetWorld;

		void Reset()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x3C8890))(this);
		}

		void GotoAngleSnap(float p_Radians, bool p_WorldSpace)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, bool)>(UFG_RVA(0x3C4B80))(this, p_Radians, p_WorldSpace);
		}

		void SetTarget(CSimObject* m_Target)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimObject*)>(UFG_RVA(0x3CD570))(this, m_Target);
		}
	};
}