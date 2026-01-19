#pragma once

namespace Render
{
	class FXForceSettings : public UFG::qResourceData, public FXComponentSettings
	{
	public:
		f32 mIntensity;
		f32 mRadMin;
		f32 mRadMax;
	};

	class FXForceSettingsHandle : public UFG::qTypedResourceHandle<RTypeUID_FXForceSettings, FXForceSettings>
	{
	public:
	};
}