#pragma once
/* Declare all forwards here if they're used too many times. */

class ActionContext;
class ActionNode;
class AnimationNode;
class Attachment;
class Creature;
class LightingSubmitTaskParams;
class PoseDriver;
class PoseNode;
class SkeletalAnimation;

// Conditions

class HasAttackRequestCondition;

// Groups

class CanAttackConditionGroup;
class TrackGroup;

// Tasks

class ITask;
class AttackRightsScoreBonusTask;

// Tracks


// Skookum Script

class SSInvokedBase;
class SSInvokedExpression;

namespace UFG
{
	class AudioEntity;
	class AudioEvent;

	class BSP;

	class CameraSubject;

	class CellTrigger;

	class CollisionData;
	class CoverData;
	class FreeRunData;

	class GameSlice;
	class GroundProperties;
	class ModelAsset;

	class ICompositeLook;

	class ParkingSpot;
	class ParkourQuery;
	class ParkourHandle;

	class PhysicsObjectProperties;

	class RigidBody;
	
	class SceneLayer;
	class SceneObjectProperties;

	class SkeletonData;

	class SpawnPoint;
	class SpawnRegion;

	class SupplementaryAttackTarget;

	class TriggerRegion;

	class WayGraph;
	class WayTraversalSearch;

	class ZoneTrigger;

	class qMemoryPool;

	/* Sim */

	enum eSimObjectFlagEnum;

	class SimObject;
	class SimObjectCharacter;
	class SimObjectVehicle;

	class SimComponent;

	/* Sim (Components) */

	class ActionTreeComponent;
	class ActionTreeResourcesComponent;
	class ActiveAIEntityComponent;
	class ActorAudioComponent;
	class AIActionTreeComponent;
	class AICharacterControllerBaseComponent;
	class AiDriverComponent;
	class AIEntityComponent;
	class AIScriptInterfaceComponent;
	class AimingBaseComponent;
	class AimingNPCComponent;
	class AimingPlayerComponent;
	class AnimatedCameraComponent;
	class AnimationLODComponent;
	class AttackRightsComponent;
	class BaseAnimationComponent;
	class CameraAnimationComponent;
	class CharacterAnimationComponent;
	class CharacterControllerInterface;
	class CharacterEffectsComponent;
	class CharacterOccupantComponent;
	class CharacterPhysicsComponent;
	class CharacterSubjectComponent;
	class CopUnitComponent;
	class CompositeDrawableComponent;
	class DialogueAnimationComponent;
	class DynamicCoverComponent;
	class EncounterUnitComponent;
	class FaceActionComponent;
	class FaceMeterComponent;
	class FacialActionTreeComponent;
	class FormationManagerComponent;
	class GameCameraComponent;
	class GetInFormationComponent;
	class GetInPedFormationComponent;
	class GunComponent;
	class HasAttackRequestComponent;
	class HkAudioEntityComponent;
	class HudComponent;
	class InteractableComponent;
	class InteractorComponent;
	class InterestPointUserComponent;
	class InventoryComponent;
	class InventoryItemComponent;
	class HealthComponent;
	class HitReactionComponent;
	class MissionFailConditionComponent;
	class NavComponent;
	class ParkourComponent;
	class PedFormationManagerComponent;
	class PhantomVolumeComponent;
	class PhysicsMoverInterface;
	class PhysicsWheeledVehicle;
	class PowerManagementComponent;
	class RagdollComponent;
	class RegionComponent;
	class RigidBodyComponent;
	class RoadSpaceComponent;
	class SceneryGroupComponent;
	class SensorComponent;
	class SimObjectCharacterPropertiesComponent;
	class SimObjectPropertiesComponent;
	class SimObjectWeaponPropertiesComponent;
	class StimulusEmitterComponent;
	class StimulusReceiverComponent;
	class StreamedResourceComponent;
	class TargetingSystemBaseComponent;
	class TargetingSystemPedBaseComponent;
	class TargetingSystemPedPlayerComponent;
	class TransformNodeComponent;
	class TriadWarsComponent;
	class TSActorComponent;
	class VehicleAudioComponent;
	class VehicleDriverInterface;
	class VehicleEffectsComponent;
	class VehicleOccupantComponent;
	class VehicleSubjectComponent;
	class WaterFloatingTrackerBaseComponent;
	class WaterFloatingTrackerComponent;
	class WorldContextComponent;
	class UELComponent;
}

namespace Render
{
	class BeamSettingsHandle;
}