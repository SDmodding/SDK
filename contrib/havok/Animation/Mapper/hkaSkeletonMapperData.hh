#pragma once

class hkaSkeletonMapperData
{
public:
	enum MappingType
	{
		HK_RAGDOLL_MAPPING,
		HK_RETARGETING_MAPPING
	};

	hkRefPtr<const hkaSkeleton> m_skeletonA;
	hkRefPtr<const hkaSkeleton> m_skeletonB;
	hkArray<i16> m_partitionMap;
	hkArray<struct PartitionMappingRange> m_simpleMappingPartitionRanges;
	hkArray<struct PartitionMappingRange> m_chainMappingPartitionRanges;
	hkArray<struct SimpleMapping> m_simpleMappings;
	hkArray<struct ChainMapping> m_chainMappings;
	hkArray<i16> m_unmappedBones;
	hkQsTransformf m_extractedMotionMapping;
	hkBool m_keepUnmappedLocal;
	hkEnum<MappingType, int> m_mappingType;
};