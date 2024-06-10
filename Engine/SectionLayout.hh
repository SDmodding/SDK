#pragma once

namespace UFG
{
	class CTriggerEdge
	{
	public:
		qVector2 mEdgePosition;
		qVector2 mEdgeNormal;
	};

	class CTrigger
	{
	public:
		qVector2 mCenter;
		qVector2 mAABB[2];
		uint32_t mEdgeCount;
		qOffset64<CTriggerEdge> mEdges;
		char mName[32];
	};

	class CCellTriggerInstance
	{
	public:
		qOffset64<void*> mTrigger;
		uint32_t mCellVisIndexUnloadSTD;
		uint32_t mCellVisIndexUnloadLOD_SD;
		uint32_t mCellVisIndexUnloadLOD_HD;

		UFG_PAD(0xC);
	};

	class CZoneTrigger : public CTrigger
	{
	public:
		uint32_t mZoneIndexLoad;
		uint32_t mMagic0;
		uint32_t mMagic1;
		uint32_t mPad0;
	};

	class CZoneTriggerInstance
	{
	public:
		qOffset64<CZoneTrigger> mTrigger;
	};

	class CSection
	{
	public:
		uint32_t mUIDSection;
		uint16_t mFlags;
		uint16_t mVisIndex;
		uint16_t mCellIndex;
		uint16_t mLayerIndex;
		uint32_t mMagic0;
		char mName[32];
	};

	class CSectionVisCellEntry
	{
	public:
		uint32_t mCellIndex;
		uint32_t mLayerIndex;
	};

	class CSectionVis
	{
	public:
		uint32_t mSectionUID;
		uint16_t mHighLODSectionCount;
		uint16_t mLowLODSectionCount_SD;
		qOffset64<unsigned short> mHighLODSectionIndices;
		qOffset64<unsigned short> mLowLODSectionIndices_SD;
		uint16_t mSectionCellCount;
		uint16_t mCellTriggerInstanceCount;
		qOffset64<CSectionVisCellEntry> mSectionCellEntries;
		qOffset64<CCellTriggerInstance> mCellTriggerInstanceList;
		uint32_t mClusterVisibilityMask;
		uint16_t mZoneIndicesLoad[2];
		qOffset64<CZoneTriggerInstance> mZoneTriggerInstanceList;
		uint32_t mZoneTriggerInstanceCount;
		uint32_t mOriginalZoneMembership;
		uint32_t mLowLODSectionCount_HD;
		qOffset64<unsigned short> mLowLODSectionIndices_HD;
		uint32_t mPad0;
		uint32_t mPad1;
	};

	class CLayer
	{
	public:
		uint32_t mIndex;
		uint32_t mUID;
		uint32_t mActive;
		uint32_t mPad0;
		char mName[32];
	};

	class CSectionLayout : public qResourceData
	{
	public:
		uint32_t mSectionCount;
		qOffset64<CSection> mSections;
		uint32_t mSectionVisCount;
		qOffset64<CSectionVis> mSectionVis;
		uint32_t mLayerCount;
		qOffset64<CLayer> mLayers;
		uint32_t mOverrideCount;
		qOffset64<qOffset64<uint32_t>> mOverrides;

		static UFG_INLINE CSectionLayout* Instance()
		{
			return *reinterpret_cast<CSectionLayout**>(UFG_RVA(0x23A8DE8));
		}
	};
}