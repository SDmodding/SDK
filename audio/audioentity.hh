#pragma once

namespace UFG
{
	class AudioEntity;
	class EventInfo;

	class WwiseEnvironment
	{
	public:
		enum EnvironmentState
		{
			eEnvironmentState_Inactive,
			eEnvironmentState_Loading,
			eEnvironmentState_FadeIn,
			eEnvironmentState_Active,
			eEnvironmentState_FadeOut,
			eEnvironmentState_FadeOutFinished
		};

		AkAuxSendValue mAuxSendValues[4];
		f32 mVolume[4];
		f32 mVolumeOverride[4];
		u16 mEnvCount[4];
		EnvironmentState mEnvState[4];
		f32 mDryLevel;
		int totalEnv;
	};
	SDK_ASSERT_SIZEOF(WwiseEnvironment, 0x60);

	class AudioEntityMotionData
	{
	public:
		qVector3 m_vLastPosition;
		qVector3 m_vLastPositionChecked;
		qVector3 m_vCurVelocity;
		qVector3 m_vPrevVelocity;
	};

	class AudioEntityRegionData
	{
	public:	
		AudioEntity* m_parent;

		virtual ~AudioEntityRegionData() = 0;
	};


	class __declspec(align(16)) AudioEntity : public qNode<AudioEntity>
	{
	public:
		qSymbol m_name;
		bool m_bEnableEnvironments;
		qMatrix44 m_WorldMatrix;
		AudioEntityMotionData* m_pMotionData;
		AudioEntityRegionData* m_pRegionData;
		f32 m_fLastDoppler;
		f32 m_fDistanceUpdateTimeAccumulator;
		RateLimitedFloatSharedRate m_obstruction;
		RateLimitedFloatSharedRate m_occlusion;
		WwiseEnvironment m_environment;
		qProxy<RegionContainmentInfo> m_containmentInfo;
		u32 m_regionCheckFrame;
		s8 m_interiorCount;
		qArray<EventInfo> m_eventInfos;
		qList<AudioEvent> m_events;
		bool m_bIsInitialized;
		bool m_bIsDopplerEnabled;
		bool m_bIsFollowingListener;
		bool m_bOcclusionIsDirty;
		bool m_bPositionIsDirty;
		bool m_bSetOcclusionOverride;
		bool m_spreadRegionChecks;
		bool m_inDoorRegion;
		bool m_oddFrame;

		/* Virtual Functions */

		virtual ~AudioEntity() = 0;
		virtual void Init(const qSymbol& object_name, const qMatrix44& transform) = 0;
		virtual void StopAndForgetEvent(u32 id, f32 ms) = 0;
		virtual void StopAndForgetAllEvents(f32 ms) = 0;
		virtual void DestroyAllEvents() = 0;
		virtual u32 CountNumPlayingEvents() = 0;
		virtual void AudioEntityUpdate(f32 delta_sec) = 0;
		virtual void UpdateVelocity(f32 delta_sec) = 0;
		virtual f32 CalculateAndApplyDoppler(f32 delta_sec, const qVector3& vListenerPos, const qVector3& vListenerVelocity) = 0;
		virtual void SetShouldFollowListener(bool bEnable) = 0;
		virtual bool CanApplyEnvironment(const qWiseSymbol& envType) = 0;

		/* Static Functions */

		SDK_SINLINE void StopAllEvents(u64 objectId) { SDK_CALL_FUNC(void, 0x14CB60, u64)(objectId); }

		/* Impl Functions */

		SDK_INLINE RegionContainmentInfo* GetContainmentInfo() { return &m_containmentInfo; }
		SDK_INLINE qSymbol GetName() { return m_name; }

		/* Functions */

		void ApplyEnvironment(u32 envId, f32 volume, f32 dryLevel, f32 wetLevel, qWiseSymbol* envType) {
			SDK_CALL_FUNC(void, 0x142B70, void*, u32, f32, f32, f32, qWiseSymbol*)(this, envId, volume, dryLevel, wetLevel, envType);
		}

		void ClearContainmentInfo() { SDK_CALL_FUNC(void, 0x143B30, void*)(this); }

		void ClearEnvironments(bool clearThenSet) { SDK_CALL_FUNC(void, 0x143B90, void*, bool)(this, clearThenSet); }

		char CreateAndPlayEvent(u32 eventId, AudioEventController* pEventController, const AudioEventInitParams* pInitParams = 0, u32 fadeInDurationMs = 0, AudioEventExternalSourceInfo* externalSourceInfo = 0) {
			return SDK_CALL_FUNC(char, 0x144070, void*, u32, AudioEventController*, const AudioEventInitParams*, u32, AudioEventExternalSourceInfo*)(this, eventId, pEventController, pInitParams, fadeInDurationMs, externalSourceInfo);
		}

		bool CreateAndPlayEvent(u32 eventId, const AudioEventInitParams* pInitParams = 0, u32 fadeInDurationMs = 0, AudioEventExternalSourceInfo* externalSourceInfo = 0) {
			return SDK_CALL_FUNC(bool, 0x1440B0, void*, u32, const AudioEventInitParams*, u32, AudioEventExternalSourceInfo*)(this, eventId, pInitParams, fadeInDurationMs, externalSourceInfo);
		}

		bool CreateDialogEvent(AudioEventController* pEventController, const AudioEventInitParams* pInitParams = 0, AudioEventExternalSourceInfo* externalSourceInfo = 0) {
			return SDK_CALL_FUNC(bool, 0x144180, void*, AudioEventController*, const AudioEventInitParams*, AudioEventExternalSourceInfo*)(this, pEventController, pInitParams, externalSourceInfo);
		}

		bool CreateEventA(u32 eventId, AudioEventController* pEventController, const AudioEventInitParams* pInitParams = 0, AudioEventExternalSourceInfo* externalSourceInfo = 0) {
			return SDK_CALL_FUNC(bool, 0x144230, void*, u32, AudioEventController*, const AudioEventInitParams*, AudioEventExternalSourceInfo*)(this, eventId, pEventController, pInitParams, externalSourceInfo);
		}

		f32 Debug_GetRtpcValue(u32 rtpcId, bool* global) { return SDK_CALL_FUNC(f32, 0x144420, void*, u32, bool*)(this, rtpcId, global); }
		f32 Distance2ToListener(u32 listenerId) { return SDK_CALL_FUNC(f32, 0x144B80, void*, u32)(this, listenerId); }
		void ForcePositionUpdate() { SDK_CALL_FUNC(void, 0x145B00, void*)(this); }
		f32 GetWetLevelForEffect(u32 id) { return SDK_CALL_FUNC(f32, 0x146870, void*, u32)(this, id); }
		bool IsPlayingId(u32 id) { return SDK_CALL_FUNC(bool, 0x147CD0, void*, u32)(this, id); }
		void RemoveEnvironment(u32 envId, f32 dryLevel, f32 wetLevel) { SDK_CALL_FUNC(void, 0x14B4D0, void*, u32, f32, f32)(this, envId, dryLevel, wetLevel); }
		void ResumeAllEvents() { SDK_CALL_FUNC(void, 0x14B690, void*)(this); }
		void SetObsOccValues(bool forceToTargetVals) { SDK_CALL_FUNC(void, 0x14C020, void*, bool)(this, forceToTargetVals); }

		void SetObstructionAndOcclusionTargets(f32 obstruction, f32 occlusion, bool forceToTargetVals) {
			SDK_CALL_FUNC(void, 0x14C0B0, void*, f32, f32, bool)(this, obstruction, occlusion, forceToTargetVals);
		}


		bool SetRtpcValue(u32 rtpcId, f32 value) { return SDK_CALL_FUNC(bool, 0x14C150, void*, u32, f32)(this, rtpcId, value); }
		bool SetWwiseState(u32 stateId, u32 stateMode) { return SDK_CALL_FUNC(bool, 0x14C4B0, void*, u32, u32)(this, stateId, stateMode); }
		bool SetWwiseSwitch(u32 switchId, u32 typeId) { return SDK_CALL_FUNC(bool, 0x14C570, void*, u32, u32)(this, switchId, typeId); }
		void Shutdown() { SDK_CALL_FUNC(void, 0x14C6D0, void*)(this); }

		void UpdateEnvironments(f32 distanceToListener, f32 delta_sec, WwiseEnvironment* enviroDBG) {
			SDK_CALL_FUNC(void, 0x14E050, void*, f32, f32, WwiseEnvironment*)(this, distanceToListener, delta_sec, enviroDBG);
		}
	};
	SDK_ASSERT_SIZEOF(AudioEntity, 0x140);
}