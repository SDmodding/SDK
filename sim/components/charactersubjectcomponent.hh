#pragma once

namespace UFG
{
	class __declspec(align(16)) CharacterSubjectComponent : public CameraSubject, public qNode<CharacterSubjectComponent>
	{
	public:
		enum { _TypeUID = 0x68000005 };

		enum LazyState
		{
			STATE_DONT_KNOW,
			STATE_TRUE,
			STATE_FALSE
		};

		enum SrcTransform
		{
			SrcTransform_Default,
			SrcTransform_Camera,
			SrcTransform_Pelvis,
			SrcTransform_Head,
			SrcTransform_POI,
			SrcTransform_POIParent,
			SrcTransform_Vehicle,
			SrcTransform_Focus,
			SrcTransform_FocusCreatureCambone,
			SrcTransform_FocusCreaturePelvis,
			SrcTransform_FocusCreatureHead,
			SrcTransform_Social,
			SrcTransform_TransformNode
		};

		struct OverrideInfo
		{
			qSymbol mSymbol;
			u32 mUID;
		};

		qMatrix44 mHeadTransformation;
		qMatrix44 mCamboneTransformation;
		qMatrix44 mPelvisTransformation;
		qMatrix44 mSyncTransformation;
		qMatrix44 mTargetWorld;
		bool bElevationLock;
		f32 rLockedElevationDef;
		f32 rLockedElevationCam;
		f32 rLockedElevationHip;
		f32 rLockedElevationHed;
		f32 rLockedElevationFocusCreatureCambone;
		f32 rLockedElevationFocusCreaturePelvis;
		f32 rLockedElevationFocusCreatureHead;
		LazyState mIsHostage;
		LazyState mJogging;
		bool mSprinting;
		bool mFallingAttack;
		LazyState mActionHijacking;
		LazyState mWalking;
		OverrideInfo mContextOverrideScriptGlobal[4];
		OverrideInfo mContextOverrideFreemanNPC[4];
		OverrideInfo mContextOverrideFreemanPlayer[4];
		OverrideInfo mContextOverrideScriptLocal[4];
		int mTypeOverrideFreeman;
		bool bGotoRise;
		f32 rGotoRise;
		f32 rGotoRiseRate;
		f32 rGotoRisePatience;
		bool bGotoRadius;
		f32 rGotoRadius;
		f32 rGotoRadiusRate;
		f32 rGotoRadiusPatience;
		bool bGotoAngle;
		f32 rGotoAngle;
		f32 rGotoAngleRate;
		f32 rGotoAnglePatience;
		bool bGotoAngleWorldSpace;
		bool bGotoAngleUseSecond;
		f32 rGotoAngleSecond;
		bool bGotoAngleFarthestAngle;
		bool bGotoAngleAdditive;
		ParkourHandle* mParkourHandle;
		qVector3 mFilteredPosition;
		f32 mPositionFilterSpeed;
		qVector3 mFilteredVelocity;
		f32 mFilteredSpeed;
		f32 mVelocityFilterSpeed;
		int mBoneHead;
		int mBoneCamera;
		int mBonePelvis;
		int mBoneSync;
		qVector3 mHeadPosition;
		qVector3 mCambonePosition;
		qVector3 mPelvisPosition;
		qVector3 mSyncPosition;
		bool mHeadDirty;
		bool mCamboneDirty;
		bool mPelvisDirty;
		bool mSyncDirty;
		qVector3 mAntiJitterPosition;
		qVector3 mGrapplePosition;
		qVector3 mLastAliveHeadPosition;
		qBox mBox;
		f32 mRadius;
		RebindingComponentHandle<CharacterPhysicsComponent> pCharacterPhysicsComponent;
		RebindingComponentHandle<CharacterAnimationComponent> pCharacterAnimationComponent;
		RebindingComponentHandle<TargetingSystemBaseComponent> pTargetingSystemBaseComponent;
		RebindingComponentHandle<CharacterSubjectComponent> pSocialTargetOverrideComponent;

		/* Impl Functions */

		SDK_INLINE TargetingSystemBaseComponent* GetTargetingSystem() { return pTargetingSystemBaseComponent.GetComponent(); }

		/* Functions */

		const qVector3& CambonePosition() { return SDK_CALL_FUNC(const qVector3&, 0x3C0BE0, void*)(this); }
		bool GetAndClearGotoAngle(f32& angle, f32& rate, f32& patience, bool& localSpace, bool& useSecond, f32& angleSecond, bool& farthestAngle, bool& angleAdditive) {
			return SDK_CALL_FUNC(bool, 0x52A8D0, void*, f32&, f32&, f32&, bool&, bool&, f32&, bool&, bool&)(this, angle, rate, patience, localSpace, useSecond, angleSecond, farthestAngle, angleAdditive);
		}
		bool GetAndClearGotoRadius(f32& radius, f32& rate, f32& patience) { return SDK_CALL_FUNC(bool, 0x52A990, void*, f32&, f32&, f32&)(this, radius, rate, patience); }
		bool GetAndClearGotoRise(f32& rise, f32& rate, f32& patience) { return SDK_CALL_FUNC(bool, 0x52A9C0, void*, f32&, f32&, f32&)(this, rise, rate, patience); }
		void GetCamboneTransform(qMatrix44* m) { SDK_CALL_FUNC(void, 0x52AD20, void*, qMatrix44*)(this, m); }
		qSymbol GetContextOverride(int type) { return SDK_CALL_FUNC(qSymbol, 0x52BC20, void*, int)(this, type); }
		u32 GetContextOverrideFreemanNPC_ID(int type) { return SDK_CALL_FUNC(u32, 0x52C100, void*, int)(this, type); }
		u32 GetContextOverrideFreemanPlayer_ID(int type) { return SDK_CALL_FUNC(u32, 0x52C110, void*, int)(this, type); }
		void GetHeadTransform(qMatrix44* m) { SDK_CALL_FUNC(void, 0x52DCC0, void*, qMatrix44*)(this, m); }
		f32 GetLockedElevation(SrcTransform src) { return SDK_CALL_FUNC(f32, 0x3C3590, void*, SrcTransform)(this, src); }
		void GetPelvisTransform(qMatrix44* m) { SDK_CALL_FUNC(void, 0x52F450, void*, qMatrix44*)(this, m); }
		void GetRigidBodyPosition(qVector3& dest) { SDK_CALL_FUNC(void, 0x52FC40, void*, qVector3&)(this, dest); }
		SrcTransform GetTransformType(const qSymbol& tag) { return SDK_CALL_FUNC(SrcTransform, 0x530BB0, const qSymbol&)(tag); }
		void GetTransformTypeOrientation(qMatrix44& orientation, SrcTransform transType) { SDK_CALL_FUNC(void, 0x530FC0, void*, qMatrix44&, SrcTransform)(this, orientation, transType); }
		void GetTransformTypePosition(qVector3& pos, SrcTransform transType, bool antiJitter) { SDK_CALL_FUNC(void, 0x531870, void*, qVector3&, SrcTransform, bool)(this, pos, transType, antiJitter); }
		void GetTransformTypePosition(qVector4& pos, SrcTransform transType, bool antiJitter) { SDK_CALL_FUNC(void, 0x532260, void*, qVector4&, SrcTransform, bool)(this, pos, transType, antiJitter); }
		const qVector3& HeadPosition() { return SDK_CALL_FUNC(const qVector3&, 0x535A30, void*)(this); }
		bool IsActionHijacking() { return SDK_CALL_FUNC(bool, 0x539630, void*)(this); }
		bool IsAirborne() { return SDK_CALL_FUNC(bool, 0x539770, void*)(this); }
		bool IsCop() { return SDK_CALL_FUNC(bool, 0x53A000, void*)(this); }
		bool IsDowned() { return SDK_CALL_FUNC(bool, 0x53A160, void*)(this); }
		bool IsHostage() { return SDK_CALL_FUNC(bool, 0x53A920, void*)(this); }
		bool IsInVehicle() { return SDK_CALL_FUNC(bool, 0x53AA60, void*)(this); }
		bool IsJogging() { return SDK_CALL_FUNC(bool, 0x53B0A0, void*)(this); }
		bool IsOnGround() { return SDK_CALL_FUNC(bool, 0x53B240, void*)(this); }
		bool IsOverrideSymbolValid(const qSymbol& _override) { return SDK_CALL_FUNC(bool, 0x53B4C0, const qSymbol&)(_override); }
		void IsPlayer() { SDK_CALL_FUNC(void, 0x53B770, void*)(this); }
		bool IsWalking() { return SDK_CALL_FUNC(bool, 0x53C2F0, void*)(this); }
		const qVector3& PelvisPosition() { return SDK_CALL_FUNC(const qVector3&, 0x3C7D60, void*)(this); }
		void SetContextOverrideFreemanNPC(ActionContext* ac, int type, const qSymbol& override, u32 uid) {
			SDK_CALL_FUNC(void, 0x54BF80, void*, ActionContext*, int, const qSymbol&, u32)(this, ac, type, override, uid);
		}
		void SetContextOverrideFreemanPlayer(ActionContext* ac, int type, const qSymbol& override, u32 uid) {
			SDK_CALL_FUNC(void, 0x54BFA0, void*, ActionContext*, int, const qSymbol&, u32)(this, ac, type, override, uid);
		}
		void SetContextOverrideFreemanPlayerChoose(ActionContext* ac, int type, const qSymbol& left) {
			SDK_CALL_FUNC(void, 0x54C0B0, void*, ActionContext*, int, const qSymbol&)(this, ac, type, left);
		}
		void SetContextOverrideFreemanPlayerPOI(ActionContext* ac, SimObject* poiobj, int type, const qSymbol& override_left, const qSymbol& override_right) {
			SDK_CALL_FUNC(void, 0x54C3C0, void*, ActionContext*, SimObject*, int, const qSymbol&, const qSymbol&)(this, ac, poiobj, type, override_left, override_right);
		}
		void SetContextOverrideScriptGlobal(int type, const qSymbol& override) { SDK_CALL_FUNC(void, 0x54C590, void*, int, const qSymbol&)(this, type, override); }
		void SetContextOverrideScriptLocal(int type, const qSymbol& override) { SDK_CALL_FUNC(void, 0x54C610, void*, int, const qSymbol&)(this, type, override); }
		void SetElevationLock(bool lock) { SDK_CALL_FUNC(void, 0x54C830, void*, bool)(this, lock); }
		void SetGotoAngle(f32 angle, f32 rate, f32 patience, bool worldSpace, bool useSecond, f32 angleSecond, bool farthestAngle, bool angleAdditive) {
			SDK_CALL_FUNC(void, 0x54D330, void*, f32, f32, f32, bool, bool, f32, bool, bool)(this, angle, rate, patience, worldSpace, useSecond, angleSecond, farthestAngle, angleAdditive);
		}
		void SetGotoRadius(f32 radius, f32 rate, f32 patience) { SDK_CALL_FUNC(void, 0x54D390, void*, f32, f32, f32)(this, radius, rate, patience); }
		void SetGotoRise(f32 rise, f32 rate, f32 patience) { SDK_CALL_FUNC(void, 0x54D3B0, void*, f32, f32, f32)(this, rise, rate, patience); }
	};
	SDK_ASSERT_SIZEOF(CharacterSubjectComponent, 0x4E0);
}