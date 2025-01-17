#pragma once

class hkpSimulationIsland : public hkpConstraintOwner
{
public:
	hkpWorld* m_world;
	int m_numConstraints;
	u16 m_storageIndex;
	u16 m_dirtyListIndex;
	char m_splitCheckFrameCounter;
	bool m_splitCheckRequested : 2;
	bool m_isSparse : 2;
	bool m_actionListCleanupNeeded : 2;
	bool m_allowIslandLocking : 2;
	bool m_isInActiveIslandsArray : 2;
	bool m_activeMark : 2;
	bool m_tryToIncreaseIslandSizeMark : 2;
	bool m_inIntegrateJob : 2;
	hkMultiThreadCheck m_multiThreadCheck;
	f32 m_timeSinceLastHighFrequencyCheck;
	f32 m_timeSinceLastLowFrequencyCheck;
	hkArray<class hkpAction*> m_actions;
	f32 m_timeOfDeactivation;
	hkInplaceArray<class hkpEntity*, 1> m_entities;
	//hkpAgentNnTrack m_midphaseAgentTrack;
	//hkpAgentNnTrack m_narrowphaseAgentTrack;
};
