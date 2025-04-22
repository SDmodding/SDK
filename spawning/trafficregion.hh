#pragma once

namespace UFG
{
	class TrafficRegion : public SpawnPointInterface, public qNode<TrafficRegion>
	{
	public:
		RegionComponent* mpRegion;
		SceneObjectProperties* mpSceneObjProps;
		qSymbol mSpawnSet;
		qSymbol mTimeSet;
		qSymbol mActiveSpawnSet;
		qVector3 mCenterCached;

		/* Static Functions */

		SDK_SINLINE void PropertiesOnActivateNew(SceneObjectProperties* pSceneObj, bool required = 1) { SDK_CALL_FUNC(void, 0x5B5540, SceneObjectProperties*, bool)(pSceneObj, required); }

		/* Functions */

		qSymbol GetSpawnSet_UseTimeSetIfPresent() { return SDK_CALL_FUNC(qSymbol, 0x5B3F60, void*)(this); }
		void Initialize(SimObjectGame* pSimObj) { SDK_CALL_FUNC(void, 0x5B4C00, void*, SimObjectGame*)(this, pSimObj); }
	};
}