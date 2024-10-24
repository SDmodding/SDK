#pragma once

class hkpWorld;

class hkpSimulation : public hkReferencedObject
{
public:
	enum LastProcessingStep
	{
		INTEGRATE,
		COLLIDE
	};

	u32 m_determinismCheckFrameCounter;
	hkpWorld* m_world;
	hkEnum<LastProcessingStep, u8> m_lastProcessingStep;
	f32 m_currentTime;
	f32 m_currentPsiTime;
	f32 m_physicsDeltaTime;
	f32 m_simulateUntilTime;
	f32 m_frameMarkerPsiSnap;
	u32 m_previousStepResult;
};
SDK_ASSERT_SIZEOF(hkpSimulation, 0x40);