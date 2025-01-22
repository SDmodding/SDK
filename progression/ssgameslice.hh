#pragma once

namespace UFG
{
	class SSGameSlice : public qSafePointerNode<SSGameSlice>, public SSActor
	{
	public:
		GameSlice* mpGameSlice;
	};
}