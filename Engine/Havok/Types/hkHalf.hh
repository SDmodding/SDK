#pragma once

class hkHalf
{
public:
	uint16_t m_Value;

	UFG_INLINE bool IsZero() 
	{ 
		return (this->m_Value & 0x7FFF) == 0; 
	}

	UFG_INLINE void SetZero()
	{
		this->m_Value = 0x0;
	}

	UFG_INLINE void SetOne()
	{
		this->m_Value = 0x3F80;
	}

	UFG_INLINE void SetMax()
	{
		this->m_Value = 0x7F7F;
	}

	UFG_INLINE void SetNegativeOne()
	{
		this->m_Value = 0xBF80;
	}

	UFG_INLINE void Set(float p_Float)
	{
		union 
		{ 
			float f; int i; 
		} u;

		u.f = (p_Float * (1.f + 1.f / 256.f));
		this->m_Value = static_cast<uint16_t>(u.i >> 16);
	}

	UFG_INLINE float Get()
	{
		union
		{
			int i;
			float f;
		} u;
		u.i = static_cast<int>(this->m_Value << 16);
		return u.f;
	}
};