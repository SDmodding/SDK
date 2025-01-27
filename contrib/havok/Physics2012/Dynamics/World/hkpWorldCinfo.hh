#pragma once

class hkpWorldCinfo : public hkReferencedObject
{
public:
	enum BroadPhaseBorderBehaviour
	{
		BROADPHASE_BORDER_ASSERT,
		BROADPHASE_BORDER_FIX_ENTITY,
		BROADPHASE_BORDER_REMOVE_ENTITY,
		BROADPHASE_BORDER_DO_NOTHING
	};

	enum BroadPhaseType
	{
		BROADPHASE_TYPE_SAP,
		BROADPHASE_TYPE_TREE,
		BROADPHASE_TYPE_HYBRID
	};

	enum ContactPointGeneration
	{
		CONTACT_POINT_ACCEPT_ALWAYS,
		CONTACT_POINT_REJECT_DUBIOUS,
		CONTACT_POINT_REJECT_MANY
	};

	enum SimulationType
	{
		SIMULATION_TYPE_INVALID,
		SIMULATION_TYPE_DISCRETE,
		SIMULATION_TYPE_CONTINUOUS,
		SIMULATION_TYPE_MULTITHREADED
	};

	enum SolverType
	{
		SOLVER_TYPE_INVALID,
		SOLVER_TYPE_2ITERS_SOFT,
		SOLVER_TYPE_2ITERS_MEDIUM,
		SOLVER_TYPE_2ITERS_HARD,
		SOLVER_TYPE_4ITERS_SOFT,
		SOLVER_TYPE_4ITERS_MEDIUM,
		SOLVER_TYPE_4ITERS_HARD,
		SOLVER_TYPE_8ITERS_SOFT,
		SOLVER_TYPE_8ITERS_MEDIUM,
		SOLVER_TYPE_8ITERS_HARD,
		SOLVER_TYPE_MAX_ID
	};

	hkVector4f m_gravity;
	int m_broadPhaseQuerySize;
	f32 m_contactRestingVelocity;
	hkEnum<BroadPhaseType, i8> m_broadPhaseType;
	hkEnum<BroadPhaseBorderBehaviour, i8> m_broadPhaseBorderBehaviour;
	hkBool m_mtPostponeAndSortBroadPhaseBorderCallbacks;
	hkAabb m_broadPhaseWorldAabb;
	f32 m_collisionTolerance;
	hkRefPtr<class hkpCollisionFilter> m_collisionFilter;
	hkRefPtr<class hkpConvexListFilter> m_convexListFilter;
	f32 m_expectedMaxLinearVelocity;
	int m_sizeOfToiEventQueue;
	f32 m_expectedMinPsiDeltaTime;
	hkRefPtr<class hkWorldMemoryAvailableWatchDog> m_memoryWatchDog;
	int m_broadPhaseNumMarkers;
	hkEnum<ContactPointGeneration, i8> m_contactPointGeneration;
	hkBool m_allowToSkipConfirmedCallbacks;
	f32 m_solverTau;
	f32 m_solverDamp;
	int m_solverIterations;
	int m_solverMicrosteps;
	f32 m_maxConstraintViolation;
	hkBool m_forceCoherentConstraintOrderingInSolver;
	f32 m_snapCollisionToConvexEdgeThreshold;
	f32 m_snapCollisionToConcaveEdgeThreshold;
	hkBool m_enableToiWeldRejection;
	hkBool m_enableDeprecatedWelding;
	f32 m_iterativeLinearCastEarlyOutDistance;
	int m_iterativeLinearCastMaxIterations;
	i8 m_deactivationNumInactiveFramesSelectFlag0;
	i8 m_deactivationNumInactiveFramesSelectFlag1;
	i8 m_deactivationIntegrateCounter;
	hkBool m_shouldActivateOnRigidBodyTransformChange;
	f32 m_deactivationReferenceDistance;
	f32 m_toiCollisionResponseRotateNormal;
	hkBool m_useCompoundSpuElf;
	int m_maxSectorsPerMidphaseCollideTask;
	int m_maxSectorsPerNarrowphaseCollideTask;
	hkBool m_processToisMultithreaded;
	int m_maxEntriesPerToiMidphaseCollideTask;
	int m_maxEntriesPerToiNarrowphaseCollideTask;
	int m_maxNumToiCollisionPairsSinglethreaded;
	f32 m_numToisTillAllowedPenetrationSimplifiedToi;
	f32 m_numToisTillAllowedPenetrationToi;
	f32 m_numToisTillAllowedPenetrationToiHigher;
	f32 m_numToisTillAllowedPenetrationToiForced;
	hkBool m_enableDeactivation;
	hkEnum<SimulationType, i8> m_simulationType;
	hkBool m_enableSimulationIslands;
	u32 m_minDesiredIslandSize;
	hkBool m_processActionsInSingleThread;
	hkBool m_allowIntegrationOfIslandsWithoutConstraintsInASeparateJob;
	f32 m_frameMarkerPsiSnap;
	hkBool m_fireCollisionCallbacks;
};