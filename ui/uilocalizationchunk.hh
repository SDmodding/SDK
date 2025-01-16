#pragma once

namespace UFG
{
	class UILocalizationChunk : public qResourceData
	{
	public:
		u32 mChunkSize;
		u32 mPadding;
		qOffset64<void*> mChunkData;
	};
	SDK_ASSERT_SIZEOF(UILocalizationChunk, 0x68);

	class UILocalizationChunkHandle : public qTypedResourceHandle<RTypeUID_UILocalizationChunk, UFG::UILocalizationChunk>{};
}