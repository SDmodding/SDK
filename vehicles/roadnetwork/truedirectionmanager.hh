#pragma once

namespace UFG
{
	class TrueDirectionManager
	{
	public:
		qVector3 mPathForward;
		u32 mEffectHash;
		u32 mEffectId;
		FX::SharedPointer<Render::FXOverride> mEffectOverride;
		qSafePointer<SimComponent, TransformNodeComponent> mEffectTransform;
		RoadNetworkLane* mCurrentLane;

		/* Functions */

		const char* GetEffectName() { return SDK_CALL_FUNC(const char*, 0x64DDA0, void*)(this); }
		void KillEffects() { SDK_CALL_FUNC(void, 0x652490, void*)(this); }
		void StartEffects() { SDK_CALL_FUNC(void, 0x65AE10, void*)(this); }
		void Update() { SDK_CALL_FUNC(void, 0x65F9C0, void*)(this); }
		void UpdateEffectFade() { SDK_CALL_FUNC(void, 0x661190, void*)(this); }
		void UpdateEffectLocation(RoadNetworkLane* roadLane) { SDK_CALL_FUNC(void, 0x661500, void*, RoadNetworkLane*)(this, roadLane); }
	};
}