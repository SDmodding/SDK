#pragma once

namespace UFG
{
	class SubTargetingProfileInfo
	{
	public:
		struct AngularInputToSubTargetingLocation
		{
			f32 m_fMaxAngularInputRad;
			SubTargetingLocationDynamic m_SubTargetingLocationDynamic;
		};

		qFixedArray<AngularInputToSubTargetingLocation, 6> m_AngularInputToSubTargetingLocations;
		f32 m_fTargetHeadingRelativeToCameraRad;
		f32 m_fAngularHalfWidthRad;
	};

	class SubTargetingProfile : public qNodeRB<SubTargetingProfile>
	{
	public:
		SubTargetingLocationDynamic m_DefaultSubTargetingLocationDynamic;
		SubTargetingLocationDynamic m_HeadLookAtSubTargetingLocationDynamic;
		qFixedArray<SubTargetingProfileInfo, 4> m_SubTargetingProfileInfos;
		f32 m_fSoftLockExtraCapsuleRadius;
	};
}