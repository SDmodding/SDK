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
#include "Preprocessors.hxx"

template <uint32_t Index, typename ReturnType, typename... Args>
UFG_INLINE ReturnType UFG_VCall(void* p_Instance, Args... p_Args)
{
	void* m_Function = *reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(p_Instance) + sizeof(void*) * Index);
	return reinterpret_cast<ReturnType(__fastcall*)(void*, Args...)>(m_Function)(p_Instance, p_Args...);
}

//==========================================================================
// Math

#include "Math/.Math.hxx"

#include "Templates.hpp"
#include "Classes.hpp"
#include "Enums.hpp" // TODO: Move all those stuff to appropriate folder so it's more readable...
#include "Typedefs.hpp"
#include "Functions.hpp"

//==========================================================================
// Globals

#include "Globals/D3D.hxx"
#include "Globals/Window.hxx"

//==========================================================================
// Engine (AK SoundEngine)

#include "Engine/AK/.AK.hxx"

//==========================================================================
// Engine (Havok)

#include "Engine/Havok/.Includes.hpp"

//==========================================================================
// Engine (Scaleform)

#include "Engine/Scaleform/.Includes.hpp"

//==========================================================================
// Engine (Skookum)

#include "Engine/Skookum/.Skookum.hxx"

//==========================================================================
// Defines

#include "Defines/BoneUID.hpp"
#include "Defines/QSymbolsDictionary.hpp"
#include "Defines/StringDictionary.hpp"
#include "Defines/TypeUID.hpp"

//==========================================================================
// Engine Important

#include "Engine/Metrics.hpp"
#include "Engine/Resources.hpp"
#include "Engine/MemoryPool.hpp"
#include "Engine/LinearAllocator.hpp"

#include "Engine/PropertySet/.PropertySet.hxx"
#include "Engine/Reflect.hpp"
#include "Engine/ResourceInventory.hpp"
#include "Engine/ResourceWarehouse.hpp"

//==========================================================================
// Engine (Illusion)

#include "Engine/Illusion/.Illusion.hpp"
#include "Engine/Illusion.hpp" // TODO: Move this to dedicated 'Illusion' folder.

//==========================================================================
// Engine (UEL)

#include "Engine/UEL/Value.hpp"
#include "Engine/UEL/Member.hpp"
#include "Engine/UEL/Expression.hpp"

//==========================================================================
// Engine (Render)

#include "Engine/Render/BeamManager.hpp"
#include "Engine/Render/VDynamic.hpp"
#include "Engine/Render/Poly.hpp"
#include "Engine/Render/RainManager.hpp"
#include "Engine/Render/View.hpp"
#include "Engine/Render/Context.hxx"
#include "Engine/Render/Callbacks.hxx"
#include "Engine/Render.hpp"

//==========================================================================
// Engine (UI)

#include "Engine/UI/.UI.hpp"

//==========================================================================
// Engine (Important)

#include "Engine/AIAwareness.hpp"
#include "Engine/Actions.hpp"
#include "Engine/Animation.hpp"
#include "Engine/Attachment.hpp"
#include "Engine/AudioEntity.hpp"
#include "Engine/Camera.hpp"
#include "Engine/Collision.hpp"
#include "Engine/Skeleton.hpp"
#include "Engine/Creature.hpp"
#include "Engine/DamageRig.hpp"
#include "Engine/Rig.hpp"
#include "Engine/Model.hpp"
#include "Engine/ObjectResourceManager.hpp"
#include "Engine/Parkour.hpp"
#include "Engine/VoiceProfile.hpp"

//==========================================================================
// Engine (Simulation)

#include "Engine/Simulation/.Simulation.hxx"

//==========================================================================
// Engine (Common)

#include "Engine/BigFile.hpp"
#include "Engine/BSP.hpp"
#include "Engine/DebugDrawManager.hpp"
#include "Engine/Door.hpp"
#include "Engine/DataStreamer.hpp"
#include "Engine/FXManager.hpp"
#include "Engine/LoadingLogic.hpp"
#include "Engine/RenderWorld.hpp"
#include "Engine/SectionChooser.hpp"
#include "Engine/SectionLayout.hpp"
#include "Engine/Director.hpp"
#include "Engine/ShapeCasterCollector.hpp"
#include "Engine/SoundBankManager.hpp"
#include "Engine/SimpleXML.hpp"
#include "Engine/StreamPool.hpp"
#include "Engine/StreamFileWrapper.hpp"
#include "Engine/StreamResourceLoader.hpp"
#include "Engine/PhysicsSystem.hpp"
#include "Engine/PhysicsPropertyManager.hpp"
#include "Engine/TiDoGame.hpp"
#include "Engine/TrueCrowdDatabase.hpp"
#include "Engine/Wwise.hpp"

//==========================================================================
// Game (RoadNetwork)

#include "Game/RoadNetwork/Node.hxx"
#include "Game/RoadNetwork/Gate.hxx"
#include "Game/RoadNetwork/Lane.hxx"
#include "Game/RoadNetwork/Section.hxx"
#include "Game/RoadNetwork/Segment.hxx"
#include "Game/RoadNetwork/Intersection.hxx"
#include "Game/RoadNetwork/Wayfinding.hxx"
#include "Game/RoadNetwork/Resource.hxx"

//==========================================================================
// Game

#include "Game/BulletManager.hpp"
#include "Game/EncounterBase.hpp"
#include "Game/ChaseCamera.hpp"
#include "Game/CopSystem.hpp"
#include "Game/EventDispatcher.hpp"
#include "Game/ExplosionManager.hpp"
#include "Game/FactionInterface.hpp"
#include "Game/GameCamera.hpp"
#include "Game/GameSlice.hpp"
#include "Game/GameStat.hpp"
#include "Game/Input.hpp"
#include "Game/LocalPlayer.hpp"
#include "Game/TiledMap.hpp"
#include "Game/PedSpawnManager.hpp"
#include "Game/ProgressionTracker.hpp"
#include "Game/RaceManager.hpp"
#include "Game/RadarSystem.hpp"
//#include "Game/RoadNetwork.hpp"
#include "Game/SaveLoad.hpp"
#include "Game/Scenery.hpp"
#include "Game/ScreenHud.hpp"
#include "Game/ScreenOverlay.hpp"
#include "Game/Store.hpp"
#include "Game/Tasks.hpp"
#include "Game/TimeOfDayManager.hpp"
#include "Game/UI.hpp"
#include "Game/Water.hpp"
#include "Game/Weapon.hpp"
#include "Game/WheeledVehicleManager.hpp"

//==========================================================================

#ifdef SDK_SD_OPTIONAL_INCLUDES
	#include "Optional/PermFile/.Includes.hpp"
	#include "Optional/StringHash.hpp"
#endif

#include "Utils.hpp"