#pragma once

namespace UFG
{
	class SimVehicle;

	class CharacterOccupantComponent : public SimComponent
	{
	public:
		qNode<CharacterOccupantComponent> mNode;
		eTargetTypeEnum mTargetType;
		uint32_t mSeatIndex;
		RebindingComponentHandle<CVehicleOccupantComponent> mCurrentVOC;

		SimVehicle* GetCurrentVehicle()
		{
			if (mCurrentVOC.m_pSimComponent) {
				return reinterpret_cast<SimVehicle*>(mCurrentVOC.m_pSimComponent->m_pSimObject);
			}

			return nullptr;
		}
	}; typedef CharacterOccupantComponent CCharacterOccupantComponent;
}