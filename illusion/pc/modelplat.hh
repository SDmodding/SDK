#pragma once

namespace Illusion
{
	class BufferD3DResource : public UFG::qResourceData
	{
	public:
		ID3D11Buffer* mGpuResource;
		u32 mResourceOffset;
		ID3D11Buffer* mStagingResource;
		int mRefCount;
		bool mFrameGenerated;
		ID3D11ShaderResourceView* mShaderResourceView;
	};
	SDK_ASSERT_SIZEOF(BufferD3DResource, 0x80);

	class BufferD3DResourceHandle : UFG::qTypedResourceHandle<RTypeUID_BufferD3DResource, BufferD3DResource>{};

	class BufferUserPlat
	{
	public:
		int mExampleOfBufferUserPlatData1;
		float mExampleOfBufferUserPlatData2;
	};

	class IBufferPlat
	{
	public:
		enum LockType
		{
			LOCK_NONE = -1,
			LOCK_READ = 0,
			LOCK_OVERWRITE,
			LOCK_MODIFY
		};
	};

	class BufferPlat
	{
	public:
		enum CpuAccess
		{
			CPU_ACCESS_NONE,
			CPU_ACCESS_READ_ONLY,
			CPU_ACCESS_WRITE_ONLY,
			CPU_ACCESS_READ_WRITE
		};

		UFG::qOffset<BufferUserPlat*> mBufferUserPlat;
		u32 mCpuAccess;
		u32 mUploadAfterUnmap;
		ID3D11Buffer* mMappedResource;
		BufferD3DResourceHandle mBufferD3DResourceHandle;
		s8 mPadding[72];
	};
	SDK_ASSERT_SIZEOF(BufferPlat, 0x80);
}