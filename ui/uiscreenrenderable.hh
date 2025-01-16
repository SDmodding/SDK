#pragma once

namespace UFG
{
	class UIScreenRenderable
	{
	public:
		Illusion::Target* m_offscreenTarget;
		bool m_ownsOffscreenTarget;
		char m_fileName[256];
		Scaleform::GFx::MovieInfo m_movieInfo;
		Scaleform::Ptr<Scaleform::GFx::MovieDef> m_movieDef;
		Scaleform::Ptr<Scaleform::GFx::Movie> m_movie;
		Scaleform::GFx::Loader* mLoader;
		int m_x;
		int m_y;
		int m_width;
		int m_height;
		bool m_shouldRender;
		volatile bool mIsLoaded;

		/* Virtual Functions */

		virtual ~UIScreenRenderable() = 0;

		/* Functions */

		void Load() { SDK_CALL_FUNC(void, 0xA274E0, void*)(this); }
		void render() { SDK_CALL_FUNC(void, 0xA319F0, void*)(this); }
		void replaceTexture(const char* flaTexture, Illusion::Texture* engineTexture) { SDK_CALL_FUNC(void, 0xA31C70, void*, const char*, Illusion::Texture*)(this, flaTexture, engineTexture); }
		void setBuffer(Illusion::Target* target) { SDK_CALL_FUNC(void, 0xA31EC0, void*, Illusion::Target*)(this, target); }

		void setViewport(int bufferWidth, int bufferHeight, int x, int y, int width, int height) { 
			SDK_CALL_FUNC(void, 0xA32110, void*, int, int, int, int, int, int)(this, bufferWidth, bufferHeight, x, y, width, height); 
		}
	};
	SDK_ASSERT_SIZEOF(UIScreenRenderable, 0x168);
}