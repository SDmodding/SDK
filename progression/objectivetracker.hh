#pragma once

namespace UFG
{
	class ObjectiveIndicator : public qNodeRB<ObjectiveIndicator>
	{
	public:
		qSymbol mIdentifier;
		qSharedString mBlipType;
		qSafePointer<TransformNodeComponent> mpEffectTransform;
		int mCoronaType;
		u32 mEffectId;
		bool mEnabled;
		bool mTemporary;

		virtual ~ObjectiveIndicator() = 0;

		void SetEnabled(bool enabled) { SDK_CALL_FUNC(void, 0x4BC1A0, void*, bool)(this, enabled); }
	};
}