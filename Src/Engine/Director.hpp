#pragma once

namespace UFG
{
	class CDirector : public CSimComponent
	{
	public:
		char m_Pad0[0x10];

		CBaseCameraComponent* mCurrentCamera;
	};

	namespace Director
	{
		CDirector* Get()
		{
			return *reinterpret_cast<CDirector**>(UFG_RVA(0x2173DF0));
		}

		CBaseCameraComponent* GetCurrentCamera()
		{
			return Get()->mCurrentCamera;
		}
	}
}