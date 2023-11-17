#pragma once
#define Resource_ActionTreeResourceInventory 0x8DB8241B
#define Resource_AlphaStateInventory 0x12C800F2
#define Resource_AnimationGroupResourceInventory 0x58087229
#define Resource_AnimationInventory 0x53F1685E
#define Resource_AudioFXSettingsInventory 0xD77CCEB2
#define Resource_BIGFileInventory 0x2AE784F9
#define Resource_BIGFileNameLookupInventory 0x21EFAF30
#define Resource_BSPDebugDataInventory 0xA076E719
#define Resource_BSPInventory 0x45ED23E5
#define Resource_BeamSettingsInventory 0xA0AAE10F
#define Resource_BlendTreeResourceInventory 0x02680E48
#define Resource_BonePaletteInventory 0x50A819E3
#define Resource_BufferD3DResourceInventory 0x171246AD
#define Resource_BufferInventory 0x92CDEC8F
#define Resource_ChunkFileFatIndexInventory 0xE36C885C
#define Resource_ChunkFileIndexInventory 0xF569FE1B
#define Resource_CloudInventory 0x528C47E3
#define Resource_CloudSceneInventory 0x4438A32F
#define Resource_CollisionInstanceInventory 0x7970FB96
#define Resource_CollisionMeshBundleInventory 0x1723EA91
#define Resource_CoronaFlareSettingsInventory 0xB76CCFB8
#define Resource_CoverDataInventory 0x8DADDB7E
#define Resource_DecalSettingsInventory 0xAE323146
#define Resource_DynamicCoverDataInventory 0xE5150EE3
#define Resource_DynamicCoverGroupBundleInventory 0xEC7A2131
#define Resource_DynamicLightGroupSettingsInventory 0x19B59D34
#define Resource_DynamicLightSettingsInventory 0xD6CD7114
#define Resource_EffectEmitterSettingsInventory 0xFF1F2832
#define Resource_FXForceSettingsInventory 0x433ED8DF
#define Resource_FXSettingsInventory 0xED341A8D
#define Resource_FarGroundLayout 0x2A05C2B9
#define Resource_FlareSettingsInventory 0xA6535FBB
#define Resource_FontInventory 0x69FCCB4C
#define Resource_GeoSettingsInventory 0xF1734D8E
#define Resource_ImposterGroupInventory 0x4E23B4B4
#define Resource_LightGroupInventory 0xF0A0724F
#define Resource_LightningSettingsInventory 0x21AE1C64
#define Resource_LocatorsInventory 0x3EDDEFF0
#define Resource_MaterialInventory 0xB4C26312
#define Resource_MaterialTableInventory 0x80D1F139
#define Resource_ModelDataInventory 0xA2ADCD77
#define Resource_MorphTargetsInventory 0xC62C2822
#define Resource_MovieResourceDataInventory 0x399051EF
#define Resource_NISSpatialDataInventory 0x59362AA3
#define Resource_NavMeshDataInventory 0x5D7E8ADF
#define Resource_ParkourContainerBundleInventory 0x4558A12E
#define Resource_ParkourContainerInventory 0x15E16140
#define Resource_ParkourInstanceInventory 0x98CD09F8
#define Resource_ParticleEmitterSettingsInventory 0x3BEE21DC
#define Resource_PropertySetInventory 0x54606C31
#define Resource_RasterStateInventory 0x3BC715E0
#define Resource_ReflectionGroupInventory 0xEFAA9CC0
#define Resource_ReflectResourceInventory 0x5B00F999
#define Resource_ResourceFileInventory 0xA428072C
#define Resource_RigInfoResourceInventory 0xAEF1F66F
#define Resource_RigInstanceInventory 0x9A00456E
#define Resource_RigInventory 0x39BC0A7E
#define Resource_RoadNetworkInventory 0xA4F6DEDB
#define Resource_SceneLayerInventory 0xE0F4D9CC
#define Resource_SceneryGroupInventory 0xF0A07244
#define Resource_ScreenParticleEmitterSettingsInventory 0x354C3CDC
#define Resource_SectionEffectsInventory 0x468D9324
#define Resource_SectionLayoutInventory 0xEC35A8A0
#define Resource_ShaderBinaryInventory 0xE80F42E1
#define Resource_ShaderInventory 0x8B5561A1
#define Resource_ShaderTemplateInventory 0x1FD4E5C5
#define Resource_SidewalkInventory 0x43E99F7E
#define Resource_StateBlockInventory 0x4D04C7F2
#define Resource_SymbolTableResourceInventory 0x7C98C388
#define Resource_TerrainDataInventory 0x392C3181
#define Resource_TextureD3DResourceInventory 0xEF77C5F7
#define Resource_TextureInventory 0x8B43FABF
#define Resource_TrackStripSettingsInventory 0x69CE5438
#define Resource_TrueCrowdDataBaseInventory 0x4AEEEFDE
#define Resource_UELFragmentTableInventory 0x2DB16C3E
#define Resource_UILocalizationInventory 0x90CE6B7A
#define Resource_UIMinimapTileInventory 0xB9C2B9E0
#define Resource_UIScreenInventory 0x442A39D9
#define Resource_UniqueUIDTableResourceInventory 0xEF00811C
#define Resource_VertexDeclInventory 0x3E5FDA3E
#define Resource_VolumetricEffectSettingsInventory 0xE4B8F46A
#define Resource_WeightSetGroupResourceInventory 0x50C27D5F
#define Resource_XMLFileInventory 0x4FF578D5
#define Resource_ZoneLayout 0xC35E39D5

namespace UFG
{
	class CResourceWarehouse
	{
	public:
		qBaseTreeRB mInventoryTree;
		qList<qResourceInventory> mInventoryList;
		qResourceInventory* mLastInventory;
		uint32_t mLastTypeUID;
		int mNumInventories;
		float mAddTime;
		float mRemoveTime;
		float mUnresolvedTime;
		float mLoadTime;
		float mUnloadTime;

		void Load(void* p_Buffer, size_t p_NumBytes)
		{
			reinterpret_cast<void(__fastcall*)(void*, void*, size_t)>(UFG_RVA(0x176B50))(this, p_Buffer, p_NumBytes);
		}

		void Unload(void* p_Buffer, size_t p_NumBytes)
		{
			reinterpret_cast<void(__fastcall*)(void*, void*, size_t)>(UFG_RVA(0x17F180))(this, p_Buffer, p_NumBytes);
		}

		qResourceInventory* GetInventory(uint32_t p_TypeUID)
		{
			return reinterpret_cast<qResourceInventory*(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x170B80))(this, p_TypeUID);
		}
	};
	CResourceWarehouse* gResourceWarehouse = reinterpret_cast<CResourceWarehouse*>(UFG_RVA(0x235B2F0));
}