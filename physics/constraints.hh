#pragma once

namespace UFG
{
	class Constraint : public qSafePointerNode<Constraint>, public qNode<Constraint>
	{
	public:
		hkpConstraintInstance* mConstraintInstance;
		qSymbol mName;
		qReflectHandle<qReflectObject> mDefinition;
	};
}