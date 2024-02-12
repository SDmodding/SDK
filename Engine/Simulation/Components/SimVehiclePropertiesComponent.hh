#pragma once

namespace UFG
{
	class CSimVehiclePropertiesComponent : public CSimObjectPropertiesComponent
	{
	public:
		struct AimLimit_t
		{
			float left;
			float right;
		};

		UFG_PAD(0x10);

		eSimObjectVehicleTypeEnum m_eSimObjectVehicleType;
		eSimObjectBoatTypeEnum m_eSimObjectBoatType;
		qArray<AimLimit_t> mAimLimit;
		AimLimit_t mDefaultAimLimit;
		float mFaceReplenishMultiplier;
		qArray<void*> mDoorPhantomInfo;
		bool mIsGarageVehicle;
	};
	UFG_ASSERT_CLASS(CSimVehiclePropertiesComponent, 0xE8);
}