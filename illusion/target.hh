#pragma once

namespace Illusion
{
	class CreateTargetParams
	{
	public:
		UFG::qString name;
		int width;
		int height;
		int depth;
		int array_size;
		s8 mrt_formats[4];
		u32 num_mrt;
		u32 texture_type;
		u32 target_flags;
		int num_mips;
		Texture* textures[4];
		Texture* depth_texture;
		u32 esram_offset[4];
		u32 esram_usage_bytes[4];
		u32 esram_offset_depth;
		u32 esram_usage_bytes_depth;
		bool use_esram[4];
		bool use_esram_depth;

		CreateTargetParams(const char* in_name, u32 in_texture_type) { SDK_CALL_FUNC(void, 0x2D370, void*, const char*, u32)(this, in_name, in_texture_type); }
	};


	class ITargetPlat
	{
	public:
		enum ClearType
		{
			CLEAR_RGBA = (1 << 0),
			CLEAR_Z = (1 << 1),
			CLEAR_STENCIL = (1 << 2),
			CLEAR_HISTENCIL_CULL = (1 << 3),
			CLEAR_SET_SCULL_PS3 = (1 << 4),
			CLEAR_PS3_ZCULL = (1 << 5),
			CLEAR_ALL = 0xFF,
		};
	};

	class Target : public ITargetPlat
	{
	public:
		int mWidth;
		int mHeight;
		TargetPlat* mTargetPlat;
		u32 mNumTargetTextures;
		Texture* mTargetTexture[4];
		s8 mOwnsTargetTexture[4];
		Texture* mDepthTexture;
		Texture* mDepthTextureCopy;
		s8 mOwnsDepthTexture;
		s8 mDescription[32];

		/* Static Functions */

		SDK_SINLINE Target* CreateTarget(CreateTargetParams* params) { return SDK_CALL_FUNC(Target*, 0x8EA80, CreateTargetParams*)(params); }
	};
	SDK_ASSERT_SIZEOF(Target, 0x78);

	/* Functions */

	SDK_SINLINE void SetFullscreenViewportScissor(Target* target, ViewportScissorState* viewport_scissor, char dest_mip_level) { 
		SDK_CALL_FUNC(void, 0x95750, Target*, ViewportScissorState*, char)(target, viewport_scissor, dest_mip_level);
	}

	SDK_SINLINE void DeleteTarget(Target* target, bool wait = true) { SDK_CALL_FUNC(void, 0x8F080, Target*, bool)(target, wait); }
}