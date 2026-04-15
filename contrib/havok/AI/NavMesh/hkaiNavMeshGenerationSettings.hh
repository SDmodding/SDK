#pragma once

struct hkaiNavMeshGenerationSettings
{
	enum TriangleWinding
	{
		WINDING_CCW,
		WINDING_CW
	};

	enum EdgeMatchingMetric
	{
		/// Order by overlap first - this prioritizes large overlapping edges
		ORDER_BY_OVERLAP = 1,

		/// Order by distance first - this prioritizies close edges
		ORDER_BY_DISTANCE = 2,
	};

	enum ConstructionFlagsBits
	{
		/// If this bit is specified for a material, the triangles with the material will be considered for the walkable surface.
		MATERIAL_WALKABLE = 1,

		/// If this bit is specified for a material, the triangles with the material will be extruded and used to cut the walkable surfaces
		MATERIAL_CUTTING = 2,

		/// The default settings for materials. Triangles with these materials will be both considered for the walkable surface and used for cutting.
		MATERIAL_WALKABLE_AND_CUTTING = 3
	};

	enum CharacterWidthUsage
	{
		/// The character diameter is ignored during nav mesh generation.
		NONE,

		/// Edges which are less than the m_minCharacterWidth and adjacent to bounday edges are blocked.
		/// This can help prune out areas that are connected by thin "bridges"
		BLOCK_EDGES,

		/// All boundaries of the nav mesh are moved "inwards" by .5*m_minCharacterWidth.
		/// This allows characters less than or equal to this width to use simpler (and faster) checks during A* and path smoothing.
		/// This feature is in beta. Behavior may change in future releases.
		SHRINK_NAV_MESH
	};

	struct RegionPruningSettings
	{
		f32 m_minRegionArea;
		f32 m_minDistanceToSeedPoints;
		f32 m_borderPreservationTolerance;
		hkBool m_preserveVerticalBorderRegions;
		hkBool m_pruneBeforeTriangulation;
		hkArray<hkVector4f> m_regionSeedPoints;
	};

	struct WallClimbingSettings
	{
		hkBool m_enableWallClimbing;
		hkBool m_excludeWalkableFaces;
	};

	struct OverrideSettings
	{
		hkRefPtr<class hkaiVolume> m_volume;
		int m_material;
		hkEnum<CharacterWidthUsage, u8> m_characterWidthUsage;
		f32 m_maxWalkableSlope;
		hkaiNavMeshEdgeMatchingParameters m_edgeMatchingParams;
		hkaiNavMeshSimplificationUtils::Settings m_simplificationSettings;
	};

	struct MaterialConstructionPair
	{
		int m_materialIndex;
		hkFlags<ConstructionFlagsBits, u8> m_flags;
	};

	f32 m_characterHeight;
	hkVector4f m_up;
	f32 m_quantizationGridSize;
	f32 m_maxWalkableSlope;
	hkEnum<TriangleWinding, u8> m_triangleWinding;
	f32 m_degenerateAreaThreshold;
	f32 m_degenerateWidthThreshold;
	f32 m_convexThreshold;
	int m_maxNumEdgesPerFace;
	hkaiNavMeshEdgeMatchingParameters m_edgeMatchingParams;
	hkEnum<EdgeMatchingMetric, u32> m_edgeMatchingMetric;
	int m_edgeConnectionIterations;
	RegionPruningSettings m_regionPruningSettings;
	WallClimbingSettings m_wallClimbingSettings;
	hkAabb m_boundsAabb;
	hkArray<hkRefPtr<class hkaiVolume>> m_carvers;
	hkArray<hkRefPtr<class hkaiMaterialPainter>> m_painters;
	void* m_painterOverlapCallback;
	hkFlags<ConstructionFlagsBits, u32> m_defaultConstructionProperties;
	hkArray<MaterialConstructionPair> m_materialMap;
	hkBool m_weldInputVertices;
	f32 m_weldThreshold;
	f32 m_minCharacterWidth;
	hkEnum<CharacterWidthUsage, u8> m_characterWidthUsage;
	hkBool m_enableSimplification;
	hkaiNavMeshSimplificationUtils::Settings m_simplificationSettings;
	int m_carvedMaterialDeprecated;
	int m_carvedCuttingMaterialDeprecated;
	hkBool m_setBestFaceCenters;
	hkBool m_checkEdgeGeometryConsistency;
	hkBool m_saveInputSnapshot;
	hkStringPtr m_snapshotFilename;
	hkArray<OverrideSettings> m_overrideSettings;

	hkaiNavMeshGenerationSettings() { SDK_CALL_FUNC(void, 0xB483D0, void*)(this); }
};
