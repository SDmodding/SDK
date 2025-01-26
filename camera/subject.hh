#pragma once

namespace UFG
{
	class CameraSubject : public SimComponent
	{
	public:
		enum { _TypeUID = 0x68000001 };

		enum PinOrientMode
		{
			PinOrientMode_Current,
			PinOrientMode_Velocity
		};

		struct UpdateParams
		{
			f32 mPinPosRate;
			f32 mUnpinPosRate;
			f32 mPinRotRate;
			f32 mUnpinRotRate;
		};

		bool bPinnedPosition;
		f32 mPinPosParam;
		qVector4 mPinPos;
		bool bPinnedOrientation;
		f32 mPinOrientParam;
		qQuaternion mPinOrient;
		qMatrix44 mLocalWorld;
		qMatrix44 mWorldLocal;
		RebindingComponentHandle<TransformNodeComponent> pTransformNodeComponent;

		/* Virtual Functions */

		virtual const qVector3& GetUp() = 0;
		virtual const qVector3& GetLeft() = 0;
		virtual const qVector3& GetForward() = 0;
		virtual const qVector3& GetPosition() = 0;
		virtual const qMatrix44& GetLocalWorld() = 0;
		virtual void _UnkVFunc19() = 0;
		virtual const qVector3& GetVelocity() = 0;
		virtual float GetRadius() = 0;
		virtual float GetHeight() = 0;
		virtual const qVector3& GetBoxMin() = 0;
		virtual const qVector3& GetBoxMax() = 0;
		virtual void _UnkVFunc25() = 0;
		virtual void _UnkVFunc26() = 0;
		virtual void _UnkVFunc27() = 0;
		virtual float GetSpeed() = 0;
		virtual bool ShouldHide() = 0;
		virtual void _UnkVFunc30() = 0;
		virtual void _UnkVFunc31() = 0;
		virtual void _UnkVFunc32() = 0;
		virtual void _UnkVFunc33() = 0;
		virtual void _UnkVFunc34() = 0;
		virtual void _UnkVFunc35() = 0;
		virtual void _UnkVFunc36() = 0;
		virtual void _UnkVFunc37() = 0;
		virtual void _UnkVFunc38() = 0;
		virtual void _UnkVFunc39() = 0;
		virtual void _UnkVFunc40() = 0;
		virtual void _UnkVFunc41() = 0;
		virtual void _UnkVFunc42() = 0;
		virtual void _UnkVFunc43() = 0;
		virtual void _UnkVFunc44() = 0;
		virtual void _UnkVFunc45() = 0;
		virtual void _UnkVFunc46() = 0;
		virtual void _UnkVFunc47() = 0;
		virtual void _UnkVFunc48() = 0;
	};
	SDK_ASSERT_SIZEOF(CameraSubject, 0x120);
}