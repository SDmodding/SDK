#pragma once

namespace UFG
{
	class CDoorNode
	{
	public:
		qBaseNodeRB mNode;
		qSymbol m_name; // For anyone reading this. Yes UFG dev add another 4 bytes member that already exist under mNode and they're same values anyway.
		qVector3 m_position;
	};

	class CDoorComponent : public SimComponent
	{
	public:
		qNode<CDoorComponent> mNode;
		CActionNode* mDoorOpeningLeftNode;
		CActionNode* mDoorOpeningRightNode;
		CActionNode* mDoorClosingNode;
		CActionNode* mDoorLockedNode;
		CActionNode* mDoorUnlockedNode;
		bool mOpen;
		bool mIsAutoClosed;
		bool mAutoCloseInit;
		qVector3 mAutoCloseCenter;
		float mAutoCloseTimer;
	};

	namespace DoorStateManager
	{
		UFG_INLINE qBaseTreeRB* GetDoors()
		{
			return reinterpret_cast<qBaseTreeRB*>(UFG_RVA(0x242E8A0));
		}
	}
}