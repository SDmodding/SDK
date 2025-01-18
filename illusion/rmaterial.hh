#pragma once

namespace Illusion
{
	namespace eAlphaState
	{
		enum Enum
		{
			None = 0x2782CCE6,
			Blend = 0xA3833FDE,
			Additive = 0x69DAE2D1,
			PunchThru = 0x2B068C0A,
			FeatherPunchThru = 0xBBB46CC6,
			Premultiplied = 0xFAB11CA1,
			Overlay = 0xEDE83382,
			Screen = 0xD668AB18
		};
	}

	namespace eDepthBias
	{
		enum Enum
		{
			NoBias,
			BiasForward1,
			BiasForward2,
			BiasForward3
		};
	}

	namespace eRasterState
	{
		enum Enum
		{
			Normal = 0x20688F05,
			DoubleSided = 0x940FB8EC,
			DoubleSidedAlpha = 0x418CAF43
		};
	}

	class rMaterial : public UFG::qReflectObjectType<rMaterial>
	{
	public:
		struct rRenderState
		{
			eAlphaState::Enum AlphaState;
			eRasterState::Enum RasterState;
			f32 mAlphaClip;
			eDepthBias::Enum mDepthBias;
			bool mDecalLayer;
			f32 mAlphaDistanceBias;
		};

		rRenderState mRenderState;
		eRenderPass::StaticPassData* mStaticRenderPass;
		eRenderPass::PassData mRenderPass[4];
	};
}