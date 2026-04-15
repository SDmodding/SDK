#pragma once

struct hkaiNavMeshEdgeMatchingParameters
{
	f32 m_maxStepHeight;
	f32 m_maxSeparation;
	f32 m_maxOverhang;
	f32 m_behindFaceTolerance;
	f32 m_cosPlanarAlignmentAngle;
	f32 m_cosVerticalAlignmentAngle;
	f32 m_minEdgeOverlap;
	f32 m_edgeTraversibilityHorizontalEpsilon;
	f32 m_edgeTraversibilityVerticalEpsilon;
	f32 m_cosClimbingFaceNormalAlignmentAngle;
	f32 m_cosClimbingEdgeAlignmentAngle;
	f32 m_minAngleBetweenFaces;
	f32 m_edgeParallelTolerance;
	hkBool m_useSafeEdgeTraversibilityHorizontalEpsilon;
};
