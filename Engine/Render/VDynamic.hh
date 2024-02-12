#pragma once

namespace Render
{
	class CVDynamic
	{
	public:
		UFG::qVector3 mPosition;
		uint16_t mTexCoord0[2];
		uint16_t mTexCoord1[2];
		UFG::qVector3 mNormal;
		UFG::qVector3 mTangent;
		uint32_t mColour;
	};
}