#pragma once

struct component_CharacterProperties : component_SimObjectProperties
{
	UFG::qSymbol simObjectCharacterType;
	bool simObjectCharacterIsFemale;
	UFG::qSymbol simObjectCharacterFightingClass;
	int Stamina;
	f32 PoiCooldownTimeMin;
	f32 PoiCooldownTimeMax;
	UFG::qSymbol FactionClass;
	UFG::qSymbol Gender;
	bool IsTired;
};