#pragma once

namespace Illusion
{
	class BonePalette : public UFG::qResourceData
	{
	public:
		u32 mNumPalettes;
		u32 mNumBones;
		UFG::qOffset<char*> mBoneNameTable;
		UFG::qOffset<u32*> mBoneUIDTable;
		UFG::qOffset<u32*> mBoneFullUIDTable;
	};

	class BonePaletteHandle : public UFG::qTypedResourceHandle<RTypeUID_BonePalette, BonePalette>{};
}