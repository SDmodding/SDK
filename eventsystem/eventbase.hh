#pragma once

namespace UFG
{
	class Event;
	class EventChannel;

	class ChannelObj : public qNode<ChannelObj>
	{
	public:
		const char* mName;
		u32 mUID;
		const char* mDescription;
		EventChannel* mEventChannel;

		ChannelObj(const char* name, const char* desc) { SDK_CALL_FUNC(void, 0x1B5C80, void*, const char*, const char*)(this, name, desc); }
		ChannelObj(u32 uid, const char* name, const char* desc) { SDK_CALL_FUNC(void, 0x1B5BF0, void*, u32, const char*, const char*)(this, uid, name, desc); }
	};
	SDK_ASSERT_SIZEOF(ChannelObj, 0x30);

	class HandlerNode : public qNode<HandlerNode>
	{
	public:
		fastdelegate::FastDelegate1<Event*> HandlerFunction;
		u32 mMyDependencyID;
		u32 mListOfWhoIDependOn[2];
	};
	SDK_ASSERT_SIZEOF(HandlerNode, 0x30);

	//----------------------------------------------------------
	//	Event, EventChannel
	//----------------------------------------------------------

	class Event : public qNode<Event>
	{
	public:
		u32 m_EventUID;
		const char* m_NamePTR;
		u64 mUserData0;
		u64 mUserData1;

		virtual ~Event() = 0;
	};
	SDK_ASSERT_SIZEOF(Event, 0x38);

	class EventChannel : public qNodeRB<EventChannel>
	{
	public:
		u32 m_channel_uid;
		ChannelObj* mChannelObj;
		bool mIsDynamic;
		qList<HandlerNode> m_HandlerList;
	};
	SDK_ASSERT_SIZEOF(EventChannel, 0x48);

	//----------------------------------------------------------
	//	Dispatcher
	//----------------------------------------------------------

	class EventDispatcher
	{
	public:
		HandlerNode* mCachedNextNode[16];
		qTreeRB<EventChannel> m_ChannelTree;
		int mListIndex;
		qList<Event> QueuedEventList[2];
		qList<ChannelObj> mSortedChannelList;

		SDK_SINLINE EventDispatcher* Instance() { return SDK_VAR(EventDispatcher*, 0x235F740); }

		/* Functions */

		EventChannel*  CreateChannel(u32 uid, ChannelObj* co, bool dynamic_flag) { return SDK_CALL_FUNC(EventChannel*, 0x1B6030, void*, u32, ChannelObj*, bool)(this, uid, co, dynamic_flag); }

		int DeleteDynamicChannel(u32 uid, EventChannel* channel) { return SDK_CALL_FUNC(int, 0x1B6230, void*, u32, EventChannel*)(this, uid, channel); }

		void DispatchAllQueuedEvents() { SDK_CALL_FUNC(void, 0x1B6380, void*)(this); }

		void DispatchEvent(Event* evt) { SDK_CALL_FUNC(void, 0x1B6460, void*, Event*)(this, evt); }

		void QueueEvent(Event* event) { SDK_CALL_FUNC(void, 0x1B6590, void*, Event*)(this, event); }

		HandlerNode* Register(const fastdelegate::FastDelegate1<Event*>& handler, u32 channel_id, const char* name = 0, u32 depID = 0) { 
			return SDK_CALL_FUNC(UFG::HandlerNode*, 0x1B65C0, void*, const fastdelegate::FastDelegate1<Event*>&, u32, const char*, u32)(this, handler, channel_id, name, depID);
		}

		void UnRegister(HandlerNode* cookie, u32 channel_id) { return SDK_CALL_FUNC(void, 0x1B6810, void*, HandlerNode*, u32)(this, cookie, channel_id); }

		void UnRegister(const fastdelegate::FastDelegate1<Event*>& handler, u32 channel_id) { 
			return SDK_CALL_FUNC(void, 0x1B6890, void*, const fastdelegate::FastDelegate1<Event*>&, u32)(this, handler, channel_id);
		}

	};
	SDK_ASSERT_SIZEOF(EventDispatcher, 0x100);
}