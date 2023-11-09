#pragma once

namespace Scaleform
{
	namespace GFx
	{
		class ASStringNode
		{
		public:
			const char* pData;
			class ASStringManager* pManager;
			ASStringNode* pNextAlloc;
			uint32_t RefCount;
			uint32_t HashFlags;
			uint32_t Size;
		};

		class ASStringNodeHolder
		{
		public:
			ASStringNode* pNode;
		};
		typedef ASStringNodeHolder ASConstString;
		typedef ASConstString ASString;

		class ASStringManager : public RefCountBase<ASStringManager, 324>
		{
		public:
			struct StringNodePage
			{
				ASStringNode Nodes[127];
				StringNodePage* pNext;
			};

			struct TextPage
			{
				union Entry
				{
					Entry* pNextAlloc;
					char Buff[16];
				};

				Entry Entries[126];
				TextPage* pNext;
				void* pMem;
			};


			HashSetBase* StringSet;
			MemoryHeap* pHeap;
			ASStringNode* pFreeStringNodes;
			StringNodePage* pStringNodePages;
			TextPage::Entry* pFreeTextBuffers;
			TextPage* pTextBufferPages;
			ASStringNode EmptyStringNode;
			ASStringNode NullStringNode;
			LogState* pLog;
			StringLH FileName;

			void CreateString(ASString* p_Result, const char* p_Str)
			{
				reinterpret_cast<void(__fastcall*)(void*, ASString*, const char*)>(UFG_RVA(0x6E1460))(this, p_Result, p_Str);
			}
		};

		namespace AS2
		{
			class StringManager
			{
			public:
				ASStringNodeHolder Builtins[156];
				ASStringManager* pStringManager;
				const char** pStaticStrings;
			};
		}
	}
}