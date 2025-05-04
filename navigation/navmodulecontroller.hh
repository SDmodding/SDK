#pragma once

namespace UFG
{
	class NavModuleController
	{
	public:
		NavComponent* m_navComponent;
		qVector3 m_vDirection;
		f32 m_fSpeed;

		/* Virtual Functions */

		virtual ~NavModuleController() = 0;
		virtual void Update() = 0;
		virtual void Reset() = 0;
	};
}