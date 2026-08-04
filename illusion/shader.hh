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
	class ShaderPlat;

	class ShaderBinary : public UFG::qResourceData
	{
	public:
		u32 mDataByteSize;
		u32 mShaderStageType;
		UFG::qOffset64<void*> mData;
		char mShaderName[52];
	};

	class ShaderBinaryHandle : public UFG::qTypedResourceHandle<RTypeUID_ShaderBinary, ShaderBinary> {};

	class Shader : public IShaderPlat, public UFG::qResourceData
	{
	public:
		enum StageType
		{
			STAGE_VERTEX,
			STAGE_PIXEL,
			STAGE_COMPUTE,
			STAGE_GEOMETRY,
			STAGE_HULL,
			STAGE_DOMAIN,
			MAX_STAGES,

			STAGE_INVALID = 99
		};

		UFG::BitFlags128 mShaderParamInputMask;
		UFG::qOffset64<class ShaderUser*> mShaderUser;
		int mSortID;
		ShaderParam* mLocalShaderParams;
		u32 mNumLocalShaderParams;
		void* mShaderParam[128];

		/* Helper Functions */

		SDK_INLINE ShaderPlat* GetPlat() { return reinterpret_cast<ShaderPlat*>(reinterpret_cast<uptr>(this) + UFG::qAlignUp(sizeof(*this), 16ull)); }

		/* Functions */

		void AddShaderStage(ShaderBinary* shader_stage_binary) { SDK_CALL_FUNC(void, 0xA17340, void*, ShaderBinary*)(this, shader_stage_binary); }
	};

	class ShaderHandle : public UFG::qTypedResourceHandle<RTypeUID_Shader, Shader>{};
}