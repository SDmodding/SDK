#pragma once

namespace UFG
{
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
}