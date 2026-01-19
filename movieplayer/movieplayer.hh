#pragma once

namespace UFG
{
	class MovieData;

	/*class MovieData
	{
	public:
		class Buffer
		{
		public:
			Illusion::Texture* mTextureY;
			Illusion::Texture* mTextureR;
			Illusion::Texture* mTextureB;
			Illusion::Texture* mTextureA;
		};

		Buffer mBuffer[2];
		Illusion::MaterialHandle mMaterial;
		BINK* mBinkHandle;
		BINKFRAMEBUFFERS mBinkFrameBuffers;
	};*/

	class MoviePlayer : public qNode<MoviePlayer>
	{
	public:
		Illusion::Target* mTarget;
		qResourceHandle mTargetTexture;
		u32 mFlags;
		const char* mFilename;
		MovieData* mMovieData;
		bool mIsPaused;
		bool mbFirstFrame;
		bool mRenderOverUI;
	};
}