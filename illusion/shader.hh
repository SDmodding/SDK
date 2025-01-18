#pragma once

namespace Illusion
{
	class ShaderParam : public UFG::qNode<ShaderParam>, public StateParam
	{
	public:
		void* mPullFunction;// void(__fastcall* mPullFunction)(Illusion::TaskRenderEnv*, Illusion::Shader*, Illusion::ShaderParam*, void*);
		bool mIsResource;
		int mPixelTextureSlot;
		int mPixelSamplerSlot;
		int mVertexTextureSlot;
		int mVertexSamplerSlot;
		int mComputeTextureSlot;
		int mComputeSamplerSlot;
		int mGeometryTextureSlot;
		int mGeometrySamplerSlot;
		int mHullTextureSlot;
		int mHullSamplerSlot;
		int mDomainTextureSlot;
		int mDomainSamplerSlot;
		int mPixelConstantSlot;
		int mVertexConstantSlot;
		int mComputeConstantSlot;
		int mGeometryConstantSlot;
		int mHullConstantSlot;
		int mDomainConstantSlot;
		ID3D11Buffer* mConstantBuffer;
		u32 mNumBytes;
		int mComputeBufferSlot;
		int mComputeUAVSlot;
	};

	class IShaderPlat{};

	class Shader : public IShaderPlat, public UFG::qResourceData
	{
	public:
		UFG::BitFlags128 mShaderParamInputMask;
		UFG::qOffset64<class ShaderUser*> mShaderUser;
		int mSortID;
		ShaderParam* mLocalShaderParams;
		u32 mNumLocalShaderParams;
		void* mShaderParam[128];
	};

	class ShaderHandle : public UFG::qTypedResourceHandle<RTypeUID_Shader, Shader>{};
}