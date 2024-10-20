#pragma once

namespace UFG
{
	class SceneObjectProperties : public SimComponent, public qNode<SceneObjectProperties, SceneObjectProperties>
	{
	public:
		qSafePointer<SimObject> mpOwner;
		SceneLayerResource* mpLayerResource;
		SceneObjectProperties* mpParent;
		qSetLogical<SceneObjectProperties, qSymbol> mChildren;
		bool mDeleteChildSimObjectOnDestruct;
		u32 mLastTeleportFrame;
		qPropertySet* mpWritableProperties;
		qPropertySet* mpConstProperties;
		u32 mPrevNameHash;
		u32 mChildIndex;
	};
	SDK_ASSERT_SIZEOF(SceneObjectProperties, 0xA8);
}