#pragma once

class Intention
{
public:
	f32 mMotionIntentionSpeedRaw;
	UFG::qVector3 mMotionIntentionDirectionRaw;
	f32 mMotionIntentionSpeed;
	UFG::qVector3 mMotionIntentionDirection;
	bool mEnableManualStrafeFacingDirection;
	UFG::qVector3 mManualStrafeFacingDirection;
	UFG::qVector3 mFacingIntentionDirection;
	bool mDesireToLookAtPoint;
	UFG::qVector3 mDesiredLookAtPoint;
	bool mDesireToLookAtPointEye;
	UFG::qVector3 mDesiredLookAtPointEye;
	UFG::AIAwareness::SubProfileAnimation mAwarenessIntention;
	f32 mCurrentRotationInput;
	f32 mCurrentRotationSpeed;
	f32 mCurrentRotationSignal;
	f32 mCurrentRotationAccel;
	f32 mCurrentRotationAngularVel;
	u32 mNodeRequestHash;
	u64 mSignals;

	UFG::qStaticBitField<548> mActionRequests;	
	union
	{
		s8 mActionRequestChargeTimes[548];
		u64 mFastClear[9];
	};

	UFG::qStaticBitField<32> mFacialRequests;
	union
	{
		s8 mFacialRequestChargeTimes[32];
		u64 mFacialFastClear[1];
	};
};
SDK_ASSERT_SIZEOF(Intention, 0x348);