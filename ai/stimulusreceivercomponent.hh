#pragma once

namespace UFG
{
	class LastTimeReceivedStimulusInfo
	{
	public:
		f32 m_Time;
		qSafePointer<SimObject> m_pProducer;
	};

	class ReceivedStimulusInfo
	{
	public:
		LastTimeReceivedStimulusInfo m_LastTimeReceived;
		LastTimeReceivedStimulusInfo m_LastTimePerceived;
	};

	class StimulusNotifyCallback : public qNode<StimulusNotifyCallback>
	{
	public:
		eStimulusType m_type;
		fastdelegate::FastDelegate<bool __cdecl(StimulusReceiverComponent*, Stimulus*, StimulusNotifyCallback*)> m_delegate;
	};

	class StimulusReceiverComponent : public SimComponent, public qNode<StimulusReceiverComponent, StimulusReceiverComponent>
	{
	public:
		enum { _TypeUID = 0x54000001 };

		bool m_DebugDraw;
		EventHandlerCookieTag* m_pRegisteredStimulusCookie;
		qStaticBitField<NUM_STIMULUS_TYPES> m_StimulusRegistered;
		ReceivedStimulusInfo* m_pReceivedStimulusInfo[NUM_STIMULUS_TYPES];
		qList<StimulusNotifyCallback> m_OnPerceivedNotifyList;
		i8 m_NumStimuliRegistered;
		i8 m_NumStimuliAllocated;
		f32 m_LastTimePerceivedAnyStimulus;

		/* Functions */

		bool CanPerceive(Stimulus* stimulus, TransformNodeComponent* receiver_transform_node_component) { 
			return SDK_CALL_FUNC(bool, 0x34C200, Stimulus*, TransformNodeComponent*)(stimulus, receiver_transform_node_component);
		}
		bool CheckIfPerceived(Stimulus* stimulus) { return SDK_CALL_FUNC(bool, 0x34DB30, void*, Stimulus*)(this, stimulus); }
		void DeregisterCallbacks() { SDK_CALL_FUNC(void, 0x352150, void*)(this); }
		void HandleStimulus(Event* this_event) { SDK_CALL_FUNC(void, 0x364CB0, void*, Event*)(this, this_event); }
		void MaybeCreateReceivedStimulusInfo(eStimulusType stimulus_type) { SDK_CALL_FUNC(void, 0x374CE0, void*, eStimulusType)(this, stimulus_type); }
		void RegisterNotifyCallback(StimulusNotifyCallback* callback) { SDK_CALL_FUNC(void, 0x380B10, void*, StimulusNotifyCallback*)(this, callback); }
		void RequestToReceiveStimulus(eStimulusType stimulus_type) { SDK_CALL_FUNC(void, 0x382610, void*, eStimulusType)(this, stimulus_type); }
		void SetLastTimePerceived(Stimulus* stimulus) { SDK_CALL_FUNC(void, 0x387010, void*, Stimulus*)(this, stimulus); }
		void SetLastTimeReceived(Stimulus* stimulus) { SDK_CALL_FUNC(void, 0x387160, void*, Stimulus*)(this, stimulus); }
		void UnrequestAllStimuli() { SDK_CALL_FUNC(void, 0x38AF90, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(StimulusReceiverComponent, 0x428);
}