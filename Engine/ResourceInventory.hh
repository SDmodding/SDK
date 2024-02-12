#pragma once

namespace UFG
{
	class qResourceInventory
	{
	public:
		void* vfptr;
		qBaseNodeRB mBaseNode;
		qNode<qResourceInventory> mNode;
		uint32_t mDefaultResourceNameUID;
		uint32_t mChunkUID;
		const char* mName;
		qResourceData* mDefaultResourceData;
		qBaseTreeRB mResourceDatas;
		qList<void*> mNullHandles;
		qList<void*> mInternalUnresolvedHandles[4];
		qList<void*>* mUnresolvedHandleLists;
		uint32_t mNumUnresolvedHandleLists;
		uint32_t mNumResourceData;
		uint32_t mNumResourceBytes;
		uint32_t mTransactionNum;
		uint32_t mLastUpdate;
		float mAddTime;
		float mRemoveTime;
		float mUnresolvedTime;
		float mLoadTime;
		float mUnloadTime;
		float mInitHandleTime;

		static UFG_INLINE qResourceInventory* Instance()
		{
			return reinterpret_cast<qResourceInventory*>(UFG_RVA(0x23693F0));
		}

		std::vector<qPropertySetResource*> GetContents()
		{
			std::vector<qPropertySetResource*> _Return;

			for (qBaseNodeRB* i = mResourceDatas.GetHead(); i; i = mResourceDatas.GetNext(i)) {
				_Return.emplace_back(reinterpret_cast<qPropertySetResource*>(i));
			}

			return _Return;
		}
	};
}