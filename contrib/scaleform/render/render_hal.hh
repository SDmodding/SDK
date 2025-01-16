#pragma once

namespace Scaleform::Render
{
	class HAL; // TODO: Implement this

	class HALNotify : public ListNode<HALNotify>
	{
	public:
		virtual ~HALNotify() = 0;
	};
}