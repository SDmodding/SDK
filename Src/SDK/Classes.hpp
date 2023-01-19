#pragma once

// hello from mp-client

namespace UFG
{
	class qBaseNodeRB
	{
	public:
		qBaseNodeRB* mParent;
		qBaseNodeRB* mChild[2];
		unsigned int mUID;
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
	};

	class qTreeRB
	{
	public:
		qBaseTreeRB mTree;
	};

	class qString
	{
	public:
		void* m_Pad0x0[0x2];

		unsigned int mMagic;
		int mLength;
		char* mData;
		unsigned int mStringHash32;
		unsigned int mStringHashUpper32;
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
		__forceinline bool operator==(qVector3& m_Other) { return (x == m_Other.x && y == m_Other.y && z == m_Other.z); }
		__forceinline bool operator!=(qVector3& m_Other) { return (x != m_Other.x || y != m_Other.y || z != m_Other.z); }

		// Funcs
		float Length()
		{
			return sqrtf(x * x + y * y + z * z);
		}

		float DistTo(qVector3* m_Other)
		{
			qVector3 m_Delta(x - m_Other->x, y - m_Other->y, z - m_Other->z);
			return m_Delta.Length();
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

		qVector3 ToVector3() { return qVector3(x, y, z); }
	};

	class qMatrix44
	{
	public:
		qVector4 v0;
		qVector4 v1;
		qVector4 v2;
		qVector4 v3;

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
}