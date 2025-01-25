#pragma once
/* Declare all forwards here if they're used too many times. */

class ActionContext;
class ActionNode;
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

	class GameSlice;
	class GroundProperties;
	class ModelAsset;

	class ParkingSpot;
	class ParkourHandle;

	class TriggerRegion;

	/* Sim */

	class SimObject;
	class SimObjectCharacter;
	class SimObjectVehicle;

	class SimComponent;

	/* Sim (Components) */

	class AIActionTreeComponent;
	class AICharacterControllerBaseComponent;
	class AiDriverComponent;
	class AIEntityComponent;
	class AIScriptInterfaceComponent;
	class ActionTreeComponent;
	class ActiveAIEntityComponent;
	class AnimationLODComponent;
	class BaseAnimationComponent;
	class CharacterAnimationComponent;
	class CharacterControllerInterface;
	class CharacterOccupantComponent;
	class CopUnitComponent;
	class CompositeDrawableComponent;
	class EncounterUnitComponent;
	class FaceActionComponent;
	class FacialActionTreeComponent;
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
	class SimObjectCharacterPropertiesComponent;
	class SimObjectPropertiesComponent;
	class StimulusEmitterComponent;
	class StimulusReceiverComponent;
	class StreamedResourceComponent;
	class TargetingSystemBaseComponent;
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