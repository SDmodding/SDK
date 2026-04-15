#pragma once

struct hkaiNavMeshSimplificationUtils
{
	struct ExtraVertexSettings
	{
		enum VertexSelectionMethod
		{
			/// The number of vertices added will be proportional to the area (in meters^2) of the partition.
			/// This gives a more uniform distribruion of the extra vertices, but it's harder to preict the
			/// increase in data size.
			PROPORTIONAL_TO_AREA,

			/// The number of vertices added will be proportional to the number of vertices in the triangulation.
			/// In this case, m_vertexFraction is used.
			PROPORTIONAL_TO_VERTICES,
		};

		hkEnum<VertexSelectionMethod, u8> m_vertexSelectionMethod;
		f32 m_vertexFraction;
		f32 m_areaFraction;
		f32 m_minPartitionArea;
		int m_numSmoothingIterations;
		f32 m_iterationDamping;
		hkBool m_addVerticesOnBoundaryEdges;
		hkBool m_addVerticesOnPartitionBorders;
		f32 m_boundaryEdgeSplitLength;
		f32 m_partitionBordersSplitLength;
		f32 m_userVertexOnBoundaryTolerance;
		hkArray<hkVector4f> m_userVertices;
	};

	struct Settings
	{
		f32 m_maxBorderSimplifyArea;
		f32 m_maxConcaveBorderSimplifyArea;
		f32 m_minCorridorWidth;
		f32 m_maxCorridorWidth;
		f32 m_holeReplacementArea;
		f32 m_aabbReplacementAreaFraction;
		f32 m_maxLoopShrinkFraction;
		f32 m_maxBorderHeightError;
		f32 m_maxBorderDistanceError;
		int m_maxPartitionSize;
		hkBool m_useHeightPartitioning;
		f32 m_maxPartitionHeightError;
		hkBool m_useConservativeHeightPartitioning;
		f32 m_hertelMehlhornHeightError;
		f32 m_cosPlanarityThreshold;
		f32 m_nonconvexityThreshold;
		f32 m_boundaryEdgeFilterThreshold;
		f32 m_maxSharedVertexHorizontalError;
		f32 m_maxSharedVertexVerticalError;
		f32 m_maxBoundaryVertexHorizontalError;
		f32 m_maxBoundaryVertexVerticalError;
		hkBool m_mergeLongestEdgesFirst;
		ExtraVertexSettings m_extraVertexSettings;
		hkBool m_saveInputSnapshot;
		hkStringPtr m_snapshotFilename;
	};
};