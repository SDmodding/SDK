#pragma once

namespace UFG
{
	template <typename T>
	class qAverageWindow
	{
	public:
		struct TimeValuePair
		{
			T m_Value;
			f32 m_Timestep;
		};

		qMemoryPool* m_pMemoryPool;
		TimeValuePair* m_pBuffer;
		int m_BufferSize;
		f32 m_MaxTimespan;
		f32 m_DesiredTimespan;
		int m_StartIndex;
		int m_EndIndex;
		f32 m_RunningSum;
		f32 m_RunningSumTime;
	};
}