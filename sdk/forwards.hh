#pragma once
/* Declare all forwards here if they're used too many times. */

class ActionContext;
class ActionNode;
class AnimationNode;
class Attachment;
class Creature;
class ICompositeLook;
class ITask;
class LightingSubmitTaskParams;
class PoseDriver;
class TrackGroup;

namespace UFG
{
	class CameraSubject;

	class CollisionData;
	class CoverData;
	class FreeRunData;

	class GameSlice;
	class GroundProperties;
	class ModelAsset;

	class ParkingSpot;
	class ParkourHandle;

	class SkeletonData;

	class TriggerRegion;

	class WayGraph;
	class WayTraversalSearch;

	/* Sim */

	enum eSimObjectFlagEnum;

	class SimObject;
	class SimObjectCharacter;
	class SimObjectVehicle;

	class SimComponent;

	/* Sim (Components) */

	class ActionTreeComponent;
	class ActiveAIEntityComponent;
	class AIActionTreeComponent;
	class AICharacterControllerBaseComponent;
	class AiDriverComponent;
	class AIEntityComponent;
	class AIScriptInterfaceComponent;
	class AimingBaseComponent;
	class AimingNPCComponent;
	class AnimatedCameraComponent;
	class AnimationLODComponent;
	class AttackRightsComponent;
	class BaseAnimationComponent;
	class CameraAnimationComponent;
	class CharacterAnimationComponent;
	class CharacterControllerInterface;
	class CharacterOccupantComponent;
	class CharacterPhysicsComponent;
	class CharacterSubjectComponent;
	class CopUnitComponent;
	class CompositeDrawableComponent;
	class EncounterUnitComponent;
	class FaceActionComponent;
	class FacialActionTreeComponent;
	class GameCameraComponent;
	class InteractableComponent;
	class InteractorComponent;
	class InterestPointUserComponent;
	class InventoryItemComponent;
	class HealthComponent;
	class HitReactionComponent;
	class MissionFailConditionComponent;
	class NavComponent;
	class PhantomVolumeComponent;
	class PhysicsMoverInterface;
	class RigidBodyComponent;
	class RoadSpaceComponent;
	class SceneryGroupComponent;
	class SimObjectCharacterPropertiesComponent;
	class SimObjectPropertiesComponent;
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