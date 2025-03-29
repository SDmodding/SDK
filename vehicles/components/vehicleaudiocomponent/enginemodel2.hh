#pragma once

namespace UFG
{
	class Base_EngineState;
	class EngineModel2;

	class EngineModelInput : public qNode<EngineModelInput>, public qNodeRB<EngineModelInput>
	{
	public:
		AudioEventController m_eventController;
		qSymbol mName;
		f32 m_value;
		f32 m_prevValue;

		/* Virtual Functions */

		virtual ~EngineModelInput() = 0;
		virtual void ReadInputs(EngineModel2* em, f32 delta_sec) = 0;
	};

	class EngineModelOutput : public qNode<EngineModelOutput>, public qNodeRB<EngineModelOutput>
	{
	public:
		qSymbol mName;
		f32 m_value;

		/* Virtual Functions */

		virtual ~EngineModelOutput() = 0;
		virtual void WriteOutput(f32 delta_sec, EngineModel2* em) = 0;
	};

	class EngineModelInputs
	{
	public:
		qList<EngineModelInput> m_inputsList;
		qTreeRB<EngineModelInput> m_inputsTree;

		/* Functions */

		void ReadInputs(EngineModel2* em, f32 delta_sec) { SDK_CALL_FUNC(void, 0x6891A0, void*, EngineModel2*, f32)(this, em, delta_sec); }
	};

	class EngineModelOutputs
	{
	public:
		qList<EngineModelOutput> m_outputsList;
		qTreeRB<EngineModelOutput> m_outputsTree;
	};

	class EngineModelBlendMode : public qNode<EngineModelBlendMode>
	{
	public:
		virtual ~EngineModelBlendMode() = 0;
		virtual f32 DoBlend(f32 a, f32 b) = 0;
	};

	class EngineModelBlendModes
	{
	public:
		qList<EngineModelBlendMode> m_modes;
	};

	class EngineStateMachine
	{
	public:
		enum Event
		{
			eEVENT_NO_EVENT,
			eEVENT_START,
			eEVENT_STOP,
			eEVENT_GAS,
			eEVENT_BRAKE,
			eEVENT_DECEL,
			eEVENT_REVERSE,
			eEVENT_UPSHIFT,
			eEVENT_DOWNSHIFT,
			eEVENT_IDLE,
			eEVENT_INAIR,
			eEVENT_NEUTRAL,
			eEVENT_REVLIMIT,
			eEVENT_TRANSITION,
			eEVENT_COLLISION,
			eEVENT_REV,
			eEVENT_DRIFT,
			eEVENT_WHEELIE,
			eEVENT_MAX
		};

		enum State
		{
			eSTATE_OFF,
			eSTATE_IDLE,
			eSTATE_INAIR,
			eSTATE_NEUTRAL,
			eSTATE_GAS,
			eSTATE_DECEL,
			eSTATE_BRAKE,
			eSTATE_REVERSE,
			eSTATE_UPSHIFT,
			eSTATE_DOWNSHIFT,
			eSTATE_REVLIMIT,
			eSTATE_TRANSITION,
			eSTATE_COLLISION,
			eSTATE_REV,
			eSTATE_DRIFTING,
			eSTATE_WHEELIE,
			eSTATE_MAX
		};

		struct Inputs
		{
			u32 curGear;
		};

		Inputs inputs;
		Event m_event;
		f32 m_eventParameter;
		State m_curState;
		f32 m_timeInCurState;
		f32 m_timeAfterRpmLookup;
		bool m_findTimeFromRpm;
		AudioCurveSet* m_stateSpecificCurveSet;
		Base_EngineState* m_states[16];
		EngineModel2* m_engineModel;

		/* Virtual Functions */

		virtual ~EngineStateMachine() = 0;

		/* Functions */

		void ChangeState(State newState) { SDK_CALL_FUNC(void, 0x6742D0, void*, State)(this, newState); }
		void Update(f32 delta_sec) { SDK_CALL_FUNC(void, 0x690EC0, void*, f32)(this, delta_sec); }
	};

	class Base_EngineState
	{
	public:
		AudioCurve* m_curCurve;
		EngineStateMachine* m_esm;

		/* Virtual Functions */

		virtual ~Base_EngineState() = 0;
		virtual void OnEnter(EngineStateMachine::State exitingState) = 0;
		virtual void OnExit(EngineStateMachine::State enteringState) = 0;
		virtual void OnEvent(EngineStateMachine::Event event) = 0;
		virtual void Update(f32 delta_sec) = 0;
		virtual const qSymbol& GetName() = 0;
		virtual f32 GetDefaultLoad(f32 futureTimeDelta) = 0;
	};

	class EngineModel2
	{
	public:
		EngineModelInputs* m_inputs;
		EngineModelOutputs* m_outputs;
		EngineModelBlendModes* m_blendModes;
		AudioEventController m_ecEngine;
		EngineStateMachine* m_engineStateMachine;
		AudioCurve* m_revLimitCurve;
		f32 m_turboChargeAccum;
		f32 m_prevSimSpeed;
		f32 m_simSpeedDelta;
		u32 m_prevMixState;
		f32 m_timeInAir;
		RateLimitedFloatNoMinMax m_accelerationRlf;
		VehicleAudioComponent* m_pVehAudComponent;

		/* Functions */

		void EvaluateCurveSet(AudioCurveSet* acs) { SDK_CALL_FUNC(void, 0x677F50, void*, AudioCurveSet*)(this, acs); }
		void PlayCurveTriggeredSounds(AudioCurve* ac, EngineModelInput* input) { SDK_CALL_FUNC(void, 0x6872C0, void*, AudioCurve*, EngineModelInput*)(this, ac, input); }
		void Update(f32 delta_sec) { SDK_CALL_FUNC(void, 0x690930, void*, f32)(this, delta_sec); }
		void UpdateGlobalCurves(f32 delta_sec) { SDK_CALL_FUNC(void, 0x696EF0, void*, f32)(this, delta_sec); }
		void UpdateMixStates(f32 delta_sec) { SDK_CALL_FUNC(void, 0x6983B0, void*, f32)(this, delta_sec); }
		void UpdateTurbo(f32 delta_sec) { SDK_CALL_FUNC(void, 0x69B4A0, void*, f32)(this, delta_sec); }
	};
}