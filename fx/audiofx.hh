#pragma once

namespace Render
{
	class AudioFXSettings : public UFG::qResourceData, public FXComponentSettings
	{
	public:
		u32 mAudioNameHash;
	};

	class AudioFXSettingsHandle : public UFG::qTypedResourceHandle<RTypeUID_AudioFXSettings, AudioFXSettings>
	{
	public:
	};
}