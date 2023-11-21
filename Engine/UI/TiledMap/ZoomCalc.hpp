#pragma once

namespace UFG
{
	class CUITiledMapZoomCalc
	{
	public:
		float mScale;
		bool mInteriorActiveLastFrame;
		float mZoomHistory[12];
		int mZoomHistoryIndex;
	};
}