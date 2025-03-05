#pragma once

namespace UFG
{
	class UIHKTweakables
	{
	public:
		SDK_VINLINE qGlobalVar<bool, 0x208E692> SocialActionFloatingTweak;
		SDK_VINLINE qGlobalVar<f32, 0x208E6B8> ObjectiveDistanceWidget_Altitude;
		SDK_VINLINE qGlobalVar<bool, 0x208E6C0> RenderMinimap;
		SDK_VINLINE qGlobalVar<bool, 0x208E6C1> ShowDirectionalDamage;
		SDK_VINLINE qGlobalVar<bool, 0x208E6C3> WardrobeTuneCamera;
		SDK_VINLINE qGlobalVar<f32, 0x208E6C4> FakeHealthValue;
		SDK_VINLINE qGlobalVar<f32, 0x208E6C8> DirectionalDamageDuration;
		SDK_VINLINE qGlobalVar<f32, 0x208E6DC> WorldMap_PanSpeed;
		SDK_VINLINE qGlobalVar<f32, 0x208E6E0> WorldMap_CursorSpeed;
		SDK_VINLINE qGlobalVar<f32, 0x208E6E4> WorldMap_MouseCursorSpeed;
		SDK_VINLINE qGlobalVar<f32, 0x208E6E8> WorldMap_MinX;
		SDK_VINLINE qGlobalVar<f32, 0x208E6EC> WorldMap_MaxX;
		SDK_VINLINE qGlobalVar<f32, 0x208E6F0> WorldMap_MinY;
		SDK_VINLINE qGlobalVar<f32, 0x208E6F4> WorldMap_MaxY;
		SDK_VINLINE qGlobalVar<f32, 0x208E708> WorldMap_CursorMargin;
		SDK_VINLINE qGlobalVar<f32, 0x208E714> WorldMap_RaceLineRes;
		SDK_VINLINE qGlobalVar<f32, 0x208E718> WorldMap_ZoomSpeed;
		SDK_VINLINE qGlobalVar<f32, 0x208E71C> WorldMap_ZoomBoostMouse;
		SDK_VINLINE qGlobalVar<f32, 0x208E720> WorldMap_MinZoom;
		SDK_VINLINE qGlobalVar<f32, 0x208E724> WorldMap_MaxZoom;
		SDK_VINLINE qGlobalVar<f32, 0x208E730> WorldMapTerritory_OffsetX;
		SDK_VINLINE qGlobalVar<f32, 0x208E734> WorldMapTerritory_OffsetY;
		SDK_VINLINE qGlobalVar<f32, 0x208E748> WorldMapTerritory_Scale;
		SDK_VINLINE qGlobalVar<f32, 0x208E758> TweakDofInFocusRange;
		SDK_VINLINE qGlobalVar<f32, 0x208E75C> TweakDofFarBlurRadius;
		SDK_VINLINE qGlobalVar<f32, 0x208E760> TweakDofFarRange;
		SDK_VINLINE qGlobalVar<f32, 0x208E764> WardrobeFOV;
		SDK_VINLINE qGlobalVar<f32, 0x208E768> WardrobeCameraDuration;
		SDK_VINLINE qGlobalVar<f32, 0x208E76C> WardrobeFootEyeHeight;
		SDK_VINLINE qGlobalVar<qVector3, 0x208EA48> WardrobeOffsetLowerBody;
		SDK_VINLINE qGlobalVar<qVector3, 0x208EA58> WardrobeOffsetFootwear;
		SDK_VINLINE qGlobalVar<qVector3, 0x208EA68> WardrobeOffsetHeadgear;
		SDK_VINLINE qGlobalVar<qVector3, 0x208EA78> WardrobeOffsetBody;
		SDK_VINLINE qGlobalVar<qVector3, 0x208EA88> WardrobeOffsetAccessories;
		SDK_VINLINE qGlobalVar<qVector3, 0x208EA98> WardrobeOffsetOutfit;
		SDK_VINLINE qGlobalVar<qVector3, 0x208EAA8> WardrobeOffsetGlasses;
		SDK_VINLINE qGlobalVar<qVector3, 0x208EAB8> WardrobeOffsetNeck;
		SDK_VINLINE qGlobalVar<qVector3, 0x208EAC8> WardrobeOffsetLeftWrist;
		SDK_VINLINE qGlobalVar<qVector3, 0x208EAD8> WardrobeOffsetRightWrist;
		SDK_VINLINE qGlobalVar<bool, 0x2431017> OnlyShowGPSInVehicles;
		SDK_VINLINE qGlobalVar<bool, 0x243102E> UseFakeHealthValue;
		SDK_VINLINE qGlobalVar<bool, 0x243102F> ToggleHealthBarHide;
		SDK_VINLINE qGlobalVar<bool, 0x2431040> CombatActive;
		SDK_VINLINE qGlobalVar<bool, 0x2431041> UseFakeCombatValues;
		SDK_VINLINE qGlobalVar<int, 0x2431044> FakeCombatMeterValue;
		SDK_VINLINE qGlobalVar<int, 0x2431048> FakeCombatChargeValue;
		SDK_VINLINE qGlobalVar<bool, 0x2431048> WorldMap_UsePointList;
		SDK_VINLINE qGlobalVar<bool, 0x2431056> WardrobeDebugFreeClothes;
		SDK_VINLINE qGlobalVar<f32, 0x243105C> WorldMap_GridAlpha;
		SDK_VINLINE qGlobalVar<f32, 0x2431060> TweakDofNearBlurRadius;
		SDK_VINLINE qGlobalVar<f32, 0x243106C> TweakDofNearRange;
		SDK_VINLINE qGlobalVar<bool, 0x243107B> TrafficPopulationStats;
		SDK_VINLINE qGlobalVar<bool, 0x243108C> TrafficAvailableVehicles;
		SDK_VINLINE qGlobalVar<bool, 0x243108D> TrafficVehicleBlips;
	};
}