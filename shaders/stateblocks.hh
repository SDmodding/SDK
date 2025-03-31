#pragma once

//------------------------------------------------------------
//	States
//------------------------------------------------------------

struct SB_DepthBiasSortLayer
{
	f32 Values[4];
};

struct SB_SpecularLook
{
	f32 Values[4];
	f32 Values2[4];
	f32 DiffuseEmissionFilter[4];
	f32 Values3[4];
};

struct SB_TextureAnim
{
	f32 UVSpeedAndUVNumPages[4];
	f32 Flipbook[4];
};

struct SB_VehicleLook
{
	f32 DiffuseTint1[4];
	f32 DiffuseTint2[4];
	f32 SpecularLook[4];
	f32 DirtColour[4];
	f32 ExtraInfo[2];
};

//------------------------------------------------------------
//	Constants
//------------------------------------------------------------

struct CB_BeamSettings
{
	f32 Colour[4];
	f32 AnimUVScaleOffset[4];
};

struct CB_ClipPlanes
{
	f32 ClipPlanes[1][4];
};

struct CB_FXOverrideSettings
{
	f32 ColorTint[4];
	f32 Params1[4];
};

struct CB_DecalSettings
{
	f32 Info[4];
	f32 Specular[4];
};

struct CB_ParticleSettings
{
	f32 ColorAlphaKeys[4][4];
	f32 ColorKeyPositions[4];
	f32 AlphaKeyPositions[4];
	f32 DepthControlAndPivot[4];
	f32 LightInfo[4];
	f32 AnimUVScaleOffset[4];
	f32 AnimExtras[4];
	f32 OpacityOverDistance[4];
	f32 OpacityOverDistancePositions[4];
};

struct CB_FXSizeModule
{
	f32 XSizeKeys[4];
	f32 YSizeKeys[4];
	f32 ZSizeKeys[4];
	f32 SizeKeys[4];
};

struct CB_FXFlowmapSettings
{
	f32 FlowmapConstants[4];
	f32 FlowmapDistortOverTimeKeys[4];
	f32 FlowmapDistortOverTimeKeyPos[4];
};

struct CB_SceneryInstance
{
	f32 ColourTint[4];
	f32 SIColourTint[4];
	f32 Mask[4];
	f32 Value0[4];
};

struct CB_ShaderParams
{
	f32 Value0[4];
	f32 Value1[4];
	f32 Value2[4];
	f32 Value3[4];
	f32 Value4[4];
	f32 Value5[4];
	f32 Value6[4];
	f32 Value7[4];
};

struct CB_EnvironmentSettings
{
	f32 SunDir[4];
	f32 SunDirWorld[4];
	f32 SunColor[4];
	f32 AmbientColorHorizon[4];
	f32 ScaleAndHeight[4];
	f32 ScatterZenithColor[4];
	f32 ScatterHorizonColor[4];
	f32 ScatterGroundColor[4];
	f32 ScatterSunColor[4];
	f32 CharacterParams[4];
	f32 FogStartStopSky[4];
	f32 WindDirAndMag[4];
	f32 DisplayDebug[4];
	f32 LitWindowTimeOn[4];
	f32 Lighting[4];
	f32 SunScatterParams[4];
};

struct CB_SkySettings
{
	f32 CloudColourTop[4];
	f32 CloudColourMid[4];
	f32 CloudColourBottom[4];
	f32 CloudShadingComponents[4];
	f32 CloudColourCeiling[4];
};

struct CB_ExternalViewTransform
{
	f32 WorldView[16];
	f32 ViewScaleAndNearFar[4];
	f32 SkyFogDir[4];
	f32 NorthFogDir[4];
	f32 EastFogDir[4];
};

struct CB_ViewTransform
{
	f32 WorldView[16];
	f32 WorldProjection[16];
	f32 WorldViewInv[16];
	f32 CameraOffset[4];
	f32 CameraPosition[4];
	f32 Target[4];
};

struct CB_Timebase
{
	f32 SimTime[4];
};

struct CB_LocalTransform
{
	f32 LocalWorld[16];
	f32 LocalView[16];
	f32 LocalProjection[16];
};

struct CB_LocalProjection
{
	f32 LocalProjection[16];
};

struct CB_ShadowTransform
{
	f32 ViewShadow[4][16];
	f32 CutDepths[4];
	f32 Biases[4];
};

struct CB_LocalTransformInverse
{
	f32 WorldLocal[16];
	f32 ViewLocal[16];
};

struct CB_UIdata
{
	f32 texgenx0[4];
	f32 texgeny0[4];
	f32 texgenx1[4];
	f32 texgeny1[4];
	f32 cmul[4];
	f32 cadd[4];
	f32 data[4];
	f32 colour[4];
};

struct CB_ViewGenericInfo
{
	f32 Generic[4];
};

struct CB_RainSettings
{
	f32 WorldViewProj[16];
	f32 PreviousWorldViewProj[16];
	f32 WorldView[16];
	f32 PositionOffset[4];
	f32 Velocity[4];
	f32 Alpha[4];
	f32 ViewPosition[4];
	f32 SizeScale[4];
	f32 Lighting[4];
	f32 Forward[4];
	f32 ParticleBoxSize[4];
};

struct CB_UberParams
{
	f32 DepthBiasSortLayer[4];
	f32 DiffuseTint[4];
	f32 Glossiness;
	f32 UseGlossinessTex;
	f32 Metallic;
	f32 NormalMapScale;
	f32 ForceNormalsUp;
	f32 BlendLayer_BlendFalloff;
	f32 VertexInput_PositionScale;
	f32 _Pad_v1;
	f32 EmissiveAmount;
	f32 EmissiveUseDiffuseAlpha;
	f32 BlendLayer_UseVertexAlpha;
	f32 BlendLayer_UseDiffuseAlpha;
	f32 DiffuseTint_BaseAmount;
	f32 DiffuseTint_BlendAmount;
	f32 WindLayer_FlutterFrequency;
	f32 WindLayer_FlutterSpatialFreq;
	f32 WindLayer_SwayScale;
	f32 WindLayer_SwayFrequency;
	f32 WindLayer_SwayStiffness;
	f32 WindLayer_FlutterScale;
	f32 GrimLayer_BaseAmount;
	f32 GrimLayer_BlendAmount;
	f32 DetailLayer_BaseAmount;
	f32 DetailLayer_BlendAmount;
	f32 ReflectionLayer_Strength;
	f32 ReflectionLayer_GlossScale;
	f32 AlphaClip;
	f32 SheenLayer_DiffuseScale;
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
	f32 SheenLayer_RimFalloff;
	f32 SheenLayer_RimStrength;
	f32 SheenLayer_InnerFalloff;
	f32 SheenLayer_InnerStrength;
	int UVChannelSets[4];
	int UVChannelAnimType[4];
	f32 UVChannelScaleOffset[16];
	f32 UVChannelAnimSpeedNumPages[16];
	f32 DiffuseTint_BlendMask[4];
	f32 BlendLayer_BlendMask[4];
	f32 GrimLayer_BlendMask[4];
	f32 DetailLayer_BlendMask[4];
	f32 SheenLayer_BlendMask[4];
	f32 WindLayer_VertexColourMask[4];
};

struct CB_WaterOffset
{
	f32 RippleOffset[4];
	f32 FogFalloff[4];
};

struct CB_FlareSettings
{
	f32 ColorAlphaKeys[4][4];
	f32 ColorKeyPositions[4];
	f32 AlphaKeyPositions[4];
	f32 Info[4];
};

struct CB_LightningGlobalSettings
{
	f32 LightningConstants[4];
};

struct CB_ParticleSoftSettings
{
	f32 SoftParticleConstants[4];
	f32 ClipPlaneConstants[4];
};

struct CB_DynamicFlareInfo
{
	f32 Info[4];
};

struct CB_DeferredLight
{
	f32 PositionAndRadius[4];
	f32 ColourAndInvRadiusSqr[4];
	f32 Fov[4];
	f32 WidthHeightNearFar[4];
};

struct CB_CloudSettings
{
	f32 CloudCenter[4];
	f32 OpacityAndVerticalParams[4];
};

struct CB_VisualTreatmentParams
{
	f32 Value0[4];
	f32 Value1[4];
	f32 Value2[4];
	f32 Value3[4];
	f32 FovOffset;
	f32 TimeScale;
	f32 Unused1;
	f32 Unused2;
};

struct CB_Motionblur
{
	f32 ViewPrevProjection[16];
	f32 ScaleAndLength[4];
};

struct CB_SphericalHarmonic
{
	f32 IrradianceConst[4];
	f32 RedIrradianceConst[3][4];
	f32 GreenIrradianceConst[3][4];
	f32 BlueIrradianceConst[3][4];
};

struct CB_GaussianBlur
{
	f32 Direction[4];
};

struct CB_ColourBiasScale
{
	f32 Bias[4];
	f32 Scale[4];
};

struct CB_DepthOfField
{
	f32 NearBlurParams[4];
	f32 FarBlurParams[4];
};