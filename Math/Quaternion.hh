#pragma once

namespace UFG
{
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