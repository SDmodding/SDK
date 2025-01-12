#pragma once

struct hkContainerHeapAllocator;

//------------------------------------
//	Common
//------------------------------------

#include "Common/hkMemoryClassDefinitions.hh"

#include "Common/Types/hkBaseTypes.hh"
#include "Common/Types/hkSimpleProperty.hh"

#include "Common/hkBaseObject.hh"
#include "Common/hkReferencedObject.hh"

#include "Common/Reflection/hkTypeInfo.hh"
#include "Common/Reflection/hkClassNameRegistry.hh"

#include "Common/hkMath.hh"

#include "Common/Container/hkArray.hh"
#include "Common/Container/hkMap.hh"
#include "Common/Container/hkPointerMap.hh"
#include "Common/Container/hkCachedHashMap.hh"
#include "Common/Container/hkStringMap.hh"

#include "Common/hkMultiThreadCheck.hh"
#include "Common/hkStringPtr.hh"

#include "Common/Types/hkGeometryTypes.hh"

//------------------------------------
//	Serialize
//------------------------------------

#include "common/serialize/hkResource.hh"
#include "common/serialize/hkPackfileData.hh"

//------------------------------------
//	Animation
//------------------------------------

#include "animation/Rig/hkaBone.hh"
#include "animation/Rig/hkaSkeleton.hh"
#include "animation/Rig/hkaPose.hh"

//------------------------------------
//	Physics
//------------------------------------

#include "Physics2012/Collide/Mopp/hkpMoppCode.hh"
#include "Physics2012/Collide/Mopp/hkpMoppCompilerInput.hh"

#include "Physics2012/Collide/Shape/hkcdShape.hh"
#include "Physics2012/Collide/Shape/hkpShapeBase.hh"
#include "Physics2012/Collide/Shape/hkpShape.hh"
#include "Physics2012/Collide/Shape/hkpShapeContainer.hh"
#include "Physics2012/Collide/Shape/hkpBvTreeShape.hh"
#include "Physics2012/Collide/Shape/hkpMoppBvTreeShape.hh"

#include "Physics2012/Collide/hkpLinkedCollidable.hh"

#include "Physics2012/Dynamics/World/hkpSimulation.hh"
#include "Physics2012/Dynamics/World/hkpWorldObject.hh"

#include "Physics2012/Dynamics/Entity/hkpEntity.hh"
#include "Physics2012/Dynamics/Entity/hkpRigidBody.hh"