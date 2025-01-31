#pragma once

namespace UFG
{
	class AimingNPCComponent : public AimingBaseComponent
	{
	public:
		enum { _TypeUID = 0xA2000005 };

		f32 m_fBaseAIAccuracy;
		f32 m_fBaseAIAccuracyVersusNPC;
		f32 m_fPlayerDodgeFactor;
		qSafePointer<SimObject> m_pSimTargetAimPos;

		/* Functions */

		void generateSimTarget(qSafePointer<SimObject*>& destPointer, const qVector3& vPosition) {
			SDK_CALL_FUNC(void, 0x5681D0, void*, qSafePointer<SimObject*>&, const qVector3&)(this, destPointer, vPosition);
		}
	};
}