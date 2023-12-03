#pragma once

namespace Render
{
	class CRenderCallbacks
	{
	public:
		struct Base_t
		{
			void** m_Base = nullptr;
			void* m_Original = nullptr;

			__inline Base_t(void* p_Func, void** p_Base)
			{
				m_Base = p_Base;
				m_Original = *p_Base;
				*m_Base = p_Func;
			}
		};

		struct RenderSim_t : Base_t
		{
			__inline RenderSim_t(void* p_Func, void** p_Base) : Base_t(p_Func, p_Base) { }

			__inline void CallOriginal(UFG::CRenderContext* p_RenderCtx, CView* p_View)
			{
				reinterpret_cast<void(__fastcall*)(UFG::CRenderContext*, CView*)>(m_Original)(p_RenderCtx, p_View);
			}
		};

		void(__fastcall* mRenderWorldFunc)(float, void*);
		bool(__fastcall* mUpdateWorldFunc)(float);
		void(__fastcall* mResizeRenderBuffersFunc)();
		void(__fastcall* mResizeShadowsFunc)();
		void(__fastcall* mChangeTexturePackFunc)();
		void(__fastcall* mChangeLODSettingFunc)();
		void(__fastcall* mRenderThreadSyncPointFunc)();
		void(__fastcall* mRenderSim)(UFG::CRenderContext*, CView*);
		void(__fastcall* mRenderSimDebug)(UFG::CRenderContext*, CView*);
		void(__fastcall* mRenderSimDebugOverlay)(UFG::CRenderContext*, CView*);
		void(__fastcall* mRenderSimOcclusionQueries)(UFG::CRenderContext*, CView*);
		void* mRenderParam;
		bool mbDisableSwapChainResizing;

		static __inline CRenderCallbacks* Instance()
		{
			return reinterpret_cast<CRenderCallbacks*>(UFG_RVA(0x2129980));
		}

		__inline RenderSim_t* AddRenderSim(void* p_Func)
		{
			RenderSim_t* m_RenderSimCallback = new RenderSim_t(p_Func, reinterpret_cast<void**>(&mRenderSim));
			return m_RenderSimCallback;
		}
	};
}