#pragma once

class hkpWorld : public hkReferencedObject
{
public:
	class hkpSimulation* m_simulation;
	hkVector4f m_gravity;
	class hkpSimulationIsland* m_fixedIsland;
	hkpRigidBody* m_fixedRigidBody;
	hkArray<class hkpSimulationIsland*> m_activeSimulationIslands;
	hkArray<class hkpSimulationIsland*> m_inactiveSimulationIslands;
	hkArray<class hkpSimulationIsland*> m_dirtySimulationIslands;
	class hkpWorldMaintenanceMgr* m_maintenanceMgr;
	hkRefPtr<class hkWorldMemoryAvailableWatchDog> m_memoryWatchDog;
	bool m_assertOnRunningOutOfSolverMemory;
	int8_t m_broadPhaseType; // hkpWorldCinfo::BroadPhaseType
	class hkpBroadPhase* m_broadPhase;
	class hkpTypedBroadPhaseDispatcher* m_broadPhaseDispatcher;
	class hkpPhantomBroadPhaseListener* m_phantomBroadPhaseListener;
	class hkpEntityEntityBroadPhaseListener* m_entityEntityBroadPhaseListener;
	class hkpBroadPhaseBorderListener* m_broadPhaseBorderListener;
	class hkpMtThreadStructure* m_multithreadedSimulationJobData;
	class hkpProcessCollisionInput* m_collisionInput;
	class hkpCollisionFilter* m_collisionFilter;
	class hkpCollisionDispatcher* m_collisionDispatcher;
	class hkpConvexListFilter* m_convexListFilter;
	class hkpWorldOperationQueue* m_pendingOperations;
	int m_pendingOperationsCount;
	int m_pendingBodyOperationsCount;
	int m_criticalOperationsLockCount;
	int m_criticalOperationsLockCountForPhantoms;
	bool m_blockExecutingPendingOperations;
	bool m_criticalOperationsAllowed;
	class hkpDebugInfoOnPendingOperationQueues* m_pendingOperationQueues;
	int m_pendingOperationQueueCount;

	UFG_PAD(0xC);
	//hkMultiThreadCheck m_multiThreadCheck;

	bool m_processActionsInSingleThread;
	bool m_allowIntegrationOfIslandsWithoutConstraintsInASeparateJob;
	unsigned int m_minDesiredIslandSize;
	class hkCriticalSection* m_modifyConstraintCriticalSection;
	int m_isLocked;
	class hkCriticalSection* m_islandDirtyListCriticalSection;
	class hkCriticalSection* m_propertyMasterLock;
	bool m_wantSimulationIslands;
	float m_snapCollisionToConvexEdgeThreshold;
	float m_snapCollisionToConcaveEdgeThreshold;
	bool m_enableToiWeldRejection;
	bool m_wantDeactivation;
	bool m_shouldActivateOnRigidBodyTransformChange;
	float m_deactivationReferenceDistance;
	float m_toiCollisionResponseRotateNormal;
	int m_maxSectorsPerMidphaseCollideTask;
	int m_maxSectorsPerNarrowphaseCollideTask;
	bool m_processToisMultithreaded;
	int m_maxEntriesPerToiMidphaseCollideTask;
	int m_maxEntriesPerToiNarrowphaseCollideTask;
	int m_maxNumToiCollisionPairsSinglethreaded;
	int m_simulationType; // hkpWorldCinfo::SimulationType
	float m_numToisTillAllowedPenetrationSimplifiedToi;
	float m_numToisTillAllowedPenetrationToi;
	float m_numToisTillAllowedPenetrationToiHigher;
	float m_numToisTillAllowedPenetrationToiForced;
	uint32_t m_lastEntityUid;
	uint32_t m_lastIslandUid;
	uint32_t m_lastConstraintUid;
	hkArray<hkpPhantom*> m_phantoms;
	hkArray<class hkpActionListener*> m_actionListeners;
	hkArray<class hkpEntityListener*> m_entityListeners;
	hkArray<class hkpPhantomListener*> m_phantomListeners;
	hkArray<class hkpConstraintListener*> m_constraintListeners;
	hkArray<class hkpWorldDeletionListener*> m_worldDeletionListeners;
	hkArray<class hkpIslandActivationListener*> m_islandActivationListeners;
	hkArray<class hkpWorldPostSimulationListener*> m_worldPostSimulationListeners;
	hkArray<class hkpWorldPostIntegrateListener*> m_worldPostIntegrateListeners;
	hkArray<class hkpWorldPostCollideListener*> m_worldPostCollideListeners;
	hkArray<class hkpIslandPostIntegrateListener*> m_islandPostIntegrateListeners;
	hkArray<class hkpIslandPostCollideListener*> m_islandPostCollideListeners;
	hkArray<class hkpContactListener*> m_contactListeners;
	hkArray<class hkpContactImpulseLimitBreachedListener*> m_contactImpulseLimitBreachedListeners;
	hkArray<class hkpWorldExtension*> m_worldExtensions;
	class hkpViolatedConstraintArray* m_violatedConstraintArray;
	class hkpBroadPhaseBorder* m_broadPhaseBorder;
	struct hkdWorld* m_destructionWorld;
	struct hknpWorld* m_npWorld;

	UFG_PAD(0x160);
	//hkpWorldDynamicsStepInfo m_dynamicsStepInfo;

	hkVector4f m_broadPhaseExtents[2];
	int m_broadPhaseNumMarkers;
	int m_sizeOfToiEventQueue;
	int m_broadPhaseQuerySize;
	int m_broadPhaseUpdateSize;
	int8_t m_contactPointGeneration; // hkpWorldCinfo::ContactPointGeneration
	bool m_useCompoundSpuElf;
};
UFG_ASSERT_CLASS(hkpWorld, 0x440);