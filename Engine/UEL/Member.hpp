#pragma once

namespace UEL
{
	class CMemberMap
	{
	public:
		void* vfptr;
		void* mResourceOwner;

		const char* GetClassname() { return UFG_VCall<4, const char*>(this); } // Can return nullptr...
		uint32_t GetClassnameUID() { return UFG_VCall<5, uint32_t>(this); }
		void GetResourcePath(char* p_Path, int p_PathSize) { UFG_VCall<6, void>(this, p_Path, p_PathSize); }
	};
}