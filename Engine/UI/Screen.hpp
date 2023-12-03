#pragma once

namespace UFG
{
	class CUIScreenRenderable
	{
	public:
		void* vfptr;
		Illusion::CTarget* m_offscreenTarget;
		bool m_ownsOffscreenTarget;
		char m_fileName[256];
		Scaleform::GFx::MovieInfo m_movieInfo;
		Scaleform::GFx::MovieDef* m_movieDef;
		Scaleform::GFx::Movie* m_movie;
		Scaleform::GFx::Loader* mLoader;
		int m_x;
		int m_y;
		int m_width;
		int m_height;
		bool m_shouldRender;
		volatile bool mIsLoaded;

		void SetViewport(int p_BufferWidth, int p_BufferHeight, int p_X, int p_Y, int p_Width, int p_Height)
		{
			reinterpret_cast<void(__fastcall*)(void*, int, int, int, int, int, int)>(UFG_RVA(0xA32110))(this, p_BufferWidth, p_BufferHeight, p_X, p_Y, p_Width, p_Height);
		}
	};

	class CUIScreen
	{
	public:
		enum eDimType : int
		{
			eDIM_INVALID,
			eDIM_ALPHA_ZERO,
			eDIM_ALPHA_FULL,
			eDIM_ALPHA_HALF,
			eDIM_ALPHA_TEN
		};

		qNode<CUIScreen> mNode;
		char m_screenName[64];
		uint32_t m_screenNameHash;
		CUIScreenRenderable* mRenderable;
		void* mLoadThread;
		uint32_t mScreenUID;
		int mControllerMask;
		int mInputEnabled;
		int mPriority;
		eDimType mDimType;
		eDimType mDimToApplyType;
		float mCurDimValue;
		float mCurDimDirection;

		virtual void Destructor(bool p_Free)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x5BDD90))(this, p_Free);
		}

		virtual void Init(CUICommandData* p_Data)
		{
			reinterpret_cast<void(__fastcall*)(void*, CUICommandData*)>(UFG_RVA(0xA2FD50))(this, p_Data);
		}

		virtual void Render()
		{
			reinterpret_cast<void(__fastcall*)(CUIScreenRenderable*)>(UFG_RVA(0xA319F0))(mRenderable);
		}

		/*
		*	Called from:
		*		IF [In-Game]:
		*			- GameStateInGame::OnUpdate > CBUpdateUI
		*		ELSE:
		*			- FlowController::DoMainLoop
		*	
		*	Basic function:
		*		- Handles the Dim logic (alpha of the root movie)
		*/
		virtual void Update(float p_TimeDelta)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0xA32660))(this, p_TimeDelta);
		}

		// Should be called as last when overriden...
		virtual bool HandleMessage(uint32_t p_MsgID, CUIMessage* p_Msg)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, uint32_t, CUIMessage*)>(UFG_RVA(0xA2F4D0))(this, p_MsgID, p_Msg);
		}

		virtual void CustomPreRender() { };

		virtual void CustomPostRender() { };

		virtual void Dim(eDimType p_DimType, bool p_Instant)
		{
			this->mDimType = p_DimType;
			this->mCurDimDirection = -200.f;
			if (p_Instant)
			{
				switch (p_DimType)
				{
				case eDIM_INVALID: case eDIM_ALPHA_ZERO:
					this->mCurDimValue = 0.f; break;
				case eDIM_ALPHA_FULL:
					this->mCurDimValue = 100.f; break;
				case eDIM_ALPHA_HALF:
					this->mCurDimValue = 50.f; break;
				case eDIM_ALPHA_TEN:
					this->mCurDimValue = 10.f; break;
				}
			}
		}

		virtual void UnDim(bool p_Instant)
		{
			this->mCurDimDirection = 200.f;
			if (p_Instant)
				this->mCurDimValue = 100.f;
		}

		virtual bool IsDimmed()
		{
			return (this->mDimType && this->mCurDimDirection == 0.f);
		}

		virtual bool IsUnDimming()
		{
			return (this->mCurDimDirection > 0.f);
		}

		virtual bool IsDimming()
		{
			return (this->mCurDimDirection < 0.f);
		}

		virtual void Intro(const char* p_FromScreen)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*)>(UFG_RVA(0xA301B0))(this, p_FromScreen);
		}

		virtual void Outro(const char* p_ToScreen)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*)>(UFG_RVA(0xA30650))(this, p_ToScreen);
		}
	};

	UFG_PAD(sizeof(CUIScreen));

	class CUIScreenDialogBox : public CUIScreen
	{
	public:
		struct Data_t
		{
			void* mCommandData;
			CUIScreen* mOwner;
			uint32_t mNumOptions;
			uint32_t mDefaultButton;
			qString mTitleText;
			qString mBodyText;
			uint32_t mOption1Msg;
			uint32_t mOption2Msg;
			uint32_t mOption3Msg;
			qString mOption1Text;
			qString mOption2Text;
			qString mOption3Text;
			uint32_t mIcon;
			bool mFullScreen;
			qString mFlashFile;
			uint32_t mHorizontalResolution;
			uint32_t mVerticalResolution;
		};
		Data_t mData;
		uint32_t mState;
	};

	class CUIHKScreenPauseMenu : public CUIScreen
	{
	public:
		UFG_PAD(0x18);
		// public: UFG::OnlineManagerObserver

		uint32_t mState;
		bool mInfoTickerSet;
	};
}