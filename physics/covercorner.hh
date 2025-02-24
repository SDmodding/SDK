#pragma once

namespace UFG
{
	class CoverCorner : public GridIntrusiveNode<CoverCorner>
	{
	public:
		enum CoverSideEnum
		{
			CS_Left,
			CS_Right
		};

		qVector3 m_vCornerPosition;
		qVector2 m_vWallNormal;
		qEnum<CoverSideEnum, u8> m_eCoverSide;
		bool m_Latch;
		bool m_IsInUse;
		bool m_IsDynamic;
		f32 m_fWallHeight;

		/* Functions */

		qVector3 GetAlongWall() const
		{
			qProxy<qVector3> res;
			return *SDK_CALL_FUNC(qVector3*, 0x466080, const void*, qVector3*)(this, &res);
		}

		qVector3 GetFiringPos() const
		{
			qProxy<qVector3> res;
			return *SDK_CALL_FUNC(qVector3*, 0x466730, const void*, qVector3*)(this, &res);
		}

		qVector3 GetSweetSpotDir() const
		{
			qProxy<qVector3> res;
			return *SDK_CALL_FUNC(qVector3*, 0x467B60, const void*, qVector3*)(this, &res);
		}

		void GetSyncMatrix(qMatrix44& outMatrix) const { SDK_CALL_FUNC(void, 0x467BE0, const void*, qMatrix44&)(this, outMatrix); }

		qVector3 GetSyncPos() const
		{
			qProxy<qVector3> res;
			return *SDK_CALL_FUNC(qVector3*, 0x467E40, const void*, qVector3*)(this, &res);
		}
	};

	class DynamicCoverCorner : public qSafePointerNode<DynamicCoverCorner>, public CoverCorner
	{
	public:
		qSafePointer<DynamicCoverComponent> m_pParentInstance;
		u32 m_uGroupIndex;
	};
}