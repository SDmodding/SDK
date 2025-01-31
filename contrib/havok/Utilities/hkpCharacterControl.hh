#pragma once

struct hkpSurfaceInfo
{
	enum SupportedState
	{
		UNSUPPORTED,
		SLIDING,
		SUPPORTED
	};


	SupportedState m_supportedState;
	hkVector4f m_surfaceNormal;
	hkVector4f m_surfaceVelocity;
	f32 m_surfaceDistanceExcess;
	hkBool m_surfaceIsDynamic;
};