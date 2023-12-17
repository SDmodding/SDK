#pragma once

namespace UFG
{
	template <typename T>
	class CUIScreenFactoryWrapper
	{
	public:
		virtual T* Create()
		{
			CUIScreen* m_Screen = reinterpret_cast<CUIScreen*>(UFG::MemoryPool::GetScaleformPool()->Allocate(sizeof(T), UFG_CONST_CHAR(0x1A1AE08)));
			if (m_Screen)
			{
				// vfptr;
				{
					T m_ScreenClass;
					*reinterpret_cast<void**>(m_Screen) = *reinterpret_cast<void**>(&m_ScreenClass);
				}

				m_Screen->mNode.mPrev = &m_Screen->mNode;
				m_Screen->mNode.mNext = &m_Screen->mNode;
				m_Screen->mRenderable = nullptr;
				m_Screen->mLoadThread = nullptr;
				m_Screen->m_screenNameHash = 0;
				m_Screen->mScreenUID = UINT32_MAX;
				m_Screen->mControllerMask = 0;
				m_Screen->mPriority = 0;
				m_Screen->mDimType = CUIScreen::eDIM_INVALID;
				m_Screen->mDimToApplyType = CUIScreen::eDIM_INVALID;
				m_Screen->mCurDimValue = 100.f;
				m_Screen->m_screenName[0] = '\0';
				m_Screen->mInputEnabled = -1;
			}

			return reinterpret_cast<T*>(m_Screen);
		};

		virtual void Destructor(bool p_Free)
		{
			if (p_Free)
				operator delete(this);
		}
	};

	class CUIScreenFactory
	{
	public:
		void* vfptr;
		qTreeRB m_factoryList;
		char m_rootDir[128];

		__inline void AddScreenMapping(const char* p_Name, void* p_Factory)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, void*)>(UFG_RVA(0xA292F0))(this, p_Name, p_Factory);
		}

		__inline CUIScreen* CreateScreen(const char* p_Name = nullptr)
		{
			return reinterpret_cast<CUIScreen*(__fastcall*)(void*, const char*)>(UFG_RVA(0xA2A6E0))(this, p_Name);
		}
	};
}