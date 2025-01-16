#pragma once

namespace Scaleform::Render
{
	class ThreadCommand : public RefCountBase<Scaleform::Render::ThreadCommand, Stat_Default_Mem>
	{
	public:
	};

	class ThreadCommandQueue
	{
	public:
		virtual ~ThreadCommandQueue() = 0;
	};
}