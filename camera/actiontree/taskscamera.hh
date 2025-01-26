#pragma once

class CameraAnimationTask : public Task<class CameraAnimationTrack>
{
public:
	ActionContext* mContext;
	UFG::qSafePointer<AnimationNode> mController;
	UFG::qSafePointer<UFG::AnimatedCameraComponent> mAnimatedCameraComponent;
	UFG::qSafePointer<UFG::GameCameraComponent> mPreviousCameraComponent;
};

class CameraChangeTask : public Task<class CameraChangeTrack>
{
public:
};

class CameraCollisionGotoAngleTask : public Task<class CameraCollisionGotoAngleTrack>
{
public:
};

class CameraConstrainYawTask : public Task<class CameraConstrainYawTrack>
{
public:
	bool mLocalPlayer;
};

class CameraDOFTask : public Task<class CameraDOFTrack>
{
public:
	ActionContext* mActionContext;
};

class CameraFollowGotoTask : public Task<class CameraFollowGotoTrack>
{
public:
};

class CameraFollowTargetTask : public Task<class CameraFollowTargetTrack>
{
public:
};

class CameraIgnoreCollisionTask : public Task<class CameraIgnoreCollisionTrack>
{
public:
	bool mLocalPlayer;
	bool mIgnoreCharacters;
	bool mIgnoreVehicles;
};

class CameraRecoilTask : public Task<class CameraRecoilTrack>
{
public:
};

class CameraResetTask : public Task<class CameraResetTrack>
{
public:
};

class CameraSetSniperModeTask : public Task<class CameraSetSniperModeTrack>
{
public:
};

class CameraShakeTask : public Task<class CameraShakeTrack>
{
public:
};