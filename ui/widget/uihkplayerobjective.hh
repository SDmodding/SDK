#pragma once

namespace UFG
{
	class UIHKPlayerObjective
	{
	public:
		qString titleCaption;
		qArray<u32> minimapBlips;
		qString gameSliceName;
		GameSlice::Type gameSliceType;
		qSafePointer<SimComponent, HudComponent> gpsTarget;
		bool useFixedPos;
		qVector3 fixedPos;
		qString alternateCaption;
		Objective* mObjective;

		/* Impl Functions */

		SDK_INLINE u32 GetDisplayPriority() { return mObjective ? mObjective->mDisplayPriority : 0; }
		SDK_INLINE Objective* GetObjective() { return mObjective; }

		/* Functions */

		SimObject* GetSimObject() { return SDK_CALL_FUNC(SimObject*, 0x5E9440, void*)(this); }
	};
}