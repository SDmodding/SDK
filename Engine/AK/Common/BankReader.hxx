#pragma once

class CAkBankReader
{
public:
	char* m_pBuffer;
	char* m_pReadBufferPtr;
	uint32_t m_ulRemainingBytes;
	uint32_t m_ulBufferSize;
	uint32_t m_ulDeviceBlockSize;
	void* m_pUserReadBuffer;
	const char* m_pInMemoryBankReaderPtr;
	void* m_pStream;
	float m_fThroughput;
	char m_priority;
	bool m_bIsInitDone;
};
UFG_ASSERT_CLASS(CAkBankReader, 64);