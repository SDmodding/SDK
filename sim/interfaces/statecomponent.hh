#pragma once

namespace UFG
{
	class StateInterface
	{
	public:
		 virtual bool Enter() = 0;
		 virtual void Update(float fDeltaT) = 0;
		 virtual void Exit() = 0;
		 virtual void Reset() = 0;
		 virtual bool IsActive() = 0;
	};
}