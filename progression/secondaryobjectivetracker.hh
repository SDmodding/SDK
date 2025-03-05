#pragma once

namespace UFG
{
	class SecondaryObjective
	{
	public:
		enum eID
		{
			ID_COP_OBJECTIVE,
			ID_TRIAD_OBJECTIVE,
			NUM_OBJECTIVE_IDS
		};

		enum eStatus
		{
			STATUS_INACTIVE,
			STATUS_ACTIVE,
			STATUS_HIGHLIGHT,
			STATUS_COMPLETED,
			STATUS_FAILED
		};

		eStatus mStatus;
		qString mCaption;
		u32 mProgress;
		u32 mMaxProgress;
	};

	class SecondaryObjectiveTracker
	{
	public:
		SecondaryObjective mObjectives[SecondaryObjective::NUM_OBJECTIVE_IDS];

		/* Static Functions */

		SDK_SINLINE SecondaryObjectiveTracker* Instance() { return SDK_VAR(SecondaryObjectiveTracker*, 0x240A330); }

		/* Impl Functions */

		SDK_INLINE SecondaryObjective* GetObjective(SecondaryObjective::eID uid) { return &mObjectives[uid]; }

		/* Functions */

		void AddObjective(SecondaryObjective::eID uid, const char* caption, u32 progress, u32 maxProgress) {
			SDK_CALL_FUNC(void, 0x493830, void*, SecondaryObjective::eID, const char*, u32, u32)(this, uid, caption, progress, maxProgress);
		}

		void RemoveObjective(SecondaryObjective::eID uid) { SDK_CALL_FUNC(void, 0x4B64D0, void*, SecondaryObjective::eID)(this, uid); }

		void UpdateCaption(SecondaryObjective::eID uid, const char* caption, u32 progress, u32 maxProgress) {
			SDK_CALL_FUNC(void, 0x4C5960, void*, SecondaryObjective::eID, const char*, u32, u32)(this, uid, caption, progress, maxProgress);
		}

		void UpdateStatus(SecondaryObjective::eID uid, SecondaryObjective::eStatus status) { 
			SDK_CALL_FUNC(void, 0x4C8A20, void*, SecondaryObjective::eID, SecondaryObjective::eStatus)(this, uid, status);
		}
	};
}