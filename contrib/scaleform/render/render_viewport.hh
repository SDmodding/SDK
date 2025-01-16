#pragma once

namespace Scaleform::Render
{
	class Viewport
	{
	public:
		int BufferWidth;
		int BufferHeight;
		int Left;
		int Top;
		int Width;
		int Height;
		int ScissorLeft;
		int ScissorTop;
		int ScissorWidth;
		int ScissorHeight;
		u32 Flags;
	};
}