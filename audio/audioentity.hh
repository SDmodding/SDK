#pragma once

namespace UFG
{
	class AudioEntity;
	class AudioEvent;
	class EventInfo;

	class WwiseEnvironment
	{
	public:
		enum EnvironmentState : int
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

		virtual ~AudioEntity() = 0;
	};
	SDK_ASSERT_SIZEOF(AudioEntity, 0x140);
}