#pragma once

namespace UFG
{
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

	class qNodeRB
	{
	public:
		qBaseNodeRB mNode;
	};

	class qBaseTreeRB
	{
	public:
		qBaseNodeRB mRoot;
		qBaseNodeRB mNULL;
		int mCount;

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

	class qTreeRB
	{
	public:
		qBaseTreeRB mTree;
	};

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
	};

	class qVector2
	{
	public:
		float x, y;

		qVector2()
		{
			x = y = 0.f;
		}

		qVector2(float f0, float f1)
		{
			x = f0; y = f1;
		}

		// Funcs
		float Length()
		{
			return sqrtf(x * x + y * y);
		}

		float DistTo(qVector2* m_Other)
		{
			qVector2 m_Delta(x - m_Other->x, y - m_Other->y);
			return m_Delta.Length();
		}
	};

	class qVector3
	{
	public:
		float x, y, z;

		qVector3()
		{
			x = y = z = 0.f;
		}

		qVector3(float f0, float f1, float f2)
		{
			x = f0; y = f1; z = f2;
		}

		// Operators
		float& operator[](int m_Index) { return (&x)[m_Index]; }

		__forceinline bool operator==(qVector3& m_Other) { return (x == m_Other.x && y == m_Other.y && z == m_Other.z); }
		__forceinline bool operator!=(qVector3& m_Other) { return (x != m_Other.x || y != m_Other.y || z != m_Other.z); }

		__forceinline qVector3 operator+(qVector3 m_Other) { return { x + m_Other.x, y + m_Other.y, z + m_Other.z }; }
		__forceinline void operator+=(qVector3 m_Other) { x += m_Other.x; y += m_Other.y; z += m_Other.z; }

		__forceinline qVector3 operator-(qVector3 m_Other) { return { x - m_Other.x, y - m_Other.y, z - m_Other.z }; }
		__forceinline void operator-=(qVector3 m_Other) { x -= m_Other.x; y -= m_Other.y; z -= m_Other.z; }

		__forceinline qVector3 operator*(qVector3 m_Other) { return { x * m_Other.x, y * m_Other.y, z * m_Other.z }; }
		__forceinline void operator*=(qVector3 m_Other) { x *= m_Other.x; y *= m_Other.y; z *= m_Other.z; }

		__forceinline qVector3 operator*(float m_Value) { return { x * m_Value, y * m_Value, z * m_Value }; }
		__forceinline void operator*=(float m_Value) { x *= m_Value; y *= m_Value; z *= m_Value; }

		__forceinline qVector3 operator/(qVector3 m_Other) { return { x / m_Other.x, y / m_Other.y, z / m_Other.z }; }
		__forceinline void operator/=(qVector3 m_Other) { x /= m_Other.x; y /= m_Other.y; z /= m_Other.z; }

		__forceinline qVector3 operator/(float m_Value) { return { x / m_Value, y / m_Value, z / m_Value }; }
		__forceinline void operator/=(float m_Value) { x /= m_Value; y /= m_Value; z /= m_Value; }

		__forceinline qVector3 operator-() { return { -x, -y, -z }; }

		// Funcs
		float Length()
		{
			return sqrtf(x * x + y * y + z * z);
		}

		float DotProduct(qVector3& m_Other) { return x * m_Other.x + y * m_Other.y + z * m_Other.z; }
		qVector3 Cross(qVector3 m_Other) { return { y * m_Other.z - z * m_Other.y, z * m_Other.x - x * m_Other.z, x * m_Other.y - y * m_Other.x }; }

		void Normalize()
		{
			float m_Length = Length();
			operator/=(m_Length);
		}

		float DistTo(qVector3* m_Other)
		{
			qVector3 m_Delta(x - m_Other->x, y - m_Other->y, z - m_Other->z);
			return m_Delta.Length();
		}

		__inline float DistTo2D(qVector2* m_Other)
		{
			return reinterpret_cast<qVector2*>(this)->DistTo(m_Other);
		}

		__inline float DistTo2D(qVector3* m_Other)
		{
			return DistTo2D(reinterpret_cast<qVector2*>(m_Other));
		}

		void ConvertToRad()
		{
			x *= UFG_Deg2Rad_Mul;
			y *= UFG_Deg2Rad_Mul;
			z *= UFG_Deg2Rad_Mul;
		}

		void AngleVectors(qVector3* forward, qVector3* right, qVector3* up)
		{
			float sp = sinf(x);
			float cp = cosf(x);

			float sy = sinf(y);
			float cy = cosf(y);

			float sr = sinf(z);
			float cr = cosf(z);

			if (forward)
			{
				forward->x = cp * cy;
				forward->y = cp * sy;
				forward->z = -sp;
			}

			if (right)
			{
				right->x = (-1 * sr * sp * cy + -1 * cr * -sy);
				right->y = (-1 * sr * sp * sy + -1 * cr * cy);
				right->z = -1 * sr * cp;
			}

			if (up)
			{
				up->x = (cr * sp * cy + -sr * -sy);
				up->y = (cr * sp * sy + -sr * cy);
				up->z = cr * cp;
			}
		}
		
		void Angles2Vector()
		{
			float m_PitchSin = sinf(x); 
			float m_PitchCos = cosf(x);

			float m_YawSin = sinf(y); 
			float m_YawCos = cosf(y);

			x = m_YawCos * m_PitchCos;
			y = m_YawSin * m_PitchCos;
			z = m_PitchSin;
		}

		void DegAngles2Vector()
		{
			ConvertToRad();

			Angles2Vector();
		}

		void Vector2Angles()
		{
			float m_Pitch = asinf(y);
			float m_Yaw = atan2f(z, x);

			x = m_Pitch;
			y = m_Yaw;
			z = 0.f;
		}
	};

	class qVector4
	{
	public:
		float x, y, z, w;

		qVector4()
		{
			x = y = z = w = 0.f;
		}

		qVector4(float f0, float f1, float f2, float f3)
		{
			x = f0; y = f1; z = f2; w = f3;
		}

		// Operators
		__forceinline bool operator==(qVector4& m_Other) { return (x == m_Other.x && y == m_Other.y && z == m_Other.z && w == m_Other.w); }
		__forceinline bool operator!=(qVector4& m_Other) { return (x != m_Other.x || y != m_Other.y || z != m_Other.z || w != m_Other.w); }

		__forceinline qVector4 operator+(qVector4 m_Other) { return { x + m_Other.x, y + m_Other.y, z + m_Other.z, w + m_Other.w }; }
		__forceinline void operator+=(qVector4 m_Other) { x += m_Other.x; y += m_Other.y; z += m_Other.z; w += m_Other.w; }

		__forceinline qVector4 operator-(qVector4 m_Other) { return { x - m_Other.x, y - m_Other.y, z - m_Other.z, w - m_Other.w }; }
		__forceinline void operator-=(qVector4 m_Other) { x -= m_Other.x; y -= m_Other.y; z -= m_Other.z; w -= m_Other.w; }

		__forceinline qVector4 operator*(float m_Value) { return { x * m_Value, y * m_Value, z * m_Value, w * m_Value }; }
		__forceinline void operator*=(float m_Value) { x *= m_Value; y *= m_Value; z *= m_Value; w *= m_Value; }

		__forceinline qVector4 operator/(float m_Value) { return { x / m_Value, y / m_Value, z / m_Value, w / m_Value }; }
		__forceinline void operator/=(float m_Value) { x /= m_Value; y /= m_Value; z /= m_Value; ; w /= m_Value; }

		__forceinline qVector4 operator-() { return { -x, -y, -z, -w }; }

		// Funcs
		operator qVector3() { return qVector3(x, y, z); }
		qVector3 ToVector3() { return qVector3(x, y, z); }

		float DotProduct(qVector4& m_Other) { return x * m_Other.x + y * m_Other.y + z * m_Other.z; }
	};

	class qMatrix44
	{
	public:
		qVector4 v0; // Forward
		qVector4 v1; // Right
		qVector4 v2; // Up
		qVector4 v3; // Position

		__forceinline qVector3 GetForward()	{ return v0; }
		__forceinline qVector3 GetRight()	{ return v1; }
		__forceinline qVector3 GetUp()		{ return v2; }

		void SetRotation(qVector3 m_Rotation)
		{
			m_Rotation *= UFG_Deg2Rad_Mul;

			float m_Pitch[2] = { cosf(m_Rotation.x), sinf(m_Rotation.x) };
			float m_Yaw[2] = { cosf(m_Rotation.y), sinf(m_Rotation.y) };
			float m_Roll[2] = { cosf(m_Rotation.z), sinf(m_Rotation.z) };

			v0 = { m_Yaw[0] * m_Pitch[0], m_Yaw[1] * m_Pitch[0], m_Pitch[1], 0.f };
			v1 = { m_Yaw[0] * m_Pitch[1] * m_Roll[1] - m_Yaw[1] * m_Roll[0], m_Yaw[1] * m_Pitch[1] * m_Roll[1] + m_Yaw[0] * m_Roll[0], -m_Pitch[0] * m_Roll[1], 0.f };
			v2 = { m_Yaw[0] * m_Pitch[1] * m_Roll[0] + m_Yaw[1] * m_Roll[1], m_Yaw[1] * m_Pitch[1] * m_Roll[0] - m_Yaw[0] * m_Roll[1], m_Pitch[0] * m_Roll[0], 0.f };
		}

		void RotationEuler(qVector3* p_Angles)
		{
			reinterpret_cast<void(__fastcall*)(qMatrix44*, qVector3*)>(UFG_RVA(0x18A6A0))(this, p_Angles);
		}

		qVector3 GetRotation()
		{
			UFG::qVector3 m_MatrixRot(acosf(v0.DotProduct(v2)), atan2f(v0.y, v0.x), atan2f(v1.z, v1.y));
			m_MatrixRot *= UFG_Rad2Deg_Mul;

			return m_MatrixRot;
		}

		// Use only if you know what you're doing!
		void SetCharacterYaw(float p_Degrees)
		{
			float m_Radians = UFG_Deg2Rad(p_Degrees);
			v0.x = cosf(m_Radians);
			v0.y = sinf(m_Radians);

			v1.x = -v0.y;
			v1.y = v0.x;
		}

		// This rotate funcs are wrong...
		void RotateRight(qVector3 vRot, float m_Theta, float m_Sin = 0.f, float m_Cos = 0.f, bool m_SinCosIncluded = false)
		{
			if (!m_SinCosIncluded)
			{
				m_Sin = sinf(m_Theta);
				m_Cos = cosf(m_Theta);
			}

			v0.x = m_Cos + (1.f - m_Cos) * vRot.x * vRot.x;
			v0.y = (1.f - m_Cos) * vRot.x * vRot.y - m_Sin * vRot.z;
			v0.z = (1.f - m_Cos) * vRot.x * vRot.z + m_Sin * vRot.y;
		}

		void RotateForward(qVector3 m_Rot, float m_Theta, float m_Sin = 0.f, float m_Cos = 0.f, bool m_SinCosIncluded = false)
		{
			if (!m_SinCosIncluded)
			{
				m_Sin = sinf(m_Theta);
				m_Cos = cosf(m_Theta);
			}

			v2.x = (1.f - m_Cos) * m_Rot.y * m_Rot.x + m_Sin * m_Rot.z;
			v2.y = m_Cos + (1.f - m_Cos) * m_Rot.y * m_Rot.y;
			v2.z = (1.f - m_Cos) * m_Rot.y * m_Rot.z - m_Sin * m_Rot.x;
		}

		void RotateUp(qVector3 m_Rot, float m_Theta, float m_Sin = 0.f, float m_Cos = 0.f, bool m_SinCosIncluded = false)
		{
			if (!m_SinCosIncluded)
			{
				m_Sin = sinf(m_Theta);
				m_Cos = cosf(m_Theta);
			}

			v1.x = (1.f - m_Cos) * m_Rot.z * m_Rot.x - m_Sin * m_Rot.y;
			v1.y = (1.f - m_Cos) * m_Rot.z * m_Rot.y + m_Sin * m_Rot.x;
			v1.z = m_Cos + (1.f - m_Cos) * m_Rot.z * m_Rot.z;
		}

		void Rotate(qVector3 m_Rot, float m_Theta)
		{
			const float m_Sin = sinf(m_Theta);
			const float m_Cos = cosf(m_Theta);

			RotateRight(m_Rot, 0.f, m_Sin, m_Cos, true);
			RotateForward(m_Rot, 0.f, m_Sin, m_Cos, true);
			RotateUp(m_Rot, 0.f, m_Sin, m_Cos, true);
		}

		qVector3 ToVector3()
		{
			float sy = sqrtf(v0.x * v0.x + v1.x * v1.y);

			bool singular = sy < 1e-6f;

			qVector3 m_Ret;
			if (!singular)
			{
				m_Ret.x = atan2f(v2.y, v2.z);
				m_Ret.y = atan2f(-v2.x, sy);
				m_Ret.z = atan2f(v1.x, v0.x);
			}
			else
			{
				m_Ret.x = atan2f(-v1.z, v1.y);
				m_Ret.y = atan2f(-v2.x, sy);
				m_Ret.z = 0.f;
			}
			
			return m_Ret;
		}

		// Crashes on 'hkQsTransformf::get4x4ColumnMajor' for some odd reason.
		void BlendSlerp(qMatrix44* p_SourceA, qMatrix44* p_SourceB, float p_Weight)
		{
			reinterpret_cast<void(__fastcall*)(qMatrix44*, qMatrix44*, qMatrix44*, float)>(UFG_RVA(0x3A4A20))(this, p_SourceA, p_SourceB, p_Weight);
		}
	};

	class qQuaternion
	{
	public:
		float x, y, z, w;

		qQuaternion()
		{
			x = y = z = w = 0.f;
		}

		qQuaternion(float f0, float f1, float f2, float f3)
		{
			x = f0; y = f1; z = f2; w = f3;
		}

		void Set(qMatrix44* m)
		{
			reinterpret_cast<void(__fastcall*)(qQuaternion*, qMatrix44*)>(UFG_RVA(0x17C460))(this, m);
		}

		void GetMatrix(qMatrix44* m)
		{
			float v6 = z * y;
			float v7 = z * w;
			float v8 = x * x;
			float v21 = x * z;
			float v9 = y * y;
			float v10 = y * w;
			float v11 = z * z;
			float v12 = x * w;
			float v13 = x * y;
			float v16 = (v11 + v8) * 2.f;
			float v18 = 1.f - v16;

			m->v0.x = 1.f - ((v11 + v9) * 2.f);
			m->v0.y = (v7 + v13) * 2.f;
			m->v0.z = (v21 - v10) * 2.f;
			m->v0.w = 0.f;

			m->v1.x = (v13 - v7) * 2.f;
			m->v1.y = v18;
			m->v1.z = (v12 + v6) * 2.f;
			m->v1.w = 0.f;

			m->v2.x = (v21 + v10) * 2.f;
			m->v2.y = (v6 - v12) * 2.f;
			m->v2.w = 0.f;
		}
	};

	class qBox
	{
	public:
		qVector3 mMin;
		qVector3 mMax;
	};

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