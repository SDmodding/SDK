#pragma once

namespace Render
{
	class GeoSettings : public UFG::qResourceData, public FXComponentSettings
	{
	public:
		UFG::qColour mColorAlphaKeys[4];
		f32 mColorKeyPositions[4];
		f32 mAlphaKeyPositions[4];
		f32 mSizeKeyPositions[4];
		UFG::qVector3 mSizeKeys[4];
		u32 mModelUID;
		f32 mFadeDistance;
		f32 mFadeSpan;
	};
}