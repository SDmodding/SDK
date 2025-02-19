#pragma once

namespace UFG
{
	class SchemaDef : public qNode<SchemaDef>, public qNodeRB<SchemaDef>
	{
	public:
		bool mbComponentSchema;
		bool mbSkipParentCheck;
		qSymbol mName;
		qString mNameString;
		qSymbol mClassName;
		qString mClassNameString;
		qSymbol mPropertyName;
		qString mPropertyNameString;
		qPropertySetHandle mPropertySet;
		qList<qPropertySet> mPropertySetInstances;
		SchemaDef* mpParentSchema;
		qList<SchemaDef> mDerivedSchemas;

		/* Impl Functions */

		SDK_INLINE void SetComponentSchema(bool componentSchema) { mbComponentSchema = componentSchema; }
		SDK_INLINE void SetSkipParentCheck(bool skipParentCheck) { mbSkipParentCheck = skipParentCheck; }

		/* Functions */

		void AddDerivedSchema(SchemaDef* derivedDef) { SDK_CALL_FUNC(void, 0x1F18D0, void*, SchemaDef*)(this, derivedDef); }
		char IsDerivedFrom(SchemaDef* otherSchema) { return SDK_CALL_FUNC(char, 0x1F9A00, void*, SchemaDef*)(this, otherSchema); }
	};

	namespace PropertySetManager
	{
		SDK_INLINE qPropertySet* AddComponentPropertySet(qPropertySet* property_set, SchemaDef* component_schema, qPropertySet* component_parent_set) { 
			return SDK_CALL_FUNC(qPropertySet*, 0x1F1760, qPropertySet*, SchemaDef*, qPropertySet*)(property_set, component_schema, component_parent_set); 
		}

		SDK_INLINE SchemaDef* AddSchemaDef(qPropertySet* property_set, SchemaDef* parent_schema_def) { 
			return SDK_CALL_FUNC(SchemaDef*, 0x1F1CA0, qPropertySet*, SchemaDef*)(property_set, parent_schema_def); 
		}

		SDK_INLINE void AppendParentLocal(qPropertySet* propertySet, const qSymbolUC& parentName) { SDK_CALL_FUNC(void, 0x1F1ED0, qPropertySet*, const qSymbolUC&)(propertySet, parentName); }
		SDK_INLINE void AppendParentLocal(qPropertySet* propertySet, const char* parentNameString) { SDK_CALL_FUNC(void, 0x1F1F10, qPropertySet*, const char*)(propertySet, parentNameString); }
		SDK_INLINE qPropertySet* CreateContainedPropertySet(const qSymbol& propSetName) { return SDK_CALL_FUNC(qPropertySet*, 0x1F4110, const qSymbol&)(propSetName); }
		SDK_INLINE qPropertySet* CreateOrFindPropertySet(const qSymbol& propSetName) { return SDK_CALL_FUNC(qPropertySet*, 0x1F4680, const qSymbol&)(propSetName); }
		SDK_INLINE qPropertySet* CreateTopLevelPropertySet(const qSymbol& propSetName) { return SDK_CALL_FUNC(qPropertySet*, 0x1F4760, const qSymbol&)(propSetName); }
		SDK_INLINE qString DeterminePathAndFilename(const char* propSetName, const char* alt_root_path) { return SDK_CALL_FUNC(qString, 0x1F51D0, const char*, const char*)(propSetName, alt_root_path); }
		SDK_INLINE qPropertySet* FindPropertySet(const qSymbol& propSetName) { return SDK_CALL_FUNC(qPropertySet*, 0x1F5560, const qSymbol&)(propSetName); }
		SDK_INLINE qPropertySet* GetPropertySet(const qSymbol& propSetName) { return SDK_CALL_FUNC(qPropertySet*, 0x1F5560, const qSymbol&)(propSetName); }
		SDK_INLINE SchemaDef* GetSchema(const qSymbol& schemaName) { return SDK_CALL_FUNC(SchemaDef*, 0x1F8110, const qSymbol&)(schemaName); }
		SDK_INLINE SchemaDef* GetSchemaForComponentPropertyName(const qSymbol& componentPropertyName) { return SDK_CALL_FUNC(SchemaDef*, 0x1F8190, const qSymbol&)(componentPropertyName); }
		SDK_INLINE SchemaDef* GetSchemaForProperty(qPropertySet* propertySet, const qSymbol& propertyName) { 
			return SDK_CALL_FUNC(SchemaDef*, 0x1F8200, qPropertySet*, const qSymbol&)(propertySet, propertyName);
		}
		SDK_INLINE bool IsComponentPropertySet(qPropertySet* property_set) { return SDK_CALL_FUNC(bool, 0x1F99A0, qPropertySet*)(property_set); }
		SDK_INLINE qPropertySet* LoadFromFile(const char* fullPath, u32 propertiesFlags, qPropertySet* pExistingPropSet = 0) {
			return SDK_CALL_FUNC(qPropertySet*, 0x1F9B40, const char*, u32, qPropertySet*)(fullPath, propertiesFlags, pExistingPropSet); 
		}
		SDK_INLINE qPropertySet* LoadPropertySetFromXML(XMLDocument* pDocument, bool alwaysReload = 0) { return SDK_CALL_FUNC(qPropertySet*, 0x1F9E10, XMLDocument*, bool)(pDocument, alwaysReload); }
		SDK_INLINE qPropertySet* NewLoadXML(const char* propSetFilename, bool& found_existing) { return SDK_CALL_FUNC(qPropertySet*, 0x1FA250, const char*, bool&)(propSetFilename, found_existing); }
		SDK_INLINE void PopCurrentlyLoadingFilename() { SDK_CALL_FUNC(void, 0x1FA4F0)(); }
		SDK_INLINE void PushCurrentlyLoadingFilename(const char* filename) { SDK_CALL_FUNC(void, 0x1FA9C0, const char*)(filename); }
		SDK_INLINE qPropertySet* ReloadPropertySet(const qSymbol& propSetName) { return SDK_CALL_FUNC(qPropertySet*, 0x1FB3D0, const qSymbol&)(propSetName); }
		SDK_INLINE void SetRootPath(const char* rootPath) { SDK_CALL_FUNC(void, 0x1FE600, const char*)(rootPath); }
		SDK_INLINE void SetupSchemaSet(qPropertySet* propertySet, const qSymbol& schemaName) { SDK_CALL_FUNC(void, 0x1FECB0, qPropertySet*, const qSymbol&)(propertySet, schemaName); }
		SDK_INLINE void UpdateDefaultValues(qPropertySet* component_property_prop_set, qPropertySet* property_set, const qSymbol& componentPropertyName) {
			SDK_CALL_FUNC(void, 0x1FF480, qPropertySet*, qPropertySet*, const qSymbol&)(component_property_prop_set, property_set, componentPropertyName);
		}
	}
}