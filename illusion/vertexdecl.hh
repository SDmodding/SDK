#pragma once

namespace Illusion
{
	class VertexDeclUser
	{
	public:
		int mExampleOfVertexDeclUserData1;
		f32 mExampleOfVertexDeclUserData2;
	};

	class IVertexDeclPlat
	{
	public:
	};

	class VertexDecl : public IVertexDeclPlat, public UFG::qResourceData
	{
	public:
		UFG::qOffset<VertexStreamElement*> mElements;
		int mNumElements;
		u32 mStreamStrides[4];
		u32 mStreamRuntimeFlags;
		UFG::qOffset<VertexDeclUser*> mVertexDeclUser;

		/* Helpers */

		VertexStreamElement* FindElement(VertexStreamElementUsage usage)
		{
			auto element = mElements.Get();
			for (int i = 0; mNumElements > i; ++i, ++element)
			{
				if (element->mUsage == usage) {
					return element;
				}
			}

			return 0;
		}
	};

	class VertexDeclHandle : public UFG::qTypedResourceHandle<RTypeUID_VertexDecl, VertexDecl>{};
}