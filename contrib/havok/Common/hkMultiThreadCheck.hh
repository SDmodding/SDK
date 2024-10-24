#pragma once

class hkMultiThreadCheck
{
public:
	u32 m_threadId;
	int m_stackTraceId;
	u16 m_markCount;
	u16 m_markBitStack;
};