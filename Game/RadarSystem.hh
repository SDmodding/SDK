#pragma once

namespace UFG
{
	enum eRadarType
	{
		eRadarType_RimLight = 0x0,
		eRadarType_Weapon,
		eRadarType_CombatProp,
		eRadarType_Explodable,
		eRadarType_Interactable,
		eRadarType_ParkourHandle,
		eRadarType_PokerTile,
		eRadarType_CashMoney,
		eRadarType_AttackingCharacter,
		eRadarType_Count
	};

	class CRadarElement
	{
	public:
		qNode<CRadarElement> mNode;
		eRadarType mType;
		qVector3 mPosition;
		qSafePointer<SimObject> mDrawable;
	};

	class CRadarSystem
	{
	public:
		// TODO

		static UFG_INLINE CRadarSystem* Instance()
		{
			return *reinterpret_cast<CRadarSystem**>(UFG_RVA(0x23DC110));
		}
	};

	namespace RadarSystem
	{
		struct RevealParam_t
		{
			qSymbol mTypeSymbol;
			float mPulseFadeMinDist;
			float mPulseFadeMaxDist;
			bool mUseDistanceScalar;
			float mScreenSpaceRevealRadius;
			bool mUseScreenSpaceScalar;
			bool mAlwaysOn;
		};

		// Array size of eRadarType_Count
		UFG_INLINE RevealParam_t* GetRevealParams()
		{
			return reinterpret_cast<RevealParam_t*>(UFG_RVA(0x23DC2F0));
		}

		// Array size of eRadarType_Count
		UFG_INLINE qColour* GetTypeColors()
		{
			return reinterpret_cast<qColour*>(UFG_RVA(0x23DC470));
		}
	}
}