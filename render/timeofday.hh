#pragma once

namespace UFG
{
	class NightFogZone;

	class TimeOfDayManager
	{
	public:
		f32 mBloomNearThreshold;
		f32 mBloomNearDistance;
		f32 mBloomFarThreshold;
		f32 mBloomFarDistance;
		f32 mBloomBoost;
		f32 mBloomSaturation;
		f32 mProbeAttenDistance;
		f32 mProbeBoost;
		f32 m_GameSecondsPerRealSecond;
		f32 m_SecondsSinceMidnight;
		f32 m_QuantizedSecondsSinceMidnight;
		f32 m_LocalLatitude;
		f32 m_SunDeclination;
		f32 m_WeatherState;
		f32 m_WeatherTarget;
		f32 m_NextWeatherTarget;
		int m_WeatherRandomInterval;
		int m_WeatherRandomIntervalPreLock;
		f32 m_WeatherSurfaceWetness;
		f32 m_WeatherChanceOfPrecipitation;
		Illusion::StateBlockHandle mOverrideStateBlockHandle;
		f32 m_OverrideStateBlockAmount;
		f32 m_OverrideSurfaceWetness;
		f32 m_NextRainingInterval;
		bool m_PendingRain;
		f32 mSkySaturation;
		f32 mSkyBoost;
		f32 mExposure;
		f32 mVisualTreatmentEV;
		f32 mMeteringEV;
		f32 mTodEV;
		f32 mGlobalIlluminationBlend;
		qVector3 mAmbientSkyDirection[3];
		f32 mWindDirectionRadians;
		f32 mWindDirectionTargetRadians;
		qVector3 mWindDirection;
		f32 mWindSpeed;
		f32 mWindSpeedTarget;
		const f32 m_DefaultGameSecondsPerRealSecond;
		int mNumFogTextures;
		Illusion::Texture* mFogCubeTexture[4];
		u32 mCurrStartSlice;
		u32 mCurrEndSlice;
		int mFogUpdateInterval;
		TransformNodeComponent* m_SunFxTransform;
		u32 m_SunFx;
		qVector3 mCameraPosition;
		NightFogZone* mNightFogZones;
		Illusion::StateBlockHandle mSunnyStateBlockHandle;
		Illusion::StateBlockHandle mOvercastStateBlockHandle;

		/* Static Functions */

		SDK_SINLINE TimeOfDayManager* Instance() { return reinterpret_cast<TimeOfDayManager*>(SDK_RVA(0x2163510)); }
		SDK_SINLINE f32 GetMinimumNightFogValue(f32 secondsSinceMidnight) { return SDK_CALL_FUNC(f32, 0x6AAC0, f32)(secondsSinceMidnight); }
		SDK_SINLINE bool GetTimeInSeconds(f32 time, int& timeInSeconds) { return SDK_CALL_FUNC(bool, 0x6B0A0, f32, int&)(time, timeInSeconds); }
		SDK_SINLINE f32 GetWeatherIntensityFromString(const qString& weather) { return SDK_CALL_FUNC(f32, 0x6B1B0, const qString&)(weather); }

		/* Impl Functions */

		SDK_INLINE void SetSurfaceWetnessOverride(f32 wetness) { m_OverrideSurfaceWetness = wetness; }

		/* Functions */

		void GetEnvironmentSettings(CB_EnvironmentSettings* envState, Render::ViewSettings* pViewSettings = 0, CB_SkySettings* skyState = 0) { 
			SDK_CALL_FUNC(void, 0x69EC0, void*, CB_EnvironmentSettings*, Render::ViewSettings*, CB_SkySettings*)(this, envState, pViewSettings, skyState);
		}

		Illusion::Texture* GetFogTexture() { return SDK_CALL_FUNC(Illusion::Texture*, 0x6AA60, void*)(this); }
		bool GetStateblockCurves(CB_EnvironmentSettings* envState, f32* sbArray) { return SDK_CALL_FUNC(bool, 0x6AB60, void*, CB_EnvironmentSettings*, f32*)(this, envState, sbArray); }
		void GetSunDir(qVector4& dir, bool bClampSunElevation, bool bUseQuantizedSeconds) { SDK_CALL_FUNC(void, 0x6AEB0, void*, qVector4&, bool, bool)(this, dir, bClampSunElevation, bUseQuantizedSeconds); }
		
		void GetViewSpaceSunDir(qVector4& out_sun_dir, Render::ViewSettings* pViewSettings) { 
			SDK_CALL_FUNC(void, 0x6B0F0, void*, qVector4&, Render::ViewSettings*)(this, out_sun_dir, pViewSettings); 
		}

		void GetWind(qVector3& direction, f32& speed) { SDK_CALL_FUNC(void, 0x6B270, void*, qVector3&, f32&)(this, direction, speed); }
		bool IsAboutToRain() { return SDK_CALL_FUNC(bool, 0x6B420, void*)(this); }
		bool IsSunShining(CB_EnvironmentSettings* envState) { return SDK_CALL_FUNC(bool, 0x6B460, void*, CB_EnvironmentSettings*)(this, envState); }
		void LockWeather(bool lock) { SDK_CALL_FUNC(void, 0x6BA30, void*, bool)(this, lock); }
		void SetFogSlicingMode(int updateInterval) { SDK_CALL_FUNC(void, 0x6BA60, void*, int)(this, updateInterval); }
		void SetOverrideEnvironmentSettings(u32 env_stateblock_uid, f32 override_amount) { SDK_CALL_FUNC(void, 0x3E4FE0, void*, u32, f32)(this, env_stateblock_uid, override_amount); }
		void SetTime(f32 secondsSinceMidnight, bool is_regular_update) { SDK_CALL_FUNC(void, 0x6BAE0, void*, f32, bool)(this, secondsSinceMidnight, is_regular_update); }
		void SetWeather(f32 weather_amount) { SDK_CALL_FUNC(void, 0x6BC10, void*, f32)(this, weather_amount); }
		void SetWeatherTarget(f32 weather_target) { SDK_CALL_FUNC(void, 0x4BDDC0, void*, f32)(this, weather_target); }
		void SetWind(f32 directionRadians, f32 speed) { SDK_CALL_FUNC(void, 0x6BC50, void*, f32, f32)(this, directionRadians, speed); }
	};
}