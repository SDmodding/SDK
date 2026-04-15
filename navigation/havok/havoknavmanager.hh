#pragma once

namespace UFG
{
	class HavokNavManager : public NavManager
	{
	public:
		/*class AiListener : hkReferencedObject, hkaiWorld::Listener
		{
		public:
			HavokNavManager* m_manager;
		};*/

		struct MeshCell
		{
			void* m_meshFixups;
			void* m_mediatorTreeFixups;
			void* m_edgesFixups;
			hkaiNavMesh* m_mesh;
			class hkaiDirectedGraphExplicitCost* m_clusterGraph;
			hkaiNavMeshQueryMediator* m_mediator;
			class hkaiUserEdgePairArray* m_userEdges;
			hkAabb m_aabb;
			u32 m_id;
			void* m_meshBuffer;
			u32 m_meshBufferSize;
			void* m_mediatorTreeBuffer;
			u32 m_mediatorTreeBufferSize;
			void* m_edgesBuffer;
			u32 m_edgesBufferSize;
			hkArray<class hkaiNavMeshInstance*> m_Instances;
			void* m_debugStrings;

			MeshCell(hkaiNavMesh* mesh, hkaiNavMeshInstance* instance, hkaiDirectedGraphExplicitCost* cost, hkaiNavMeshQueryMediator* mediator, hkaiUserEdgePairArray* userEdges, const hkAabb& aabb, u32 id, void* debugStrings = 0) {
				SDK_CALL_FUNC(void, 0xE4B00, void*, hkaiNavMesh*, hkaiNavMeshInstance*, hkaiDirectedGraphExplicitCost*, hkaiNavMeshQueryMediator*, hkaiUserEdgePairArray*, const hkAabb&, u32, void*)(this, mesh, instance, cost, mediator, userEdges, aabb, id, debugStrings);
			}
		};

		qProxy<hkaiStreamingManager> m_manager;
		class hkaiWorld* m_world;
		hkArray<MeshCell*> m_cells;
		bool m_highspeedMode;
		hkArray<hkaiNavMeshInstance*> m_StitchInstances;
		int m_StitchingDelay;
		hkJobQueue* m_jobQueue;
		hkJobThreadPool* m_jobThreadPool;
		HavokJobMemoryPoolTagger* m_jobMemoryPoolTagger;
		/*hkRefPtr<AiListener> m_listener;
		hkaiUFGNavMeshCostModifier m_costModifier;
		hkaiUFGAStarEdgeFilter m_edgeFilter;
		qArray<HavokNavDynamicOutline*> m_dynamicOutlines;
		qArray<HavokNavDynamicOutline*> m_dynamicOutlinesAdditionQueue;
		qArray<HavokNavDynamicOutline*> m_dynamicOutlinesDeletionQueue;
		hkArray<hkaiUserEdgeUtils::UserEdgePair> m_dynamicEdges;
		hkArray<hkaiUserEdgeUtils::UserEdgePair> m_dynamicEdgesNew;
		qArray<qVector3, 0> m_aTesselationData;
		qArray<qVector3, 0> m_aTmpTesselationData;*/

		/* Static Functions */
		
		SDK_SINLINE HavokNavManager* Instance() { return SDK_VAR_GET(HavokNavManager*, 0x23AD7B8); }

		/* Virtual Functions */

		virtual void SpawnNavMeshInstance(const qMatrix44& transform, u32 meshUid, u32 meshInstanceUid) = 0;
		virtual void DespawnNavMeshInstance(u32 meshUid, u32 meshInstanceUid) = 0;
		virtual void CalculateStitches(bool stitchEverything, hkaiNavMeshInstance* stitchInstance = 0) = 0;
	};
}