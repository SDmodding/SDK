#pragma once

namespace Scaleform::GFx
{
	class MovieImpl;

	class ASSupport : public State
	{
	public:
	};

	class ASMovieRootBase : RefCountBase<ASMovieRootBase, StatMV_Other_Mem>
	{
	public:
		MovieImpl* pMovieImpl;
		Ptr<ASSupport> pASSupport;
		char AVMVersion;
	};
}