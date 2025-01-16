#pragma once

namespace UFG
{
	class UIGfxFileOpener : public Scaleform::GFx::FileOpener
	{
	public:
		bool mUsingChunkFiles;
	};
}