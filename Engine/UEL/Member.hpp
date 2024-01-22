#pragma once

namespace UEL
{
	class CMemberMap
	{
	public:
		void* vfptr;
		void* mResourceOwner;

		// Can return nullptr...
		UFG_INLINE const char* GetClassname() 
		{ 
			return UFG_VCall<4, const char*>(this); 
		}

		UFG_INLINE uint32_t GetClassnameUID()
		{ 
			return UFG_VCall<5, uint32_t>(this); 
		}

		UFG_INLINE void GetResourcePath(char* p_Path, int p_PathSize)
		{ 
			UFG_VCall<6, void>(this, p_Path, p_PathSize); 
		}
	};
}