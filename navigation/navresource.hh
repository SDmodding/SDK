#pragma once

namespace UFG
{
	class NavResource
	{
	public:
		qSymbol m_name;
		u32 m_tag;

		virtual ~NavResource() = 0;
		virtual void Reference() = 0;
		virtual void Dereference() = 0;
	};
}