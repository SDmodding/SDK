#pragma once

namespace UFG
{
	enum eNearbyCharacterType
	{
		eNEARBY_CHARACTER_FIGHTER,
		eNEARBY_CHARACTER_PEDESTRIAN,
		NUM_NEARBY_CHARACTER_TYPES,
		eNEARBY_CHARACTER_NONE = -1,
	};

	class NearbyCharacter : public qNode<NearbyCharacter>, public qNode<NearbyCharacter, class NearbyCharacterLocalList>
	{
	public:
		qSafePointer<AIEntityComponent> m_pAIEntityComponent;
		qSafePointer<TargetingSystemBaseComponent> m_pTargetingSystemComponent;
	};

	class NearbyCharacterManager
	{
	public:
		qList<NearbyCharacter> m_Characters[NUM_NEARBY_CHARACTER_TYPES];
	};
}