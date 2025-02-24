#pragma once

namespace UFG
{
	class CoverDataResource : public qResourceData
	{
	public:
		u32 mCellId;
		u32 mNumCorners;
		qOffset64<CoverCorner*> mCorners;
	};
}