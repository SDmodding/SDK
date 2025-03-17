#pragma once

namespace UFG
{
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
}