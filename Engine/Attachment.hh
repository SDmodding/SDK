#pragma once

namespace UFG
{
	class CCreature;
	class SimObject;

	class CAttachment
	{
	public:
		void* vfptr;
		qNode<CAttachment> mNode;
		bool mPositionOnly;
		bool mPositionXYOnly;
		bool mAttachRelative;
		bool mScaleRelative;
		bool mUseRubberBand;
		int attachedJoint;
		qSafePointer<SimObject> mRootSimObject;
		qSafePointer<CCreature> mRootCreature;
		qSafePointer<SimObject> mAttachedSimObject;
		qMatrix44 mRelativeAttachmentLS;
		qVector3 mRelativeScaleLS;
		float mBlendRate;
		float mBlendWeight;
	};
}