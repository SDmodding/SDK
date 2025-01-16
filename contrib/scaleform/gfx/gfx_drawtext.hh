#pragma once
#ifdef DrawText
#undef DrawText
#endif

namespace Scaleform::GFx
{
	class DrawTextManagerImpl;

	class DrawText : public RefCountBaseNTS<DrawText, StatMV_Text_Mem>
	{
	public:
	};

	class DrawTextManager : public RefCountBaseNTS<DrawTextManager, Stat_Default_Mem>, public StateBag
	{
	public:
		DrawTextManagerImpl* pImpl;
		MemoryHeap* pHeap;
	};
}