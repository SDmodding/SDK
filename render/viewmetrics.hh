#pragma once

namespace Render
{
	class ViewMetrics
	{
	public:
		u64 mTargetTimingStartTicks;
		f32 mTargetTiming;
		f32 mDrawScenery;
		f32 mDrawComposite;
		f32 mDrawLights;
		f32 mClouds;
		u32 mPad0;
		u32 mNumCompositeProcessed;
		u32 mNumModelsProcessed;
		u32 mNumModelsRendered;
		u32 mNumSkinnedModelsRendered;
		u32 mNumRigidModelsRendered;
		u32 mNumMeshsRendered;
		u32 mPad1;
		u32 mPad2;
		u32 mNumLightsProcessed;
		u32 mNumLightsNearTotal;
		u32 mNumLightsNearRendered;
		u32 mNumLightsStencilTotal;
		u32 mNumLightsStencilRendered;
		u32 mNumLightsFarTotal;
		u32 mNumLightsFarRendered;
		u32 mNumLightCards;
		u32 mNumShadowsRendered;
		u32 mNumCloudsRendered;
		u32 mNumParticles;
		u32 mNumLargeParticleBatches;
		u32 mNumSmallParticleBatches;
		u32 mPad3;
		u32 mPad4;
		u32 mPad5;
	};
}