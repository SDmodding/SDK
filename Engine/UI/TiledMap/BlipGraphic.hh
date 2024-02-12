#pragma once

namespace UFG
{
	class CUIMapBlipGraphic
	{
	public:
		void* vfptr;
		bool mAnimateBlink;
		float mBlinkScale;
		uint32_t mBlinkTimesLooped;
		uint32_t mBlinkTimesMax;
		CUIRenderQuad* mPolys[5];
		CUIRenderQuad mIconPoly;
	};
}