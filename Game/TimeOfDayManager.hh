#pragma once

namespace UFG
{
	struct NightFogZone
	{
		float x;
		float y;
		float innerRadius;
		float outerRadius;
	};

	class __declspec(align(0x8)) CTimeOfDayManager
	{
	public:
		float mBloomNearThreshold;
		float mBloomNearDistance;
		float mBloomFarThreshold;
		float mBloomFarDistance;
		float mBloomBoost;
		float mBloomSaturation;
		float mProbeAttenDistance;
		float mProbeBoost;
		float m_GameSecondsPerRealSecond;
		float m_SecondsSinceMidnight;
		float m_QuantizedSecondsSinceMidnight;
		float m_LocalLatitude;
		float m_SunDeclination;
		float m_WeatherState;
		float m_WeatherTarget;
		float m_NextWeatherTarget;
		int m_WeatherRandomInterval;
		int m_WeatherRandomIntervalPreLock;
		float m_WeatherSurfaceWetness;
		float m_WeatherChanceOfPrecipitation;
		qResourceHandle mOverrideStateBlockHandle;
		float m_OverrideStateBlockAmount;
		float m_OverrideSurfaceWetness;
		float m_NextRainingInterval;
		bool m_PendingRain;
		float mSkySaturation;
		float mSkyBoost;
		float mExposure;
		float mVisualTreatmentEV;
		float mMeteringEV;
		float mTodEV;
		float mGlobalIlluminationBlend;
		qVector3 mAmbientSkyDirection[3];
		float mWindDirectionRadians;
		float mWindDirectionTargetRadians;
		qVector3 mWindDirection;
		float mWindSpeed;
		float mWindSpeedTarget;
		const float m_DefaultGameSecondsPerRealSecond;
		int mNumFogTextures;
		void* mFogCubeTexture[4];
		uint32_t mCurrStartSlice;
		uint32_t mCurrEndSlice;
		int mFogUpdateInterval;
		void* m_SunFxTransform;
		uint32_t m_SunFx;
		qVector3 mCameraPosition;
		NightFogZone* mNightFogZones;

		static UFG_INLINE CTimeOfDayManager* Instance()
		{
			return reinterpret_cast<CTimeOfDayManager*>(UFG_RVA(0x2163510));
		}

		UFG_INLINE bool IsAboutToRain()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x6B420))(this);
		}

		UFG_INLINE void LockWeather(bool m_Lock)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x6BA30))(this, m_Lock);
		}

		// ViewSettings & SkySettings are optional
		UFG_INLINE void GetEnvironmentSettings(Illusion::CB_EnvironmentSettings* p_EnvSettings, Render::CViewSettings* p_ViewSettings = nullptr, Illusion::CB_SkySettings* p_SkySettings = nullptr)
		{
			reinterpret_cast<void(__fastcall*)(void*, Illusion::CB_EnvironmentSettings*, Render::CViewSettings*, Illusion::CB_SkySettings*)>(UFG_RVA(0x69EC0))(this, p_EnvSettings, p_ViewSettings, p_SkySettings);
		}
	};
}