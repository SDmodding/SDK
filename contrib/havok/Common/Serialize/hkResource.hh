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

	/* Virtual Functions */

	virtual const char* getName() const = 0;
	virtual void callDestructors() = 0;
	virtual void getImportsExports(hkArray<Import>& impOut, hkArray<Export>& expOut) const = 0;
	virtual void* getContentsPointer(const char* typeName, const void* typeRegistry = 0) const = 0;
};