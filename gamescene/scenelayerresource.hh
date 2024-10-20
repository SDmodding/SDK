#pragma once

namespace UFG
{
	class SceneObjectProperties;

	class SceneLayerResource : public qResourceData, public qNode<SceneLayerResource, SceneLayerResource>
	{
	public:
		enum Flags
		{
			FLAG_MEMIMAGE,
			FLAG_IN_INVENTORY,
			FLAG_EXTERNAL_REFERENCES,
			FLAG_ACTIVE
		};

		u32 mFlags;
		u32 mPropertySetCount;
		qOffset64<qOffset64<qPropertySet*>*> mPropertySets;
		qOffset64<qPropertySet*> mGeoInfoPropSet;
		u32 mScriptUID;
		void* mpRuntimeSceneLayer;
		qList<SceneObjectProperties> mObjects;
		qVector3 mAABBMin;
		qVector3 mAABBMax;
		u32 mSourceCRC;
	};
	SDK_ASSERT_SIZEOF(SceneLayerResource, 0xC0);
}