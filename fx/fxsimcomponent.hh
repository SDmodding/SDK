#pragma once

namespace Render
{
	class FXComponentSettings {};

	enum eFXKillOption
	{
		FXKILLOPTION_DEFAULT,
		FXKILLOPTION_ERASE_EMITTED_OBJECTS
	};

	class FXSimComponent : public UFG::SimComponent, public UFG::qNode<FXSimComponent>
	{
	public:
		enum { _TypeUID = 0x32000001 };

		struct FxBinding : public UFG::qNode<FxBinding>
		{
		public:
			int mAttachJoint;
			UFG::TransformNodeComponent* mAttachTransform;
			UFG::qMatrix44* mAttachTransformOffset;
			u32 mEffectHandle;
			u32 mFXSettingsId;
			f32 mEndTime;
		};

		UFG::qList<FxBinding> mEffects;
		SkeletalPose* mPose;
		UFG::TransformNodeComponent* mXform;

		/* Functions */

		u32 AttachEffect(u32 effectId, int jointID, const UFG::qMatrix44* offset = 0, FXOverride* fxOverride = 0) { 
			return SDK_CALL_FUNC(u32, 0x1C78F0, void*, u32, int, const UFG::qMatrix44*, FXOverride*)(this, effectId, jointID, offset, fxOverride);
		}

		void DetachEffect(u32 fxHandle, eFXKillOption killOption = FXKILLOPTION_DEFAULT) { SDK_CALL_FUNC(void, 0x1CB150, void*, u32, eFXKillOption)(this, fxHandle, killOption); }
	};
	SDK_ASSERT_SIZEOF(FXSimComponent, 0x70);
}