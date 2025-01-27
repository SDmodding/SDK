#pragma once

namespace UFG
{
	class SceneryGroup : public qResourceData
	{
	public:
		u16 mNumObjects;
		u16 mNumInstances;
		u16 mNumOccluders;
		u16 mNumColours;
		qOffset64<SceneryObject*> mObjects;
		qOffset64<SceneryInstance*> mInstances;
		qOffset64<CullInfo*> mCullInfo;
		qOffset64<CullInfoFull*> mOccluderInfo;
		qOffset64<SceneryTintEntry*> mInstanceColours;
		SceneryGroupComponent* mRenderComponent;
		qVector3 mAABBMin;
		qVector3 mAABBMax;
		u16 mSectionCellIndex;
		u16 mSectionVisIndex;
		u16 mSceneryLayer;
		u16 mFlags;

		/* Static Functions */

		SDK_SINLINE void MakeAllVisible() { SDK_CALL_FUNC(void, 0x233990)(); }

		/* Functions */

		void MakeInvisible(u32 cullIndex) { SDK_CALL_FUNC(void, 0x233A40, void*, u32)(this, cullIndex); }
	};
}