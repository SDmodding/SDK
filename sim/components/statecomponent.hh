#pragma once

namespace UFG
{
	template <typename T>
	class StateComponentI : public SimComponent, public StateInterface
	{
	public:
		bool mAutoActivate;
		f32 mAge;
	};
}