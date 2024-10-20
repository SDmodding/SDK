#pragma once

namespace UFG
{
	class TransformNodeComponent : public SimComponent, public qNode<TransformNodeComponent>
	{
	public:
		enum eInheritXformType : int
		{
			eInheritXform_Full,
			eInheritXform_Translation
		};

		qList<TransformNodeComponent> mChildren;
		u32 mChangeID;
		TransformNodeComponent* mParent;
		int mChanged;
		__declspec(align(16)) qMatrix44 mWorldTransform;
		qMatrix44 mLocalTransform;
		qVector3 mWorldVelocity;
		eInheritXformType mInheritXformType;

		/* Functions */

		void SetLocalTransform(const qMatrix44& m) { reinterpret_cast<void(SDK_CALL*)(void*, const qMatrix44&)>(SDK_RVA(0x191250))(this, m); }
		void SetLocalTranslation(const qVector3& pos) { reinterpret_cast<void(SDK_CALL*)(void*, const qVector3&)>(SDK_RVA(0x1912E0))(this, pos); }
		void SetParent(TransformNodeComponent* new_parent, eInheritXformType inheritXformType) { 
			reinterpret_cast<void(SDK_CALL*)(void*, TransformNodeComponent*, eInheritXformType)>(SDK_RVA(0x191370))(this, new_parent, inheritXformType);
		}
		void SetParentKeepWorld(TransformNodeComponent* new_parent, eInheritXformType inheritXformType) {
			reinterpret_cast<void(SDK_CALL*)(void*, TransformNodeComponent*, eInheritXformType)>(SDK_RVA(0x1913D0))(this, new_parent, inheritXformType);
		}
		void SetWorldTransform(const qMatrix44& m) { reinterpret_cast<void(SDK_CALL*)(void*, const qMatrix44&)>(SDK_RVA(0x1914B0))(this, m); }
		void SetWorldTranslation(const qVector3& pos) { reinterpret_cast<void(SDK_CALL*)(void*, const qVector3&)>(SDK_RVA(0x191520))(this, pos); }
		void UpdateWorldTransform() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x191D60))(this); }
	};
	SDK_ASSERT_SIZEOF(TransformNodeComponent, 0x110);
}