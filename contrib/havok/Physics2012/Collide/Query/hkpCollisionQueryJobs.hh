#pragma once

struct hkpWorldLinearCastCommand
{
	hkpLinearCastInput m_input;
	hkpCollidable* m_collidable;
	hkpRootCdPoint* m_results;
	int m_resultsCapacity;
	int m_numResultsOut;
};

struct hkpCollisionQueryJobHeader
{
	int m_openJobs;
};