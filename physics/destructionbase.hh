#pragma once

namespace UFG
{
	class BreakoffPart
	{
	public:
		hkpRigidBody* collidingRigidBody;
		hkpRigidBody* breakingRigidBody;
		hkpRigidBody* newRigidBody;
		u32 shapeKey;
		hkpRemoveTerminalsMoppModifier* mRemoveTerminalsMoppModifier;
	};

	enum eFractureConnectivity : u32
	{
		FC_NONE,
		FC_AUTO_BY_CONTACT
	};

	class FractureConnectivity
	{
	public:
		struct Connection : qNode<Connection>
		{
			u32 nodeIdx;
		};

		struct Node
		{
			u32 partIdx;
			int color;
			qList<Connection> adjacencyList;
		};

		qArray<Node*> mNodes;
		int mNumColors;
		bool mColorsDirty;
	};

	class DestructionEvent : public Event
	{
	public:
		qSafePointer<SimComponent> mCollidingComponent;
		qSafePointer<SimComponent, RigidBody> mBreakingBody;
		qReflectHandle<PhysicsObjectProperties> objectProperty;
		u32 instanceUid;

		/* Constructor, Destructor */

		 DestructionEvent(SimComponent* collidingComponent, RigidBody* breakingBody, u32 instanceGuid) { 
			 SDK_CALL_FUNC(void, 0x98960, void*, SimComponent*, RigidBody*, u32)(this, collidingComponent, breakingBody, instanceGuid);
		 }

		 ~DestructionEvent() { SDK_CALL_FUNC(void, 0x9C260, void*)(this); }
	};

	class Destruction : public hkpBreakOffPartsListener, public hkReferencedObject
	{
	public:
		ThreadSafeQueue<BreakoffPart> mBreakOffPartsQueue;
		qSafePointer<SimComponent, RigidBody> mObjects[15];
		class hkpBreakOffPartsUtil* mBreakOffPartsUtil;

		/* Static Functions */

		SDK_SINLINE Destruction* Instance() { return SDK_VAR_GET(Destruction*, 0x216B298); }

		/* Functions */

		void ForceFracture(RigidBody* rbc, hkpPhysicsSystem* system, int partIndex) { SDK_CALL_FUNC(void, 0xA87E0, void*, RigidBody*, hkpPhysicsSystem*, int)(this, rbc, system, partIndex); }
		bool IsPartMarkedAsBreakable(hkpEntity* entity, u32 shapeKey) { return SDK_CALL_FUNC(bool, 0xACD00, void*, hkpEntity*, u32)(this, entity, shapeKey); }
		void RemovePart(RigidBody* rbc, u32 partIndex) { SDK_CALL_FUNC(void, 0xAFB90, void*, RigidBody*, u32)(this, rbc, partIndex); }
		void ResetScene() { SDK_CALL_FUNC(void, 0xB00A0, void*)(this); }

		void breakOffSubPart(hkpRigidBody* collidingBody, hkpRigidBody* breakingBody, u32 brokenPieceKey, f32 maxImpulse, const hkVector4f& normal, const hkVector4f& position, hkArray<u32>& keysBrokenOffOut, hkpPhysicsSystem* system) {
			SDK_CALL_FUNC(void, 0xB6920, void*, hkpRigidBody*, hkpRigidBody*, u32, f32, const hkVector4f&, const hkVector4f&, hkArray<u32>&, hkpPhysicsSystem*)(this, collidingBody, breakingBody, brokenPieceKey, maxImpulse, normal, position, keysBrokenOffOut, system);
		}

		void removeKeysFromListShape(hkpEntity* entity, u32* keysToRemove, u32 numKeys) { SDK_CALL_FUNC(void, 0xB89E0, hkpEntity*, u32*, u32)(entity, keysToRemove, numKeys); }
	};
	SDK_ASSERT_SIZEOF(Destruction, 0x1E8);
}