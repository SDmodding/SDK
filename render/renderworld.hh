#pragma once

namespace UFG
{
	class RenderWorld
	{
	public:
		/* Static Members */

		SDK_VINLINE qGlobalPVar<SimObject*, 0x21363B0> msRenderStagePlugin;

		/* Static Functions */

		SDK_SINLINE void RequestScreenShot(void* function_callback, f32 scale = 1.f, Render::ImageFileFormat format = Render::IMAGE_FILE_FORMAT_JPG) {
			SDK_CALL_FUNC(void, 0x5AED0, void*, f32, Render::ImageFileFormat)(function_callback, scale, format);
		}
	};
}