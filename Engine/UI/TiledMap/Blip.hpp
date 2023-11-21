#pragma once

namespace UFG
{
	class CUIMapBlip
	{
	public:
		qBaseNodeRB mNode;

		bool mBoundIcon;
		bool mHasAltitude;
		bool mHasObjectiveHighlight;
		bool mUseCustomFilterDistance;
		float mCustomFilterDistance;
		float mAltitudeIconRangeSq;
		bool mIsAmbient;
		bool mChanged;
		bool mIconTypeChanged;
		bool mVisible;
		CUIHKMinimapBlipType* mType;
		void* mObjective;
		qVector3 pos;
		float rot;
		float mAltitudeDiff;
		int mAltitudeState;
		bool mAltitudeStateChanged;
		bool mInAltitudeRange;
		bool mHasRadius;
		bool mHasInteriorRadius;
		bool mTouchesEdge;
		float radiusScale;
		bool mShouldBlink;
		bool mShouldPulse;
		bool mShouldHighlight;
		bool mShouldStopBlink;
		bool mShouldStopHighlight;
		bool mIsSelectedObjective;
		bool mProximityUnlockDone;
		const char* mWorldMapCaption;
		CUIMapBlipGraphic* mNativeIcon;

		void SetVisible(bool p_Visible) 
		{ 
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0xCB8B0))(this, p_Visible);
		}

		void SetPosition(qVector3* p_WorldPosition) 
		{ 
			reinterpret_cast<void(__fastcall*)(void*, qVector3*)>(UFG_RVA(0xCB3B0))(this, p_WorldPosition);
		}

		void SetColor(qColour p_Colour)
		{
			if (mNativeIcon)
				mNativeIcon->mIconPoly.Color = p_Colour;
		}

		void SetHigherAltitude() 
		{ 
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0xCA880))(this); 
		}

		void SetNormalAltitude() 
		{ 
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0xCAE30))(this); 
		}

		void SetLowerAltitude() 
		{ 
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0xCACA0))(this); 
		}

		void SetWorldMapCaption(const char* p_Caption) 
		{ 
			reinterpret_cast<void(__fastcall*)(void*, const char*)>(UFG_RVA(0xCB8F0))(this, p_Caption);
		}
	};
}