#pragma once

namespace Illusion
{
	class IEnginePlat
	{
	public:
		void WaitUntilGPUDone() { SDK_CALL_FUNC(void, 0xA22E20, void*)(this); }
	};
}