#pragma once

class hkPackfileWriter : public hkReferencedObject
{
public:
	struct Options
	{
		u32 m_userTag;
		hkStructureLayout m_layout;
		hkBool m_writeMetaInfo;
		hkBool m_writeSerializedFalse;
		const char* m_contentsVersion;

		Options()
			: m_userTag(0),
			m_writeMetaInfo(false),
			m_writeSerializedFalse(false),
			m_contentsVersion(0)
		{
		}
	};


	//hkArray<hkPackfileWriter::PendingWrite, hkContainerHeapAllocator> m_pendingWrites;
	//hkPointerMap<void const*, int, hkContainerHeapAllocator> m_knownObjects;
	//hkPointerMap<void const*, char const*, hkContainerHeapAllocator> m_imports;
	//hkPointerMap<void const*, char const*, hkContainerHeapAllocator> m_exports;
	//hkStringMap<hkClass const*, hkContainerHeapAllocator> m_knownClasses;
	//hkPointerMap<void const*, void const*, hkContainerHeapAllocator> m_replacements;
	//hkArray<char*, hkContainerHeapAllocator> m_knownSections;
	//hkStringMap<int, hkContainerHeapAllocator> m_sectionTagToIndex;
	//hkArray<hkVariant, hkContainerHeapAllocator> m_objectsWithUnregisteredClass;
	//int m_contentsPtrPWIndex;
	//int m_contentsClassPWIndex;
	//int m_numDataInstances;
	//int m_numClassInstances;
	//hkPointerMap<void const*, unsigned int, hkContainerHeapAllocator> m_sectionOverrideByPointer;
	//hkStringMap<unsigned int, hkContainerHeapAllocator> m_sectionOverrideByType;
	//hkSerializeMultiMap<void const*, int, hkPointerMap<void const*, int, hkContainerHeapAllocator> > m_pwIndexesFromReferencedPointer;
	//hkPackfileWriter::Options m_startOptions;
};