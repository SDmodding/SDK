#pragma once

namespace UFG
{
	class qPropertySetResource;

	class qProperty
	{
	public:
		u32 mTypeUIDOffsetChanged;
		u32 mNameUID;
	};

	class qPropertyCollection
	{
	public:
		u32 mFlags;
		u32 mPad0;
		qOffset64<qPropertyCollection*> mOwner;
	};

	class qPropertySetHandle : qTypedResourceHandle<0x54606C31, qPropertySetResource>
	{
	public:
	};

	class qPropertySet : public qPropertyCollection, public qNode<qPropertySet>
	{
	public:
		qOffset64<qPropertySetHandle*> mParents;
		qOffset64<u8*> mValues;
		qOffset64<unsigned long*> mDefaultBits;
		qOffset64<qProperty*> mProperties;
		qSymbol mName;
		u16 mRefCount;
		u16 mNumParents;
		u32 mParentMask;
		qSymbol mSchemaName;
		u32 mPropertyMask;
		u16 mNumDataBytes;
		u16 mNumProperties;
	};
	SDK_ASSERT_SIZEOF(qPropertySet, 0x58);

	class qPropertySetResource : public qResourceData
	{
	public:
		u32 mFlags;
		u32 mSourceCRC;
		qOffset64<char const*> mNameString;
		qPropertySet mData;
	};
}