#pragma once

namespace UFG
{
	class RigidBodyComponent : public RigidBody, public qNode<RigidBodyComponent>
	{
	public:
		enum { _TypeUID = 0x16000003 };

		qSafePointer<class ParkourComponent> mParkourComponent;
		qSafePointer<class DynamicCoverComponent> mCoverComponent;
		qSafePointer<class PhysicsRenderHelper> mRenderComponent;
		qSafePointer<class StateMachineComponent> mStateMachineComponent;
		RebindingComponentHandle<class CharacterAnimationComponent> mAnimationComponent;
		i16 mFollowBoneIndex;
		StateMachineDefinition* mRuntimeStateMachineDefinition;
		f32 mLifeSpan;
		f32 mTimeSinceAddedToWorld;
		u32 mStoredCollisionFilter;

		/* Static Members */

		SDK_VINLINE qGlobalVar<qList<RigidBodyComponent>*, 0x2081A08> s_RigidBodyComponentList;

		/* Functions */

		void CreateRuntimeStateMachineDefinition(StateMachineDefinition* definition) { SDK_CALL_FUNC(void, 0x45FE90, void*, StateMachineDefinition*)(this, definition); }
		bool Deflate() { return SDK_CALL_FUNC(bool, 0x4608B0, void*)(this); }
		void Delete() { SDK_CALL_FUNC(void, 0x4609B0, void*)(this); }
		SimObject* FracturePart(u32 index) { return SDK_CALL_FUNC(SimObject*, 0x465580, void*, u32)(this, index); }
		bool GetKeyframe(hkVector4f& nextPosition, hkQuaternionf& nextOrientation) { return SDK_CALL_FUNC(bool, 0x466990, void*, hkVector4f&, hkQuaternionf&)(this, nextPosition, nextOrientation); }
		void GetStateMachineDefinition(qReflectHandle<UFG::StateMachineDefinition>& h) { SDK_CALL_FUNC(void, 0x467AF0, void*, qReflectHandle<UFG::StateMachineDefinition>&)(this, h); }
		void Inflate(bool addToWorld) { SDK_CALL_FUNC(void, 0x468BD0, void*, bool)(this, addToWorld); }
		void NotifyProxyModeChanged(SimObject::eProxyMode proxyMode) { SDK_CALL_FUNC(void, 0x46D870, void*, SimObject::eProxyMode)(this, proxyMode); }
		const RigidBody* OnRemovePart(class BreakoffPart* breakOffPart, CollisionMeshData::PartDetails* partDetails, u32 instanceGuid) { 
			return SDK_CALL_FUNC(const RigidBody*, 0x46EDB0, void*, BreakoffPart*, CollisionMeshData::PartDetails*, u32)(this, breakOffPart, partDetails, instanceGuid);
		}

		void RestoreCollisionFilter() { SDK_CALL_FUNC(void, 0x474070, void*)(this); }
		void SetStateMachineComponent(StateMachineComponent* smc) { SDK_CALL_FUNC(void, 0x475560, void*, StateMachineComponent*)(this, smc); }
	};
}