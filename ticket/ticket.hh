#pragma once

namespace UFG
{
	class Ticket : public qNode<Ticket>
	{
	public:
		u64 mTimestamp;
		fastdelegate::FastDelegate1<float, void> mActiveCallback;
		fastdelegate::FastDelegate0<void> mInactiveCallback;
	};
	SDK_ASSERT_SIZEOF(Ticket, 0x38);
}