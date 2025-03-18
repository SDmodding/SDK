#pragma once

namespace UFG
{
	class TriggerEdge
	{
	public:
		qVector2 mEdgePosition;
		qVector2 mEdgeNormal;
	};

	class Trigger
	{
	public:
		qVector2 mCenter;
		qVector2 mAABB[2];
		u32 mEdgeCount;
		qOffset64<TriggerEdge*> mEdges;
		char mName[32];
	};

	class ZoneTrigger : public Trigger
	{
	public:
		u32 mZoneIndexLoad;
		u32 mMagic0;
		u32 mMagic1;
		u32 mPad0;
	};

	class CellTriggerInstance
	{
	public:
		qOffset64<CellTrigger*> mTrigger;
		u32 mCellVisIndexUnloadSTD;
		u32 mCellVisIndexUnloadLOD_SD;
		u32 mCellVisIndexUnloadLOD_HD;
		u32 mPad[3];
	};

	class Layer
	{
	public:
		u32 mIndex;
		u32 mUID;
		u32 mActive;
		u32 mPad0;
		char mName[32];
	};

	class Override
	{
	public:
		enum TYPE
		{
			NO_LOOKAHEAD,
			ZONE_USAGE,
			SELF_CONTAINED_ZONE,
			CELL_ZONE
		};

		u32 mType;
	};

	class Section
	{
	public:
		u32 mUIDSection;
		u16 mFlags;
		u16 mVisIndex;
		u16 mCellIndex;
		u16 mLayerIndex;
		u32 mMagic0;
		char mName[32];
	};

	class SectionVisCellEntry
	{
	public:
		u32 mCellIndex;
		u32 mLayerIndex;
	};

	class ZoneTriggerInstance
	{
	public:
		qOffset64<ZoneTrigger*> mTrigger;
	};

	class SectionVis
	{
	public:
		u32 mSectionUID;
		u16 mHighLODSectionCount;
		u16 mLowLODSectionCount_SD;
		qOffset64<u16*> mHighLODSectionIndices;
		qOffset64<u16*> mLowLODSectionIndices_SD;
		u16 mSectionCellCount;
		u16 mCellTriggerInstanceCount;
		qOffset64<SectionVisCellEntry*> mSectionCellEntries;
		qOffset64<CellTriggerInstance*> mCellTriggerInstanceList;
		u32 mClusterVisibilityMask;
		u16 mZoneIndicesLoad[2];
		qOffset64<ZoneTriggerInstance*> mZoneTriggerInstanceList;
		u32 mZoneTriggerInstanceCount;
		u32 mOriginalZoneMembership;
		u32 mLowLODSectionCount_HD;
		qOffset64<u16*> mLowLODSectionIndices_HD;
		u32 mPad0;
		u32 mPad1;
	};
}

namespace UFG
{
	class SectionLayout : public qResourceData
	{
	public:
		u32 mSectionCount;
		qOffset64<Section*> mSections;
		u32 mSectionVisCount;
		qOffset64<SectionVis*> mSectionVis;
		u32 mLayerCount;
		qOffset64<Layer*> mLayers;
		u32 mOverrideCount;
		qOffset64<qOffset64<Override*>*> mOverrides;

		/* Static Impl Functions */

		SDK_SINLINE u32 GetLayerCount() { return Instance()->mLayerCount; }

		/* Static Functions */

		SDK_SINLINE SectionLayout* Instance() { return SDK_VAR_GET(SectionLayout*, 0x23A8DE8); }

		SDK_SINLINE u32 GetHighLODSectionVisIndices(u32 visIndex, u32* outputBuffer, u32 outputBufferSize) {
			return SDK_CALL_FUNC(u32, 0x232870, u32, u32*, u32)(visIndex, outputBuffer, outputBufferSize);
		}

		SDK_SINLINE u32 GetLayerIndex(const char* layer_name) { return SDK_CALL_FUNC(u32, 0x232910, const char*)(layer_name); }
		SDK_SINLINE const char* GetLayerName(u32 layer_index) { return SDK_CALL_FUNC(const char*, 0x2329A0, u32)(layer_index); }

		SDK_SINLINE u32 GetLowLODSectionVisIndices(u32 visIndex, u32* outputBuffer, u32 outputBufferSize) {
			return SDK_CALL_FUNC(u32, 0x2329E0, u32, u32*, u32)(visIndex, outputBuffer, outputBufferSize);
		}

		SDK_SINLINE u32 GetLowLODSectionVisIndices_HD(u32 visIndex, u32* outputBuffer, u32 outputBufferSize) {
			return SDK_CALL_FUNC(u32, 0x232A70, u32, u32*, u32)(visIndex, outputBuffer, outputBufferSize);
		}

		SDK_SINLINE Section* GetSectionFromCellIndex(u32 sectionIndex) { return SDK_CALL_FUNC(Section*, 0x232B70, u32)(sectionIndex); }
		SDK_SINLINE const char* GetSectionNameFromCellIndex(u32 sectionIndex) { return SDK_CALL_FUNC(const char*, 0x232BB0, u32)(sectionIndex); }

		SDK_SINLINE u32 GetSectionUIDFromIndex(u32 cell_index) { return SDK_CALL_FUNC(u32, 0x232BE0, u32)(cell_index); }

		SDK_SINLINE bool IsLookaheadAllowed(u32 visIndexFrom, u32 visIndexTo) { return SDK_CALL_FUNC(bool, 0x233200, u32, u32)(visIndexFrom, visIndexTo); }

		SDK_SINLINE bool SetLayerActive(const char* layer_name, bool active) { return SDK_CALL_FUNC(bool, 0x2350F0, const char*, bool)(layer_name, active); }
		SDK_SINLINE bool SetLayerActive(u32 layer_index, bool active) { return SDK_CALL_FUNC(bool, 0x2350A0, u32, bool)(layer_index, active); }

		/* Function */

		void BuildLayerTweakers() { SDK_CALL_FUNC(void, 0x230A20)(); }

		u16 GetFlags(u32 sectionIndex) { return SDK_CALL_FUNC(u16, 0x232840, u32)(sectionIndex); }
	};
}