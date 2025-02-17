#pragma once

namespace UFG
{
	struct HighlightParams
	{
		qColour mColour;
		f32 mOutlineStrength = 1.5f;
		f32 mXrayStrength = 0.f;
		bool mIsDepthEnabled = true;
	};

	class HighlightComponent : public SimComponent, public qNode<HighlightComponent>
	{
	public:
		enum { _TypeUID = 0x08000001 };

		HighlightParams mHighlightParams;
	};

	//---------------------------
	//	Functions
	//---------------------------

	SDK_INLINE void HighlightSimObject(SimObject* sim_object, const HighlightParams& highlight_params) {
		SDK_CALL_FUNC(void, 0x6E560, SimObject*, const HighlightParams&)(sim_object, highlight_params);
	}

	SDK_INLINE bool IsHighlightSimObject(SimObject* sim_object) { return SDK_CALL_FUNC(bool, 0x6E680, SimObject*)(sim_object); }

	SDK_INLINE void UnHighlightSimObject(SimObject* sim_object) { SDK_CALL_FUNC(void, 0x6EE30, SimObject*)(sim_object); }
}