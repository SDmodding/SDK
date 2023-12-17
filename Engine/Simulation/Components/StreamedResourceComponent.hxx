#pragma once

namespace UFG
{
	class CCompositeDrawableComponent;

	class CStreamedResourceComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x4C8);

		bool mPartsBound;
		bool mFirstResourceLoad;
		qColour mColourTints[16];
		qSymbol mActivePriority;
		qPropertySet* mPropertySet;
		uint32_t mSpawnPriorityReferenceCount[4];
		float mCameraDistance;
		eSimObjectTypeEnum mSimObjectType;

		__inline void Constructor(CSceneObjectProperties* p_SceneObject)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSceneObjectProperties*)>(UFG_RVA(0x4373B0))(this, p_SceneObject);
		}

		__inline void Destructor()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x438000))(this);
		}

		__inline qPropertySet* GetAssetPropertySet(qSymbol p_PropName)
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(void*, qSymbol*)>(UFG_RVA(0x43D0D0))(this, &p_PropName);
		}

		__inline void BindAllModels(CCompositeDrawableComponent* p_CompositeDrawable, bool p_UsingTempRig = false)
		{
			reinterpret_cast<void(__fastcall*)(void*, CCompositeDrawableComponent*, bool)>(UFG_RVA(0x438DD0))(this, p_CompositeDrawable, p_UsingTempRig);
		}

		__inline void UnbindAllModels(CCompositeDrawableComponent* p_CompositeDrawable)
		{
			reinterpret_cast<void(__fastcall*)(void*, CCompositeDrawableComponent*)>(UFG_RVA(0x4440F0))(this, p_CompositeDrawable);
		}

		__inline void Update(float p_TimeDelta, qVector3* p_StreamPosition)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, qVector3*)>(UFG_RVA(0x444D00))(this, p_TimeDelta, p_StreamPosition);
		}

		__inline void UpdateLoadState(CSimObject* p_SimObject)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimObject*)>(UFG_RVA(0x446130))(this, p_SimObject);
		}

		__inline void IncrementPriorityReferenceCount(qSymbol p_Priority)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*)>(UFG_RVA(0x43DF90))(this, &p_Priority);
		}

		__inline bool IsLoadActive()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x43F160))(this);
		}

		__inline bool AreResourcesLoaded()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x438CC0))(this);
		}
	};
}