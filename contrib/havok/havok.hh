#pragma once

//------------------------------------
//	Forwards
//------------------------------------

struct hkpCollisionInput;
struct hkContainerHeapAllocator;

class hkpEntity;
class hkpPhantom;
class hkpWorld;

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
#include "Common/Reflection/hkClass.hh"

#include "Common/hkMath.hh"
#include "Common/Types/hkMotionState.hh"

#include "Common/Container/hkArray.hh"
#include "Common/Container/hkSmallArray.hh"
#include "Common/Container/hkMap.hh"
#include "Common/Container/hkPointerMap.hh"
#include "Common/Container/hkCachedHashMap.hh"
#include "Common/Container/hkStringMap.hh"

#include "Common/hkMultiThreadCheck.hh"
#include "Common/hkStringPtr.hh"
#include "Common/hkMemoryAllocator.hh"

#include "Common/Thread/hkSemaphore.hh"
#include "Common/Thread/hkCriticalSection.hh"
#include "Common/Thread/hkThreadPool.hh"
#include "Common/Thread/hkJobThreadPool.hh"
#include "Common/Thread/hkJobQueue.hh"

#include "Common/Types/hkGeometryTypes.hh"
#include "Common/Types/hkPhysicsTypes.hh"

#include "Common/GeometryUtilities/hkInertiaTensorComputer.hh"

#include "Common/IO/hkStreamWriter.hh"
#include "Common/IO/hkOstream.hh"

//------------------------------------
//	Serialize
//------------------------------------

#include "Common/Serialize/hkResource.hh"
#include "Common/Serialize/hkPackfileData.hh"

#include "Common/Serialize/Util/hkStructureLayout.hh"
#include "Common/Serialize/hkPackfileWriter.hh"

#include "Common/Serialize/Util/hkSerializeUtil.hh"

//------------------------------------
//	Geometry
//------------------------------------

#include "Geometry/DataStructures/hkcdDynamicAabbTree.hh"
#include "Geometry/DataStructures/hkcdStaticAabbTree.hh"

//------------------------------------
//	AI
//------------------------------------

#include "AI/Pathfinding/NavMesh/hkaiNavMesh.hh"

#include "AI/Pathfinding/Collide/hkaiNavMeshQueryMediator.hh"
#include "AI/Pathfinding/Collide/hkaiStaticTreeNavMeshQueryMediator.hh"

#include "AI/Pathfinding/Streaming/hkaiStreamingManager.hh"

#include "AI/NavMesh/hkaiNavMeshEdgeMatchingParams.hh"
#include "AI/NavMesh/hkaiNavMeshSimplificationUtils.hh"
#include "AI/NavMesh/hkaiNavMeshGenerationSettings.hh"
#include "AI/NavMesh/hkaiNavMeshGenerationUtils.hh"


//------------------------------------
//	Animation
//------------------------------------

#include "Animation/Rig/hkaBone.hh"
#include "Animation/Rig/hkaSkeleton.hh"
#include "Animation/Rig/hkaPose.hh"

#include "Animation/hkaAnimation.hh"
#include "Animation/hkaAnimationBinding.hh"

#include "Animation/Mapper/hkaSkeletonMapperData.hh"
#include "Animation/Mapper/hkaSkeletonMapper.hh"

//------------------------------------
//	Physics
//------------------------------------

#include "Physics/Constraint/Data/hkpConstraintInfo.hh"

//------------------------------------
//	Physics2012
//------------------------------------

#include "Physics2012/Collide/Util/hkpWeldingUtility.hh"

#include "Physics2012/Collide/hkpCollidableQualityType.hh"

#include "Physics2012/Collide/Mopp/hkpMoppCode.hh"

#include "Physics2012/Collide/Shape/hkpMeshMaterial.hh"
#include "Physics2012/Collide/Shape/hkcdShape.hh"
#include "Physics2012/Collide/Shape/hkpShapeBase.hh"
#include "Physics2012/Collide/Shape/hkpShape.hh"
#include "Physics2012/Collide/Shape/hkpShapeContainer.hh"
#include "Physics2012/Collide/Shape/hkpPhantomCallbackShape.hh"
#include "Physics2012/Collide/Shape/hkpSphereRepShape.hh"
#include "Physics2012/Collide/Shape/hkpConvexShape.hh"
#include "Physics2012/Collide/Shape/hkpSphereShape.hh"
#include "Physics2012/Collide/Shape/hkpBvTreeShape.hh"
#include "Physics2012/Collide/Shape/hkpMoppBvTreeShape.hh"

#include "Physics2012/Collide/Shape/Compound/Collection/hkpShapeCollection.hh"
#include "Physics2012/Collide/Shape/Compound/Collection/hkpExtendedMeshShape.hh"

#include "Physics2012/Collide/Shape/Compound/Tree/hkpMoppCompilerInput.hh"
#include "Physics2012/Collide/Shape/Compound/Tree/hkpMoppUtility.hh"

#include "Physics2012/Collide/BroadPhase/hkpBroadPhaseHandle.hh"
#include "Physics2012/Collide/BroadPhase/hkpTypedBroadPhaseHandle.hh"

#include "Physics2012/Collide/hkpLinkedCollidable.hh"

#include "Physics2012/Collide/hkpCdBody.hh"
#include "Physics2012/Collide/hkpCollidable.hh"

#include "Physics2012/Dynamics/Collide/hkpContactListener.hh"

#include "Physics2012/Dynamics/Constraint/hkpConstraintOwner.hh"
#include "Physics2012/Dynamics/Constraint/hkpConstraintInstance.hh"

#include "Physics2012/Dynamics/Phantom/hkpPhantomOverlapListener.hh"
#include "Physics2012/Dynamics/World/Listener/hkpWorldDeletionListener.hh"
#include "Physics2012/Dynamics/World/Listener/hkpWorldPostSimulationListener.hh"

#include "Physics2012/Dynamics/World/hkpSimulation.hh"
#include "Physics2012/Dynamics/World/hkpSimulationIsland.hh"
#include "Physics2012/Dynamics/World/hkpWorldObject.hh"
#include "Physics2012/Dynamics/World/hkpWorldCinfo.hh"
#include "Physics2012/Dynamics/World/hkpBroadPhaseBorder.hh"

#include "Physics2012/Dynamics/Phantom/hkpPhantom.hh"
#include "Physics2012/Dynamics/Phantom/hkpShapePhantom.hh"
#include "Physics2012/Dynamics/Phantom/hkpSimpleShapePhantom.hh"
#include "Physics2012/Dynamics/Phantom/hkpAabbPhantom.hh"

#include "Physics2012/Dynamics/hkpAction.hh"
#include "Physics2012/Dynamics/hkpArrayAction.hh"
#include "Physics2012/Dynamics/hkpUnaryAction.hh"
#include "Physics2012/Dynamics/hkpMaterial.hh"

#include "Physics2012/Dynamics/Motion/hkpMotion.hh"
#include "Physics2012/Dynamics/Motion/hkpKeyframedRigidMotion.hh"

#include "Physics2012/Dynamics/Entity/hkpEntity.hh"
#include "Physics2012/Dynamics/Entity/hkpEntityListener.hh"
#include "Physics2012/Dynamics/Entity/hkpRigidBody.hh"

#include "Physics2012/Utilities/Actions/hkpReorientAction.hh"
#include "Physics2012/Utilities/Actions/hkpEaseConstraintsAction.hh"

#include "Physics2012/Collide/Shape/Query/hkpShapeRayCastCollectorOutput.hh"
#include "Physics2012/Collide/Shape/Query/hkpShapeRayCastInput.hh"
#include "Physics2012/Collide/Shape/Query/hkpShapeRayCastOutput.hh"

#include "Physics2012/Collide/Query/CastUtil/hkpLinearCastInput.hh"
#include "Physics2012/Collide/Query/CastUtil/hkpWorldRayCastInput.hh"
#include "Physics2012/Collide/Query/CastUtil/hkpWorldRayCastOutput.hh"

#include "Physics2012/Collide/Query/Collector/hkpRootCdPoint.hh"

#include "Physics2012/Collide/Query/hkpCollisionQueryJobs.hh"
#include "Physics2012/Collide/Query/hkpRayCastQueryJobs.hh"

#include "Physics2012/Collide/Shape/Query/hkpRayShapeCollectionFilter.hh"
#include "Physics2012/Collide/Filter/hkpCollidableCollidableFilter.hh"
#include "Physics2012/Collide/Filter/hkpShapeCollectionFilter.hh"
#include "Physics2012/Collide/Filter/hkpRayCollidableFilter.hh"
#include "Physics2012/Collide/Filter/hkpCollisionFilter.hh"
#include "Physics2012/Collide/Filter/hkpGroupFilter.hh"

#include "Physics2012/Vehicle/hkpVehicleWheelCollide.hh"
#include "Physics2012/Vehicle/hkpVehicleInstance.hh"
#include "Physics2012/Vehicle/hkpVehicleEngine.hh"
#include "Physics2012/Vehicle/hkpVehicleTransmission.hh"
#include "Physics2012/Vehicle/hkpVehicleBrake.hh"
#include "Physics2012/Vehicle/hkpVehicleSteering.hh"
#include "Physics2012/Vehicle/hkpVehicleAerodynamics.hh"
#include "Physics2012/Vehicle/hkpRejectChassisListener.hh"

#include "Physics2012/Vehicle/WheelCollide/hkpVehicleRayCastWheelCollide.hh"

#include "Utilities/hkpCharacterControl.hh"

//------------------------------------
//	Animation (Physics2012Bridge)
//------------------------------------

#include "Animation/Physics2012Bridge/hkaRagdollInstance.hh"

#include "Animation/Physics2012Bridge/Controller/hkaKeyFrameHierarchyUtility.hh"
#include "Animation/Physics2012Bridge/Controller/hkaRagdollRigidBodyController.hh"

#include "Animation/Physics2012Bridge/hkaDetectRagdollPenetration.hh"