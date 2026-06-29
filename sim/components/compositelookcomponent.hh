#pragma once

namespace UFG
{
	class ICompositeLook
	{
	public:
		virtual bool OnIsCulled(CompositeDrawableComponent* composite_drawable, Render::View* view) = 0;
		virtual void OnDraw(CompositeDrawableComponent* composite_drawable, Render::View* view, const qMatrix44& local_matrix) = 0;
		virtual void OnDrawSkin(CompositeDrawableComponent* composite_drawable, Render::View* view, ModelType::ModelBindingSkin* model_binding, Render::SkinningParams* skinning_params) = 0;
		virtual void OnDrawRigid(CompositeDrawableComponent* composite_drawable, Render::View* view, ModelType::ModelBindingRigid* model_binding) = 0;
		virtual void OnReset(CompositeDrawableComponent* composite_drawable) = 0;
		virtual void OnSetHidden(CompositeDrawableComponent* composite_drawable, bool bIsHidden) = 0;
		virtual void OnUpdateMaterial(CompositeDrawableComponent* composite_drawable) = 0;
		virtual void OnUpdateCullResults(CompositeDrawableComponent* composite_drawable, Render::ViewSettings* view_settings) = 0;
	};

	class CompositeLookComponent : public SimComponent, public ICompositeLook, public UpdateInterface, public qNode<CompositeLookComponent>
	{
	public:
		enum { _TypeUID = 0xCC000001 };

		qColour* mColourTints;
		s8 mTransparencyState[3];
		s8 mForceTransparencyState;
		bool mSlowFade;
		u32 mHighlightingMode;
		CB_SceneryInstance* mSceneryInstance;
		RebindingComponentHandle<BaseAnimationComponent> mAnimationComponent;

		/* Static Functions */

		SDK_SINLINE CompositeLookComponent* PropertiesOnActivateNew(SceneObjectProperties* sceneObject, bool required = 1) {
			return SDK_CALL_FUNC(CompositeLookComponent*, 0x58A7F0, SceneObjectProperties*, bool)(sceneObject, required);
		}

		/* Impl Functions */

		SDK_INLINE void ForceFadeOut() { mForceTransparencyState = 0; }
		SDK_INLINE bool HasFadedOut() { return mTransparencyState[0] == 0; }

		/* Functions */

		void ForceFadeIn() { SDK_CALL_FUNC(void, 0x582000, void*)(this); }
		void ForceInvisibleTransparency() { SDK_CALL_FUNC(void, 0x582020, void*)(this); }
		void ForceTransparencyOnAttachments(int transparency_target) { SDK_CALL_FUNC(void, 0x582060, void*, int)(this, transparency_target); }
		void ForceVisibleTransparency() { SDK_CALL_FUNC(void, 0x5822E0, void*)(this); }
		bool HasFadedIn() { return SDK_CALL_FUNC(bool, 0x582B20, void*)(this); }
		void StartFadeIn() { SDK_CALL_FUNC(void, 0x58C6B0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(CompositeLookComponent, 0xB0);

	class CharacterLookComponent : public CompositeLookComponent
	{
	public:
		u32 mOverlayTextureID;
		bool mIsSkinSSEnabled;
		f32 mSweatLevel;
		f32 mWetnessLevel;
		void* mPrevWetSphericalMap;
	};

	class VehicleLookComponent : public CompositeLookComponent
	{
	public:
		VehicleEffectsComponent* mVehicleEffectsComponent;
		__declspec(align(16)) qMatrix44 mVehicleInteriorMS;
		s8 mVehiclePaintID;
		s8 mVehicleGlassID;
	};
}