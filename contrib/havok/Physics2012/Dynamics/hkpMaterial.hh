#pragma once

class hkpMaterial
{
public:
	enum ResponseType
	{
		RESPONSE_INVALID,
		RESPONSE_SIMPLE_CONTACT,
		RESPONSE_REPORTING,
		RESPONSE_NONE,
		RESPONSE_MAX_ID
	};

	hkEnum<ResponseType, s8> m_responseType;
	hkHalf m_rollingFrictionMultiplier;
	f32 m_friction;
	f32 m_restitution;
};