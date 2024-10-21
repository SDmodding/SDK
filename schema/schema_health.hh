#pragma once

class component_Health
{
public:
	int maxUpgradedHealth;
	int maxHealth;
	float regenerativeHealthRate;
	bool InvulnerableCharacter;
	float healthProjectileDamageMultiplier;
};
SDK_ASSERT_SIZEOF(component_Health, 0x14);