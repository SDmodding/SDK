#pragma once

class Attachment : public UFG::qNode<Attachment>
{
public:
	bool mPositionOnly;
	bool mPositionXYOnly;
	bool mAttachRelative;
	bool mScaleRelative;
	bool mUseRubberBand;
	int attachedJoint;
	UFG::qSafePointer<UFG::SimObject> mRootSimObject;
	UFG::qSafePointer<Creature> mRootCreature;
	UFG::qSafePointer<UFG::SimObject> mAttachedSimObject;
	UFG::qMatrix44 mRelativeAttachmentLS;
	UFG::qVector3 mRelativeScaleLS;
	f32 mBlendRate;
	f32 mBlendWeight;

	/* Virtual Functions */

	virtual ~Attachment() = 0;
	virtual bool Update(float timeDelta) = 0;
	virtual void UpdatePose() = 0;
	virtual void UpdatePostPhysics() = 0;
	virtual void DebugDraw() = 0;
	virtual bool IsEffectorAttachment() = 0;
	virtual PoseDriver* GetEffector() = 0;
	virtual int GetEffectorFollowJoint() = 0;
	virtual int GetEffectorAdjustJoint() = 0;
	virtual void OnRemove() = 0;
	virtual bool CanDeleteAttachment() = 0;
};
