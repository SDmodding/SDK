#pragma once

namespace UFG
{
	class qHalfFloat
	{
	public:
		uint16_t mRep;

		qHalfFloat()
		{
			mRep = 0;
		}

		__inline qHalfFloat(float p_Float)
		{
			uint32_t m_FloatBytes = *reinterpret_cast<uint32_t*>(&p_Float);
			uint32_t m_Mantissa = m_FloatBytes & 0x7FFFFFFF;
			uint32_t m_Exponent = HIWORD(m_FloatBytes) & 0x8000;
			if (m_Mantissa <= 0x47FFEFFF)
			{
				uint32_t m_Unknown;
				if (m_Mantissa >= 0x38800000)
					m_Unknown = m_Mantissa - 0x38000000;
				else
					m_Unknown = (m_FloatBytes & 0x7FFFFF | 0x800000u) >> (0x71 - (m_Mantissa >> 23));
				mRep = ((((m_Unknown >> 13) & 1) + m_Unknown + 0xFFF) >> 13) | m_Exponent;
			}
			else
				mRep = m_Exponent | 0x7FFF;
		}

		__inline operator float()
		{
			uint32_t m_FloatValue = ((((mRep >> 10) & 0x1F) + 0x70) << 23) & 0x7F800000 | ((mRep & 0x3FF | (8 * (mRep & 0xFFFF8000))) << 13);
			return *reinterpret_cast<float*>(&m_FloatValue);
		}
	};
}