#pragma once

class PoseDriver : public Expression::IMemberMap, public UFG::qNode<PoseDriver>
{
public:
	RigInfo* mResourceOwner;
	bool mActive;
	bool mDisabled;
	bool mBreakpoint;
	UFG::qSymbolUC mName;

	/* Functions */

	SDK_INLINE bool IsActive() { return mActive; }
	SDK_INLINE bool IsDisabled() { return mDisabled; }
	SDK_INLINE void SetActive(bool tf) { mActive = tf; }
};