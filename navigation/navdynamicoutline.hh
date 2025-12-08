#pragma once

namespace UFG
{
	class NavDynamicOutline
	{
	public:
		virtual ~NavDynamicOutline() = 0;
		virtual void UpdateTransform(const qMatrix44& transform) = 0;
	};
};