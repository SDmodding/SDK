#pragma once

namespace UFG
{
	class CObjectResourceManager
	{
	public:
		static UFG_INLINE CObjectResourceManager* Instance() 
		{ 
			return *reinterpret_cast<CObjectResourceManager**>(UFG_RVA(0x24015E8)); 
		}

		UFG_INLINE bool HasStreamedResource(qPropertySet* m_PropertySet)
		{
			qPropertySet* m_StreamedResourceSet = m_PropertySet->GetPropertySet(0xDB4EBBFF); // component_StreamedResource::sPropertyName
			return m_StreamedResourceSet;
		}

		UFG_INLINE bool IsLoaded(qPropertySet* m_PropertySet)
		{
			// We return true because we have no clue if the resource is loaded or not because is part of world cell and not streamed resource...
			if (!HasStreamedResource(m_PropertySet)) {
				return true;
			}

			// Wrapped around (UFG::TrueCrowdSet::IsLoaded)
			return reinterpret_cast<bool(__fastcall*)(void*, qPropertySet*)>(UFG_RVA(0x43F280))(this, m_PropertySet);
		}

		UFG_INLINE void PreLoadCriticalResource(qPropertySet* m_PropertySet)
		{
			if (HasStreamedResource(m_PropertySet)) {
				reinterpret_cast<void(__fastcall*)(void*, qPropertySet*)>(UFG_RVA(0x43FBE0))(this, m_PropertySet);
			}
		}

		UFG_INLINE void ReleaseCriticalResource(qPropertySet* m_PropertySet)
		{
			if (HasStreamedResource(m_PropertySet)) {
				reinterpret_cast<void(__fastcall*)(void*, qPropertySet*)>(UFG_RVA(0x441910))(this, m_PropertySet);
			}
		}
	};

	namespace ObjectResourceManager
	{
		bool PreloadResource(qPropertySet* p_PropertySet)
		{
			CObjectResourceManager* m_ObjResourceManager = CObjectResourceManager::Instance();
			if (!m_ObjResourceManager) {
				return false;
			}

			if (!m_ObjResourceManager->IsLoaded(p_PropertySet)) {
				m_ObjResourceManager->PreLoadCriticalResource(p_PropertySet);
			}

			return true;
		}
	}
}