#pragma once

namespace Scaleform
{
	namespace GFx
	{
		class Loader : public StateBag
		{
		public:
			void* pImpl;
			Scaleform::GFx::ResourceLib* pStrongResourceLib;
			unsigned int DefLoadFlags;
		};
	}
}