#pragma once

namespace UFG
{
	class CoverObjectParkour;
	class CoverPosition;
	class CoverObjectGroup;

	class CoverObjectBase
	{
	public:
		struct CoverUser : qNode<CoverUser>
		{
			void* pCoverObject;
			SimObject* pUser;
		};

		int m_iRefCount;
		CoverObjectGroup* m_pCoverObjectGroup;
		f32 m_fPriority;

		/* Virtual Functions */

		virtual ~CoverObjectBase() = 0;
		virtual void Clear() = 0;
		virtual bool IsValid() = 0;
		virtual void _VFunc3() = 0;
		virtual bool IsPosition() = 0;
		virtual bool IsCorner() = 0;
		virtual bool IsParkour() = 0;
		virtual bool InRange2(const qVector3& vPosition, f32 fRange2) = 0;
		virtual bool FacesPosition(const qVector3& vPosition, f32 fTestAngle) = 0;
		virtual f32 GetAngleFromSweetSpot(const qVector3& vPosition) = 0;
		virtual bool IsConnectedTo(CoverObjectBase* coOther) = 0;
		virtual bool IsLeftOf(CoverObjectParkour* coOther) = 0;
		virtual CoverPosition* GetCoverPosition(const qVector3& vCharPos, CoverPosition* pCurrentPosition, f32 fRange) = 0;
		virtual bool GetCoverPositions(qArray<CoverPosition*>& aCoverPositions) = 0;
		virtual qVector3 GetPosition() = 0;
		virtual qVector3 GetSyncPos() = 0;
		virtual qVector3 GetFiringPosition(u32 index) = 0;
		virtual qVector3 GetFiringPosition() = 0;
		virtual u32 GetNumFiringPositions() = 0;
		virtual qVector3 GetSweetSpotDir() = 0;
		virtual qVector3 GetWallNormal() = 0;
		virtual void AddUser(SimObject* pUser) = 0;
		virtual void RemoveUser() = 0;
		virtual bool CanUse(SimObject* pUser) = 0;
		virtual CoverObjectGroup* GetCoverObjectGroup() = 0;
		virtual void SetCoverObjectGroup(CoverObjectGroup* coGroup) = 0;
		virtual bool operator==(CoverObjectBase* other) = 0;
		virtual bool IsAnyLineOrCornerShared(CoverObjectBase* pOther) = 0;
		virtual f32 GetHeight() = 0;
		virtual void UpdateTransforms() = 0;
		virtual bool GetInUse() = 0;
		virtual void SetInUse(bool bInUse) = 0;
	};
}