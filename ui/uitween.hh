#pragma once

namespace UFG
{
	class UITween : public qNode<UITween>
	{
	public:
		enum eTweenType : i32
		{
			TWEEN_LINEAR,
			TWEEN_SINE_IN,
			TWEEN_SINE_OUT,
			TWEEN_SINE_INOUT,
			TWEEN_QUAD_IN,
			TWEEN_QUAD_OUT,
			TWEEN_QUAD_INOUT,
			TWEEN_CUBIC_IN,
			TWEEN_CUBIC_OUT,
			TWEEN_CUBIC_INOUT,
			TWEEN_QUART_IN,
			TWEEN_QUART_OUT,
			TWEEN_QUART_INOUT,
			TWEEN_QUINT_IN,
			TWEEN_QUINT_OUT,
			TWEEN_QUINT_INOUT,
			TWEEN_EXPO_IN,
			TWEEN_EXPO_OUT,
			TWEEN_EXPO_INOUT,
			TWEEN_CIRC_IN,
			TWEEN_CIRC_OUT,
			TWEEN_CIRC_INOUT,
			TWEEN_BACK_IN,
			TWEEN_BACK_OUT,
			TWEEN_BACK_INOUT,
			TWEEN_BOUNCE_IN,
			TWEEN_BOUNCE_OUT,
			TWEEN_BOUNCE_INOUT,
			TWEEN_ELASTIC_IN,
			TWEEN_ELASTIC_OUT,
			TWEEN_ELASTIC_INOUT
		};

		enum eTweenLoop : i32
		{
			LOOP_NONE,
			LOOP_OSCILLATE,
			LOOP_REPEAT
		};

		enum eTweenRoughnessTaper : i32
		{
			TAPER_NONE,
			TAPER_IN,
			TAPER_OUT
		};

		struct PropertyValues
		{
			f32 start;
			f32 end;
			bool isActive;
		};

		struct RoughnessPoint : qNode<RoughnessPoint>
		{
			f32 tValue;
			f32 yValue;
		};

		Scaleform::GFx::Movie* mMovie;
		qString mPath;
		f32 mDuration;
		eTweenType mType;
		PropertyValues mValues[12];
		f32 mDelay;
		f32 mStep;
		eTweenLoop mLoopType;
		int mLoopCount;
		f32 mLoopDelay;
		f32 mRoughnessRange;
		u32 mRoughnessNumPoints;
		bool mRoughnessRandomize;
		eTweenRoughnessTaper mRoughnessTaper;
		qList<RoughnessPoint> mRoughnessPoints;
		void(__fastcall* mCodeCallbacks[6])(void*);
		void* mCodeCallbackParams[6];
		Scaleform::GFx::Value mCallbacks[6];
		Scaleform::GFx::Value mCallbackParams[6];
		qString mTextFormat;
		f32 mElapsed;
		bool mInited;
		bool mStarted;
		bool mOscillating;
	};
	SDK_ASSERT_SIZEOF(UITween, 0x3E0);
}