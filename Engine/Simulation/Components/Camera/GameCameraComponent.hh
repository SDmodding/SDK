#pragma once

namespace UFG
{
	class CGameCameraComponent : public CBaseCameraComponent
	{
	public:
		UFG_PAD(0x1F0);
	};
	UFG_ASSERT_CLASS(CGameCameraComponent, 0x4E0);
}