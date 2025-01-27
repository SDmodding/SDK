#pragma once

namespace UFG
{
	class BroadPhaseHandler : public hkpBroadPhaseBorder
	{
	public:
		void(__fastcall* mCallback)(hkpEntity*);
	};
}