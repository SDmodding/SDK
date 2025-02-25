#pragma once

class hkaRagdollRigidBodyController
{
public:
	hkArray<hkaKeyFrameHierarchyUtility::ControlData> m_controlDataPalette;
	hkArray<int> m_bodyIndexToPaletteIndex;
	hkaKeyFrameHierarchyUtility::BodyData m_bodyData;
	hkArray<hkaKeyFrameHierarchyUtility::WorkElem> m_internalData;
	hkaRagdollInstance* m_ragdollInstance;
	hkArray<i16> m_rbParentIndices;
};