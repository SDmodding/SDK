#pragma once

namespace UFG
{
	class VisualTreatmentPostEffect : public RenderStagePlugin
	{
	public:
		enum { _TypeUID = 0x06000009 };

		struct TreatmentComponent
		{
			int mTreatmentIndex;
			int mPriority;
			f32 mTimeElapsed;
			u32 mId;
			f32 mFadeOutDuration;
			f32 mFadeOutElapsed;
			bool mFadeOut;
		};

		struct State
		{
			TreatmentComponent mBaseTreatment;
			TreatmentComponent mAdditiveTreatment[5];
			u32 mNumAdditive;
			bool mBasePlaying;
			u32 mTreatmentID;
			bool mRenderTreatment;
		};

		f32* mDefaultVisualTreatmentParams;
		bool mShouldSetCameraFOVOffset;
		f32 mCameraFOVOffset;
		State mState;
		State mSavedState;
		CB_ShaderParams mShaderParams;

		/* Impl Functions */

		SDK_INLINE void StopAllVisualTreatments() { mState.mBasePlaying = mState.mNumAdditive = mSavedState.mBasePlaying = mSavedState.mNumAdditive = 0; }

		/* Functions */

		void AccumulateTreatment(f32* treatmentParams, TreatmentComponent& component, f32 sim_time_delta, bool& expired) {
			SDK_CALL_FUNC(void, 0x5F850, void*, f32*, TreatmentComponent&, f32, bool&)(this, treatmentParams, component, sim_time_delta, expired);
		}

		void RestoreState() { SDK_CALL_FUNC(void, 0x607D0, void*)(this); }
		void SaveState() { SDK_CALL_FUNC(void, 0x60880, void*)(this); }
		u32 StartVisualTreatment(int index, bool isAdditive, int priority) { return SDK_CALL_FUNC(u32, 0x60AF0, void*, int, bool, int)(this, index, isAdditive, priority); }
		void StopVisualTreatment(u32 treatmentId, f32 fade_duration) { SDK_CALL_FUNC(void, 0x60D80, void*, u32, f32)(this, treatmentId, fade_duration); }
	};
	SDK_ASSERT_SIZEOF(VisualTreatmentPostEffect, 0x250);
}