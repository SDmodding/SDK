#pragma once

class hkpConstraintInstance : public hkReferencedObject
{
public:
	enum ConstraintPriority
	{
		/// Invalid priority.
		PRIORITY_INVALID,
		/// Constraint is only solved at regular physics time steps (==PSIs)
		PRIORITY_PSI,
		/// This is an unused value -- it corresponds to COLLISION_QUALITY_SIMPLIFIED_TOI. It's put here, because the ordering and values of this enum must match those
		/// of collidable qualities and of collisionQualityInfos in the hkpCollisionDispatcher.
		PRIORITY_SIMPLIFIED_TOI_UNUSED,
		/// Constraint is also touched at time of impact events.(TOI).
		PRIORITY_TOI,
		/// For internal use only! Higher quality. Warning: Use this quality only for contact constraints between moving and fixed objects.
		/// \note Higher priority constraints have higher priority in the solver in PSI steps. They are actually processed as normal PRIORITY_TOI
		///       constraints in TOI events.
		PRIORITY_TOI_HIGHER,
		/// For internal use only! Enforced quality. Warning: Use this quality only for contact constraints between critical and fixed objects.
		/// \note Forced priority constraints have higher priority in the solver in PSI steps. They have also higher priority in the solver in TOI steps.
		///        Additionally extra CPU time is used at the end of TOI event in attempt to enforce those constraints (with the cost of ignoring the state
		///        of other -- non-forced -- constraints).
		PRIORITY_TOI_FORCED,

		/// The number of priorities.
		NUM_PRIORITIES
	};

	enum OnDestructionRemapInfo
	{
		ON_DESTRUCTION_REMAP = 0,			///< remap the constraint to the newly created pieces
		ON_DESTRUCTION_REMOVE = 1,			///< if set, do not remap the constraint to the broken pieces
		ON_DESTRUCTION_RESET_REMOVE = 2,	///< if set, remove the constraint on a remerge event
	};

	hkpConstraintOwner* m_owner;
	class hkpConstraintData* m_data;
	class hkpModifierConstraintAtom* m_constraintModifiers;
	class hkpEntity* m_entities[2];
	hkEnum<ConstraintPriority, u8> m_priority;
	hkBool m_wantRuntime;
	hkEnum<OnDestructionRemapInfo, u8> m_destructionRemapInfo;
	hkSmallArray<class hkpConstraintListener*> m_listeners;
	hkStringPtr m_name;
	u64 m_userData;
	class hkConstraintInternal* m_internal;
	u32 m_uid;
};