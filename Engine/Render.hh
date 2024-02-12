#pragma once

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

		static CDepthOfField* Instance()
		{
			return reinterpret_cast<CDepthOfField*>(UFG_RVA(0x2129328));
		}

		bool* DontRender() { return reinterpret_cast<bool*>(UFG_RVA(0x2136120)); }

		void Enable(bool enable)
		{
			if (*DontRender() != enable) return;

			*DontRender() = !enable;

			mFocalDistance	= 0.f;
			mInFocusRange	= 0.f;
			mNearRange		= 0.f;
			mNearBlurRadius = 0.f;
			mFarRange		= 0.f;
			mFarBlurRadius	= 0.f;
		}
	};

	bool IsLoadScreenRendering()
	{
		return reinterpret_cast<bool(__fastcall*)()>(UFG_RVA(0x48050))();
	}

	bool IsFullscreen()
	{
		return *reinterpret_cast<bool*>(UFG_RVA(0x2439A42));
	}

	int* GetScreenSize()
	{
		return reinterpret_cast<int*>(UFG_RVA(0x2439A94));
	}

	ID3D11RenderTargetView** GetRenderTargetView()
	{
		if (!IsFullscreen())
			return reinterpret_cast<ID3D11RenderTargetView**>(UFG_RVA(0x2439B18));

		Illusion::CTarget* m_BackBufferTarget = *reinterpret_cast<Illusion::CTarget**>(UFG_RVA(0x2439A50));
		return m_BackBufferTarget->mTargetPlat->mRenderTargetView[0];
	}
}