#pragma once

class hkpRigidBody : public hkpEntity
{
public:
	void SetMotionType(hkpMotion::MotionType p_NewState, hkpEntityActivation p_ActivationState, hkpUpdateCollisionFilterOnEntityMode p_CollisionFilterUpdateMode)
	{
		reinterpret_cast<void(_fastcall*)(void*, hkpMotion::MotionType, hkpEntityActivation, hkpUpdateCollisionFilterOnEntityMode)>(UFG_RVA(0xD62D20))(this, p_NewState, p_ActivationState, p_CollisionFilterUpdateMode);
	}

	void SetPosition(hkVector4f* p_Position)
	{
		reinterpret_cast<void(_fastcall*)(void*, hkVector4f*)>(UFG_RVA(0xD627D0))(this, p_Position);
	}

	void SetRotation(hkQuaternionf* p_Rotation)
	{
		reinterpret_cast<void(_fastcall*)(void*, hkQuaternionf*)>(UFG_RVA(0xD62800))(this, p_Rotation);
	}

	void SetPositionAndRotation(hkVector4f* p_Position, hkQuaternionf* p_Rotation)
	{
		reinterpret_cast<void(_fastcall*)(void*, hkVector4f*, hkQuaternionf*)>(UFG_RVA(0xD62830))(this, p_Position, p_Rotation);
	}
};