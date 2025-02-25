#pragma once

class hkaKeyFrameHierarchyUtility
{
public:
	struct BodyData
	{
		int m_numRigidBodies;
		hkpRigidBody* const* m_rigidBodies;
		const i16* m_parentIndices;
		int* m_controlDataIndices;
		const f32* m_boneWeights;
	};

	struct ControlData
	{
		f32 m_hierarchyGain;
		f32 m_velocityDamping;
		f32 m_accelerationGain;
		f32 m_velocityGain;
		f32 m_positionGain;
		f32 m_positionMaxLinearVelocity;
		f32 m_positionMaxAngularVelocity;
		f32 m_snapGain;
		f32 m_snapMaxLinearVelocity;
		f32 m_snapMaxAngularVelocity;
		f32 m_snapMaxLinearDistance;
		f32 m_snapMaxAngularDistance;
	};

	struct WorkElem
	{
		hkVector4f m_prevPosition;
		hkQuaternionf m_prevRotation;
		hkVector4f m_prevLinearVelocity;
		hkVector4f m_prevAngularVelocity;
	};

	struct KeyFrameData
	{
		hkQsTransformf m_worldFromRoot;
		hkQsTransformf* m_desiredPoseLocalSpace;
		WorkElem* m_internalReferencePose;
	};

	struct Output
	{
		f32 m_stressSquared;
	};
};