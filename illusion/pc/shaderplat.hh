#pragma once

namespace Illusion
{
	class ShaderConstBufInfo;
	class ShaderParamInfo;
	class ShaderResourceInfo;

	class StageShader
	{
	public:
		char* mRawShader;
		u32 mRawShaderSize;
		Shader::StageType mStage;
		D3D11_SHADER_DESC mShaderDesc;
		ID3D11ShaderReflection* mReflection;
		ID3D11PixelShader* mPixelShader;
		ID3D11VertexShader* mVertexShader;
		ID3D11ComputeShader* mComputeShader;
		ID3D11GeometryShader* mGeometryShader;
		ID3D11HullShader* mHullShader;
		ID3D11DomainShader* mDomainShader;
		int mInputCount;
		ShaderParamInfo* mInputInfo;
		int mOutputCount;
		ShaderParamInfo* mOutputInfo;
		int mConstBufCount;
		ShaderConstBufInfo* mConstBufInfo;
		UFG::qMap<ShaderConstBufInfo*> mConstBufByName;
		int mResourceCount;
		ShaderResourceInfo* mResourceInfo;
		UFG::qMap<ShaderResourceInfo*> mResourceByName;

		/* Functions */

		bool LoadShader(void* bin, u32 size, Shader::StageType stageType) { return SDK_CALL_FUNC(char, 0xA1BE00, void*, void*, u32, Shader::StageType)(this, bin, size, stageType); }
		void ReleaseResources() { SDK_CALL_FUNC(void, 0xA21000, void*)(this); }
	}; 

	class ShaderUserPlat
	{
	public:
		int mExampleOfShaderUserPlatData1;
		f32 mExampleOfShaderUserPlatData2;
	};

	class ShaderPlat
	{
	public:
		StageShader* mShaderStage[6];
		UFG::qOffset64<ShaderUserPlat*> mShaderUserPlat;
		UFG::qList<ShaderParam> mParams;
	};
}