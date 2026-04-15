#pragma once

class hkaiNavMesh : public hkReferencedObject
{
public:
	enum EdgeFlagBits
	{
		/// Edge is blocked by a silhouette.
		EDGE_SILHOUETTE = 1,
		/// Edge is formed by re-triangulating an existing face.
		EDGE_RETRIANGULATED = 2,
		/// Edge lies on original cell boundary.
		EDGE_ORIGINAL = 4,
		/// Opposite edge isn't loaded yet (this isn't used anymore)
		OPPOSITE_EDGE_UNLOADED_UNUSED = 8,
		/// User edge: belongs to a face, but isn't part of the convex boundary for the face
		EDGE_USER = 16,
		/// Edge is not traversable during searches (mainly used for one-way user edge pairs).
		EDGE_BLOCKED = 32,
		/// The edge connects to another edge in another nav mesh
		EDGE_EXTERNAL_OPPOSITE = 64,
	};

	enum NavMeshFlagBits
	{
		/// No flags set
		MESH_NONE = 0,

		/// Whether or not this is a wall-climbing mesh
		MESH_CLIMBING = 1,
	};

	struct Edge
	{
		int m_a;
		int m_b;
		u32 m_oppositeEdge;
		u32 m_oppositeFace;
		hkFlags<EdgeFlagBits, u8> m_flags;
		i8 m_paddingByte;
		hkHalf m_userEdgeCost;
	};

	struct Face
	{
		int m_startEdgeIndex;
		int m_startUserEdgeIndex;
		i16 m_numEdges;
		i16 m_numUserEdges;
		i16 m_clusterIndex;
		u16 m_padding;
	};

	hkArray<Face> m_faces;
	hkArray<Edge> m_edges;
	hkArray<hkVector4f> m_vertices;
	hkArray<class hkaiStreamingSet> m_streamingSets;
	hkArray<int> m_faceData;
	hkArray<int> m_edgeData;
	int m_faceDataStriding;
	int m_edgeDataStriding;
	hkFlags<NavMeshFlagBits, u8> m_flags;
	hkAabb m_aabb;
	f32 m_erosionRadius;
	u64 m_userData;

	SDK_INLINE void ctor() { SDK_CALL_FUNC(void, 0xBE3710, void*)(this); }
};