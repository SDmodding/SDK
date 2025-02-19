#pragma once

namespace UFG
{
	class SpawnInfoInterface 
	{
	public:
		enum SpawnPriority : int
		{
			Mission,			// Critical
			High,
			Medium,
			Low,
			NumSpawnPriorities,
			DontCare			// Doesn't set
		};

		SDK_SINLINE SimObject* SpawnObject(const qSymbol& objName, const qSymbol& parentSetName, const qMatrix44& xform, SpawnPriority priority = DontCare, SceneLayer* pOwnerLayer = 0, SceneObjectProperties* pSpawnerSceneObj = 0) {
			return SDK_CALL_FUNC(SimObject*, 0x5B72D0, const qSymbol&, const qSymbol&, const qMatrix44&, SpawnPriority, SceneLayer*, SceneObjectProperties*)(objName, parentSetName, xform, priority, pOwnerLayer, pSpawnerSceneObj);
		}

		SDK_SINLINE SimObject* SpawnObject(const qSymbol& objName, const qSymbol& parentSetName, SpawnPriority priority = DontCare, SceneLayer* pOwnerLayer = 0, SceneObjectProperties* pSpawnerSceneObj = 0, SimObject* pOwner = 0) {
			return SDK_CALL_FUNC(SimObject*, 0x5B7310, const qSymbol&, const qSymbol&, SpawnPriority, SceneLayer*, SceneObjectProperties*, SimObject*)(objName, parentSetName, priority, pOwnerLayer, pSpawnerSceneObj, pOwner);
		}

		SDK_SINLINE SimObject* SpawnObject(const qSymbol& objName, qPropertySet* parentSet, const qMatrix44& xform, SpawnPriority priority = DontCare, SceneLayer* pOwnerLayer = 0, SceneObjectProperties* pSpawnerSceneObj = 0) {
			return SDK_CALL_FUNC(SimObject*, 0x5B7350, const qSymbol&, qPropertySet*, const qMatrix44&, SpawnPriority, SceneLayer*, SceneObjectProperties*)(objName, parentSet, xform, priority, pOwnerLayer, pSpawnerSceneObj);
		}

		SDK_SINLINE SimObject* SpawnObject(const qSymbol& objName, qPropertySet* parentSet, SpawnPriority priority = DontCare, SceneLayer* pOwnerLayer = 0, SceneObjectProperties* pSpawnerSceneObj = 0, SimObject* pOwner = 0) {
			return SDK_CALL_FUNC(SimObject*, 0x5B7410, const qSymbol&, qPropertySet*, SpawnPriority, SceneLayer*, SceneObjectProperties*, SimObject*)(objName, parentSet, priority, pOwnerLayer, pSpawnerSceneObj, pOwner);
		}
	};
}