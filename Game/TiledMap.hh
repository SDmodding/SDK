#pragma once

namespace UFG
{
	namespace TiledMap
	{
		// NOTE: This function is wrapped around RoadNetwork...
		// https://github.com/SDmodding/PseudoSource/blob/4db2cab98665cd03e0796021e8d1c7db5c06d1ea/ufg/madscience/project/sdhd/sdhd_pc/package/tiledmap/dev/source/ui/tiledmap/uitiledmapgps.cpp#L614
		float GetApproxAltitude(qVector3& p_Position) 
		{ 
			return reinterpret_cast<float(__fastcall*)(qVector3&)>(UFG_RVA(0xC0CE0))(p_Position);
		}
	}
}