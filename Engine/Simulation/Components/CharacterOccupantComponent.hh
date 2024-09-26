#pragma once

namespace UFG
{
	class CSimVehicle;

	class CCharacterOccupantComponent : public SimComponent
	{
	public:
		qNode<CCharacterOccupantComponent> mNode;
		eTargetTypeEnum mTargetType;
		uint32_t mSeatIndex;
		RebindingComponentHandle<CVehicleOccupantComponent> mCurrentVOC;

		CSimVehicle* GetCurrentVehicle()
		{
			if (mCurrentVOC.m_pSimComponent) {
				return reinterpret_cast<CSimVehicle*>(mCurrentVOC.m_pSimComponent->m_pSimObject);
			}

			return nullptr;
		}
	};
}