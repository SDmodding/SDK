#pragma once

namespace UFG
{
	class TargetSphere : public qNode<TargetSphere>
	{
	public:
		qVector3 positionT0;
		qVector3 positionT1;
		f32 radius;
		void* owner;
		u32 userData;
	};
	SDK_ASSERT_SIZEOF(TargetSphere, 0x40);
}