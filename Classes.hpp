#pragma once

namespace UFG
{
	class ClipRect
	{
	public:
		float x0;
		float u0 = 0.f;
		float x1;
		float u1 = 1.f;
		float y0;
		float v0 = 0.f;
		float y1;
		float v1 = 1.f;
		void* tile = nullptr;

		ClipRect()
		{
			x0 = 0.f; x1 = 0.f; y0 = 0.f; y1 = 0.f;
		}

		ClipRect(float p_MinX, float p_MaxX, float p_MinY, float p_MaxY)
		{
			x0 = p_MinX; x1 = p_MaxX;
			y0 = p_MinY; y1 = p_MaxY;
		}
	};

	class qMutex
	{
	public:
		uint32_t mMutexMemory[12];

		void Lock()
		{
			EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(this));
		}

		void Unlock()
		{
			LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(this));
		}
	};

	class qBaseNodeRB
	{
	public:
		qBaseNodeRB* mParent;
		qBaseNodeRB* mChild[2];
		uint32_t mUID;

		template <typename T>
		T* GetPointer() { return reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(this)); }

		template <typename T, uintptr_t N>
		T* GetPointer() { return reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(this) - N); }

		template <typename T, uintptr_t N>
		T* ReadPointerOffset() { return *reinterpret_cast<T**>(reinterpret_cast<uintptr_t>(this) + N); }
	};
	typedef qBaseNodeRB qNodeRB;

	class qBaseTreeRB
	{
	public:
		qBaseNodeRB mRoot;
		qBaseNodeRB mNULL;
		int mCount;

		void Remove(void* p_Node)
		{
			reinterpret_cast<void(__fastcall*)(void*, void*)>(UFG_RVA(0x17A0F0))(this, p_Node);
		}

		qBaseTreeRB* Get(unsigned int uid)
		{
			qBaseTreeRB* result = this;
			for (bool i = (this == (qBaseTreeRB*)&mNULL); ; i = (result == (qBaseTreeRB*)&mNULL))
			{
				if (i)
					return nullptr;

				if (result != this && result->mRoot.mUID == uid)
					break;

				if (uid > result->mRoot.mUID)
					result = (qBaseTreeRB*)result->mRoot.mChild[1];
				else
					result = (qBaseTreeRB*)result->mRoot.mChild[0];
			}

			for (qBaseNodeRB* j = result->mRoot.mChild[0]; j; j = j->mChild[0])
			{
				if (j->mUID != uid)
					break;

				result = (qBaseTreeRB*)j;
			}

			return result;
		}

		qBaseNodeRB* GetHead()
		{
			qBaseNodeRB* m_Head = mRoot.mChild[0];
			for (qBaseNodeRB* i = m_Head->mChild[0]; i != &mNULL; i = i->mChild[0])
				m_Head = i;

			if (m_Head == &mNULL)
				return nullptr;

			return m_Head;
		}

		qBaseNodeRB* GetTail()
		{
			qBaseNodeRB* m_Tail = mRoot.mChild[0];
			for (qBaseNodeRB* i = m_Tail->mChild[1]; i != &mNULL; i = i->mChild[1])
				m_Tail = i;

			if (m_Tail == &mNULL)
				return nullptr;

			return m_Tail;
		}

		qBaseNodeRB* GetNext(qBaseNodeRB* m_Node)
		{
			qBaseNodeRB* m_NextNode = m_Node->mChild[1];
			if (m_NextNode == &mNULL) // If there is no right child, go up the tree until a parent is found whose left child this node is.
			{
				// Find the first parent whose left child is the node's ancestor.
				qBaseNodeRB* m_Parent = reinterpret_cast<qBaseNodeRB*>(reinterpret_cast<uintptr_t>(m_Node->mParent) & 0xFFFFFFFFFFFFFFFEui64);
				if (m_Node == m_Parent->mChild[1])
				{
					// Go up the tree until a parent is found whose left child is this node's ancestor.
					qBaseNodeRB* m_Children = m_Parent->mChild[1];
					while (m_Children == m_Parent->mChild[1])
					{
						m_Children = m_Parent;
						m_Parent = reinterpret_cast<qBaseNodeRB*>(reinterpret_cast<uintptr_t>(m_Parent->mParent) & 0xFFFFFFFFFFFFFFFEui64);
					}
				}

				// If we reach the root node and its left child is not the input node, return nullptr.
				if (m_Parent == &mNULL)
					return nullptr;

				// Set the current node to the parent node.
				m_Node = m_Parent;
			}
			else // If there is a right child, find the leftmost child of the right child.
			{
				for (qBaseNodeRB* i = m_NextNode->mChild[0]; i != &mNULL; i = i->mChild[0])
					m_NextNode = i;

				m_Node = m_NextNode;
			}

			return m_Node;
		}

		template <typename T>
		std::vector<T*> GetNodes()
		{
			std::vector<T*> m_Nodes;

			for (qBaseNodeRB* i = GetHead(); i; i = GetNext(i))
				m_Nodes.emplace_back(reinterpret_cast<T*>(i));

			return m_Nodes;
		}

		void GetContent(std::vector<unsigned int>& m_List)
		{
			for (qBaseNodeRB* i = GetHead(); i; i = GetNext(i))
				m_List.emplace_back(i->mUID);
		}
	};
	typedef qBaseTreeRB qTreeRB;

	class qTree64Base
	{
	public:
		uint64_t mUID;
		qTree64Base* mParent;
		qTree64Base* mChildren[2];
		qTree64Base* mNeighbours[2];
	};
	typedef qTree64Base qTreeNode64;

	struct qString
	{
		qString* mPrev;
		qString* mNext;
		uint32_t mMagic;
		int mLength;
		char* mData;
		uint32_t mStringHash32;
		uint32_t mStringHashUpper32;

		~qString()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x1643D0))(this);
		}

		qString()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x1620A0))(this);
		}

		void Set(const char* p_Text)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*)>(UFG_RVA(0x17C9B0))(this, p_Text);
		}
	};

	struct qStringBuilder
	{
		char* mBuffer;
		int mBufferSize;
		int mStringLength;

		~qStringBuilder()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x164430))(this);
		}

		qStringBuilder()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x1620F0))(this);
		}
	};

	class qColour
	{
	public:
		float r, g, b, a; 
		
		qColour()
		{
			r, g, b, a = 0.f;
		}

		qColour(float f0, float f1, float f2, float f3)
		{
			r = f0; g = f1; b = f2; a = f3;
		}

		// Hue (0.f to 360.f), Saturation (0.f to 1.f), Vibrance (0.f to 1.f), Alpha (0.f to 1.f)
		__inline void HSVToRGB(const qColour& p_HSV)
		{
			reinterpret_cast<void(__fastcall*)(void*, const qColour&)>(UFG_RVA(0x1824E0))(this, p_HSV);
		}

		__inline void RGBToHSV(const qColour& p_RGB)
		{
			reinterpret_cast<void(__fastcall*)(void*, const qColour&)>(UFG_RVA(0x182630))(this, p_RGB);
		}
	};

	class qBox
	{
	public:
		qVector3 mMin;
		qVector3 mMax;
	};

	struct UIPoint2f
	{
		float x, y;

		UIPoint2f()
		{
			x = y = 0.f;
		}

		UIPoint2f(float f0, float f1)
		{
			x = f0; y = f1;
		}
	};
	typedef UIPoint2f ScreenPoint2f, WorldPoint2f, WideMinimapPoint2f, MinimapPoint2f, MinimapTilePoint2f;

	// ...

	struct BitFlags128 
	{
		uint64_t mFlags[2];
	};

	class __declspec(align(16)) CHavokNavPosition
	{
	public:
		void* vfptr;
		qVector3 m_vPosition;

		UFG_PAD(0x4);

		bool m_bValid = false;
		qVector4 m_hkvMeshPosition;
		uint32_t m_packedKey = -1;
		uint32_t m_aiMeshUid = -1;

		CHavokNavPosition() { }
		CHavokNavPosition(qVector3 m_Position) 
		{ 
			m_vPosition = m_Position;
			m_hkvMeshPosition = { m_Position.x, m_Position.y, m_Position.z, 1.f };
		}
	};
}