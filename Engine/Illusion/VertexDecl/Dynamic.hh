#pragma once

namespace Illusion
{
	struct DynamicVertex_t
	{
		UFG::qVector3 m_Position;
		UFG::qHalfFloat m_TexCoord0[2];
		UFG::qHalfFloat m_TexCoord1[2];
		UFG::qVector3 m_Normal;
		UFG::qVector3 m_Tangent;
		uint8_t m_Color[4];

		static UFG_INLINE CVertexDecl* GetDecl()
		{
			UFG::qResourceHandle* pDeclHandle = reinterpret_cast<UFG::qResourceHandle*>(UFG_RVA(0x212B908));
			if (!pDeclHandle->mData) {
				pDeclHandle->Init(Resource_VertexDeclInventory, 0x64A43DAE);
			}

			return reinterpret_cast<CVertexDecl*>(pDeclHandle->mData);
		}
	};
}