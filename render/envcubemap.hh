#pragma once

namespace Render
{
	class EnvCubeMap
	{
	public:
		Illusion::Target* mTarget;
		Illusion::Target* mSideTarget;
		Illusion::Material* mMSAADownsampleMaterial;
		__declspec(align(16)) Render::ViewSettings mViewSettings[6];
		Illusion::Texture* mDebugOverlay[6];
		UFG::qString mFaceName[6];
		f32 mFrameTime;
		u32 mNumDrawCalls;
	};
	SDK_ASSERT_SIZEOF(EnvCubeMap, 0x4B0);
}