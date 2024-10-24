#pragma once

namespace Illusion
{
	class IUnorderedAccessViewPlat
	{
	public:
		UnorderedAccessViewPlat* mPlat;
	};

	class UnorderedAccessView : public IUnorderedAccessViewPlat
	{
	public:
		union
		{
			Buffer* mBuffer;
			Texture* mTexture;
		} mResource;
		bool mIsBufferResource;
	};
}