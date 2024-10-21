#pragma once

namespace UFG
{
	class UpdateInterface
	{
	public:
		virtual void Update(f32 delta_sec) = 0;
	};
	SDK_ASSERT_SIZEOF(UpdateInterface, 0x8);
}