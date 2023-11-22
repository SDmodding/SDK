#pragma once

namespace UFG
{
	class CTransformNodeComponent;
}

namespace Render
{
	struct RainDropParameters_t
	{
		float mLength;
		float mSpeed;
		float mAlpha;
		float mWidth;
		float mDensity;
		float mAlphaFadeSpeedBegin;
		float mAlphaFadeSpeedEnd;
	};

	struct RainDropSeeds_t
	{
		float mSpeedScale[16];
	};

	struct RainDropStates_t
	{
		float mDeltaTime;
		uint32_t mNumActivePasses;
		UFG::qVector3 mWindVariance[16];
		UFG::qVector4 mOffset[16];
	};

	class CRainManager
	{
	public:
		uint32_t mStateblockIndex;
		UFG::qResourceHandle mRainDropTexture;
		UFG::qResourceHandle mRainDropMaterial;
		UFG::qResourceHandle mRainMistTexture;
		UFG::qResourceHandle mRainMistMaterial;
		class Illusion_Primitive* mRainDropPrimitive;
		UFG::qResourceHandle mRainDropVertexDecl;
		RainDropParameters_t* mCurrentRainProfile;
		RainDropParameters_t mDefaultRainParameters;
		RainDropParameters_t mRainProfileParameters[3];
		RainDropSeeds_t mRainDropSeeds;
		RainDropStates_t mRainDropStates;
		void* mRainDropVertexData;
		uint32_t mRainDropVertexCount;
		void* mRainDropIndexData;
		uint32_t mRainDropIndexCount;
		UFG::qVector3 mPreviousCameraPosition;
		UFG::qMatrix44 mPreviousWorldViewProjMatrix;
		bool mRainEnabled;
		UFG::CTransformNodeComponent* mRainDropSplashEffectTransform;
		uint32_t mRainDropSplashEffectID;
		float mRainInteriorBlend;
		float mRainIndoorAlphaOverride;

		static CRainManager* Instance()
		{
			return reinterpret_cast<CRainManager*>(UFG_RVA(0x2142F50));
		}
	};
}