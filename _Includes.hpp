#pragma once

/*
// Use this define before including SDK if you don't wanna use strings inside projects and etc...
// #define SDK_SD_MINIMAL_BUILD
*/

/*
// Use this define before including SDK if you want use some optional includes...
// #define SDK_SD_OPTIONAL_INCLUDES
*/

//==========================================================================

#include <intrin.h>
#include <unordered_map>
#include <map>
#include <d3d11.h>

uintptr_t g_BaseAddress = reinterpret_cast<uintptr_t>(GetModuleHandleA(0));
#include "Preprocessors.hh"

template <uint32_t Index, typename ReturnType, typename... Args>
UFG_INLINE ReturnType UFG_VCall(void* p_Instance, Args... p_Args)
{
	void* m_Function = *reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(p_Instance) + sizeof(void*) * Index);
	return reinterpret_cast<ReturnType(__fastcall*)(void*, Args...)>(m_Function)(p_Instance, p_Args...);
}

//==========================================================================
// Math

#include "Math/.Math.hh"

#include "Templates.hh"
#include "Classes.hh"
#include "Enums.hh" // TODO: Move all those stuff to appropriate folder so it's more readable...
#include "Typedefs.hh"
#include "Functions.hh"

//==========================================================================
// Globals

#include "Globals/D3D.hh"
#include "Globals/Window.hh"

//==========================================================================
// Engine (AK SoundEngine)

#include "Engine/AK/.AK.hh"

//==========================================================================
// Engine (Havok)

#include "Engine/Havok/.Havok.hh"

//==========================================================================
// Engine (Scaleform)

#include "Engine/Scaleform/.Scaleform.hh"

//==========================================================================
// Engine (Skookum)

#include "Engine/Skookum/.Skookum.hh"

//==========================================================================
// Defines

#include "Defines/BoneUID.hh"
#include "Defines/QSymbolsDictionary.hh"
#include "Defines/StringDictionary.hh"
#include "Defines/TypeUID.hh"

//==========================================================================
// Engine Important

#include "Engine/Metrics.hh"
#include "Engine/Resources.hh"
#include "Engine/MemoryPool.hh"
#include "Engine/LinearAllocator.hh"

#include "Engine/PropertySet/.PropertySet.hh"
#include "Engine/Reflect.hh"
#include "Engine/ResourceInventory.hh"
#include "Engine/ResourceWarehouse.hh"

//==========================================================================
// Engine (Illusion)

#include "Engine/Illusion/.Illusion.hh"
#include "Engine/Illusion.hh" // TODO: Move this to dedicated 'Illusion' folder.

//==========================================================================
// Engine (UEL)

#include "Engine/UEL/Value.hpp"
#include "Engine/UEL/Member.hpp"
#include "Engine/UEL/Expression.hpp"

//==========================================================================
// Engine (Render)

#include "Engine/Render/BeamManager.hh"
#include "Engine/Render/VDynamic.hh"
#include "Engine/Render/Poly.hh"
#include "Engine/Render/RainManager.hh"
#include "Engine/Render/View.hh"
#include "Engine/Render/Context.hh"
#include "Engine/Render/Callbacks.hh"
#include "Engine/Render.hh"

//==========================================================================
// Engine (UI)

#include "Engine/UI/.UI.hh"

//==========================================================================
// Engine (Important)

#include "Engine/AIAwareness.hh"
#include "Engine/Actions.hh"
#include "Engine/Animation.hh"
#include "Engine/Attachment.hh"
#include "Engine/AudioEntity.hh"
#include "Engine/Camera.hh"
#include "Engine/Collision.hh"
#include "Engine/Skeleton.hh"
#include "Engine/Creature.hh"
#include "Engine/DamageRig.hh"
#include "Engine/Rig.hh"
#include "Engine/Model.hh"
#include "Engine/ObjectResourceManager.hh"
#include "Engine/Parkour.hh"
#include "Engine/VoiceProfile.hh"

//==========================================================================
// Engine (Simulation)

#include "Engine/Simulation/.Simulation.hh"

//==========================================================================
// Engine (Common)

#include "Engine/BigFile.hh"
#include "Engine/BSP.hh"
#include "Engine/DebugDrawManager.hh"
#include "Engine/Door.hh"
#include "Engine/DataStreamer.hh"
#include "Engine/FXManager.hh"
#include "Engine/LoadingLogic.hh"
#include "Engine/RenderWorld.hh"
#include "Engine/SectionChooser.hh"
#include "Engine/SectionLayout.hh"
#include "Engine/Director.hh"
#include "Engine/ShapeCasterCollector.hh"
#include "Engine/SoundBankManager.hh"
#include "Engine/SimpleXML.hh"
#include "Engine/StreamPool.hh"
#include "Engine/StreamFileWrapper.hh"
#include "Engine/StreamResourceLoader.hh"
#include "Engine/PhysicsSystem.hh"
#include "Engine/PhysicsPropertyManager.hh"
#include "Engine/TiDoGame.hh"
#include "Engine/TrueCrowdDatabase.hh"
#include "Engine/Wwise.hh"

//==========================================================================
// Game (RoadNetwork)

#include "Game/RoadNetwork/Node.hh"
#include "Game/RoadNetwork/Gate.hh"
#include "Game/RoadNetwork/Lane.hh"
#include "Game/RoadNetwork/Section.hh"
#include "Game/RoadNetwork/Segment.hh"
#include "Game/RoadNetwork/Intersection.hh"
#include "Game/RoadNetwork/Wayfinding.hh"
#include "Game/RoadNetwork/Resource.hh"

//==========================================================================
// Game

#include "Game/BulletManager.hh"
#include "Game/EncounterBase.hh"
#include "Game/ChaseCamera.hh"
#include "Game/CopSystem.hh"
#include "Game/EventDispatcher.hh"
#include "Game/ExplosionManager.hh"
#include "Game/FactionInterface.hh"
#include "Game/GameCamera.hh"
#include "Game/GameSlice.hh"
#include "Game/GameStat.hh"
#include "Game/Input.hh"
#include "Game/LocalPlayer.hh"
#include "Game/TiledMap.hh"
#include "Game/PedSpawnManager.hh"
#include "Game/PlayerBuffTracker.hh"
#include "Game/ProgressionTracker.hh"
#include "Game/RaceManager.hh"
#include "Game/RadarSystem.hh"
#include "Game/SaveLoad.hh"
#include "Game/Scenery.hh"
#include "Game/ScreenHud.hh"
#include "Game/ScreenOverlay.hh"
#include "Game/Store.hh"
#include "Game/Tasks.hh"
#include "Game/TimeOfDayManager.hh"
#include "Game/UI.hh"
#include "Game/Water.hh"
#include "Game/Weapon.hh"
#include "Game/WheeledVehicleManager.hh"

//==========================================================================

#ifdef SDK_SD_OPTIONAL_INCLUDES
	#include "Optional/PermFile/.Includes.hh"
	#include "Optional/StringHash.hh"
#endif

#include "Utils.hh"