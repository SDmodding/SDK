#pragma once

namespace Illusion
{
	namespace eCompression
	{
		enum Enum
		{
			Default,
			None,
			DXT1,
			DXT1_N,
			DXT3,
			DXT5,
			DXT5_N,
			A8R8G8B8,
			A1R5G5B5,
			R5G6B5,
			R32F,
			X16FY16FZ16FW16F,
			X8,
			X16,
			BC6H_UF16,
			BC6H_SF16,
			BC7,
			BC7_SRGB
		};
	}

	namespace eFilter
	{
		enum Enum
		{
			Default,
			Linear,
			Point,
			Anisotropic,
			Convolution
		};
	}

	namespace eOutputScale
	{
		enum Enum
		{
			Default,
			Half,
			Quarter,
			Eighth,
			Sixteenth,
			ThirtySecondth,
			Fixed_4096,
			Fixed_2048,
			Fixed_1024,
			Fixed_512,
			Fixed_256,
			Fixed_128,
			Fixed_64,
			Fixed_32,
			Fixed_16
		};
	}

	namespace eTiling
	{
		enum Enum
		{
			Default,
			None,
			Clamp,
			Mirror
		};
	}

	namespace eTrueFalse
	{
		enum Enum
		{
			True,
			False
		};
	}

	namespace eType
	{
		enum Enum
		{
			Default,
			ColourCube,
			CubeMap,
			VolumeMap,
			NormalMap,
			SpecularMap,
			HDR,
			TextureArray,
			NormalMapArray
		};
	}

	namespace eYesNo
	{
		enum Enum
		{
			Default,
			Yes,
			No
		};
	}

	class rTexture : public UFG::qReflectObjectType<rTexture>
	{
	public:
		UFG::qReflectString mFilePath;
		UFG::qReflectString mMovie;
		eOutputScale::Enum mOutputScale;
		eOutputScale::Enum mOutputScale_PC_High;
		eOutputScale::Enum mOutputScale_PC_Medium;
		eOutputScale::Enum mOutputScale_PC_Low;
		eCompression::Enum mCompression;
		int mMipmaps;
		eFilter::Enum mFilter;
		eType::Enum mType;
		u32 mVolumeSlices;
		u32 mArraySize;
		eTiling::Enum mTilingU;
		eTiling::Enum mTilingV;
		eYesNo::Enum mWrapV;
		u32 mBrightnessDiffuse;
		u32 mBrightnessIllum;
		eTrueFalse::Enum mPreserveSize;
		TextureHandle mTextureHandle;
	};
	SDK_ASSERT_SIZEOF(rTexture, 0xD0);
}