#pragma once

namespace UFG
{
	class __declspec(align(16)) WorldContextComponent : public SimComponent, public qNode<WorldContextComponent>
	{
	public:
		enum { _TypeUID = 0xA6000001 };

		struct FocusHandleActionNode
		{
			qSafePointer<ParkourHandle> mFocusParkourHandle;
			ActionNode* mActionNode;
		};

		qMatrix44 mLatchTest;
		qMatrix44 mLatchContactPoint;
		qMatrix44 mWorldAnchor;
		bool mSyncFeet;
		bool mSyncLatchedHandle;
		int mSyncBoneIndex;
		bool mSyncPositionOnly;
		bool mSyncToClosestEndpoint;
		bool mSyncPlanar;
		bool mSyncXForward;
		bool mSyncLeftEdge;
		bool mSyncRightEdge;
		bool mLockSyncPosition;
		bool mSyncPositionLocked;
		f32 mDistanceFromEdge;
		f32 mBlendRate;
		f32 mBlendWeight;
		int mFocusLatchCount;
		qSafePointer<ParkourHandle> mFocusParkourHandle;
		qSafePointer<ParkourHandle> mParkourHandle;
		CoverCornerHandle mFocusCoverCornerHandle;
		CoverCornerHandle mLatchedCoverCornerHandle;
		CoverPosition* mpCoverPosition;
		bool mbSyncingCoverParkour;
		bool mbSyncingCoverLCorner;
		bool mbSyncingCoverRCorner;
		qList<Attachment> mAttachments;
		RebindingComponentHandle<CharacterPhysicsComponent> mCharacterPhysicsComponent;
		ActionNode* mToSwimming;
		RebindingComponentHandle<ActionTreeComponent> mActionTreeComponent;

		/* Static Functions */

		SDK_SINLINE qVector4 GetClosestAnchorOnLine(const qVector4& vSyncPosition, const qVector4& vHandleOrigin, const qVector3& vHandleAxis, f32 fSegmentLength, f32 fLeftConstraint, f32 fRightConstraint, bool syncToClosestEndpoint, bool syncPlanar)
		{
			qProxy<qVector4> res;
			return *SDK_CALL_FUNC(qVector4*, 0x52B2E0, qVector4*, const qVector4&, const qVector4&, const qVector3&, f32, f32, f32, bool, bool)(&res, vSyncPosition, vHandleOrigin, vHandleAxis, fSegmentLength, fLeftConstraint, fRightConstraint, syncToClosestEndpoint, syncPlanar);
		}

		/* Impl Functions */

		SDK_INLINE bool IsSyncing() { return mSyncLatchedHandle || mbSyncingCoverParkour || mbSyncingCoverLCorner || mbSyncingCoverRCorner; }

		/* Functions */

		void AttachTo(SimObject* simObject, TransformNodeComponent* transformNodeComponent, int attachmentBoneID, f32 blendIn, bool positionOnly, bool positionXY, bool useRubberBand) {
			SDK_CALL_FUNC(void, 0x5224E0, void*, SimObject*, TransformNodeComponent*, int, f32, bool, bool, bool)(this, simObject, transformNodeComponent, attachmentBoneID, blendIn, positionOnly, positionXY, useRubberBand);
		}

		void ClearLatchedParkourHandle() { SDK_CALL_FUNC(void, 0x522DB0, void*)(this); }

		void ConstrainSyncBoneWorldAnchorToLine(qMatrix44& newWorldAnchor, Creature* pCreature, int syncBoneIndex, const qVector4& vHandleOrigin, const qVector3& vHandleAxis, f32 fSegmentLength, f32 fLeftConstraint, f32 fRightConstraint, bool syncPositionOnly, bool syncForward, bool syncClosestEndPoint, bool syncPlanar) {
			SDK_CALL_FUNC(void, 0x523640, qMatrix44&, Creature*, int, const qVector4&, const qVector3&, f32, f32, f32, bool, bool, bool, bool)(newWorldAnchor, pCreature, syncBoneIndex, vHandleOrigin, vHandleAxis, fSegmentLength, fLeftConstraint, fRightConstraint, syncPositionOnly, syncForward, syncClosestEndPoint, syncPlanar);
		}

		void DetachAll() { SDK_CALL_FUNC(void, 0x5259A0, void*)(this); }

		void DetachFrom(SimObject* simObject, TransformNodeComponent* transformNodeComponent) {
			SDK_CALL_FUNC(void, 0x525A30, void*, SimObject*, TransformNodeComponent*)(this, simObject, transformNodeComponent);
		}

		void LatchFocusParkourHandle() { SDK_CALL_FUNC(void, 0x53C880, void*)(this); }
		void LatchParkourHandle(ParkourHandle* newHandle) { SDK_CALL_FUNC(void, 0x53C8D0, void*, ParkourHandle*)(this, newHandle); }
		void SetCoverPosition(CoverPosition* pPosition) { SDK_CALL_FUNC(void, 0x54C6A0, void*, CoverPosition*)(this, pPosition); }
		void SetFocusParkourHandle(ParkourHandle* newHandle, ActionNode* node) { SDK_CALL_FUNC(void, 0x54D1B0, void*, ParkourHandle*, ActionNode*)(this, newHandle, node); }

		void StartSync(int syncBoneIndex, bool positionOnly, bool syncToClosestEndpoint, bool planer, bool syncXforward, bool syncLeftEdge, bool syncRightEdge, f32 distanceFromEdge, f32 blendIn) {
			SDK_CALL_FUNC(void, 0x54FFB0, void*, int, bool, bool, bool, bool, bool, bool, f32, f32)(this, syncBoneIndex, positionOnly, syncToClosestEndpoint, planer, syncXforward, syncLeftEdge, syncRightEdge, distanceFromEdge, blendIn);
		}

		void StartSyncHandle(int syncBoneIndex, bool positionOnly, bool syncToClosestEndpoint, bool planer, bool syncXforward, bool syncLeftEdge, bool syncRightEdge, f32 distanceFromEdge, f32 blendIn) {
			SDK_CALL_FUNC(void, 0x550050, void*, int, bool, bool, bool, bool, bool, bool, f32, f32)(this, syncBoneIndex, positionOnly, syncToClosestEndpoint, planer, syncXforward, syncLeftEdge, syncRightEdge, distanceFromEdge, blendIn);
		}

		void StopSync() { SDK_CALL_FUNC(void, 0x5528C0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(WorldContextComponent, 0x270);
}