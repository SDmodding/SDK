#pragma once

namespace UFG
{
	class VehicleAudioComponent : public HkAudioEntityComponent, public qNode<VehicleAudioComponent>
	{
	public:
		enum { _TypeUID = 0xD2000005 };

		enum eDriverType
		{
			eDriverType_Player,
			eDriverType_PlayerPassenger,
			eDriverType_Traffic,
			eDriverType_Racer,
			eDriverType_Script,
			eDriverType_Cop,
			eDriverType_GhostRider,
			eDriverType_Disabled,
			eDriverType_Last,
			eDriverType_Uninitialized = -1
		};

		class ImpactEntity : public AudioEntity
		{
		public:
			qVector3 m_vLocalPos;
			VehicleAudioComponent* m_pVehicleAudio;
			AudioEventController m_Event;
			bool m_bActive;
		};

		class ScrapeImpactEntity : public ImpactEntity
		{
		public:
			u32 m_myPrevAudioProperty;
			u32 m_otherPrevAudioProperty;
			f32 m_fScrapeCountdown;
		};

		bool m_bMissionPlaylist;
		ScrapeImpactEntity* m_entScrape;
		qWiseSymbol m_vehicleBank;
		qWiseSymbol m_driverTypeBank;
		qWiseSymbol m_commonBank;
		eDriverType m_eDriverType;
		eDriverType m_eLastDriverType;
		eDriverType m_eOverridenDriverType;
		VehicleAudioParameters* m_pTypeParameters;
		VehicleAudioSubTypeParameters* m_pSubTypeParameters;
		qPropertySet* m_pEnginePropertySet;
		f32 m_fTimeAlive;
		f32 m_ghostRiderTime;
		f32 m_fLastWhooshTime;
		f32 m_fDistance2ToListener;
		u32 m_surfaceType;
		f32 m_hornAccum;
		f32 m_hornTime;
		qSafePointer<SimComponent, PhysicsMoverInterface> m_physicsMoverInterface;
		qSafePointer<SimComponent, TransformNodeComponent> m_transformNode;
		EngineModel2* m_engineModel;
		DamageModel* m_damageModel;
		EnvironmentalModel* m_envModel;
		RadioFullyControlled* m_radio;
		DriverReactions* m_driverReaction;
		AudioEventController m_ecRoadNoise;
		AudioEventController m_ecHorn;
		AudioEventController m_ecSiren;
		u32 m_ambientHornId;
		RateLimitedFloat m_rateLimitedSpeed;
		bool m_bEngineRunning : 1;
		bool m_bEngineRunningFlag : 1;
		bool m_bKeepAlive : 1;
		bool m_bRadioEnabledFlag : 1;
		bool m_bUseRadioEnabledFlag : 1;
		bool m_bRadioOnFlag : 1;
		bool m_bVehicleIsInitialized;
		bool m_bHornOn : 1;
		bool m_bHornOnFlag : 1;
		bool m_bHornHasStimulus : 1;
		bool m_bSirenOn : 1;
		bool m_bSirenOnFlag : 1;
		bool m_bUnloadBanksFlag : 1;
		bool m_bShutdownOnExit : 1;
		bool m_bOverrideDriverType;

		/* Virtual Functions */

		virtual void Update(f32 delta_sec) = 0;
		virtual void Init(const qSymbol& objectName) = 0;
		virtual void Shutdown() = 0;

		/* Static Functions */

		SDK_SINLINE void KillOffensiveSoundsForNIS() { SDK_CALL_FUNC(void, 0x67F670)(); }
		SDK_SINLINE void StaticUpdate() { SDK_CALL_FUNC(void, 0x68C860)(); }

		/* Impl Functions */

		SDK_INLINE void EngineStart() { m_bEngineRunningFlag |= 1; }
		SDK_INLINE void SetShutdownOnExit(bool shutdown) { m_bShutdownOnExit = shutdown; }
		SDK_INLINE void StartHorn(bool stimulus) { m_bHornOn = 1; m_bHornHasStimulus = stimulus; }
		SDK_INLINE void StartSiren(bool stimulus) { m_bSirenOnFlag = 1; }
		SDK_INLINE void StopHorn(bool stimulus) { m_bHornOn = 0; m_bHornHasStimulus = stimulus; }
		SDK_INLINE void StopSiren(bool stimulus) { m_bSirenOnFlag = 0; }

		/* Functions */

		void AddTrackToPlaylist(const char* track) { SDK_CALL_FUNC(void, 0x670190, void*, const char*)(this, track); }
		void AudioEntityUpdate(f32 delta_sec) { SDK_CALL_FUNC(void, 0x670CE0, void*, f32)(this, delta_sec); }

		f32 CalculateAndApplyDoppler(f32 delta_sec, const qVector3& vListenerPos, const qVector3& vListenerVelocity) {
			return SDK_CALL_FUNC(f32, 0x673C50, void*, f32, const qVector3&, const qVector3&)(this, delta_sec, vListenerPos, vListenerVelocity);
		}

		void ClearRadioHistory() { SDK_CALL_FUNC(void, 0x674550, void*)(this); }
		void ClearRadioPlaylist() { SDK_CALL_FUNC(void, 0x6745A0, void*)(this); }
		void DoStartHorn(bool stimulus) { SDK_CALL_FUNC(void, 0x676D70, void*, bool)(this, stimulus); }
		void DoStartSiren(bool stimulus) { SDK_CALL_FUNC(void, 0x676E70, void*, bool)(this, stimulus); }
		void DoStopHorn(bool stimulus) { SDK_CALL_FUNC(void, 0x677130, void*, bool)(this, stimulus); }
		void DoStopSiren(bool stimulus) { SDK_CALL_FUNC(void, 0x677190, void*, bool)(this, stimulus); }
		eDriverType FindDriverType() { return SDK_CALL_FUNC(eDriverType, 0x678970, void*)(this); }
		int FindPlayerIndexInVehicleOccupantComponent() { return SDK_CALL_FUNC(int, 0x678AD0, void*)(this); }
		VehicleAudioSubTypeParameters* FindSubTypeParameters() { return SDK_CALL_FUNC(VehicleAudioSubTypeParameters*, 0x678C60, void*)(this); }
		bool GetRadioIsEnabled() { return SDK_CALL_FUNC(bool, 0x67B0D0, void*)(this); }
		u32 GetRadioStation() { return SDK_CALL_FUNC(u32, 0x67B140, void*)(this); }
		bool HasDriver() { return SDK_CALL_FUNC(bool, 0x67D0E0, void*)(this); }
		bool HasOccupant() { return SDK_CALL_FUNC(bool, 0x67D150, void*)(this); }
		void HonkAmbientHorn(f32 timeSec) { SDK_CALL_FUNC(void, 0x67D250, void*, f32)(this, timeSec); }
		void HotSwapEngineCurve(const char* filename) { SDK_CALL_FUNC(void, 0x67D310, const char*)(filename); }
		bool IsDriverTypeWithinCutoffRange(eDriverType driverType, f32 distanceToListener2) { return SDK_CALL_FUNC(bool, 0x67EC80, void*, eDriverType, f32)(this, driverType, distanceToListener2); }
		bool IsEmergencyVehicle() { return SDK_CALL_FUNC(bool, 0x67ED10, void*)(this); }
		bool IsPoliceVehicle() { return SDK_CALL_FUNC(bool, 0x67F4E0, void*)(this); }
		bool IsUndercoverVehicle() { return SDK_CALL_FUNC(bool, 0x67F5B0, void*)(this); }
		bool KeepAliveTest(eDriverType desiredDriverType, f32 distance2ToListener) { return SDK_CALL_FUNC(bool, 0x67F600, void*, eDriverType, f32)(this, desiredDriverType, distance2ToListener); }
		void OnDriverComponentParked() { SDK_CALL_FUNC(void, 0x6848E0, void*)(this); }
		void OnDriverComponentUncontrolled() { SDK_CALL_FUNC(void, 0x684970, void*)(this); }

		void PlayVehicleEvent(const qSymbol& name, AudioEventController* pController, u32 fadeInDurationMs) {
			SDK_CALL_FUNC(void, 0x687440, void*, const qSymbol&, AudioEventController*, u32)(this, name, pController, fadeInDurationMs);
		}

		void RandomizeRadioPlaylist() { SDK_CALL_FUNC(void, 0x688640, void*)(this); }
		void SetDriverType(eDriverType driverType) { SDK_CALL_FUNC(void, 0x68A700, void*, eDriverType)(this, driverType); }
		void SetRadioIsEnabled(bool isEnabled) { SDK_CALL_FUNC(void, 0x68B070, void*, bool)(this, isEnabled); }
		void SetRadioStation(u32 stationIdx) { SDK_CALL_FUNC(void, 0x68B130, void*, u32)(this, stationIdx); }
		bool SoundbanksLoaded() { return SDK_CALL_FUNC(bool, 0x68C240, void*)(this); }
		void StartRoadNoise() { SDK_CALL_FUNC(void, 0x68C3B0, void*)(this); }
		void StopRadio() { SDK_CALL_FUNC(void, 0x68C9B0, void*)(this); }
		void TurnOffRadio() { SDK_CALL_FUNC(void, 0x68DFB0, void*)(this); }
		void TurnOnRadio() { SDK_CALL_FUNC(void, 0x68EAF0, void*)(this); }
		void UnloadSoundbanks() { SDK_CALL_FUNC(void, 0x68ED70, void*)(this); }
		bool WheelsInAir() { return SDK_CALL_FUNC(bool, 0x69B950, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(VehicleAudioComponent, 0x280);
}