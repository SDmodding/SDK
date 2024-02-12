#pragma once

namespace UFG
{
	//============================================================

	class CRoadNetworkSpawnPoint;

	//============================================================

	class CRoadNetworkGate
	{
	public:
		qOffset64<CRoadNetworkNode> mNode;
		qOffset64<CRoadNetworkNode> mConnectedNode;
		qOffset64<CRoadNetworkGate> mConnectedGate;
		qVector3 mPosition;
		qVector3 mDirection;
		uint32_t mNumIncomingConnections;
		qOffset64<qOffset64<CRoadNetworkConnection>> mIncomingConnection;
		uint32_t mNumOutgoingConnections;
		qOffset64<qOffset64<CRoadNetworkConnection>> mOutgoingConnection;
		CRoadNetworkSpawnPoint* mSpawnPoint;
	};
	UFG_ASSERT_CLASS(CRoadNetworkGate, 0x58);
}