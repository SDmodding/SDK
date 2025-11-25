#pragma once

namespace Render
{
	// VertexDecl.Dynamic (0x64A43DAE)
	class vDynamic
	{
	public:
		UFG::qVector3 mPosition;
		u16 mTexCoord0[2];
		u16 mTexCoord1[2];
		UFG::qVector3 mNormal;
		UFG::qVector3 mTangent;
		u32 mColour;

		void SetUV(const UFG::qVector2& uv0, const UFG::qVector2& uv1)
		{
			reinterpret_cast<UFG::qHalfFloat*>(&mTexCoord0[0])->Set(uv0.x);
			reinterpret_cast<UFG::qHalfFloat*>(&mTexCoord0[1])->Set(uv0.y);

			reinterpret_cast<UFG::qHalfFloat*>(&mTexCoord1[0])->Set(uv1.x);
			reinterpret_cast<UFG::qHalfFloat*>(&mTexCoord1[1])->Set(uv1.y);
		}

		void SetUV(f32 u, f32 v)
		{
			reinterpret_cast<UFG::qHalfFloat*>(&mTexCoord0[0])->Set(u);
			reinterpret_cast<UFG::qHalfFloat*>(&mTexCoord0[1])->Set(v);
		}

		void SetColor(u32 r, u32 g, u32 b, u32 a = 255)
		{
			mColour = (r) | (g << 8) | (b << 16) | (a << 24);
		}

		void SetColor(const UFG::qColour& col)
		{
			SetColor(static_cast<u32>(col.r * 255.f), static_cast<u32>(col.g * 255.f), static_cast<u32>(col.b * 255.f), static_cast<u32>(col.a * 255.f));
		}
	};
	SDK_ASSERT_SIZEOF(vDynamic, 0x30);
}