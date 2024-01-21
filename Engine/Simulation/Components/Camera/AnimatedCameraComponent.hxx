#pragma once

namespace UFG
{
	class CAnimatedCameraComponent : public CGameCameraComponent
	{
	public:
		UFG_PAD(0xF0);

		// Use in Skookum (Animation > Begin/End)
		// If the pointer is not nullptr it means that skookum script is currently doing animation for cutscene camera...
		static UFG_INLINE CAnimatedCameraComponent* GetSkookumAnimatedCamera()
		{
			return *reinterpret_cast<CAnimatedCameraComponent**>(UFG_RVA(0x240C100));
		}
	};
	UFG_ASSERT_CLASS(CAnimatedCameraComponent, 0x5D0);
}