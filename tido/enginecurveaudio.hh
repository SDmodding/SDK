#pragma once

namespace UFG
{
	class AudioCurve
	{
	public:
		struct PointProperties
		{
			u32 mPointIndex;
			qWiseSymbol mEvent;
			qSymbol mVehicleEvent;
		};

		s16 m_minRpm;
		s16 m_maxRpm;
		s16 m_minSpeed;
		s16 m_maxSpeed;
		LinearGraph<f32> m_graphCurve;
		f32 mPlayLength;
		qArray<PointProperties>* mPointProperties;
		s8 mSourceValue;
		s8 mTargetValue;
		s8 mBlendMode;
		s8 mId;

		/* Functions */

		f32 FindMinValue() { return SDK_CALL_FUNC(f32, 0x59C620, void*)(this); }
		const qSymbol& GetBlendModeSymbol() { return SDK_CALL_FUNC(const qSymbol&, 0x679640, void*)(this); }
		const qSymbol& GetSourceValueSymbol() { return SDK_CALL_FUNC(const qSymbol&, 0x67B1C0, void*)(this); }
		const qSymbol& GetTargetValueSymbol() { return SDK_CALL_FUNC(const qSymbol&, 0x67B2E0, void*)(this); }
	};

	class AudioCurveSet : public qNode<AudioCurveSet>
	{
	public:
		qSymbol m_name;
		qArray<AudioCurve*> m_curves;
		qArray<AudioCurveSet*> m_childCurveSets;

		/* Functions */

		AudioCurveSet* FindChildCurveSet(qSymbol* name) { return SDK_CALL_FUNC(AudioCurveSet*, 0x59BE30, void*, qSymbol*)(this, name); }
		AudioCurve* FindCurve(const qSymbol& type) { return SDK_CALL_FUNC(AudioCurve*, 0x59BF40, void*, const qSymbol&)(this, type); }
	};

	class EngineCurve : public qNode<EngineCurve>
	{
	public:
		qArray<AudioCurveSet*> m_gears;
		qArray<AudioCurveSet*> m_namedCurveSets;
		qSymbol m_name;
		f32 m_maxRpm;
		int m_refCount;

		/* Impl Functions */

		AudioCurveSet* GetGear(u32 gear) { return (m_gears.size > gear ? m_gears[gear] : 0); }

		/* Functions */

		void DestroyCurveSet(AudioCurveSet* curveSet) { SDK_CALL_FUNC(void, 0x59ADA0, void*, AudioCurveSet*)(this, curveSet); }
		void DestroyEngineCurve() { SDK_CALL_FUNC(void, 0x59AF20, void*)(this); }
		AudioCurve* FindGearCurve(u32 gear, const qSymbol& type) { return SDK_CALL_FUNC(AudioCurve*, 0x59C0B0, void*, u32, const qSymbol&)(this, gear, type); }
		AudioCurveSet* FindNamedCurveSet(const qSymbol& type) { return SDK_CALL_FUNC(AudioCurveSet*, 0x59C6C0, void*, const qSymbol&)(this, type); }
		void Reload(qPropertySet* ps) { SDK_CALL_FUNC(void, 0x5A9CF0, void*, qPropertySet*)(this, ps); }
		bool SetUpFromPropertySet(qPropertySet* ps) { return SDK_CALL_FUNC(bool, 0x5AB860, void*, qPropertySet*)(this, ps); }
	};
}