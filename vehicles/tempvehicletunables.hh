#pragma once

// Move this in appropriate file if found good place.
namespace CarAI
{
	enum EEscortMode : i32
	{
		AttackEnemy,
		EscortObjective,
		NumEscortModes
	};

	enum Mode
	{
		Stop,
		Wander,
		GoTo,
		Chase,
		Follow,
		StopAt,
		Race,
		Escort,
		NumModes
	};

	enum Role
	{
		Traffic,
		Racer,
		Enemy,
		Ally,
		Taxi,
		Cop,
		Bus,
		Tram,
		Ferry,
		Boat,
		NumRoles
	};
}

// Same applies for this like the one abov.
namespace CarCombat
{
	enum Attack : i32
	{
		Ram,
		Sideswipe,
		PitManeuvre,
		Block,
		Melee,
		Projectile,
		AnyAttack,
		NumAttacks
	};

	enum FormationAttack : i32
	{
		Box,
		Box2,
		RollingRoadBlock,
		AnyFormationAttack,
		NumFormationAttacks
	};

	enum Position : i32
	{
		Follow,
		Behind,
		RearCorner,
		PitPosition,
		Beside,
		FrontCorner,
		Front,
		NumPositions
	};

	enum Side : i32
	{
		Left,
		Right,
		Closest,
		AnySide,
		NumSides
	};
}

namespace UFG
{
	class DrivingTargetOffsetMover
	{
	public:
		f32 m_CurrentLateralOffset;
		f32 m_DesiredLateralOffset;
		f32 m_CurrentDriftSpeed;
		bool m_AtTarget;

		void SetNewTarget(f32 desiredOffset, f32 transitonTime) { SDK_CALL_FUNC(void, 0x68AA40, void*, f32, f32)(this, desiredOffset, transitonTime); }
	};
}