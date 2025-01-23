#pragma once

namespace UFG
{
	class AnimationResource : public qResourceData
	{
	public:
		u32 m_uAnimationBindingSize;
		hkaAnimationBinding* m_pAnimationBinding;

		union
		{
			void* mStreamingFixups;
			hkPackfileData* m_pLoadedData;
		};
	};

	class AnimationResourceHandle : public qTypedResourceHandle<RTypeUID_AnimationResource, AnimationResource>
	{
	public:
		SkeletalAnimation* m_pSkeletalAnimationOwner;
		u32 m_bUnloading;
	};
}