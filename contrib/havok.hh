#pragma once

struct hkContainerHeapAllocator;

/* Common */

#include "havok/Common/Types/hkBaseTypes.hh"
#include "havok/Common/Types/hkSimpleProperty.hh"

#include "havok/Common/hkMath.hh"

#include "havok/Common/Container/hkArray.hh"

#include "havok/Common/hkBaseObject.hh"
#include "havok/Common/hkReferencedObject.hh"

#include "havok/Common/hkMultiThreadCheck.hh"
#include "havok/Common/hkStringPtr.hh"

/* Physics2012 */

#include "havok/Physics2012/Collide/Mopp/hkpMoppCode.hh"
#include "havok/Physics2012/Collide/Mopp/hkpMoppCompilerInput.hh"

#include "havok/Physics2012/Collide/Shape/hkcdShape.hh"
#include "havok/Physics2012/Collide/Shape/hkpShapeBase.hh"
#include "havok/Physics2012/Collide/Shape/hkpShape.hh"
#include "havok/Physics2012/Collide/Shape/hkpShapeContainer.hh"
#include "havok/Physics2012/Collide/Shape/hkpBvTreeShape.hh"
#include "havok/Physics2012/Collide/Shape/hkpMoppBvTreeShape.hh"

#include "havok/Physics2012/Collide/hkpLinkedCollidable.hh"

#include "havok/Physics2012/Dynamics/World/hkpSimulation.hh"
#include "havok/Physics2012/Dynamics/World/hkpWorldObject.hh"

#include "havok/Physics2012/Dynamics/Entity/hkpEntity.hh"
#include "havok/Physics2012/Dynamics/Entity/hkpRigidBody.hh"