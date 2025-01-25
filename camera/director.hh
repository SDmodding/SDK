#pragma once

namespace UFG
{
	class Director : public SimComponent, public qNode<Director>
	{
	public:
		BaseCameraComponent* mCurrentCamera;

		/* Static Functions */

		SDK_SINLINE Director* Instance() { return SDK_VAR_GET(Director*, 0x2173DF0); }

		/* Functions */

		void SetCurrentCamera(BaseCameraComponent* newCam) { SDK_CALL_FUNC(void, 0xBA270, void*, BaseCameraComponent*)(this, newCam); }
	};
}