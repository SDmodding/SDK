#pragma once

namespace UFG
{
	class GroupFollower
	{
	public:
		qSafePointer<GroupComponent> mLeader;

		virtual ~GroupFollower() = 0;
	};

	class GroupLeader
	{
	public:
		qFixedArray<qSafePointer<GroupComponent>, 4> mFollowers;
		PedFormationProfile* mFormationProfile;

		virtual ~GroupLeader() = 0;
	};

	class GroupComponent : public SimComponent, public UpdateInterface, public qSafePointerNode<GroupComponent>, public qNode<GroupComponent>
	{
	public:
		enum { _TypeUID = 0x50000001 };

		enum Flags
		{
			Flags_Is_Allowed_To_Join_Groups = 1,
			Flags_Default = Flags_Is_Allowed_To_Join_Groups
		};

		qProxy<GroupLeader> mGroupLeader;
		qProxy<GroupFollower> mGroupFollower;
		PedSpawningInfo* mOwner;
		u32 mFlags;

		/* Static Functions */

		SDK_SINLINE GroupComponent* GetGroupComponent(SimObject* pSimObject) { return SDK_CALL_FUNC(GroupComponent*, 0x35FD10, SimObject*)(pSimObject); }

		SDK_SINLINE bool IsFollower(SimObject* pSimObject) { return SDK_CALL_FUNC(bool, 0x36A9F0, SimObject*)(pSimObject); }
		SDK_SINLINE bool IsGroupMember(SimObject* pSimObject) { return SDK_CALL_FUNC(bool, 0x36AA50, SimObject*)(pSimObject); }
		SDK_SINLINE bool IsLeader(SimObject* pSimObject) { return SDK_CALL_FUNC(bool, 0x36B4F0, SimObject*)(pSimObject); }

		SDK_SINLINE bool JoinGroup(SimObject* pLeaderSim, SimObject* pFollowerSim, PedFormationProfile* pFormation) {
			return SDK_CALL_FUNC(bool, 0x36C920, SimObject*, SimObject*, PedFormationProfile*)(pLeaderSim, pFollowerSim, pFormation);
		}

		SDK_SINLINE void LeaveGroup(SimObject* pSimObject) { SDK_CALL_FUNC(void, 0x36D2B0, SimObject*)(pSimObject); }

		/* Impl Functions */

		SDK_INLINE bool IsFollower() { return !GetLeader(); }
		SDK_INLINE bool IsLeader() { return mGroupLeader->mFormationProfile && mGroupLeader->mFollowers.size; }

		SDK_INLINE GroupComponent* GetFollower(u32 index) { return mGroupLeader->mFollowers[index].Get(); }
		SDK_INLINE GroupComponent* GetLeader() { return mGroupFollower->mLeader.Get(); }

		SDK_INLINE GroupComponent* GetSharedGroupComponent() 
		{
			if (auto leader = GetLeader()) {
				return leader;
			}
			return this;
		}

		SDK_INLINE SimObject* GetSimObjectPtr() { return (mOwner ? mOwner->mSimObjectPtr.m_pPointer : 0); }

		SDK_INLINE u32 GetGroupSize() 
		{
			if (auto leader = GetLeader()) {
				return leader->mGroupLeader->mFollowers.size + 1;
			}
			return 1;
		}

		SDK_INLINE void SetOwner(PedSpawningInfo* pOwner) { mOwner = pOwner; }

		/* Functions */

		bool GetDefaultFollowerPosition(qVector3& followerPosition) { return SDK_CALL_FUNC(bool, 0x35D680, void*, qVector3&)(this, followerPosition); }

		qVector3 GetPosition()
		{
			qProxy<qVector3> res;
			return *SDK_CALL_FUNC(qVector3*, 0x3620D0, void*, qVector3*)(this, &res);
		}

		bool IsFormationFull() { return SDK_CALL_FUNC(bool, 0x36AA20, void*)(this); }
		bool IsInGroup(GroupComponent* pGroupComponent) { return SDK_CALL_FUNC(bool, 0x36AD80, void*, GroupComponent*)(this, pGroupComponent); }

		bool JoinExistingGroup(GroupComponent& leader, PedFormationProfile* pFormation) {
			return SDK_CALL_FUNC(bool, 0x36C8A0, void*, GroupComponent&, PedFormationProfile*)(this, leader, pFormation);
		}

		bool JoinNewGroup(GroupComponent& leader, PedFormationProfile* pFormation) { return SDK_CALL_FUNC(bool, 0x36D150, void*, GroupComponent&, PedFormationProfile*)(this, leader, pFormation); }
		void MakeSingle(bool isAllowedToJoinGroups) { SDK_CALL_FUNC(void, 0x36D900, void*, bool)(this, isAllowedToJoinGroups); }
		void Reset() { SDK_CALL_FUNC(void, 0x382A10, void*)(this); }
		void SetFormationProfile(PedFormationProfile* pProfile) { SDK_CALL_FUNC(void, 0x386550, void*, PedFormationProfile*)(this, pProfile); }
		void UnregisterFarFollowers(f32 distanceSqr) { SDK_CALL_FUNC(void, 0x38A5F0, void*, f32)(this, distanceSqr); }
	};
}