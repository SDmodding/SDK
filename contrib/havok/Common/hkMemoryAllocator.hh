#pragma once

class hkMemoryAllocator
{
public:
	struct ExtendedInterface
	{
		virtual ~ExtendedInterface() = 0;
	};

	struct MemoryStatistics
	{
		s64 m_allocated;
		s64 m_inUse;
		s64 m_peakInUse;
		s64 m_available;
		s64 m_totalAvailable;
		s64 m_largestBlock;
	};

	virtual ~hkMemoryAllocator() = 0;
	virtual void* blockAlloc(int numBytes) = 0;
	virtual void blockFree(void* p, int numBytes) = 0;
	virtual void* bufAlloc(int& reqNumBytesInOut) = 0;
	virtual void bufFree(void* p, int numBytes) = 0;
	virtual void* bufRealloc(void* pold, int oldNumBytes, int& reqNumBytesInOut) = 0;
	virtual void blockAllocBatch(void** ptrsOut, int numPtrs, int blockSize) = 0;
	virtual void blockFreeBatch(void** ptrsIn, int numPtrs, int blockSize) = 0;
	virtual void getMemoryStatistics(MemoryStatistics& u) = 0;
	virtual int getAllocatedSize(const void* obj, int nbytes) = 0;
	virtual void resetPeakMemoryStatistics() = 0;
	virtual ExtendedInterface* getExtendedInterface() = 0;
};