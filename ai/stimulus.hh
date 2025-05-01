#pragma once

namespace UFG
{
	class Stimulus : public Event
	{
	public:
		StimulusDescription m_Description;
		StimulusParameters m_StimulusParameters;
		qSafePointer<SimObject> m_pStimulusProducer;
		qStaticBitField<116> m_StimulusMask;
		qSafePointer<AIEntityComponent> m_pStimulusProducerAIEntityComponent;
		qSafePointer<RigidBodyComponent> m_pStimulusProducerRigidBodyComponent;
		qSafePointer<SimObjectCharacterPropertiesComponent> m_pStimulusProducerCharacterPropertiesComponent;
		qSafePointer<InventoryItemComponent> m_pStimulusProducerInventoryItemComponent;
		qSafePointer<TargetingSystemBaseComponent> m_pStimulusProducerTargetingSystemBaseComponent;
		qSafePointer<StimulusEmitterComponent> m_pStimulusProducerStimulusEmitterComponent;
		bool m_StimulusProducerInfoValid;
		qVector3 m_StimulusProducerPosition;
		qVector3 m_StimulusProducerVelocity;
		qVector3 m_StimulusProducerFacing;
		bool m_IsTargeted;
		qSafePointer<SimObject> m_pStimulusTarget;

		void Init(StimulusEmitterComponent* emitter, SimObject* stimulus_target) { SDK_CALL_FUNC(void, 0x366490, void*, StimulusEmitterComponent*, SimObject*)(this, emitter, stimulus_target); }
	};
}