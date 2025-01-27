#pragma once

struct hkpWorldRayCastCommand
{
	hkpWorldRayCastInput m_rayInput;
	hkpWorldRayCastOutput* m_results;
	int m_resultsCapacity;
	int m_numResultsOut;
	hkBool m_useCollector;
	hkBool m_stopAfterFirstHit;
};