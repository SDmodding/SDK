#pragma once

namespace Render
{
	class BeamSettings : public UFG::qResourceData, FXComponentSettings
	{
	public:
		UFG::qVector4 minColour;
		UFG::qVector4 maxColour;
		UFG::qVector2 numAnimPages;
		f32 mWidth;
		f32 mLength;
		u32 mTextureUID;
		f32 mLifeTime;
		u32 mRayCastLength;
	};
	SDK_ASSERT_SIZEOF(BeamSettings, 0x98);

	class BeamSettingsHandle : public UFG::qTypedResourceHandle<RTypeUID_BeamSettings, BeamSettings> {};

	//------------------------------------------------------------------

	class BeamManager
	{
	public:
		struct AddBeamParameters
		{
			BeamSettings* beamSettings;
			UFG::qVector3 startPoint;
			UFG::qVector3 endPoint;
			UFG::qColour colour;
			f32 width;
			f32 age;
		};

		struct Beam
		{
			UFG::qVector3 p0;
			UFG::qVector3 p1;
			CB_BeamSettings* settings;
			f32 width;
			u32 texID;
			u32 textureAnimStart;
			f32 age;
			f32 lifeTime;
		};

		Illusion::MaterialHandle mBeamMat;
		u32 mNumBeams;
		Beam mBeams[32];
		u32 mBeamSettingsStateIndex;
		u32 mAnimCounter;
		u32 mLastUpdateSimFrame;

		/* Static Functions */

		SDK_SINLINE BeamManager* Instance() { return SDK_VAR(BeamManager*, 0x23625E0); }

		/* Functions */

		void AddBeam(const AddBeamParameters& beamParameters) { SDK_CALL_FUNC(void, 0x1C6A00, void*, const AddBeamParameters&)(this, beamParameters); }
	};
	SDK_ASSERT_SIZEOF(BeamManager, 0x738);
}