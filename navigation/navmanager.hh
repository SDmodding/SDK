#pragma once

namespace UFG
{
	class NavManager
	{
	public:
		virtual ~NavManager() = 0;
		virtual void _VFunc1() = 0;
		virtual void ExitGame() = 0;
		virtual void Update(f32 delta_sec) = 0;
		virtual void LowHealthDefrag() = 0;
		virtual void UpdateDynamicObstaclesPre() = 0;
		virtual void UpdateDynamicObstaclesPost() = 0;
		virtual bool IsInsideAIMesh(const qVector3& position, f32 tolerance) = 0;
		virtual bool GetClosestAIMesh(const qVector3& position, const qVector3& closestPosition, f32 tolerance) = 0;
		virtual bool IsAIMeshLoadedAt(const qVector3& position) = 0;
		virtual bool FindPointOnNavmesh(const qVector3& aabbMin, const qVector3& aabbMax, u32 materialFlags) = 0;
		virtual bool AIRayCastHits(HavokNavPosition& positionStart, HavokNavPosition& positionEnd, const NavParams& navParams) = 0;
		virtual bool AIRayCastHits(HavokNavPosition& positionStart, const qVector3& vEnd, const NavParams& navParams, qVector3* pCollisionPoint) = 0;
		virtual class HavokNavDynamicOutline* AddDynamicOutline(const qMatrix44& transform, const qVector3& aabbMin, const qVector3& aabbMax, class DynamicUserEdgeInfo* edgesInfo, u32 edgesCount) = 0;
		virtual bool RemoveDynamicOutline(HavokNavDynamicOutline* outline) = 0;
		virtual bool IsAnyAIMeshAvailable() = 0;
	};
}