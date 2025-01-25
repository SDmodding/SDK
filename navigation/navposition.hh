#pragma once

namespace UFG
{
	class NavPositionBase
	{
	public:
		qVector3 m_vPosition;

		virtual void Validate(f32 fToleranceXY, f32 fToleranceZ, f32 fRadius) = 0;
		virtual void Invalidate() = 0;
		virtual void SetInvalidMeshPosition() = 0;
		virtual bool IsOnMesh(float fToleranceXY) = 0;
		virtual bool IsMeshPositionValid() = 0;
		virtual void GetMeshPosition(qVector3& vMeshPosOut) = 0;
	};
}