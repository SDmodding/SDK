#pragma once

namespace UFG
{
	namespace GameCamera
	{
		class CDofOverrideParams
		{
		public:
			bool bActive;

			UFG_PAD(0x3);

			float rFocalRange;
			float rNearRange;
			float rFarRange;
			float rNearBlur;
			float rFarBlur;

			static CDofOverrideParams* Instance()
			{
				return reinterpret_cast<CDofOverrideParams*>(UFG_RVA(0x23CF6F8));
			}
		};
	}
}