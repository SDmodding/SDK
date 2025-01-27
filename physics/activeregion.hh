#pragma once

namespace UFG
{
	class ActiveRegion : public qNode<ActiveRegion>
	{
	public:
		hkVector4f mExtents;
		hkAabb mAabb;
	};

	class ActiveRegionManager
	{
	public:
		qList<ActiveRegion> mRegions;
		u32 mCurrentMode;
		qArray<qString> mNames;
		hkArray<hkVector4f> mExtents;

		/* Functions */

		hkVector4f GetCentre() { return SDK_CALL_FUNC(hkVector4f, 0xA96F0, void*)(this); }
		bool IsInActiveRegion(const hkVector4f& p) { return SDK_CALL_FUNC(bool, 0xACC90, void*, const hkVector4f&)(this, p); }
		void SetCentre(const hkVector4f& centre) { SDK_CALL_FUNC(void, 0xB0650, void*, const hkVector4f&)(this, centre); }
		void SetMode(int mode) { SDK_CALL_FUNC(void, 0xB1400, void*, int)(this, mode); }
		void SetModeFromSymbol(const qSymbol& name) { SDK_CALL_FUNC(void, 0xB1440, void*, const qSymbol&)(this, name); }
	};
}