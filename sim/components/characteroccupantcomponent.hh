#pragma once

namespace UFG
{
	class CharacterOccupantComponent : public SimComponent, public qNode<CharacterOccupantComponent>
	{
	public:
		enum { _TypeUID = 0x96000001 };

		eTargetTypeEnum mTargetType;
		u32 mSeatIndex;
		RebindingComponentHandle<VehicleOccupantComponent> mCurrentVOC;

		/* Functions */

		bool IsEnteringOrExiting() { return SDK_CALL_FUNC(bool, 0x53A380, void*)(this); }

		SDK_INLINE SimObjectVehicle* GetCurrentVehicle() { return mCurrentVOC.GetObject<SimObjectVehicle>(); }
	};
	SDK_ASSERT_SIZEOF(CharacterOccupantComponent, 0x88);
}