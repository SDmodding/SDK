#pragma once

namespace UFG
{
	class HintComponentBase : public SimComponent, public qNamed
	{
	public:
		u32 mFlags;
	};
	SDK_ASSERT_SIZEOF(HintComponentBase, 0x48);
}