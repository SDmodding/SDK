#pragma once

namespace UFG
{
	class CompositeDrawableComponent;

	class StreamedResourceComponent : public SimComponent
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

		UFG_INLINE void Constructor(SceneObjectProperties* p_SceneObject)
		{
			reinterpret_cast<void(__fastcall*)(void*, SceneObjectProperties*)>(UFG_RVA(0x4373B0))(this, p_SceneObject);
		}

		UFG_INLINE void Destructor()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x438000))(this);
		}

		UFG_INLINE qPropertySet* GetAssetPropertySet(qSymbol p_PropName)
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(void*, qSymbol*)>(UFG_RVA(0x43D0D0))(this, &p_PropName);
		}

		UFG_INLINE void BindAllModels(CompositeDrawableComponent* p_CompositeDrawable, bool p_UsingTempRig = false)
		{
			reinterpret_cast<void(__fastcall*)(void*, CompositeDrawableComponent*, bool)>(UFG_RVA(0x438DD0))(this, p_CompositeDrawable, p_UsingTempRig);
		}

		UFG_INLINE void UnbindAllModels(CompositeDrawableComponent* p_CompositeDrawable)
		{
			reinterpret_cast<void(__fastcall*)(void*, CompositeDrawableComponent*)>(UFG_RVA(0x4440F0))(this, p_CompositeDrawable);
		}

		UFG_INLINE void Update(float p_TimeDelta, qVector3* p_StreamPosition)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, qVector3*)>(UFG_RVA(0x444D00))(this, p_TimeDelta, p_StreamPosition);
		}

		UFG_INLINE void UpdateLoadState(SimObject* p_SimObject)
		{
			reinterpret_cast<void(__fastcall*)(void*, SimObject*)>(UFG_RVA(0x446130))(this, p_SimObject);
		}

		UFG_INLINE void IncrementPriorityReferenceCount(qSymbol p_Priority)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*)>(UFG_RVA(0x43DF90))(this, &p_Priority);
		}

		UFG_INLINE bool IsLoadActive()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x43F160))(this);
		}

		UFG_INLINE bool AreResourcesLoaded()
		{
			return reinterpret_cast<bool(__fastcall*)(void*)>(UFG_RVA(0x438CC0))(this);
		}
	}; typedef StreamedResourceComponent CStreamedResourceComponent;
}