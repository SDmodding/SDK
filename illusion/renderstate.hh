#pragma once

namespace Illusion
{
	class __declspec(align(16)) ViewportScissorState
	{
	public:
		f32 mViewPortX;
		f32 mViewPortY;
		f32 mViewPortWidth;
		f32 mViewPortHeight;
		f32 mViewPortMinDepth;
		f32 mViewPortMaxDepth;
		int mScissorX;
		int mScissorY;
		int mScissorWidth;
		int mScissorHeight;
	};
	SDK_ASSERT_SIZEOF(ViewportScissorState, 0x30);

	class __declspec(align(16)) AlphaState : public UFG::qResourceData
	{
	public:
		s8 mBlendModeEnabled;
		s8 mBlendModeSrc;
		s8 mBlendModeDest;
		s8 mEquationColor;
		s8 mEquationAlpha;
		s8 mAlphaTestEnabled;
		s8 mAlphaTestRefValue;
		s8 mAlphaTestFunction;
		s8 mSeperateAlphaBlendModeEnabled;
		s8 mSeperateAlphaBlendModeSrc;
		s8 mSeperateAlphaBlendModeDest;
		s8 mColourMask;
		u16 mDitherMask;
		u16 pad0;
	};
	SDK_ASSERT_SIZEOF(AlphaState, 0x70);

	class AlphaStateHandle : public UFG::qTypedResourceHandle<RTypeUID_AlphaState, AlphaState> {};

	class __declspec(align(16)) RasterState : public UFG::qResourceData
	{
	public:
		s8 mZEnabled;
		s8 mZWriteEnabled;
		s8 mZFunction;
		s8 mCullMode;
		s8 mHiZEnabled;
		s8 mHiZWriteEnabled;
		s8 mSEnabled;
		s8 mSHiEnabled;
		s8 mSHiFunction;
		s8 mSHiRef;
		s8 mSHiForceWrite;
		s8 mSHiForceDisableWrite;
		s8 mSRefMask;
		s8 mSRefBits;
		s8 mSFunction;
		s8 mSPassOperation;
		s8 mSFailOperation;
		s8 mSZFailOperation;
		s8 mSTwoSidedEnable;
		s8 mSRefMask_CCW;
		s8 mSRefBits_CCW;
		s8 mSFunction_CCW;
		s8 mSPassOperation_CCW;
		s8 mSFailOperation_CCW;
		s8 mSZFailOperation_CCW;
		s8 mSWriteMask;
		s8 mFillMode;
		s8 mPad0;
	};
	SDK_ASSERT_SIZEOF(RasterState, 0x80);

	class RasterStateHandle : UFG::qTypedResourceHandle<RTypeUID_RasterState, RasterState> {};
}