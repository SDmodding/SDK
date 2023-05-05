#pragma once

namespace SimpleXML
{
	class CXMLFileResource : public UFG::qResourceData
	{
	public:
		unsigned int mUncompressedSize;
		unsigned int mCompressedSize;
		unsigned int mPad1;
		unsigned int mPad2;

		void* GetCompressHeader()
		{
			return reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(this) + sizeof(CXMLFileResource));
		}
	};

	namespace XMLCache
	{
		char* ExtractFromCache(const char* filename)
		{
			return reinterpret_cast<char*(__fastcall*)(const char*)>(UFG_RVA(0x8A580))(filename);
		}
	}
}