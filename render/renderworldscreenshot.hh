#pragma once

namespace Render
{
	enum ImageFileFormat
	{
		IMAGE_FILE_FORMAT_BMP,
		IMAGE_FILE_FORMAT_JPG,
		IMAGE_FILE_FORMAT_PNG,
		IMAGE_FILE_FORMAT_DDS
	};
}

class ScreenShotState
{
public:
	u32 mState;
	Illusion::Target* mTarget;
	void(__fastcall* mCallback)(Illusion::Target*);
	f32 mScale;
	Render::ImageFileFormat mFormat;

	/* Static Functions */

	SDK_SINLINE ScreenShotState* Instance() { return SDK_VAR(ScreenShotState*, 0x2023920); }

	/* Functions */

	void DoRequestedScreenShot() { SDK_CALL_FUNC(void, 0x4AFA0, void*)(this); }
};
