#pragma once

class component_BaseAnimation
{
public:
	bool DestroyAttachedCharacters;
	UFG::qOffset64<char*> RigName;
	UFG::qOffset64<char*> WeightSetFileName;
	UFG::qSymbolUC PoseDriverSet;
	UFG::qOffset64<char*> RigNameHD;
	UFG::qOffset64<char*> WeightSetFileNameHD;
	UFG::qSymbolUC PoseDriverSetHD;
	UFG::qOffset64<UFG::qPropertyList*> RequiredAnimBanks;
	u32 pad_BaseAnimation;
};