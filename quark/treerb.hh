#pragma once

namespace UFG
{
	class qBaseNodeRB
	{
	public:
		qBaseNodeRB* mParent;
		qBaseNodeRB* mChild[2];
		u32 mUID;
	};

	template <typename T>
	class qNodeRB
	{
	public:
		qBaseNodeRB mNode;
	};
}