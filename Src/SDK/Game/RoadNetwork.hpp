#pragma once

namespace UFG
{
	class CRoadNetworkLane
	{
	public:
		void GetPos(qVector3* result, float t)
		{
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, float)>(UFG_RVA(0xDB360))(this, result, t);
		}
	};

	class CRoadNetworkNode
	{
	public:
		unsigned short mType;
		unsigned short mActive;
		unsigned int mNameHash;
		unsigned int mDataHash;
		qVector3 mPosition;
		unsigned int mIndex;
		
		UFG_PAD(0x8);

		char mNumLanes;
		char mNumGates;
		char mNumIncomingConnections;
		char mNumOutgoingConnections;

		CRoadNetworkLane* GetLane(unsigned int index)
		{
			return reinterpret_cast<CRoadNetworkLane*(__fastcall*)(void*, unsigned int)>(UFG_RVA(0xD94E0))(this, index);
		}
	};

	class CRoadNetworkResource
	{
	public:
		CRoadNetworkNode* GetClosestNode(qVector3* pos, qVector3* nodePos = nullptr, unsigned int roadNetworkType = 0)
		{
			return reinterpret_cast<CRoadNetworkNode*(__fastcall*)(void*, qVector3*, unsigned int, qVector3*, void*)>(UFG_RVA(0xD6E30))(this, pos, roadNetworkType, nodePos, nullptr);
		}

		qVector3 GetClosetLane(qVector3* pos)
		{
			qVector3 m_Return;

			UFG::CRoadNetworkNode* m_Node = GetClosestNode(pos);
			if (m_Node)
			{
				UFG::CRoadNetworkLane* m_Lane = m_Node->GetLane(0);
				if (m_Lane)
					m_Lane->GetPos(&m_Return, 1.f);
			}

			return m_Return;
		}
	};

	namespace RoadNetwork
	{
		CRoadNetworkResource* Get()
		{
			return *reinterpret_cast<CRoadNetworkResource**>(UFG_RVA(0x2174A50));
		}
	}
}