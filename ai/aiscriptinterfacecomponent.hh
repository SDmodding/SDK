#pragma once

namespace UFG
{
	enum eScriptArgumentType
	{
		eSCRIPT_ARGUMENT_NONE,
		eSCRIPT_ARGUMENT_VECTOR,
		eSCRIPT_ARGUMENT_STRING,
		eSCRIPT_ARGUMENT_INT,
		eSCRIPT_ARGUMENT_FLOAT,
		eSCRIPT_ARGUMENT_SYMBOL,
		eSCRIPT_ARGUMENT_TRANSFORM_NODE,
		NUM_SCRIPT_ARGUMENT_TYPES
	};

	enum eScriptCommand
	{
		eSCRIPT_COMMAND_NONE,
		eSCRIPT_COMMAND_MOVE_DIRECTLY_TO_POSITION,
		eSCRIPT_COMMAND_PATH_TO_TARGET,
		eSCRIPT_COMMAND_FOLLOW_SCRIPTED_PATH,
		eSCRIPT_COMMAND_PLAY_ACTION_NODE,
		eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST,
		eSCRIPT_COMMAND_TURN_TO_FACE_DIRECTION,
		eSCRIPT_COMMAND_TURN_TO_FACE_POSITION,
		NUM_SCRIPT_COMMANDS
	};

	class ScriptArgument
	{
	public:
		qVector3 m_Vector;
		qSharedString m_String;
		int m_Int;
		f32 m_Float;
		qSymbol m_Symbol;
		qSafePointer<SimComponent, TransformNodeComponent> m_pTransformNodeComponent;
		eScriptArgumentType m_Type;
	};

	class AIScriptInterfaceComponent : public SimComponent, public qNode<AIScriptInterfaceComponent>
	{
	public:
		enum { _TypeUID = 0x56000001 };

		bool m_DebugDrawFollowers;
		u32 m_ScriptTaskRefCount;
		eScriptCommand m_CurrentScriptCommand;
		ScriptArgument m_ScriptArgument[5];
		int m_NumScriptArguments;
		RebindingComponentHandle<ActiveAIEntityComponent> m_pAIEntityComponent;
		RebindingComponentHandle<SimObjectCharacterPropertiesComponent> m_pSimObjectCharacterPropertiesComponent;
		RebindingComponentHandle<TargetingSystemBaseComponent> m_pTargetingSystemBaseComponent;
		qVector3 m_Offset;
		qStaticBitField<548> m_ActionRequestToHold;
		eAIEmotion m_DesiredEmotion;
		f32 m_RadiusToDefend;
		f32 m_InitialAttackTimeMin[2][3][2][2][2];
		f32 m_InitialAttackTimeMax[2][3][2][2][2];
		f32 m_AttackTimeMin[2][3][2][2][2];
		f32 m_AttackTimeMax[2][3][2][2][2];
		f32 m_AttackTimeMinDowned[2][3][2][2][2];
		f32 m_AttackTimeMaxDowned[2][3][2][2][2];
		qSafePointer<SimComponent, ActiveAIEntityComponent> m_pFollower[10];
		bool m_IsOffsetLocalCoords : 1;
		bool m_GotToDesiredActionNode : 1;
		bool m_FinishedHoldingActionRequest : 1;
		bool m_HoldingAnyActionRequests : 1;
		bool m_WantToFlee : 1;
		bool m_IsOutOfFight : 1;
		bool m_HavePositionToDefend : 1;
		bool m_CrouchWhileDefendingPosition : 1;
		bool m_AbandonPositionWhenCompromised : 1;
		bool m_AbandonPositionWhenNoGun : 1;
		bool m_RequestedDialogueState : 1;
		bool m_CanShoveCargo : 1;
		bool m_CanGainAttackRights : 1;
		bool m_FakeHasHostage : 1;
		bool m_AllowedToSprintDuringCombat : 1;
		bool m_FollowScriptedPathPointsSubmitted : 1;
		bool m_InteractingWithVehicleHeuristic : 1;
		bool m_SocialCombatFastTalkSucceeded : 1;

		/* Impl Functions */

		SDK_INLINE void ScriptTaskDecrement() { --m_ScriptTaskRefCount; }
		SDK_INLINE void ScriptTaskIncrement() { ++m_ScriptTaskRefCount; }

		/* Functions */

		bool AddArgument(const qSymbol& symbol) { return SDK_CALL_FUNC(bool, 0x33FFD0, void*, const qSymbol&)(this, symbol); }
		char AddArgument(const char* string) { return SDK_CALL_FUNC(char, 0x33FF70, void*, const char*)(this, string); }
		bool AddArgument(int integer) { return SDK_CALL_FUNC(bool, 0x33FF30, void*, int)(this, integer); }
		void AddFollower(ActiveAIEntityComponent* follower) { SDK_CALL_FUNC(void, 0x340760, void*, ActiveAIEntityComponent*)(this, follower); }
		void BeginCommandActionRequest() { SDK_CALL_FUNC(void, 0x3493C0, void*)(this); }
		void ClearCollisionAvoidanceOverride() { SDK_CALL_FUNC(void, 0x34F100, void*)(this); }
		void ClearPositionToDefend() { SDK_CALL_FUNC(void, 0x34F6B0, void*)(this); }
		void DrawDebugInfo(Render::View* view) { SDK_CALL_FUNC(void, 0x3539F0, void*, Render::View*)(this, view); }
		f32 GetAttackTimeMax(eAttackType attack_type, eTargetTypeEnum target_type, eInCoverType in_cover_type) { 
			return SDK_CALL_FUNC(f32, 0x359F40, void*, eAttackType, eTargetTypeEnum, eInCoverType)(this, attack_type, target_type, in_cover_type);
		}
		f32 GetAttackTimeMaxDowned(eAttackType attack_type, eTargetTypeEnum target_type, eInCoverType in_cover_type) {
			return SDK_CALL_FUNC(f32, 0x35A040, void*, eAttackType, eTargetTypeEnum, eInCoverType)(this, attack_type, target_type, in_cover_type);
		}
		f32 GetAttackTimeMin(eAttackType attack_type, eTargetTypeEnum target_type, eInCoverType in_cover_type) { 
			return SDK_CALL_FUNC(f32, 0x35A140, void*, eAttackType, eTargetTypeEnum, eInCoverType)(this, attack_type, target_type, in_cover_type); 
		}
		f32 GetAttackTimeMinDowned(eAttackType attack_type, eTargetTypeEnum target_type, eInCoverType in_cover_type) {
			return SDK_CALL_FUNC(f32, 0x35A240, void*, eAttackType, eTargetTypeEnum, eInCoverType)(this, attack_type, target_type, in_cover_type);
		}
		f32 GetInitialAttackTimeMax(eAttackType attack_type, eTargetTypeEnum target_type, eInCoverType in_cover_type) {
			return SDK_CALL_FUNC(f32, 0x360670, void*, eAttackType, eTargetTypeEnum, eInCoverType)(this, attack_type, target_type, in_cover_type);
		}
		f32 GetInitialAttackTimeMin(eAttackType attack_type, eTargetTypeEnum target_type, eInCoverType in_cover_type) {
			return SDK_CALL_FUNC(f32, 0x360770, void*, eAttackType, eTargetTypeEnum, eInCoverType)(this, attack_type, target_type, in_cover_type);
		}
		const qVector3& GetPositionToDefend() { return SDK_CALL_FUNC(const qVector3&, 0x362270, void*)(this); }
		bool GiveCommand(eScriptCommand command) { return SDK_CALL_FUNC(bool, 0x363830, void*, eScriptCommand)(this, command); }
		bool GiveCommand(eScriptCommand command, TransformNodeComponent* transform_node_component) { 
			return SDK_CALL_FUNC(bool, 0x363950, void*, eScriptCommand, TransformNodeComponent*)(this, command, transform_node_component);
		}
		bool GiveCommand(eScriptCommand command, const qVector3& vector) { return SDK_CALL_FUNC(bool, 0x363880, void*, eScriptCommand, const qVector3&)(this, command, vector); }
		bool GiveCommand(eScriptCommand command, f32 floating_point) { return SDK_CALL_FUNC(bool, 0x3638F0, void*, eScriptCommand, f32)(this, command, floating_point); }
		void ReadParametersFromPropertySet() { SDK_CALL_FUNC(void, 0x37F670, void*)(this); }
		void Reset() { SDK_CALL_FUNC(void, 0x382720, void*)(this); }
		void SetCollisionAvoidanceOverride(eCollisionAvoidanceType overRideType) { SDK_CALL_FUNC(void, 0x385050, void*, eCollisionAvoidanceType)(this, overRideType); }
		void SetDesiredTarget(eTargetTypeEnum target_type, SimObject* target) { SDK_CALL_FUNC(void, 0x386060, void*, eTargetTypeEnum, SimObject*)(this, target_type, target); }
		void SetPositionToDefend(SimObject* marker_to_defend, f32 radius, bool crouch, bool abandon_when_compromised, bool abandon_when_no_gun) { 
			SDK_CALL_FUNC(void, 0x387A40, void*, SimObject*, f32, bool, bool, bool)(this, marker_to_defend, radius, crouch, abandon_when_compromised, abandon_when_no_gun);
		}
		void StartHoldingActionRequest(const char* action_request_name) { SDK_CALL_FUNC(void, 0x388DE0, void*, const char*)(this, action_request_name); }
		void StopHoldingActionRequest(const char* action_request_name) { SDK_CALL_FUNC(void, 0x3891C0, void*, const char*)(this, action_request_name); }
		void StopHoldingAllActionRequests() { SDK_CALL_FUNC(void, 0x389280, void*)(this); }
	};

	SDK_ASSERT_SIZEOF(AIScriptInterfaceComponent, 0x838);
}