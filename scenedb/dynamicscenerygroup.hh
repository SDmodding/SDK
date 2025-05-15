#pragma once

namespace UFG
{
	class DynamicSceneryInstance : public Render::IDecalScenery, public SimComponent, public qNode<DynamicSceneryInstance>
	{
	public:
		s16 mHidden;
		s16 mForceTransparencyState;
		CullInfo* mCullInfo;
		CullResults* mCullResults;
		s8 mTransparencyState[3];
		Illusion::ModelHandle mModelHandle;
		__declspec(align(16)) qMatrix44 mLocalWorld;
		f32 mSelfIlluminationOverride;
		u32 mNameUID;
		u32 mTagUID;

		/* Constructor */

		void ctor(u32 instance_name_uid, u32 model_name_uid, u32 tag_uid = 0) { SDK_CALL_FUNC(void, 0x22F3D0, void*, u32, u32, u32)(this, instance_name_uid, model_name_uid, tag_uid); }

		/* Impl Functions */

		SDK_INLINE void ForceFadeOut() { mForceTransparencyState = 0; }
		SDK_INLINE bool HasFadedOut() { return mTransparencyState[0] == 0; }

		/* Functions */

		void Draw(Render::View* view) { SDK_CALL_FUNC(void, 0x230FE0, void*, Render::View*)(this, view); }
		void ForceVisible() { SDK_CALL_FUNC(void, 0x231900, void*)(this); }
		void UpdateCullInfo() { SDK_CALL_FUNC(void, 0x2357E0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(DynamicSceneryInstance, 0x100);
}