#pragma once

namespace UFG
{
	class qResourceInventory
	{
	public:
		UFG_PAD(0x50);

		qBaseTreeRB mResourceDatas;

		UFG_PAD(0x50);

		unsigned int mNumUnresolvedHandleLists;
		unsigned int mNumResourceData;
		unsigned int mNumResourceBytes;
		unsigned int mTransactionNum;
		unsigned int mLastUpdate;
		float mAddTime;
		float mRemoveTime;
		float mUnresolvedTime;
		float mLoadTime;
		float mUnloadTime;
		float mInitHandleTime;

		std::vector<qPropertySetResource*> GetContents()
		{
			std::vector<qPropertySetResource*> m_Return;

			for (qBaseNodeRB* i = mResourceDatas.GetHead(); i; i = mResourceDatas.GetNext(i))
				m_Return.emplace_back(reinterpret_cast<qPropertySetResource*>(i));

			return m_Return;
		}
	};

	namespace ResourceInventory
	{
		qResourceInventory* Get()
		{
			return reinterpret_cast<qResourceInventory*>(UFG_RVA(0x23693F0));
		}

		std::vector<qPropertySetResource*> GetContents(qResourceInventory* m_ResourceInventory)
		{
			return m_ResourceInventory->GetContents();
		}
	}
}