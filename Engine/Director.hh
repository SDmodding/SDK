#pragma once

namespace UFG
{
	class CDirector : public SimComponent, public qNode<CDirector>
	{
	public:
		CBaseCameraComponent* mCurrentCamera;

		static UFG_INLINE CDirector* Instance()
		{
			return *reinterpret_cast<CDirector**>(UFG_RVA(0x2173DF0));
		}
		
		static UFG_INLINE CBaseCameraComponent* GetCurrentCamera()
		{
			return Instance()->mCurrentCamera;
		}

		UFG_INLINE void SetCurrentCamera(CBaseCameraComponent* p_NewCamera)
		{
			reinterpret_cast<void(__fastcall*)(void*, CBaseCameraComponent*)>(UFG_RVA(0xBA270))(this, p_NewCamera);
		}
	};
	UFG_ASSERT_CLASS(CDirector, 0x58);
}