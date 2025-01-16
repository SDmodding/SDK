#pragma once

namespace UFG
{
	class UIScreen : public qNode<UIScreen>
	{
	public:
		enum eDimType : i32
		{
			eDIM_INVALID,
			eDIM_ALPHA_ZERO,
			eDIM_ALPHA_FULL,
			eDIM_ALPHA_HALF,
			eDIM_ALPHA_TEN
		};

		char m_screenName[64];
		u32 m_screenNameHash;
		UIScreenRenderable* mRenderable;
		qThread* mLoadThread;
		u32 mScreenUID;
		int mControllerMask;
		int mInputEnabled;
		int mPriority;
		eDimType mDimType;
		eDimType mDimToApplyType;
		f32 mCurDimValue;
		f32 mCurDimDirection;

		/* Virtual Functions */

		virtual ~UIScreen() = 0;
		virtual void init(UICommandData* data) = 0;
		virtual void render() = 0;
		virtual void update(f32 elapsed) = 0;
		virtual bool handleMessage(u32 msgId, UIMessage* msg) = 0;
		virtual void customPreRender(Render::View* view) = 0;
		virtual void customPostRender(Render::View* view) = 0;
		virtual void dim(eDimType dimType, bool instant) = 0;
		virtual void undim(bool instant) = 0;
		virtual bool isDimmed() = 0;
		virtual bool isUnDimming() = 0;
		virtual bool isDimming() = 0;
		virtual void intro(const char* fromScreen) = 0;
		virtual void outro(const char* toScreen) = 0;

		/* Functions */

		Scaleform::GFx::Movie* getMovieSafe() { return SDK_CALL_FUNC(Scaleform::GFx::Movie*, 0xA2B980, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(UIScreen, 0x90);
}