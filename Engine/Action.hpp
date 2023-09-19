#pragma once

namespace UFG
{
	// ...
	class CSimObject;
	class CActionController;

	// Track Classes
	class CTrack
	{
	public:
		void* vfptr;
		void* mResourceOwner;
		uint32_t m_TrackClassNameUID;
		char mBreakPoint;
		char mDisable;
		char mMaster;

		UFG_PAD(0x18);
		//ExpressionParameterFloat mMasterRate;

		float mTimeBegin;
		float mTimeEnd;

		const char* GetClassname() { return UFG_VCall<4, const char*>(this); }
		uint32_t GetClassnameUID() { return UFG_VCall<5, uint32_t>(this); }
	};

	class CTrackGroup
	{
	public:
		UFG_PAD(0x10);

		int mCount;

		UFG_PAD(0x4);

		qOffset64<qOffset64<CTrack>> mData;

		uint32_t GetCount()
		{
			return (static_cast<uint32_t>(mCount) & 0x7FFFFFFFu);
		}

		CTrack* GetTrack(uint32_t p_Index)
		{
			qOffset64<CTrack>* m_Offset = mData.GetPointer();
			if (m_Offset)
				return m_Offset[p_Index].GetPointer();

			return nullptr;
		}
	};

	// Action Classes
	class CActionPath
	{
	public:
		int mCount;
		qSymbol* mData;
	};

	class CActionNode
	{
	public:
		void* vfptr;
		void* mResourceOwner;
		qOffset64<CActionNode> mParent;
		void* mFirstCallback;
		unsigned int mMostUsedIndex;
		unsigned int mUniqueID;
		qSymbol mID;
		char mBreakPoint;
		char mDisable;
		char mPad0;
		char mPad1;
		char mPad2;

		void GetResourcePath(char* m_Path, int m_PathSize)
		{
			reinterpret_cast<void(__fastcall*)(void*, char*, int)>(UFG_RVA(0x26EBD0))(this, m_Path, m_PathSize);
		}
	};

	class CActionNodeImplementation : public CActionNode
	{
	public:
		qOffset64<void*> mConditions;
		qOffset64<CTrackGroup> mTracks;

		UFG_PAD(0x10);
		//BinPtrArray<ActionNode, 0, 0> mChildren;

		CTrackGroup* GetTrackGroup()
		{
			return reinterpret_cast<CTrackGroup*(__fastcall*)(void*)>(UFG_RVA(0x26EEE0))(this);
		}
	};


	class CActionNodePlayable : public CActionNodeImplementation
	{
	public:
	};

	class CActionNodeBank : public CActionNodeImplementation
	{
	public:
		qNode<CActionNodeBank> mBankNode;
		unsigned __int16 m_Level;
		char m_NeedsBalancing;
		unsigned __int64 mSignalMask;
	};

	class CActionNodeRoot : public CActionNodeBank
	{
	public:
		qNode<CActionNodeRoot> mRootNode;
		__int64 mToolVersion;
		qList<void*> m_ConditionInitList;
		qList<CActionNodeRoot> m_SubRoots;
		qList<CActionNodeBank> m_BanksToBalance;
		int m_NumNeededActionTreeComponentBaseValueUIDs[11];
		uint8_t mActionTreeType;
	};

	class CActionContext
	{
	public:
		qSafePointer<CSimObject> mSimObject; 
		CActionNode* m_OpeningBranch;
		CActionController* mActionController;
		CActionContext* mParentContext;
		bool mDebugBreak;
		unsigned __int64 mSignals;
	};

	class CActionController
	{
	public:
		UFG_PAD(0x10);

		CActionNodePlayable* m_currentNode;
		CActionContext* m_Context;
		float m_ActionNodePlayTime;
		char mUpdating;
		char mKeepAlive;
		char mOverRideNode;
		char m_BankTracksEnabled;
		char m_OnEnterExitCallbacksEnabled;
		CActionNodePlayable* m_previousNode;
		CActionNodePlayable* m_SequenceNode;

		bool IsPlaying(uint32_t p_ID, uint32_t p_MostUsedInex = -1, bool p_RecurseOnSpawns = false)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, uint32_t*, uint32_t, bool)>(UFG_RVA(0x26F170))(this, &p_ID, p_MostUsedInex, p_RecurseOnSpawns);
		}

		bool WasPlaying(uint32_t p_ID, bool p_RecurseOnSpawns = false)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, uint32_t*, bool)>(UFG_RVA(0x273AB0))(this, &p_ID, p_RecurseOnSpawns);
		}

		void Play(CActionNode* m_Node, bool m_ForcePlay)
		{
			reinterpret_cast<void(__fastcall*)(void*, CActionNode*, bool)>(UFG_RVA(0x270140))(this, m_Node, m_ForcePlay);
		}

		void Play(CActionNodePlayable* m_Node)
		{
			reinterpret_cast<void(__fastcall*)(void*, CActionNodePlayable*)>(UFG_RVA(0x270360))(this, m_Node);
		}

		void Stop()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x272A80))(this);
		}

		void Update(float timeDelta)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x272E40))(this, timeDelta);
		}

		void GetDebugString(qStringBuilder* p_StringBuilder, bool p_ShowAllTracks, CActionController* p_ControllerToHighlight = nullptr, void* p_TrackToHighlight = nullptr)
		{
			reinterpret_cast<void(__fastcall*)(void*, qStringBuilder*, bool, CActionController*, void*)>(UFG_RVA(0x26E5B0))(this, p_StringBuilder, p_ShowAllTracks, p_ControllerToHighlight, p_TrackToHighlight);
		}
	};

	class CActionTreeResource : public qResourceData
	{
	public:
		qOffset64<void*> mRootNode;
		qOffset64<void*> mTypeTable;

		CActionNodeRoot* GetRoot()
		{
			if (!mRootNode.mOffset)
				return nullptr;

			return reinterpret_cast<CActionNodeRoot*>(reinterpret_cast<uintptr_t>(this) + mRootNode.mOffset + sizeof(qResourceData));
		}
	};


	namespace ActionNode
	{
		CActionNodePlayable* FindNode(const char* resourcePath)
		{
			return reinterpret_cast<CActionNodePlayable*(__fastcall*)(void*, const char*)>(UFG_RVA(0x26DE60))(nullptr, resourcePath);
		}
	}

	class CActionNodePlayableDatabase
	{
	public:
		qTreeRB mPlayables;
	};

	namespace ActionNodePlayableDatabase
	{
		CActionNodePlayableDatabase* Get()
		{
			return *reinterpret_cast<CActionNodePlayableDatabase**>(UFG_RVA(0x23B1310));
		}

		CActionNodePlayable* Find(uint32_t m_ID)
		{
			qBaseTreeRB* m_ActionNodePlayableDatabase = &Get()->mPlayables.mTree;
			for (qBaseNodeRB* i = m_ActionNodePlayableDatabase->GetHead(); i; i = m_ActionNodePlayableDatabase->GetNext(i))
			{
				if (i->mUID == -1)
					continue;

				UFG::CActionNodePlayable* m_ActioNodePlayable = i->ReadPointerOffset<UFG::CActionNodePlayable, 0x20>();
				if (m_ActioNodePlayable->mUniqueID == m_ID)
					return m_ActioNodePlayable;
			}

			return nullptr;
		}

		std::vector<CActionNodePlayable*> GetContents()
		{
			std::vector<CActionNodePlayable*> m_ActionPlayables;

			qBaseTreeRB* m_ActionNodePlayableDatabase = &Get()->mPlayables.mTree;
			for (qBaseNodeRB* i = m_ActionNodePlayableDatabase->GetHead(); i; i = m_ActionNodePlayableDatabase->GetNext(i))
			{
				if (i->mUID == -1)
					continue;

				m_ActionPlayables.emplace_back(i->ReadPointerOffset<UFG::CActionNodePlayable, 0x20>());
			}
			
			return m_ActionPlayables;
		};
	}
}