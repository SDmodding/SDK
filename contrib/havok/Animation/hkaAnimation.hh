#pragma once

class hkaAnimation : public hkReferencedObject
{
public:
	enum AnimationType
	{
		HK_UNKNOWN_ANIMATION,
		HK_INTERLEAVED_ANIMATION,
		HK_MIRRORED_ANIMATION,
		HK_SPLINE_COMPRESSED_ANIMATION,
		HK_QUANTIZED_COMPRESSED_ANIMATION,
		HK_PREDICTIVE_COMPRESSED_ANIMATION,
		HK_REFERENCE_POSE_ANIMATION
	};

	struct DataChunk
	{
		const char* m_data;
		u32 m_size;
	};

	hkEnum<AnimationType, int> m_type;
	f32 m_duration;
	int m_numberOfTransformTracks;
	int m_numberOfFloatTracks;
	hkRefPtr<const class hkaAnimatedReferenceFrame> m_extractedMotion;
	hkArray<class hkaAnnotationTrack> m_annotationTracks;
};