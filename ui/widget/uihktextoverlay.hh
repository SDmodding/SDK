#pragma once

namespace UFG
{
	class UIHKTextOverlay;

	class UISubtitleMessage : public qNode<UISubtitleMessage>
	{
	public:
		enum eSUBTITLE_MESSAGE_STATE
		{
			STATE_FADEIN,
			STATE_HOLD,
			STATE_FADEOUT,
			STATE_DONE,
			STATE_NONE
		};

		enum eSUBTITLE_MESSAGE_TYPE
		{
			TYPE_SUBTITLE_TEXT,
			TYPE_FREE_TEXT,
			TYPE_MISSION_COMPLETE,
			TYPE_UNLOCK_ITEM
		};

		u32 id;
		u32 mTagHash;
		f32 lifetime;
		f32 age;
		f32 xPos;
		f32 yPos;
		qString color;
		qString title;
		eSUBTITLE_MESSAGE_STATE state;
		eSUBTITLE_MESSAGE_TYPE type;
		qString mIcon;
		qString mText;

		/* Constructors */

		UISubtitleMessage(eSUBTITLE_MESSAGE_TYPE type, const char* text, const char* icon) {
			SDK_CALL_FUNC(void, 0x3E0660, void*, eSUBTITLE_MESSAGE_TYPE, const char*, const char*)(this, type, text, icon);
		}

		UISubtitleMessage(eSUBTITLE_MESSAGE_TYPE type, u32 tagHash, const char* icon) {
			SDK_CALL_FUNC(void, 0x593700, void*, eSUBTITLE_MESSAGE_TYPE, u32, const char*)(this, type, tagHash, icon);
		}
	};

	class UISubtitleMessageQueue
	{
	public:
		bool mUsesSecondSubtitle;
		bool mPauseQueue;
		UIHKTextOverlay* mParent;
		UISubtitleMessage* mCurrent1;
		UISubtitleMessage* mCurrent2;
		qList<UISubtitleMessage> mQueue;

		/* Impl Functions */

		SDK_INLINE bool IsPlaying() { return mCurrent1 || mCurrent2 || reinterpret_cast<qList<UISubtitleMessage>*>(mQueue.mNode.mNext) != &mQueue; }

		/* Functions */

		void Clear() { SDK_CALL_FUNC(void, 0x5D5310, void*)(this); }
		void CutShort(bool fadeOut) { SDK_CALL_FUNC(void, 0x5D5EE0, void*, bool)(this, fadeOut); }
		void Kill(u32 id) { SDK_CALL_FUNC(void, 0x5F04F0, void*, u32)(this, id); }
		void StartFadeOut() { SDK_CALL_FUNC(void, 0x611EA0, void*)(this); }
	};

	class UIHKTextOverlay
	{
	public:
		bool mChanged;
		bool mSubtitlesVisible;
		UIScreen* mScreen;
		UISubtitleMessageQueue mSubtitleQueue;
		UISubtitleMessageQueue mMissionObjQueue;
		UISubtitleMessageQueue mFreeTextQueue;
		UISubtitleMessageQueue mUnlockItemQueue;
		UISubtitleMessage* mMissionComplete;
		UIHKTimeOfDayWidget TimeOfDay;
		bool mInTransit;
		bool mInTaxi;
		qSafePointer<SimObject, SimObjectVehicle> mVehicle;
		bool mShowIt;
		bool mShowItChanged;
		f32 mSubtitleYOffset;

		/* Virtual Functions */

		virtual ~UIHKTextOverlay() = 0;
		virtual void update(UIScreen* screen, f32 elapsed) = 0;
		virtual bool handleMessage(UIScreen* screen, u32 msgId, UIMessage* msg) = 0;

		/* Functions */

		void ChangeSubtitleLifetime(u32 id, f32 newLifetime) { SDK_CALL_FUNC(void, 0x5D4CA0, void*, u32, f32)(this, id, newLifetime); }
		void Flash_SetSubtitlesVisible(UIScreen* screen, bool visible) { SDK_CALL_FUNC(void, 0x5E0F60, void*, UIScreen*, bool)(this, screen, visible); }
		void Flash_SetSubtitlesYOffset(UIScreen* screen, f32 y_offset) { SDK_CALL_FUNC(void, 0x5E1040, void*, UIScreen*, f32)(this, screen, y_offset); }
		f32 GetSubtitleAge(u32 id) { return SDK_CALL_FUNC(f32, 0x5E95D0, void*, u32)(this, id); }
		void HideMissionObjectives() { SDK_CALL_FUNC(void, 0x5ED0F0, void*)(this); }
		void KillSubtitles(u32 id) { SDK_CALL_FUNC(void, 0x5F0600, void*, u32)(this, id); }
		void OnHideNow(UISubtitleMessage* msg, int subtitleSlotId) { SDK_CALL_FUNC(void, 0x5F2DA0, void*, UISubtitleMessage*, int)(this, msg, subtitleSlotId); }
		void OnStartFadeIn(UISubtitleMessage* msg, int subtitleSlotId) { SDK_CALL_FUNC(void, 0x5F31A0, void*, UISubtitleMessage*, int)(this, msg, subtitleSlotId); }
		void OnStartFadeOut(UISubtitleMessage* msg, int subtitleSlotId) { SDK_CALL_FUNC(void, 0x5F3570, void*, UISubtitleMessage*, int)(this, msg, subtitleSlotId); }
		u32 QueueMessage(UISubtitleMessage* msg) { return SDK_CALL_FUNC(u32, 0x5FEDD0, void*, UISubtitleMessage*)(this, msg); }
		void StartMissionComplete() { SDK_CALL_FUNC(void, 0x611ED0, void*)(this); }
		void StopAllSubtitles(bool fadeOut) { SDK_CALL_FUNC(void, 0x6124C0, void*, bool)(this, fadeOut); }
	};
	SDK_ASSERT_SIZEOF(UIHKTextOverlay, 0x108);
}