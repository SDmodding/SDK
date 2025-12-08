#pragma once

namespace UFG
{
	class NISSpatialData : public qResourceData
	{
	public:
		qVector3 mCameraBBMin;
		qVector3 mCameraBBMax;
		qVector3 mCameraBBCentre;
		u32 mCameraCutCount;
		qOffset64<u32*> mCameraCutFrameIndices;
	};

	class NISSpatialDataHandle : public qTypedResourceHandle<RTypeUID_NISSpatialData, NISSpatialData> {};
}