#pragma once

namespace UFG
{
	class VehicleCombatStats
	{
	public:
		f32 mLastAttack[CarCombat::NumAttacks];
		u32 mNumAttacks[CarCombat::NumAttacks];
	};
}