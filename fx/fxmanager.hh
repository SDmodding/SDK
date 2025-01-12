#pragma once

namespace Render
{
	class FXOverride : public FX::SharedPointerBase<FXOverride>
	{
	public:
		struct PrecalculatedTriangle
		{
			float surfaceArea;
			u16 meshIndex;
			u16 primIndex;
		};

		__declspec(align(16)) CB_FXOverrideSettings stateBlock;
		u32 modelToEmitFromUID;
		f32 mAABBMin[3];
		f32 mAABBMax[3];
		f32 velocityScale;
		f32 emissionScale;
		f32 sizeScale;
		UFG::qMemoryPool* mMemoryPool;
		PrecalculatedTriangle* mTriangleInfo;
		u32 mNumTriangleInfo;
		f32 mTotalMeshSurfaceArea;
	};
	SDK_ASSERT_SIZEOF(FXOverride, 0x70);

	class FXSettings : public UFG::qResourceData
	{
	public:
		UFG::qVector3 mAABBMin;
		UFG::qVector3 mAABBMax;
		f32 mLength;
		f32 mTransformNodeExtraTime;
		u64 mAudioId;
		u32 mSlowMoFxId;
		f32 mAttachToCameraZDist;
		i8 mLoop;
		i8 mComponentCount;
		i8 mAttachToCamera;
		i8 mPad[13];
	};
	SDK_ASSERT_SIZEOF(FXSettings, 0x98);

	class FXSettingsHandle : public UFG::qTypedResourceHandle<RTypeUID_FXSettings, FXSettings> {};

	class __declspec(align(16)) FXInstance : public UFG::qNodeRB<FXInstance>, public UFG::qNode<FXInstance, class FXInstance_OcclusionList>, public UFG::qNode<FXInstance, class FXInstance_UpdateList>
	{
	public:
		FXSettingsHandle mSettings;
		UFG::qList<class FXComponentInstance> mComponents;
		float mStartTime;
		float mEndTime;
		unsigned int mId;
		float mTransformNodeExtraTime;
		unsigned __int64 mAudioId;
		unsigned int mSplitScreenViewMask;
		char mLoop;
		char mBasisRelativeToParent;
		UFG::qMatrix44 mCullMatrix;
		CullInfo* mCullInfo;
		CullResults* mCullResults;
		FX::HardwareOcclusionQuery* mOcclusionQuery;
		UFG::qSafePointer<UFG::SimComponent, UFG::TransformNodeComponent> mParentNode;
		UFG::qMatrix44 mBasis;
		UFG::qMatrix44 mRelativeBasis;
		FX::SharedPointer<FXOverride> mStateBlockOverride;
	};
	SDK_ASSERT_SIZEOF(FXInstance, 0x190);

	class FXComponentInstance : public UFG::qNode<FXComponentInstance>
	{
	public:
		enum eForceSuspendedState : i32
		{
			eUnsuspended,
			eSuspended,
			eSuspending,
			eUnsuspending
		};

		FXInstance* mContainer;
		f32 mStartTime;
		f32 mEndTime;
		u32 mComponentIndex;
		bool mIsActive;
		bool mIsSuspended;
		eForceSuspendedState mForceSuspendState;
		u32 mSettingsId;

		/* Virtual Functions */

		virtual ~FXComponentInstance() = 0;
		virtual void Init(u32 settingsId) = 0;
		virtual void Activate() = 0;
		virtual void Deactivate(bool willLoopImmediately) = 0;
		virtual void Loop() = 0;
		virtual void ChatlineLiveUpdate() = 0;
		virtual void Suspend(float sim_time) = 0;
		virtual void Resume(float sim_time) = 0;
		virtual void Update(const UFG::qVector3& cam_pos, float sim_time) = 0;
		virtual void DebugDraw(Render::View* view) = 0; // UNUSED

		/* Functions */

		void GetBasis(UFG::qMatrix44& dst) { SDK_CALL_FUNC(void, 0x1CC280, void*, UFG::qMatrix44&)(this, dst); }
	};
	SDK_ASSERT_SIZEOF(FXComponentInstance, 0x38);

	//----------------------------------------------------------------------
	//	Manager
	//----------------------------------------------------------------------

	class FXManager
	{
	public:
		UFG::qTreeRB<FXInstance> mEffectsTree;
		UFG::qList<FXInstance> mEffectsList;
		UFG::qArray<u32> mFilteredEffects;
		u32 mEffectId;
		f32 mCurrentTimeOfDay;
		bool mRenderRainWhileInside;
		f32 mLastUpdateTime;
		i16 mFXOverrideStateParamIndex;
		FX::SharedPointer<FXOverride> mStateBlockDefaultOverride;
		UFG::qSafePointer<UFG::TransformNodeComponent> mCamTransformNode;
		bool mDisplayFXInfo;

		/* Static Functions */

		SDK_SINLINE FXManager* Instance() { return SDK_VAR(FXManager*, 0x2366990); }

		/* Functions */

		FXComponentInstance* CreateComponentFromID(u32 typeId, u32 nameId) { return SDK_CALL_FUNC(FXComponentInstance*, 0x1C9170, u32, u32)(typeId, nameId); }

		u32 CreateEffect(u32 fx_id, UFG::TransformNodeComponent* parent = 0, u32 splitScreenViewMask = -1, FXOverride* overrideObject = 0) {
			return SDK_CALL_FUNC(u32, 0x1CA510, void*, u32, UFG::TransformNodeComponent*, u32, FXOverride*)(this, fx_id, parent, splitScreenViewMask, overrideObject);
		}

		u32 CreateEffect(u32 fx_id, const UFG::qMatrix44& basis, u32 splitScreenViewMask = -1, FXOverride* overrideObject = 0) {
			return SDK_CALL_FUNC(u32, 0x1CA220, void*, u32, const UFG::qMatrix44&, u32, FXOverride*)(this, fx_id, basis, splitScreenViewMask, overrideObject);
		}

		u32 CreateEffect(u32 fx_id, const UFG::qVector3& vPos, const UFG::qVector3& vDir, u32 splitScreenViewMask = -1, FXOverride* overrideObject = 0) {
			return SDK_CALL_FUNC(u32, 0x1CA250, void*, u32, const UFG::qVector3&, const UFG::qVector3&, u32, FXOverride*)(this, fx_id, vPos, vDir, splitScreenViewMask, overrideObject);
		}

		u32 CreateEffect(u32 fx_id, const UFG::qMatrix44& basis, UFG::TransformNodeComponent* parent, f32 currentTime, u32 splitScreenViewMask = -1, FXOverride* overrideObject = 0) {
			return SDK_CALL_FUNC(u32, 0x1C9D30, void*, u32, const UFG::qMatrix44&, UFG::TransformNodeComponent*, f32, u32, FXOverride*)(this, fx_id, basis, parent, currentTime, splitScreenViewMask, overrideObject);
		}

		void EnableOcclusionCulling(u32 fxId) { SDK_CALL_FUNC(void, 0x1CBC90, void*, u32)(this, fxId); }
		FXInstance* FindEffect(u32 fxId) { return SDK_CALL_FUNC(FXInstance*, 0x1CBDE0, void*, u32)(this, fxId); }
		bool IsEffectLooping(u32 fxId) { return SDK_CALL_FUNC(bool, 0x1D0F40, void*, u32)(this, fxId); }
		void KillAllEffects() { SDK_CALL_FUNC(void, 0x1D12F0, void*)(this); }
		void KillEffect(u32 fxId, eFXKillOption killOption = FXKILLOPTION_DEFAULT) { SDK_CALL_FUNC(void, 0x1D1520, void*, u32, eFXKillOption)(this, fxId, killOption); }
		void SetTrackStrength(u32 fxId, f32 strength) { SDK_CALL_FUNC(void, 0x1D6B10, void*, u32, f32)(this, fxId, strength); }
	};
	SDK_ASSERT_SIZEOF(FXManager, 0xA8);
}