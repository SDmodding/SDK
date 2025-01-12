#pragma once

class hkResource : public hkReferencedObject
{
public:
	struct Export
	{
		const char* name;
		void* data;
	};

	struct Import
	{
		const char* name;
		void** location;
	};
};