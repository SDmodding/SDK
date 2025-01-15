#pragma once

namespace UFG
{
	namespace PingType
	{
		enum Enum : i32
		{
			PingNone,
			PingIdle,
			PingAllOnce,
			PingAlwaysOn,
			PingWhileAiming,
			PingWhileRunning,
			PingWhileGrappling,
			Count
		};
	}

	namespace RadarType
	{
		enum Enum : i32
		{
			RimLight,
			Weapon,
			CombatProp,
			Explodable,
			Interactable,
			ParkourHandle,
			PokerTile,
			CashMoney,
			AttackingCharacter,
			Count
		};
	}

	class RadarElement : public qNode<RadarElement>
	{
	public:
		RadarType::Enum mType;
		qVector3 mPosition;
		qSafePointer<SimObject> mDrawable;
	};

	class RadarSystem
	{
	public:
		struct SimObjectListEntry : public qNode<SimObjectListEntry>
		{
			qSafePointer<SimObject> mSimObject;
		};

		struct ElementRevealParams
		{
			qSymbol mTypeSymbol;
			f32 mPulseFadeMinDist;
			f32 mPulseFadeMaxDist;
			bool mUseDistanceScalar;
			f32 mScreenSpaceRevealRadius;
			bool mUseScreenSpaceScalar;
			bool mAlwaysOn;
		};


		bool mbPokerDiceMode;
		bool mGrappleModeActive;
		PingType::Enum mPingType;
		f32 mPulseDuration;
		f32 mPulseMaxRadius;
		f32 mPulseActiveRange;
		f32 mPulseCurrentDuration;
		qList<RadarElement> mElements;
		qList<SimObjectListEntry> mRimLightObjects;
		qList<SimObjectListEntry> mCombatProps;
		qList<SimObjectListEntry> mPokerTiles;

		/* Static Members */

		SDK_VINLINE qGlobalVar<bool, 0x23DC118> sDisableRadarSystem;
		SDK_VINLINE qGlobalVar<bool, 0x23DC119> sDebugRender;
		SDK_VINLINE qGlobalArray<ElementRevealParams, RadarType::Count, 0x23DC2F0> sRevealParams;
		SDK_VINLINE qGlobalArray<qColour, RadarType::Count, 0x23DC470> sRadarTypeColors;

		/* Static Functions */

		SDK_SINLINE RadarSystem* Instance() { return SDK_VAR_GET(RadarSystem*, 0x23DC110); }

		/* Functions */

		void AddCombatProp(SimObject* object) { SDK_CALL_FUNC(void, 0x3FE6C0, void*, SimObject*)(this, object); }
		void AddRimLight(SimObject* object) { SDK_CALL_FUNC(void, 0x3FE780, void*, SimObject*)(this, object); }
		void AddSimObject(SimObject* object, RadarType::Enum type) { SDK_CALL_FUNC(void, 0x3FE840, void*, SimObject*, RadarType::Enum)(this, object, type); }
		void Clear() { SDK_CALL_FUNC(void, 0x400170, void*)(this); }
		void RemoveCombatProp(SimObject* object) { SDK_CALL_FUNC(void, 0x400FE0, void*, SimObject*)(this, object); }
		void RemoveRimLight(SimObject* object) { SDK_CALL_FUNC(void, 0x401050, void*, SimObject*)(this, object); }
	};
	SDK_ASSERT_SIZEOF(RadarSystem, 0x58);
}