#pragma once

namespace UFG
{
	class qTree64Base
	{
	public:
		struct BaseNode
		{
			u64 mUID;
			BaseNode* mParent;
			BaseNode* mChildren[2];
			BaseNode* mNeighbours[2];
		};

		BaseNode mHead;
		i64 mCount;
	};


	template <typename T>
	class qTreeNode64
	{
	public:
		qTree64Base::BaseNode mBaseNode;
	};
}