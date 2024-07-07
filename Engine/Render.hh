#pragma once

namespace UFG
{
	class DrawInfo
	{
	public:
		qColour mColour1;
		qColour mColour2;
		float mScale;
		uint32_t mAlphaBlend;
		bool mDepthBuffer;
		bool mFaceCull;
		bool mDepthBias;
		void* mPreDrawCallback;
	};
}

namespace Render
{
	class CDepthOfField
	{
	public:
		void* mMaterial;
		__int16 mStateBlockIndex;
		float mFocalDistance;
		float mInFocusRange;
		float mNearRange;
		float mNearBlurRadius;
		float mFarRange;
		float mFarBlurRadius;
		bool mNearBlurRendered;

		static UFG_INLINE CDepthOfField* Instance()
		{
			return reinterpret_cast<CDepthOfField*>(UFG_RVA(0x2129328));
		}

		UFG_INLINE bool* DontRender() 
		{ 
			return reinterpret_cast<bool*>(UFG_RVA(0x2136120)); 
		}

		void Enable(bool p_bEnable)
		{
			bool* pDontRender = DontRender();
			if (*pDontRender != p_bEnable) {
				return;
			}

			*pDontRender = !p_bEnable;

			mFocalDistance	= 0.f;
			mInFocusRange	= 0.f;
			mNearRange		= 0.f;
			mNearBlurRadius = 0.f;
			mFarRange		= 0.f;
			mFarBlurRadius	= 0.f;
		}
	};

	UFG_INLINE bool IsLoadScreenRendering()
	{
		return reinterpret_cast<bool(__fastcall*)()>(UFG_RVA(0x48050))();
	}

	UFG_INLINE bool IsFullscreen()
	{
		return *reinterpret_cast<bool*>(UFG_RVA(0x2439A42));
	}

	UFG_INLINE int* GetScreenSize()
	{
		return reinterpret_cast<int*>(UFG_RVA(0x2439A94));
	}

	UFG_INLINE ID3D11RenderTargetView** GetRenderTargetView()
	{
		if (!IsFullscreen()) {
			return reinterpret_cast<ID3D11RenderTargetView**>(UFG_RVA(0x2439B18));
		}

		Illusion::CTarget* pBackBuffer = *reinterpret_cast<Illusion::CTarget**>(UFG_RVA(0x2439A50));
		return pBackBuffer->mTargetPlat->mRenderTargetView[0];
	}
}