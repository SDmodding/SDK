#pragma once

//------------------------------------------------------------
//	States
//------------------------------------------------------------

struct SB_DepthBiasSortLayer
{
	float Values[4];
};

struct SB_SpecularLook
{
	float Values[4];
	float Values2[4];
	float DiffuseEmissionFilter[4];
	float Values3[4];
};

struct SB_TextureAnim
{
	float UVSpeedAndUVNumPages[4];
	float Flipbook[4];
};

//------------------------------------------------------------
//	Constants
//------------------------------------------------------------

struct CB_BeamSettings
{
	float Colour[4];
	float AnimUVScaleOffset[4];
};

struct CB_ClipPlanes
{
	float ClipPlanes[1][4];
};

struct CB_FXOverrideSettings
{
	float ColorTint[4];
	float Params1[4];
};

struct CB_DecalSettings
{
	float Info[4];
	float Specular[4];
};

struct CB_ParticleSettings
{
	float ColorAlphaKeys[4][4];
	float ColorKeyPositions[4];
	float AlphaKeyPositions[4];
	float DepthControlAndPivot[4];
	float LightInfo[4];
	float AnimUVScaleOffset[4];
	float AnimExtras[4];
	float OpacityOverDistance[4];
	float OpacityOverDistancePositions[4];
};

struct CB_FXSizeModule
{
	float XSizeKeys[4];
	float YSizeKeys[4];
	float ZSizeKeys[4];
	float SizeKeys[4];
};

struct CB_FXFlowmapSettings
{
	float FlowmapConstants[4];
	float FlowmapDistortOverTimeKeys[4];
	float FlowmapDistortOverTimeKeyPos[4];
};

struct CB_SceneryInstance
{
	float ColourTint[4];
	float SIColourTint[4];
	float Mask[4];
	float Value0[4];
};

struct CB_ShaderParams
{
	float Value0[4];
	float Value1[4];
	float Value2[4];
	float Value3[4];
	float Value4[4];
	float Value5[4];
	float Value6[4];
	float Value7[4];
};

struct CB_EnvironmentSettings
{
	float SunDir[4];
	float SunDirWorld[4];
	float SunColor[4];
	float AmbientColorHorizon[4];
	float ScaleAndHeight[4];
	float ScatterZenithColor[4];
	float ScatterHorizonColor[4];
	float ScatterGroundColor[4];
	float ScatterSunColor[4];
	float CharacterParams[4];
	float FogStartStopSky[4];
	float WindDirAndMag[4];
	float DisplayDebug[4];
	float LitWindowTimeOn[4];
	float Lighting[4];
	float SunScatterParams[4];
};

struct CB_SkySettings
{
	float CloudColourTop[4];
	float CloudColourMid[4];
	float CloudColourBottom[4];
	float CloudShadingComponents[4];
	float CloudColourCeiling[4];
};

struct CB_ExternalViewTransform
{
	float WorldView[16];
	float ViewScaleAndNearFar[4];
	float SkyFogDir[4];
	float NorthFogDir[4];
	float EastFogDir[4];
};

struct CB_ViewTransform
{
	float WorldView[16];
	float WorldProjection[16];
	float WorldViewInv[16];
	float CameraOffset[4];
	float CameraPosition[4];
	float Target[4];
};

struct CB_Timebase
{
	float SimTime[4];
};

struct CB_LocalTransform
{
	float LocalWorld[16];
	float LocalView[16];
	float LocalProjection[16];
};

struct CB_LocalProjection
{
	float LocalProjection[16];
};

struct CB_ShadowTransform
{
	float ViewShadow[4][16];
	float CutDepths[4];
	float Biases[4];
};

struct CB_LocalTransformInverse
{
	float WorldLocal[16];
	float ViewLocal[16];
};

struct CB_UIdata
{
	float texgenx0[4];
	float texgeny0[4];
	float texgenx1[4];
	float texgeny1[4];
	float cmul[4];
	float cadd[4];
	float data[4];
	float colour[4];
};

struct CB_ViewGenericInfo
{
	float Generic[4];
};

struct CB_RainSettings
{
	float WorldViewProj[16];
	float PreviousWorldViewProj[16];
	float WorldView[16];
	float PositionOffset[4];
	float Velocity[4];
	float Alpha[4];
	float ViewPosition[4];
	float SizeScale[4];
	float Lighting[4];
	float Forward[4];
	float ParticleBoxSize[4];
};

struct CB_UberParams
{
	float DepthBiasSortLayer[4];
	float DiffuseTint[4];
	float Glossiness;
	float UseGlossinessTex;
	float Metallic;
	float NormalMapScale;
	float ForceNormalsUp;
	float BlendLayer_BlendFalloff;
	float VertexInput_PositionScale;
	float _Pad_v1;
	float EmissiveAmount;
	float EmissiveUseDiffuseAlpha;
	float BlendLayer_UseVertexAlpha;
	float BlendLayer_UseDiffuseAlpha;
	float DiffuseTint_BaseAmount;
	float DiffuseTint_BlendAmount;
	float WindLayer_FlutterFrequency;
	float WindLayer_FlutterSpatialFreq;
	float WindLayer_SwayScale;
	float WindLayer_SwayFrequency;
	float WindLayer_SwayStiffness;
	float WindLayer_FlutterScale;
	float GrimLayer_BaseAmount;
	float GrimLayer_BlendAmount;
	float DetailLayer_BaseAmount;
	float DetailLayer_BlendAmount;
	float ReflectionLayer_Strength;
	float ReflectionLayer_GlossScale;
	float AlphaClip;
	float SheenLayer_DiffuseScale;
	int BaseLayer_UVChannel;
	int BlendLayer_UVChannel;
	int GrimeLayer_UVChannel;
	int DetailLayer_UVChannel;
	int DebugOutput;
	int SheenLayer_Enable;
	int BlendMask_Enable;
	int DiffuseTint_Enable;
	int WindLayer_Enable;
	int _padi3[3];
	float SheenLayer_RimFalloff;
	float SheenLayer_RimStrength;
	float SheenLayer_InnerFalloff;
	float SheenLayer_InnerStrength;
	int UVChannelSets[4];
	int UVChannelAnimType[4];
	float UVChannelScaleOffset[16];
	float UVChannelAnimSpeedNumPages[16];
	float DiffuseTint_BlendMask[4];
	float BlendLayer_BlendMask[4];
	float GrimLayer_BlendMask[4];
	float DetailLayer_BlendMask[4];
	float SheenLayer_BlendMask[4];
	float WindLayer_VertexColourMask[4];
};

struct CB_WaterOffset
{
	float RippleOffset[4];
	float FogFalloff[4];
};

struct CB_FlareSettings
{
	float ColorAlphaKeys[4][4];
	float ColorKeyPositions[4];
	float AlphaKeyPositions[4];
	float Info[4];
};

struct CB_LightningGlobalSettings
{
	float LightningConstants[4];
};

struct CB_ParticleSoftSettings
{
	float SoftParticleConstants[4];
	float ClipPlaneConstants[4];
};

struct CB_DynamicFlareInfo
{
	float Info[4];
};

struct CB_DeferredLight
{
	float PositionAndRadius[4];
	float ColourAndInvRadiusSqr[4];
	float Fov[4];
	float WidthHeightNearFar[4];
};

struct CB_CloudSettings
{
	float CloudCenter[4];
	float OpacityAndVerticalParams[4];
};

struct CB_VisualTreatmentParams
{
	float Value0[4];
	float Value1[4];
	float Value2[4];
	float Value3[4];
	float FovOffset;
	float TimeScale;
	float Unused1;
	float Unused2;
};

struct CB_Motionblur
{
	float ViewPrevProjection[16];
	float ScaleAndLength[4];
};

struct CB_SphericalHarmonic
{
	float IrradianceConst[4];
	float RedIrradianceConst[3][4];
	float GreenIrradianceConst[3][4];
	float BlueIrradianceConst[3][4];
};

struct CB_GaussianBlur
{
	float Direction[4];
};

struct CB_ColourBiasScale
{
	float Bias[4];
	float Scale[4];
};

struct CB_DepthOfField
{
	float NearBlurParams[4];
	float FarBlurParams[4];
};