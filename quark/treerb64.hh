#pragma once

namespace UFG
{
	template <typename T>
	class qBaseNodeVariableRB
	{
	public:
		qBaseNodeVariableRB<T>* mParent;
		qBaseNodeVariableRB<T>* mChild[2];
		u64 mUID;
	};

	template <typename T>
	class qNodeRB64
	{
	public:
		qBaseNodeVariableRB<u64> mNode;
	};

	template <typename T>
	class qBaseTreeVariableRB
	{
	public:
		qBaseNodeVariableRB<T> mRoot;
		qBaseNodeVariableRB<T> mNULL;
		int mCount;
	};

	template <typename T, typename U = T>
	class qTreeRB64
	{
	public:
		qBaseTreeVariableRB<u64> mTree;
	};
}