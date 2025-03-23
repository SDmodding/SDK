#pragma once

namespace Scaleform
{
	class WStringBuffer
	{
	public:
		struct ReserveHeader
		{
			wchar_t* pBuffer;
			u64 Size;
		};

		wchar_t* pText;
		u64 Length;
		ReserveHeader Reserved;
	};
}