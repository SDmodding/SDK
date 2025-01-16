#pragma once

namespace Scaleform
{
	class String
	{
	public:
		struct DataDesc
		{
			u64 Size;
			volatile int RefCount;
			char Data[1];
		};

		union
		{
			DataDesc* pData;
			u64 HeapTypeBits;
		};

		SF_INLINE operator const char* () const { return (pData ? pData->Data : nullptr); }
	};

	class StringLH : public String
	{
	public:
	};

}