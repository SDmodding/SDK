#pragma once

namespace UFG
{
	class WindAction : public hkpUnaryAction
	{
	public:
		f32 mWindFactor;
		int mWindTicket;
		hkVector4f wforce;
		hkVector4f wtorque;
	};
}