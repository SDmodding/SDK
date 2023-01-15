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
	};

	namespace ResourceInventory
	{
		qResourceInventory* Get()
		{
			return reinterpret_cast<qResourceInventory*>(UFG_RVA(0x23693F0));
		}

		std::vector<qPropertySetResource*> GetContents()
		{
			std::vector<qPropertySetResource*> m_Return;

			qResourceInventory* m_ResourceInventory = Get();
			{
				qBaseNodeRB* v2 = m_ResourceInventory->mResourceDatas.mRoot.mChild[0];
				uintptr_t m_ResourceTree = reinterpret_cast<uintptr_t>(&m_ResourceInventory->mResourceDatas);
				qBaseNodeRB* v4 = v2->mChild[0];
				uintptr_t v5;
				for (v5 = m_ResourceTree + 0x20; v4 != reinterpret_cast<qBaseNodeRB*>(v5); v4 = v4->mChild[0])
					v2 = v4;

				qBaseNodeRB* m_Current = nullptr;
				if (v2 != reinterpret_cast<qBaseNodeRB*>(m_ResourceTree))
					m_Current = v2;

				while (m_Current)
				{
					m_Return.emplace_back(reinterpret_cast<qPropertySetResource*>(m_Current));

					qBaseNodeRB* v7 = m_Current->mChild[1];
					if (reinterpret_cast<qBaseNodeRB*>(v5) == v7)
					{
						qBaseNodeRB* m_Parent = reinterpret_cast<qBaseNodeRB*>(reinterpret_cast<uintptr_t>(m_Current->mParent) & 0xFFFFFFFFFFFFFFFEui64);
						if (m_Current == m_Parent->mChild[1])
						{
							qBaseNodeRB* m_Children = m_Parent->mChild[1];
							while (m_Children == m_Parent->mChild[1])
							{
								m_Children = m_Parent;
								m_Parent = reinterpret_cast<qBaseNodeRB*>(reinterpret_cast<uintptr_t>(m_Parent->mParent) & 0xFFFFFFFFFFFFFFFEui64);
							}
						}

						if (m_Parent == reinterpret_cast<qBaseNodeRB*>(m_ResourceTree))
							break;

						m_Current = m_Parent;
					}
					else
					{
						for (qBaseNodeRB* j = v7->mChild[0]; j != reinterpret_cast<qBaseNodeRB*>(v5); j = j->mChild[0])
							v7 = j;
						m_Current = v7;
					}
				}
			}

			return m_Return;
		}
	}
}