#pragma once

namespace Render
{
	class TrackStripSettings : public UFG::qResourceData, public FXComponentSettings
	{
	public:
		u32 mShaderUID;
		u32 mTextureUID;
		f32 mWidth;
		f32 mMinLength;
		f32 mMaxClusterLength;
		f32 mUVTile;
		f32 mLifeMin;
		f32 mLifeMax;
	};

	class TrackStripSettingsHandle : public UFG::qTypedResourceHandle<RTypeUID_TrackStripSettings, TrackStripSettings>
	{
	public:
	};
}