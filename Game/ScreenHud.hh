#pragma once

namespace UFG
{
	struct PDAInputLocker_t
	{
		qString mOwner;
		bool mAcquired;
	};

	class CPDAPhoneContactsWidget
	{
	public:
		void* vfptr;
		int mState;
		unsigned int mNumContacts;
		unsigned int mSelectedIndex;
		unsigned int mSelectedSubOptionIndex;
		qString mSelectedName;
		qString mSelectedSubOption;
		qArray<qString> mMissionList;

		struct TxtMsgInfo_t
		{
			qString message;
			qSymbol symbol;
		};
		qArray<TxtMsgInfo_t> mMessages;

		qPropertySet* mData;
		qPropertySet* mContactData;
		qString mTraceName;
		qSymbol mTraceSymbol;
		qString mPerkGiverName;
		qSymbol mPerkGiverSymbol;
		bool mShowingPerkIcon;
		bool mDisablePerk;
		bool mUpdateContactMethod;
		qSymbol mSelectedSymbol;
		qArray<qSymbol> mSymbolList;
		qArray<qString> mNameList;
		qArray<qString> mPortraitList;

		void AddContact(void* m_Screen, qSymbol m_Sym, const char* m_Name, const char* m_Portrait)
		{
			reinterpret_cast<void(__fastcall*)(void*, void*, qSymbol*, const char*, const char*)>(UFG_RVA(0x5D1AA0))(this, m_Screen, &m_Sym, m_Name, m_Portrait);
		}

		void Exit(void* m_Screen, bool m_PlaySound)
		{
			reinterpret_cast<void(__fastcall*)(void*, void*, bool)>(UFG_RVA(0x5D7D50))(this, m_Screen, m_PlaySound);
		}
	};

	class CPDARootMenuWidget
	{
	public:
		int mState;
		float mIdleTime;
		float mRefreshTimer;
		bool mLastScrolledPrev;
		unsigned int mIntroIndex;
		unsigned int mSelectedIndex;
		qString mSelectedItem;
		PDAInputLocker_t mInputLocker;
	};


	class CPDAIncomingCallWidget
	{
	public:
		int mState;
		float mTimer;
		int mOldSeconds;
		bool mUpdateTimer;
		qString mCallerName;
		qString mCallerPortrait;
		bool mVoiceMail;
		PDAInputLocker_t mInputLocker;

		void SetCallerName(const char* m_CallerName, const char* m_Portrait, bool m_VoiceMail)
		{
			mCallerName.Set(m_CallerName);
			mCallerPortrait.Set(m_Portrait);
			mVoiceMail = m_VoiceMail;
		}
	};

	class CPDAIncomingTextWidget
	{
	public:
		int mState;
		bool mMessageRead;
		bool mHelpbarShown;
		bool mIgnoreButtonOnce;
		int mDismissCause;
		float mDisplayTime;
		PDAInputLocker_t mInputLocker;
	};

	class CPDAWidget
	{
	public:
		void* vfptr;
		CPDAPhoneContactsWidget PhoneContacts;
		int mState;
		int mPrevState;
		void* mMovie;

		CPDARootMenuWidget RootMenu;
		int mTextInboxState;
		CPDAIncomingCallWidget IncomingCall;
		CPDAIncomingTextWidget IncomingText;
		int mClockTime;
		qPropertySet* mContactData;
		bool m_objectiveScrollingInProgress;
		float m_objectiveScrollingTimer;
		float m_R1_timer;
		float m_R3_timer;
		float mLeftStickTimer;
		float mRightStickTimer;
		bool mLeftStickActive;
		bool mRightStickActive;
		bool mGPSActivatedFlag;
		unsigned int mPDAOpenDelay;
		bool mTextMsgRead;
		bool mShouldHighlight;
		bool mPreLocked;
		unsigned int mRootIntro;
		qString mPhoneContact;
		bool mOutgoingCall;
		bool mAutoAnsCall;
		bool mVoiceMail;
		float mTime;

		UFG_INLINE void DeactivateAll()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x5D6080))(this);
		}

		// This crap is for some reason defined in global ptr...
		// And its used only in "PDAPhoneContactsWidget::LaunchCallMission", but it will call function from this class anyway, so it could be defined under class.
		static UFG_INLINE qString* GetContactImage() 
		{ 
			return reinterpret_cast<qString*>(UFG_RVA(0x2431410)); 
		}

		UFG_INLINE void AnswerPhoneCall(const char* p_ContactName, const char* p_Portrait, bool p_VoiceMail)
		{
			// Information needed because the function below will call (PDAIncomingCallWidget::SetCallerName)
			mPhoneContact.Set(p_ContactName);
			GetContactImage()->Set(p_Portrait);
			mVoiceMail = p_VoiceMail;

			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x5D3B10))(this);
		}

		UFG_INLINE void QueueIncomingPhoneCall(const char* p_ContactName, bool p_Outgoing, bool p_AutoAnswer, bool p_VoiceMail)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, bool, bool, bool)>(UFG_RVA(0x5FE9C0))(this, p_ContactName, p_Outgoing, p_AutoAnswer, p_VoiceMail);
		}

		UFG_INLINE bool EndPhoneCall(bool p_PlaySound)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, bool)>(UFG_RVA(0x5D7150))(this, p_PlaySound);
		}
	};


	class CActionButton
	{
	public:
		static UFG_INLINE CActionButton* Instance() 
		{ 
			return *reinterpret_cast<CActionButton**>(UFG_RVA(0x2430BB8)); 
		}

		UFG_INLINE void Hide()
		{ 
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x5EC990))(this); 
		}

		UFG_INLINE void Show(const char* actionText, unsigned int button, const char* actionType)
		{ 
			reinterpret_cast<void(__fastcall*)(void*, const char*, unsigned int, const char*)>(UFG_RVA(0x60CA80))(this, actionText, button, actionType); 
		}

		UFG_INLINE void ShowOneFrame(const char* actionText, unsigned int button, const char* actionType)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, unsigned int, const char*)>(UFG_RVA(0x610C90))(this, actionText, button, actionType);
		}
	};

	enum MissionProgressState : unsigned int
	{
		MISSIONPROGRESS_INVALID = 0x0,
		MISSIONPROGRESS_NORMAL = 0x1,
		MISSIONPROGRESS_DANGER = 0x2,
		MISSIONPROGRESS_COMPLETE = 0x3,
		MISSIONPROGRESS_INCOMPLETE = 0x4,
		MISSIONPROGRESS_ANIMATE_COMPLETE = 0x5,
	};

	class CMissionProgress
	{
	public:
		bool mVisible;
		bool mChanged;

		static UFG_INLINE CMissionProgress* Instance() 
		{ 
			return *reinterpret_cast<CMissionProgress**>(UFG_RVA(0x2430BD0)); 
		}

		UFG_INLINE void Clear() 
		{ 
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x5D50D0))(this); 
		}

		UFG_INLINE void SetState(unsigned int state, unsigned int slot) 
		{ 
			reinterpret_cast<void(__fastcall*)(void*, unsigned int, unsigned int)>(UFG_RVA(0x609040))(this, state, slot); 
		}

		UFG_INLINE void SetText(const char* text, unsigned int slot) 
		{ 
			reinterpret_cast<void(__fastcall*)(void*, const char*, unsigned int)>(UFG_RVA(0x609FF0))(this, text, slot); 
		}
	};

	class CInfoPopup
	{
	public:
		static UFG_INLINE CInfoPopup* Instance() 
		{ 
			return *reinterpret_cast<CInfoPopup**>(UFG_RVA(0x2430BD8));
		}

		UFG_INLINE void Show(const char* caption, qSymbol type, float duration, int position = 0)
		{ 
			reinterpret_cast<void(__fastcall*)(void*, const char*, qSymbol*, float, int)>(UFG_RVA(0x60D100))(this, caption, &type, duration, position); 
		}

		UFG_INLINE void Hide()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x5ECBD0))(this);
		}
	};

	class CMissionHealth
	{
	public:
		bool mChanged;
		bool mVisible;
		bool mVisibleChanged;
		bool mSuccess;
		float mHealth;
		qString mCaption;

		static UFG_INLINE CMissionHealth* Instance() 
		{ 
			return *reinterpret_cast<CMissionHealth**>(UFG_RVA(0x2430BE0));
		}

		UFG_INLINE void SetCaption(const char* caption) { reinterpret_cast<void(__fastcall*)(void*, const char*)>(UFG_RVA(0x605610))(this, caption); }

		UFG_INLINE void SetHealth(float value)
		{
			if (mHealth != value) {
				reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x606230))(this, value);
			}
		}

		UFG_INLINE void SetSuccess(bool success) 
		{ 
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x609F80))(this, success); 
		}

		UFG_INLINE void SetVisible(bool visible) 
		{
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x60C630))(this, visible);
		}
	};

	class CTurnHintWidget
	{
	public:
		static UFG_INLINE CTurnHintWidget* Instance() 
		{ 
			return *reinterpret_cast<CTurnHintWidget**>(UFG_RVA(0x2430BE8)); 
		}

		UFG_INLINE void Show(qSymbol m_Icon)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*)>(UFG_RVA(0x60D260))(this, &m_Icon);
		}

		UFG_INLINE void Hide()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x5ECC40))(this);
		}
	};

	class CRaceTimerWidget
	{
	public:
		static UFG_INLINE CRaceTimerWidget* Instance() 
		{ 
			return *reinterpret_cast<CRaceTimerWidget**>(UFG_RVA(0x2430BF0)); 
		}

		UFG_INLINE void SetVisible(bool p_bVisible) 
		{ 
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x60C650))(this, p_bVisible);
		}

		UFG_INLINE void SetTime(uint32_t p_uMinutes, uint32_t p_uSeconds, uint32_t p_uThousandths)
		{ 
			reinterpret_cast<void(__fastcall*)(void*, uint32_t, uint32_t, uint32_t)>(UFG_RVA(0x60A0C0))(this, p_uMinutes, p_uSeconds, p_uThousandths);
		}

		UFG_INLINE void SetTime(float p_fTime)
		{
			uint32_t uTime = static_cast<uint32_t>(p_fTime * 1000.f);
			SetTime((uTime / 1000 / 60), (uTime / 1000 % 60), (uTime % 1000));
		}

		static UFG_INLINE void StartCountdown() 
		{ 
			reinterpret_cast<void(__fastcall*)()>(UFG_RVA(0x4F2480))(); 
		}
	};

	class CRacePositionWidget
	{
	public:
		static UFG_INLINE CRacePositionWidget* Instance() 
		{ 
			return *reinterpret_cast<CRacePositionWidget**>(UFG_RVA(0x2430BF8)); 
		}

		UFG_INLINE void SetVisible(bool p_bVisible) 
		{ 
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x60C640))(this, p_bVisible);
		}

		UFG_INLINE void SetNumRacers(uint32_t p_uNumRacers) 
		{ 
			reinterpret_cast<void(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x606620))(this, p_uNumRacers);
		}

		UFG_INLINE void SetPlayerRank(uint32_t p_uRank)
		{ 
			reinterpret_cast<void(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x606F00))(this, p_uRank);
		}
	};

	class CRacePathWidget
	{
	public:
		UFG_PAD(0x28);

		uint32_t m_MarkerPositionsSize;
		uint32_t m_MarkerPositionsCapacity;
		qVector3* m_MarkerPositionsPointer;

		static UFG_INLINE CRacePathWidget* Instance() 
		{ 
			return *reinterpret_cast<CRacePathWidget**>(UFG_RVA(0x2430C28)); 
		}

		static UFG_INLINE void SetVisible(bool p_bVisible)
		{
			*reinterpret_cast<bool*>(UFG_RVA(0x2173F01)) = p_bVisible;
		}

		void GenerateSpline(qVector3* m_Array, uint32_t m_Size)
		{
			m_MarkerPositionsPointer	= m_Array;
			m_MarkerPositionsSize		= m_Size;

			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0xC0910))(this);

			m_MarkerPositionsPointer	= nullptr;
			m_MarkerPositionsSize		= 0;
		}

		UFG_INLINE void Clear()
		{ 
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0xBE980))(this); 
			SetVisible(false);
		}
	};

	class CHintText
	{
	public:
		static UFG_INLINE CHintText* Instance() 
		{ 
			return *reinterpret_cast<CHintText**>(UFG_RVA(0x2430C40)); 
		}

		UFG_INLINE void Show(const char* p_szText, float p_fDisplayTime, bool p_bRepeat = false, float p_fRepeatTime = 0.f)
		{ 
			reinterpret_cast<void(__fastcall*)(void*, const char*, float, bool, float)>(UFG_RVA(0x63AFD0))(this, p_szText, p_fDisplayTime, p_bRepeat, p_fRepeatTime);
		}

		UFG_INLINE void Hide()
		{ 
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x62FBF0))(this); 
		}
	};

	class CMissionComplete
	{
	public:

	};

	class CSecondaryTutorialWidget
	{
	public:
		static UFG_INLINE CSecondaryTutorialWidget* Instance() 
		{ 
			return *reinterpret_cast<CSecondaryTutorialWidget**>(UFG_RVA(0x2430C58)); 
		}


		UFG_INLINE void Show(const char* p_szText)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*)>(UFG_RVA(0x60D240))(this, p_szText);
		}

		UFG_INLINE void Hide()
		{ 
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x5ECC30))(this);
		}
	};

	class CScreenHud : public CUIScreen
	{
	public:
		CUITiledMapWidget Minimap;
		CPDAWidget* PDA;

		/*UFG::UIHKHealthMeterWidget HealthMeter;
		UFG::UIHKWeaponAmmoWidget WeaponAmmo;
		UFG::UIHKRadioStationWidget RadioStationWidget;
		UFG::UIHKActionHijackWidget ActionHijack;
		UFG::UIHKMoneyPopupWidget MoneyPopup;
		UFG::UIHKBuffWidget Buffs;
		UFG::UIHKSocialActionManager SocialActionManager;
		UFG::UIHKSecondaryObjectivesWidget SecondaryObjectives;
		UFG::UIHKObjectiveFlasherWidget ObjectiveFlasher;
		UFG::UIHKScreenHud::eState mState;
		float mMinimapAlpha;
		float mMinimapFadeTimeout;
		bool mMinimapVisibleChanged;
		UFG::UIHKReticleWidget Reticle;
		UFG::UIHKDirectionalDamageWidget DirectionalDamage;
		UFG::UIHKHeatLevelWidget HeatLevel;
		UFG::UIHKTimeOfDayWidget TimeOfDay;
		UFG::UIHKSniperWidget SniperWidget;
		float mStatInfoTimer;
		bool mStatSocialAwardActive;
		bool mStatGameInfoActive;
		bool mUpdateStatGamePosition;
		bool mHudEnable;*/

		static UFG_INLINE CScreenHud* Instance() 
		{ 
			return *reinterpret_cast<CScreenHud**>(UFG_RVA(0x2430CC8)); 
		}
	};

	namespace ScreenHud
	{
		UFG_INLINE void SetVisible(bool value)
		{
			reinterpret_cast<void(__fastcall*)(bool)>(UFG_RVA(0x60C670))(value);
		}

		UFG_INLINE bool GetVisible()
		{
			return *reinterpret_cast<bool*>(UFG_RVA(0x208E330));
		}

		namespace MissionComplete
		{
			UFG_INLINE int* TotalScore() 
			{ 
				return reinterpret_cast<int*>(UFG_RVA(0x2430C04)); 
			}

			UFG_INLINE int* PoliceScore() 
			{ 
				return reinterpret_cast<int*>(UFG_RVA(0x2430C20));
			}

			UFG_INLINE int* TriadScore() 
			{ 
				return reinterpret_cast<int*>(UFG_RVA(0x2430C24));
			}

			UFG_INLINE int* UncappedTotalScore() 
			{ 
				return reinterpret_cast<int*>(UFG_RVA(0x2430C38)); 
			}

			UFG_INLINE float* PoliceScorePercentage() 
			{ 
				return reinterpret_cast<float*>(UFG_RVA(0x243121C)); 
			}

			UFG_INLINE float* TriadScorePercentage() 
			{ 
				return reinterpret_cast<float*>(UFG_RVA(0x2431CEC)); 
			}

			UFG_INLINE void Activate(qSymbol m_GameSliceType, qSymbol m_GameSliceSubType, const char* m_Caption, bool m_ShowXPTutorial)
			{
				reinterpret_cast<void(__fastcall*)(qSymbol*, qSymbol*, const char*, bool)>(UFG_RVA(0x5D10C0))(&m_GameSliceType, &m_GameSliceSubType, m_Caption, m_ShowXPTutorial);
			}

			UFG_INLINE void AddReward(const char* m_Caption, qSymbol m_Icon)
			{
				qSymbol qScreenType = 0xD1FAADB0; // I FORGOT WHAT IS THIS
				reinterpret_cast<void(__fastcall*)(const char*, qSymbol, qSymbol*)>(UFG_RVA(0x5D2A70))(m_Caption, m_Icon, &qScreenType);
			}

			UFG_INLINE void ClearRacers()
			{
				reinterpret_cast<void(__fastcall*)()>(UFG_RVA(0x5D5860))();
			}

			UFG_INLINE void ClearRewards()
			{
				reinterpret_cast<void(__fastcall*)()>(UFG_RVA(0x5D5900))();
			}
		}
	}
}