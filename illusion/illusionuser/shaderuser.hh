#pragma once

namespace Illusion
{
	class ShaderUser
	{
	public:
		ShaderHandle mOverride_OutputDepth;
		ShaderHandle mOverride_OutputDepthAlpha;
		ShaderHandle mOverride_OutputDepthAlphaWind;
		ShaderHandle mOverride_OutputDepthWind;
		ShaderHandle mOverride_OutputHighlight;
		ShaderTemplateHandle mShaderTemplateHandle;
		bool mIgnoreOverrides;
	};
}