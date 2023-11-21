#pragma once

namespace UFG
{
	namespace TiledMap
	{
		CUITiledMapGPS* GetGPS() { return *reinterpret_cast<CUITiledMapGPS**>(UFG_RVA(0x24310A0)); }

		CUIMapBlipTypeManager* GetBlipTypeManager() { return reinterpret_cast<CUIMapBlipTypeManager*(__fastcall*)()>(UFG_RVA(0xCEFE0))(); }

		CUIMapBlipManager* GetBlipManager() { return *reinterpret_cast<CUIMapBlipManager**>(UFG_RVA(0x2430CD8)); }

		// NOTE: This function is wrapped around RoadNetwork...
		// https://github.com/SDmodding/PseudoSource/blob/4db2cab98665cd03e0796021e8d1c7db5c06d1ea/ufg/madscience/project/sdhd/sdhd_pc/package/tiledmap/dev/source/ui/tiledmap/uitiledmapgps.cpp#L614
		float GetApproxAltitude(qVector3& p_Position) 
		{ 
			return reinterpret_cast<float(__fastcall*)(qVector3&)>(UFG_RVA(0xC0CE0))(p_Position);
		}
	}
}