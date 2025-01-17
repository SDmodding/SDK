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
			UFG::qList<Connection> adjacencyList;
		};

		qArray<Node*> mNodes;
		int mNumColors;
		bool mColorsDirty;
	};
}