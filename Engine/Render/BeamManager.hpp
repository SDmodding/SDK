#pragma once

namespace Render
{
	// Custom Structure
	struct AddBeamParams_t
	{
		UFG::qVector3 m_StartPoint;
		UFG::qVector3 m_EndPoint;
		float m_Width;
		UFG::qSymbol m_TexUID;
		UFG::qColour m_Colour;
		float m_AnimUVScale[2];
	};

	class CBeamManager
	{
	public:
		UFG::qResourceHandle mBeamMat;
		uint32_t mNumBeams;

		struct Beam_t
		{
			UFG::qVector3 p0;
			UFG::qVector3 p1;
			Illusion::CB_BeamSettings* settings;
			float width;
			uint32_t texID;
			uint32_t textureAnimStart;
			float age;
			float lifeTime;
		};
		Beam_t mBeams[32];

		uint32_t mBeamSettingsStateIndex;
		uint32_t mAnimCounter;
		uint32_t mLastUpdateSimFrame;

		bool AddBeam(AddBeamParams_t& p_BeamParams)
		{
			if (mNumBeams == 32 || UFG::Metrics->mSimPausedInGame || UFG::Metrics->mSimPausedDebug)
				return false;

			Beam_t& m_Beam = mBeams[mNumBeams];
			++mNumBeams;

			m_Beam.p0 = p_BeamParams.m_StartPoint;
			m_Beam.p1 = p_BeamParams.m_EndPoint;
			m_Beam.width = p_BeamParams.m_Width;
			m_Beam.texID = p_BeamParams.m_TexUID;

			memcpy(m_Beam.settings->Colour, &p_BeamParams.m_Colour, sizeof(UFG::qColour));
			m_Beam.settings->AnimUVScaleOffset[0] = p_BeamParams.m_AnimUVScale[0];
			m_Beam.settings->AnimUVScaleOffset[1] = p_BeamParams.m_AnimUVScale[1];

			m_Beam.textureAnimStart = 1;
			m_Beam.age = 0.f;

			/*	- Make sure this isn't zero because (division by zero violation will come) 
			*	Pseudocode: mBeams[i].settings->AnimUVScaleOffset[3] = mBeams[i].age / mBeams[i].lifeTime;
			*/
			m_Beam.lifeTime = 1.f;

			return true;
		}
	};
}