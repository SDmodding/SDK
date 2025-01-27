#pragma once

class hkpBroadPhaseBorder : public hkReferencedObject, protected hkpWorldDeletionListener, protected hkpPhantomOverlapListener, protected hkpWorldPostSimulationListener
{
public:
	hkpWorld* m_world;
	hkpPhantom* m_phantoms[6];
	hkpWorldCinfo::BroadPhaseBorderBehaviour m_type;
	hkBool m_postponeAndSortCallbacks;
	hkArray<hkpEntity*> m_entitiesExitingBroadPhase;
};