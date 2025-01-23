#pragma once

class hkaAnimationBinding : public hkReferencedObject
{
public:
	enum BlendHint
	{
		NORMAL,
		ADDITIVE
	};

	hkStringPtr m_originalSkeletonName;
	hkRefPtr<hkaAnimation> m_animation;
	hkArray<i16> m_transformTrackToBoneIndices;
	hkArray<i16> m_floatTrackToFloatSlotIndices;
	hkArray<i16> m_partitionIndices;
	hkEnum<BlendHint, i8> m_blendHint;
};