#pragma once

namespace UFG
{
	class CChaseCameraComponent : public CGameCameraComponent
	{
	public:
		void Reset()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x3C8730))(this);
		}

		void GotoAngleSnap(float p_Radians, bool p_WorldSpace)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, bool)>(UFG_RVA(0x3C4990))(this, p_Radians, p_WorldSpace);
		}
	};
}