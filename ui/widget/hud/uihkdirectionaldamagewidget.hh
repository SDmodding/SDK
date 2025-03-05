#pragma once

namespace UFG
{
	class DamageTimer
	{
	public:
		bool bActive;
		f32 fElapsedTime;
	};

	class UIHKDirectionalDamageWidget
	{
	public:
		DamageTimer mDDTimers[4];
		bool mTweakFakeAttackDir[4];
	};
}