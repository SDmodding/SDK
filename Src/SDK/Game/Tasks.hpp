#pragma once

namespace UFG
{
	class CReadControllerInputTask
	{
	public:
		UFG_PAD(0x28);

		CActionContext* m_pContext;
		qVector2 mLockedPadModified;

		UFG_PAD(0x10);

		CAICharacterControllerBaseComponent* m_pAICharacterControllerComponent;

		UFG_PAD(0x10);

		CAimingBaseComponent* m_pAimingBaseComponent;

		UFG_PAD(0x10);

		CTargetingSystemBaseComponent* m_pTargetingSystemPedPlayerComponent;

		void Begin(CActionContext* m_Context)
		{
			reinterpret_cast<void(__fastcall*)(void*, CActionContext*)>(UFG_RVA(0x2F2F30))(this, m_Context);
		}

		void Update(float timeDelta)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x307EC0))(this, timeDelta);
		}
	};
}