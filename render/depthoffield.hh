#pragma once

namespace Render
{
	class DepthOfField
	{
	public:
		struct Focus
		{
			float mFocalDistance;
			float mInFocusRange;
			float mNearRange;
			float mNearBlurRadius;
			float mFarRange;
			float mFarBlurRadius;

			SDK_INLINE void DisableFocus() { mNearBlurRadius = mFarBlurRadius = 0.f; }
		};

		struct RenderContext
		{
			enum Quality : s32
			{
				QUALITY_INGAME,
				QUALITY_NIS
			};

			Quality mQuality;
			Illusion::Target* mSourceTarget;
			Illusion::Target* mDestTarget;
			Illusion::Texture* mDepthTexture;
			Illusion::Target* mHalfSizeScratchTarget;
			Illusion::Target* mQuarterSizeScratchTargetA;
			Illusion::Target* mQuarterSizeScratchTargetB;
			Illusion::Target* mNearBlur;
		};

		Illusion::Material* mMaterial;
		i16 mStateBlockIndex;
		Focus mCurrFocus;
		bool mNearBlurRendered;

		/* Static Functions */

		SDK_SINLINE DepthOfField* Instance() { return SDK_VAR(DepthOfField*, 0x2129328); }

		/* Functions */

		void Set(const Focus& target_focus) { SDK_CALL_FUNC(void, 0x9300, void*, const Focus&)(this, target_focus); }
	};
	SDK_ASSERT_SIZEOF(DepthOfField, 0x28);

	SDK_VINLINE qGlobalVar<bool, 0x2129300> gOverrideFocusEnabled;
	SDK_VINLINE qGlobalVar<DepthOfField::Focus, 0x2129358> gOverrideFocus;
}