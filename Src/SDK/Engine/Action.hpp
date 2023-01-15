#pragma once

namespace UFG
{
	class CSimObject;

	class CActionPath
	{
	public:
	};

	class CActionNode
	{
	public:
		UFG_PAD(0x10);

		CActionNode* mParent;

		UFG_PAD(0x8);

		unsigned int mMostUsedIndex;
		unsigned int mUniqueID;
		qSymbol mID;

		UFG_PAD(0xC);
	};

	class CActionNodePlayable : public CActionNode
	{
	public:
	};

	class CActionContext
	{
	public:
		UFG_PAD(0x10);

		CSimObject* mSimObject;
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

		void Play(CActionNodePlayable* node)
		{
			reinterpret_cast<void(__fastcall*)(void*, CActionNodePlayable*)>(UFG_RVA(0x270360))(this, node);
		}

		void Stop()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x272A80))(this);
		}

		void Update(float timeDelta)
		{
			reinterpret_cast<void(__fastcall*)(void*, float)>(UFG_RVA(0x272E40))(this, timeDelta);
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

		std::vector<CActionNodePlayable*> GetContents()
		{
			std::vector<CActionNodePlayable*> m_Return;

			CActionNodePlayableDatabase* ActionNodePlayableDatabase = Get();
			{
				auto v2 = ActionNodePlayableDatabase->mPlayables.mTree.mRoot.mChild[0];
				auto v3 = v2->mChild[0];
				signed __int64 i;
				for (i = (signed __int64)&ActionNodePlayableDatabase->mPlayables.mTree.mNULL;
					v3 != (UFG::qBaseNodeRB*)i;
					v3 = v3->mChild[0])
				{
					v2 = v3;
				}
				CActionNodePlayableDatabase* v5 = 0i64;
				if (v2 != (UFG::qBaseNodeRB*)i)
					v5 = (CActionNodePlayableDatabase*)v2;

				while (v5)
				{
					auto v6 = v5->mPlayables.mTree.mRoot.mUID;
					auto v7 = (CActionNodePlayable*)v5->mPlayables.mTree.mNULL.mParent;
					if (v7)
					{
						m_Return.emplace_back(v7);
					}

					auto v11 = (CActionNodePlayableDatabase*)v5->mPlayables.mTree.mRoot.mChild[1];
					if ((CActionNodePlayableDatabase*)i == v11)
					{
						auto v13 = (CActionNodePlayableDatabase*)((uintptr_t)v5->mPlayables.mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
						if (v5 == (CActionNodePlayableDatabase*)v13->mPlayables.mTree.mRoot.mChild[1])
						{
							auto v14 = v13;
							do
							{
								v14 = v13;
								v13 = (CActionNodePlayableDatabase*)((uintptr_t)v13->mPlayables.mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
							} while (v14 == (CActionNodePlayableDatabase*)v13->mPlayables.mTree.mRoot.mChild[1]);
						}
						v5 = v13;
						if (v13 == ActionNodePlayableDatabase)
							v5 = 0i64;
					}
					else
					{
						for (auto j = (CActionNodePlayableDatabase*)v11->mPlayables.mTree.mRoot.mChild[0];
							j != (CActionNodePlayableDatabase*)i;
							j = (CActionNodePlayableDatabase*)j->mPlayables.mTree.mRoot.mChild[0])
						{
							v11 = j;
						}
						v5 = v11;
					}
				}
			}

			return m_Return;
		};
	}
}