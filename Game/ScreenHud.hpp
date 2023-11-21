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

		void DeactivateAll()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x5D6080))(this);
		}

		// This crap is for some reason defined in global ptr...
		// And its used only in "PDAPhoneContactsWidget::LaunchCallMission", but it will call function from this class anyway, so it could be defined under class.
		__inline qString* GetContactImage() { return reinterpret_cast<qString*>(UFG_RVA(0x2431410)); }

		void AnswerPhoneCall(const char* m_ContactName, const char* m_Portrait, bool m_VoiceMail)
		{
			// Information needed because the function below will call (PDAIncomingCallWidget::SetCallerName)
			mPhoneContact.Set(m_ContactName);
			GetContactImage()->Set(m_Portrait);
			mVoiceMail = m_VoiceMail;

			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x5D3B10))(this);
		}

		void QueueIncomingPhoneCall(const char* m_ContactName, bool m_Outgoing, bool m_AutoAnswer, bool m_VoiceMail)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, bool, bool, bool)>(UFG_RVA(0x5FE9C0))(this, m_ContactName, m_Outgoing, m_AutoAnswer, m_VoiceMail);
		}

		bool EndPhoneCall(bool m_PlaySound)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, bool)>(UFG_RVA(0x5D7150))(this, m_PlaySound);
		}
	};


	class CActionButton
	{
	public:
		void Hide() 
		{ 
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x5EC990))(this); 
		}

		void Show(const char* actionText, unsigned int button, const char* actionType) 
		{ 
			reinterpret_cast<void(__fastcall*)(void*, const char*, unsigned int, const char*)>(UFG_RVA(0x60CA80))(this, actionText, button, actionType); 
		}

		void ShowOneFrame(const char* actionText, unsigned int button, const char* actionType)
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

		void Clear() { reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x5D50D0))(this); }

		void SetState(unsigned int state, unsigned int slot) { reinterpret_cast<void(__fastcall*)(void*, unsigned int, unsigned int)>(UFG_RVA(0x609040))(this, state, slot); }

		void SetText(const char* text, unsigned int slot) { reinterpret_cast<void(__fastcall*)(void*, const char*, unsigned int)>(UFG_RVA(0x609FF0))(this, text, slot); }
	};

	class CInfoPopup
	{
	public:
		void Show(const char* caption, qSymbol type, float duration, int position = 0)
		{ 
			reinterpret_cast<void(__fastcall*)(void*, const char*, qSymbol*, float, int)>(UFG_RVA(0x60D100))(this, caption, &type, duration, position); 
		}

		void Hide()
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

		void SetCaption(const char* caption) { reinterpret_cast<void(__fastcall*)(void*, const char*)>(UFG_RVA(0x605610))(this, caption); }

		void SetHealth(float value) 
		{
			if (mHealth == value) return;

			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x606230))(this, value); 
		}

		void SetSuccess(bool success) { reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x609F80))(this, success); }

		void SetVisible(bool visible) { reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x60C630))(this, visible); }
	};

	class CTurnHintWidget
	{
	public:
		void Show(qSymbol m_Icon)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*)>(UFG_RVA(0x60D260))(this, &m_Icon);
		}

		void Hide()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x5ECC40))(this);
		}
	};

	class CRaceTimerWidget
	{
	public:
		void SetVisible(bool visible) { reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x60C650))(this, visible); }

		void SetTime(unsigned int minutes, unsigned int seconds, unsigned int thousandths) 
		{ 
			reinterpret_cast<void(__fastcall*)(void*, unsigned int, unsigned int, unsigned int)>(UFG_RVA(0x60A0C0))(this, minutes, seconds, thousandths);
		}

		void SetTime(float m_FloatTime)
		{
			uint32_t m_Time = static_cast<uint32_t>(m_FloatTime * 1000.f);
			SetTime((m_Time / 1000 / 60), (m_Time / 1000 % 60), (m_Time % 1000));
		}

		void StartCountdown() { reinterpret_cast<void(__fastcall*)()>(UFG_RVA(0x4F2480))(); }
	};

	class CRacePositionWidget
	{
	public:
		void SetVisible(bool visible) { reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x60C640))(this, visible); }

		void SetNumRacers(unsigned int numRacers) { reinterpret_cast<void(__fastcall*)(void*, unsigned int)>(UFG_RVA(0x606620))(this, numRacers); }

		void SetPlayerRank(unsigned int rank) { reinterpret_cast<void(__fastcall*)(void*, unsigned int)>(UFG_RVA(0x606F00))(this, rank); }
	};

	class CRacePathWidget
	{
	public:
		UFG_PAD(0x28);

		uint32_t m_MarkerPositionsSize;
		uint32_t m_MarkerPositionsCapacity;
		qVector3* m_MarkerPositionsPointer;

		void SetVisible(bool m_Enable) { *reinterpret_cast<bool*>(UFG_RVA(0x2173F01)) = m_Enable; }

		void GenerateSpline(qVector3* m_Array, uint32_t m_Size)
		{
			m_MarkerPositionsPointer	= m_Array;
			m_MarkerPositionsSize		= m_Size;

			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0xC0910))(this);

			m_MarkerPositionsPointer	= nullptr;
			m_MarkerPositionsSize		= 0;
		}

		void Clear() 
		{ 
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0xBE980))(this); 
			SetVisible(false);
		}
	};

	class CHintText
	{
	public:
		void Show(const char* text, float displayTime, bool repeat = false, float repeatTime = 0.f) { reinterpret_cast<void(__fastcall*)(void*, const char*, float, bool, float)>(UFG_RVA(0x63AFD0))(this, text, displayTime, repeat, repeatTime); }

		void Hide() { reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x62FBF0))(this); }
	};

	class CMissionComplete
	{
	public:

	};

	class CSecondaryTutorialWidget
	{
	public:
		void Show(const char* m_Text)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*)>(UFG_RVA(0x60D240))(this, m_Text);
		}

		void Hide() 
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
	};

	namespace ScreenHud
	{
		CScreenHud* Get() { return *reinterpret_cast<CScreenHud**>(UFG_RVA(0x2430CC8)); }

		CActionButton* GetActionButton() { return *reinterpret_cast<CActionButton**>(UFG_RVA(0x2430BB8)); }

		CMissionProgress* GetMissionProgress() { return *reinterpret_cast<CMissionProgress**>(UFG_RVA(0x2430BD0)); }

		CInfoPopup* GetInfoPopup() { return *reinterpret_cast<CInfoPopup**>(UFG_RVA(0x2430BD8)); }

		CMissionHealth* GetMissionHealth() { return *reinterpret_cast<CMissionHealth**>(UFG_RVA(0x2430BE0)); }

		CTurnHintWidget* GetTurnHintWidget() { return *reinterpret_cast<CTurnHintWidget**>(UFG_RVA(0x2430BE8)); }

		CRaceTimerWidget* GetRaceTimerWidget() { return *reinterpret_cast<CRaceTimerWidget**>(UFG_RVA(0x2430BF0)); }

		CRacePositionWidget* GetRacePositionWidget() { return *reinterpret_cast<CRacePositionWidget**>(UFG_RVA(0x2430BF8)); }

		CRacePathWidget* GetRacePathWidget() { return *reinterpret_cast<CRacePathWidget**>(UFG_RVA(0x2430C28)); }

		CHintText* GetHintText() { return *reinterpret_cast<CHintText**>(UFG_RVA(0x2430C40)); }

		CSecondaryTutorialWidget* GetSecondaryTutorialWidget() { return *reinterpret_cast<CSecondaryTutorialWidget**>(UFG_RVA(0x2430C58)); }

		void SetVisible(bool value)
		{
			reinterpret_cast<void(__fastcall*)(bool)>(UFG_RVA(0x60C670))(value);
		}

		bool GetVisible()
		{
			return *reinterpret_cast<bool*>(UFG_RVA(0x208E330));
		}

		namespace MissionComplete
		{
			int* TotalScore() { return reinterpret_cast<int*>(UFG_RVA(0x2430C04)); }
			int* PoliceScore() { return reinterpret_cast<int*>(UFG_RVA(0x2430C20)); }
			int* TriadScore() { return reinterpret_cast<int*>(UFG_RVA(0x2430C24)); }
			int* UncappedTotalScore() { return reinterpret_cast<int*>(UFG_RVA(0x2430C38)); }


			float* PoliceScorePercentage() { return reinterpret_cast<float*>(UFG_RVA(0x243121C)); }
			float* TriadScorePercentage() { return reinterpret_cast<float*>(UFG_RVA(0x2431CEC)); }

			void Activate(qSymbol m_GameSliceType, qSymbol m_GameSliceSubType, const char* m_Caption, bool m_ShowXPTutorial)
			{
				reinterpret_cast<void(__fastcall*)(qSymbol*, qSymbol*, const char*, bool)>(UFG_RVA(0x5D10C0))(&m_GameSliceType, &m_GameSliceSubType, m_Caption, m_ShowXPTutorial);
			}

			void AddReward(const char* m_Caption, qSymbol m_Icon)
			{
				static qSymbol m_UIScreenType = 0xD1FAADB0;
				reinterpret_cast<void(__fastcall*)(const char*, qSymbol, qSymbol*)>(UFG_RVA(0x5D2A70))(m_Caption, m_Icon, &m_UIScreenType);
			}

			void ClearRacers()
			{
				reinterpret_cast<void(__fastcall*)()>(UFG_RVA(0x5D5860))();
			}

			void ClearRewards()
			{
				reinterpret_cast<void(__fastcall*)()>(UFG_RVA(0x5D5900))();
			}
		}
	}
}