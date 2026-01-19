#pragma once

namespace UFG
{
	class UIPropertySetMenuData
	{
	public:
		UIScreen* mScreen;
		qString mPropertySetName;
		qString mPathToWidget;

		virtual ~UIPropertySetMenuData() = 0;
	};

	class UIPropertySetMenu
	{
	public:
		enum eMenuState
		{
			STATE_INIT,
			STATE_BRIGHTNESS,
			STATE_VOLUME,
			STATE_UISCALE,
			NUM_CALIBRATION_STATES
		};

		qPropertySet* mPSSetData;
		qProxy<UIPropertySetMenuData> mInitData;
		eMenuState mState;
		qString mSelectedItem;
		qString mSelectedSubItem;
		u32 mNumVisibleSlots;
		qString mGameSetup;
		qString mOperation;
		qString mOpDependant;
		qString mScriptFunc;
		qSymbol mProgressionFlow;

		virtual ~UIPropertySetMenu() = 0;
		virtual bool handleMessage(u32 msgId, UIMessage* msg) = 0;
		virtual void setItemEnabled(const char* caption, bool enabled) = 0;
		virtual void removeItem(const char* caption) = 0;
		virtual void clear() = 0;
		virtual void initSubMenu(int numSlots) = 0;
		virtual void addItem(const char* caption, bool enabled) = 0;
		virtual bool addItem(const char* caption, const char* platform, bool enabled) = 0;
		virtual bool addSubmenuItem(const char* caption, const char* platform, bool enabled) = 0;
		virtual void addSubmenuItem(const char* caption, bool enabled) = 0;
		virtual void setGameSetup(const char* gameStr) = 0;
		virtual void setOperation(const char* cmdStr) = 0;
		virtual void setScriptFuncStr(const char* cmdStr) = 0;
		virtual void setOpDependant(const char* cmdStr) = 0;
		virtual void setProgressionFlow(const qSymbol& flow) = 0;
		virtual void expandSubMenu() = 0;
		virtual void leaveSubMenu() = 0;
		virtual void updateHelpbar() = 0;
	};

	class UIPropertySetMenuMainNav : public UIPropertySetMenu
	{
	public:
	};
}