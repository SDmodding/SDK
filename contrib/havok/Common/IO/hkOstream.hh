#pragma once

class hkOstream : public hkReferencedObject
{
public:
	hkRefPtr<hkStreamWriter> m_writer;

	SDK_INLINE void ctor(const char* filename) { SDK_CALL_FUNC(void, 0xC66040, void*, const char*)(this, filename); }

	/* Functions */

	SDK_INLINE hkStreamWriter* getStreamWriter() { return m_writer.m_pntr; }
};