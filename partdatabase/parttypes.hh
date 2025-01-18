#pragma once

// No idea where to put this...
namespace UFG::TextureOverride
{
	enum Slot : u32
	{
		Diffuse = 0xDCE06689,				// texDiffuse
		Normal = 0xADBE1A5A,				// texBump
		Specular = 0xCB460EC7,				// texSpecular
		BlendLayerDiffuse = 0x19410F73,		// texDiffuse2
		BlendLayerNormal = 0xA348DC23,		// texBump2
		BlendLayerSpecular = 0xED7FCA06,	// texSpecular2
		SelfIllumination = 0xBEFFB144,		// ?
		BlendMask = 0xCEFC139C				// texBlendMask
	};
}

namespace UFG
{
	class PartDefinition : qReflectObjectType<PartDefinition>
	{
	public:
		enum LODIndex
		{
			LOD_A,
			LOD_B,
			LOD_C,
			LOD_D,
			LOD_E,
			LOD_F
		};

		enum MorphType
		{
			MORPH_None,
			MORPH_Base,
			MORPH_Target1,
			MORPH_Target2
		};

		struct CompositeData
		{
			f32 mAlpha;
			f32 mHeight;
			qReflectArray<qColour> mDiffuseChannelDefaults;
			qReflectArray<f32> mSpecularChannelDefaults;
		};

		struct TextureData
		{
			TextureOverride::Slot mTextureSlot;
			qReflectHandle<Illusion::rTexture> mOriginalTexture;
			qReflectHandle<Illusion::rTexture> mOverrideTexture;
		};

		struct TextureAlternate
		{
			qSymbolUC mId;
			qReflectString mName;
			qReflectArray<TextureData> mTextures;
			CompositeData mCompositeData;
		};

		qReflectString mName;
		qSymbolUC mSlotName;
		qReflectHandle<ModelAsset> mModelAsset;
		CompositeData mCompositeData;
		qReflectArray<TextureAlternate> mTextureAlternates;
		qReflectArray<qColour> mTintColours;
		u32 mModelSize;
		u32 mTextureSize;

		/* Functions */

		qString GetModelFileName() { return SDK_CALL_FUNC(qString, 0x158BC0, void*)(this); }
		u32 GetModelSize() { return SDK_CALL_FUNC(u32, 0x158C10, void*)(this); }
		TextureAlternate* GetTextureAlternate(const qSymbolUC& textureSet) { return SDK_CALL_FUNC(TextureAlternate*, 0x159060, void*, const qSymbolUC&)(this, textureSet); }
		qString GetTextureFileName() { return SDK_CALL_FUNC(qString, 0x1590A0, void*)(this); }
	};
}