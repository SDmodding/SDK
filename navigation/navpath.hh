#pragma once

namespace UFG
{
	class NavPath
	{
	public:
		qArray<NavWaypoint> m_aWaypoints;
		qArray<NavResource*> m_aResources;
		u32 m_uRefCount;

		/* Functions */

		void AddResource(NavResource* pNavResource) { SDK_CALL_FUNC(void, 0x340D70, void*, NavResource*)(this, pNavResource); }
		void Append(NavPath* pNavPath) { SDK_CALL_FUNC(void, 0x263770, void*, NavPath*)(this, pNavPath); }
		void RemoveTaggedResources(u32 tag) { SDK_CALL_FUNC(void, 0x265CA0, void*, u32)(this, tag); }
		void RemoveWaypointEnd() { SDK_CALL_FUNC(void, 0x265D80, void*)(this); }
	};

	class NavPathRefPtr
	{
	public:
		NavPath* m_pNavPath;
	};
}