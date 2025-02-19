#pragma once

class component_StreamedResource
{
public:
	UFG::qOffset64<UFG::qPropertyList*> ResourceTags;
	UFG::qOffset64<UFG::qPropertyList*> ResourceList;
	UFG::qOffset64<UFG::qPropertyList*> ComponentList;
	UFG::qOffset64<UFG::qPropertyList*> TextureSetList;
	UFG::qSymbolUC EntityType;
	u32 TrueCrowdSelectionType;
	f32 BMIMin;
	f32 BMIMax;
	UFG::qOffset64<UFG::qPropertyList*> PartList;
};
