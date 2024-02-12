#pragma once

namespace UFG
{
	class CUIHKMinimapBlipType
	{
	public:
		qSymbol TypeNameSymbol;
		qSymbol Icon;
		qString Caption;
		bool IsWorldMapOnly;
		bool IsObjective;
		bool IsDistanceFiltered;
		bool IsDistanceFilteredOnWorldMap;
		bool IsWorldMapZoomFiltered;

		UFG_PAD_ALIGN(0x4);

		float FilterDistance;
		float WorldMapZoomFilter;
		qColour RadiusColor;
		qColour InnerRadiusColor;
		uint32_t DrawDepth;
		bool IsHiddenIndoors;
		bool HasAltitude;
		bool IsProximityUnlockable;
		bool HideOnBorder;
		qSymbol ProgressionFlow;
		bool IsVisible;

		UFG_PAD_ALIGN(0x4);
	};

	class CUIMapBlipTypeManager
	{
	public:
		qArray<CUIHKMinimapBlipType> mData;
		uint32_t mNumTypes;

		static UFG_INLINE CUIMapBlipTypeManager* Instance()
		{ 
			return reinterpret_cast<CUIMapBlipTypeManager * (__fastcall*)()>(UFG_RVA(0xCEFE0))();
		}
	};
}