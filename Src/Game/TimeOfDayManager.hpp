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
		char mOverrideStateBlockHandle[0x20];
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
		unsigned int mCurrStartSlice;
		unsigned int mCurrEndSlice;
		int mFogUpdateInterval;
		void* m_SunFxTransform;
		unsigned int m_SunFx;
		qVector3 mCameraPosition;
		NightFogZone* mNightFogZones;

		bool IsAboutToRain()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x6B420))(this);
		}

		void LockWeather(bool m_Lock)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x6BA30))(this, m_Lock);
		}
	};
	CTimeOfDayManager* TimeOfDayManager = reinterpret_cast<CTimeOfDayManager*>(UFG_RVA(0x2163510));
}