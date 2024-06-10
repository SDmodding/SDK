#pragma once

namespace UFG
{
	class CTrueCrowdDefinition
	{
	public:
		uint32_t mComponentCount;

		struct Component
		{
			unsigned int mNameUID;
			char mName[32];
		};
		Component mComponents[25];

		uint32_t mEntityCount;

		struct Entity
		{
			uint32_t mNameUID;
			uint32_t mComponentCount;
			uint32_t mRequiredComponentCount;

			struct EntityComponent
			{
				qSymbol mName;
				uint32_t mResourceIndex;
				uint32_t mBoneUID[16];
				uint32_t mNumBoneUIDs;
				uint32_t mbRequired;
			};
			EntityComponent mComponents[16];
		};
		Entity mEntities[25];

		uint32_t mNumTags;
		qSymbol* mTagList;
	};

	class CTrueCrowdDataBase
	{
	public:
		UFG_PAD(0x58);	
		CTrueCrowdDefinition mDefinition;
		unsigned int mNumComponentEntries;

		static UFG_INLINE CTrueCrowdDataBase* Instance()
		{
			return *reinterpret_cast<CTrueCrowdDataBase**>(UFG_RVA(0x24015E0));
		}

		UFG_INLINE void* QueryDataBase(qPropertySet* p_PropertySet, void* p_DataPtr = nullptr)
		{
			return reinterpret_cast<void*(__fastcall*)(void*, qPropertySet*, void*)>(UFG_RVA(0x4408F0))(this, p_PropertySet, p_DataPtr);
		}

		UFG_INLINE uint32_t GetEntityIndex(uint32_t m_NameUID)
		{
			for (uint32_t i = 0; mDefinition.mEntityCount > i; ++i)
			{
				if (mDefinition.mEntities[i].mNameUID == m_NameUID) {
					return i;
				}
			}

			return -1;
		}
	};
}