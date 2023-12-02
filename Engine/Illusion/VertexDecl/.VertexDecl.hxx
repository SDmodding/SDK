#pragma once

namespace Illusion
{
	class CVertexStreamElement
	{
	public:
		eVertexStreamElementUsage usage;
		eVertexSteamElementType type;
		int16_t stream;
		int offset;
		int size;
		UFG::qVector4 mDefault;
	};

	class IVertexDeclPlat
	{
	public:

	};

	class CVertexDeclUser
	{
	public:
		int mExampleOfVertexDeclUserData1;
		float mExampleOfVertexDeclUserData2;
	};

	class CVertexDecl : public IVertexDeclPlat, public UFG::qResourceData
	{
	public:
		UFG::qOffset64<CVertexStreamElement> mElements;
		int mNumElements;
		uint32_t mStreamStrides[4];
		uint32_t mStreamRuntimeFlags;
		UFG::qOffset64<CVertexDeclUser> mVertexDeclUser;
	};
}

#include "Dynamic.hxx"