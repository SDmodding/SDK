#pragma once

// Move this to appropriate file.
namespace UFG
{
	enum SCENERY_LAYER
	{
		SCENERY_LAYER_NONE,
		SCENERY_LAYER_LOW,
		SCENERY_LAYER_STD,
		SCENERY_LAYER_FAR,
		SCENERY_LAYER_LOW_D,
		SCENERY_LAYER_COUNT
	};
}

namespace UFG
{
	class SectionChooser
	{
	public:
		enum LOD_SUPRESSION
		{
			SUPRESS_NONE,
			SUPRESS_ISLAND,
			SUPRESS_ISLAND_AND_LOW
		};


		class Lookahead
		{
		public:
			bool mEnabled;
			qVector3 mViewerPosition;
			qVector3 mViewerDirection;
			qVector3 mViewerVelocity;
			qVector3 mCurrentLookaheadPos;
			f32 mCurrentLookaheadDistance;

			virtual void Process(const qVector3& viewerPosition, const qVector3& _viewerDirection, const qVector3& _viewerCameraDirection, const qVector3& _viewerVelocity, f32 deltaTime, bool enabled) = 0;
			virtual void DebugDraw(Render::View* view) = 0;
		};

		/* Static Impl Functions */

		SDK_SINLINE BSP* GetBSP() { return SDK_VAR_GET(BSP*, 0x23A8D78); }
		SDK_SINLINE u32 GetCurrentSectionIndex() { return SDK_VAR_GET(u32, 0x2043520); }
		SDK_SINLINE void SetLookahead(Lookahead* look_ahead) { SDK_VAR_GET(Lookahead*, 0x23A8DA0) = look_ahead; }
		SDK_SINLINE void SetToStreamGameplayFromWorldBigFile(bool streamGameplayFromWorldBigFile) { SDK_VAR_GET(bool, 0x2043524) = streamGameplayFromWorldBigFile; }

		/* Static Functions */

		SDK_SINLINE void AddPOV(const qVector3& position, const qVector3& direction, const qVector3& camera_direction, const qVector3& velocity, f32 deltaTime, SimObject* simObject, u32 flags, bool is_ingame) {
			SDK_CALL_FUNC(void, 0x230320, const qVector3&, const qVector3&, const qVector3&, const qVector3&, f32, SimObject*, u32, bool)(position, direction, camera_direction, velocity, deltaTime, simObject, flags, is_ingame);
		}

		SDK_SINLINE bool AreAnyLoadsPending() { return SDK_CALL_FUNC(bool, 0x230920)(); }

		SDK_SINLINE void BeginFlush(bool emptyCache) { SDK_CALL_FUNC(void, 0x2309A0, bool)(emptyCache); }

		SDK_SINLINE void CalculateVisibleSectionIndices(u32 baseSectionIndex, u32 currentSectionIndex, bool keepCurrentlyLoadedAltLayers) {
			SDK_CALL_FUNC(void, 0x230AA0, u32, u32, bool)(baseSectionIndex, currentSectionIndex, keepCurrentlyLoadedAltLayers);
		}

		SDK_SINLINE void Destroy() { SDK_CALL_FUNC(void, 0x230ED0)(); }

		SDK_SINLINE void EnableStreamingLookahead(bool enable) { SDK_CALL_FUNC(void, 0x2315A0, bool)(enable); }

		SDK_SINLINE void EnableStreamsUpdate(bool enable) { SDK_CALL_FUNC(void, 0x2315B0, bool)(enable); }

		SDK_SINLINE void FlushAltLayer(const char* layer_name, bool layer_enabled) { SDK_CALL_FUNC(void, 0x2316D0, const char*, bool)(layer_name, layer_enabled); }


		SDK_SINLINE u32 GetBytesRemainingToLoad() { return SDK_CALL_FUNC(u32, 0x2323A0)(); }

		SDK_SINLINE u32 GetCellIndexAtPosition(const qVector3& position, bool dbg_print_serials) { return SDK_CALL_FUNC(u32, 0x232460, const qVector3&, bool)(position, dbg_print_serials); }

		SDK_SINLINE u32 GetCellToLoadFromVisIndex(u32 vis_index, bool keep_currently_loaded_alt_layers) {
			return SDK_CALL_FUNC(u32, 0x2324A0, u32, bool)(vis_index, keep_currently_loaded_alt_layers);
		}

		SDK_SINLINE void GetFilenameForSectionIndex(u32 sectionIndex, qString& fileName, SCENERY_LAYER eLODLevel) {
			SDK_CALL_FUNC(void, 0x2326B0, u32, qString&, SCENERY_LAYER)(sectionIndex, fileName, eLODLevel);
		}

		SDK_SINLINE bool GetMIDStreamingStateForSectionIndex(u32 section_index) { return SDK_CALL_FUNC(bool, 0x232AF0, u32)(section_index); }

		SDK_SINLINE bool GetSTDStreamingStateForSectionIndex(u32 section_index) { return SDK_CALL_FUNC(bool, 0x232B40, u32)(section_index); }

		SDK_SINLINE const qVector3& GetViewerPosition() { return SDK_CALL_FUNC(const qVector3&, 0x232E80)(); }

		SDK_SINLINE u32 GetVisIndexAtPosition(const qVector3& position, bool dbg_print_serials) { return SDK_CALL_FUNC(u32, 0x232E90, const qVector3&, bool)(position, dbg_print_serials); }
	
		SDK_SINLINE void HandleFlush() { SDK_CALL_FUNC(void, 0x232ED0)(); }

		SDK_SINLINE bool Initialize(const char* worldName) { return SDK_CALL_FUNC(bool, 0x2330D0, const char*)(worldName); }

		SDK_SINLINE bool IsSectionVisible_CellIndex(u32 sectionIndex, SCENERY_LAYER eLodLevel, bool bConsiderVisibleOnlyAfterDelay) {
			return SDK_CALL_FUNC(bool, 0x2332A0, u32, SCENERY_LAYER, bool)(sectionIndex, eLodLevel, bConsiderVisibleOnlyAfterDelay);
		}

		SDK_SINLINE bool IsSectionVisible_VisIndex(u32 visIndex, SCENERY_LAYER eLodLevel, bool bConsiderVisibleOnlyAfterDelay) {
			return SDK_CALL_FUNC(bool, 0x233340, u32, SCENERY_LAYER, bool)(visIndex, eLodLevel, bConsiderVisibleOnlyAfterDelay);
		}

		SDK_SINLINE bool LineInsideTriggerHull(CellTrigger* trigger, const qVector3& _start_position, const qVector3& _end_position, const qVector3& clippedPos) {
			return SDK_CALL_FUNC(bool, 0x233410, CellTrigger*, const qVector3&, const qVector3&, const qVector3&)(trigger, _start_position, _end_position, clippedPos);
		}

		SDK_SINLINE void LoadGlobalCell(bool enabled) { SDK_CALL_FUNC(void, 0x233810, bool)(enabled); }

		SDK_SINLINE void ModifyLookaheadForStickyTriggers(u32 _vis_index_current_section, u32 _vis_index_lookahead_section, const qVector3& viewerPosition, const qVector3& currentLookaheadPos) {
			SDK_CALL_FUNC(void, 0x233AA0, u32, u32, const qVector3&, const qVector3&)(_vis_index_current_section, _vis_index_lookahead_section, viewerPosition, currentLookaheadPos);
		}

		SDK_SINLINE void ModifyVisibliltyFromTriggersForPosition(const qVector3& pov_position, const qVector3& lookahead_position, u32 _pov_section_index, u32 _lookahead_section_index, u32& STDSectionCount, u32* STDVisIndices, u32& LODSectionCount, u32* LODVisIndices) {
			SDK_CALL_FUNC(void, 0x233BD0, const qVector3&, const qVector3&, u32, u32, u32&, u32*, u32&, u32*)(pov_position, lookahead_position, _pov_section_index, _lookahead_section_index, STDSectionCount, STDVisIndices, LODSectionCount, LODVisIndices);
		}

		SDK_SINLINE u32 ModifyZonesFromTriggersForPosition(const qVector3& position, u32 vis_index_chooser_section, u32 zoneCount, u32* mZoneIndices) {
			return SDK_CALL_FUNC(u32, 0x233EC0, const qVector3&, u32, u32, u32*)(position, vis_index_chooser_section, zoneCount, mZoneIndices);
		}

		SDK_SINLINE bool QueueSectionLoad(u32 globalSectionIndex, SCENERY_LAYER eLODLevel) { return SDK_CALL_FUNC(bool, 0x234890, u32, SCENERY_LAYER)(globalSectionIndex, eLODLevel); }

		SDK_SINLINE bool QueueZoneLoad(u32 globalZoneIndex) { return SDK_CALL_FUNC(bool, 0x234B70, u32)(globalZoneIndex); }

		SDK_SINLINE void SetSuppressLOD(LOD_SUPRESSION eSuppressLOD) { SDK_CALL_FUNC(void, 0x235170, LOD_SUPRESSION)(eSuppressLOD); }

		SDK_SINLINE void UpdateStreams(bool bFadeout) { SDK_CALL_FUNC(void, 0x235B90, bool)(bFadeout); }
	};
}