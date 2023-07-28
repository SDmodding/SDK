#pragma once

namespace UFG
{
	namespace GameCamera
	{
		class CDofOverrideParams
		{
		public:
			bool bActive;

			char m_Pad0x1[0x3];

			float rFocalRange;
			float rNearRange;
			float rFarRange;
			float rNearBlur;
			float rFarBlur;
		};
		CDofOverrideParams* DofOverrideParams = reinterpret_cast<CDofOverrideParams*>(UFG_RVA(0x23CF6F8));
	}
}