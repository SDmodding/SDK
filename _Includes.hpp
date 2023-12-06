#pragma once

/*
// Use this define before including SDK if you don't wanna use strings inside projects and etc...
// #define SDK_SD_MINIMAL_BUILD
*/

/*
// Use this define before including SDK if you want use some optional includes...
// #define SDK_SD_OPTIONAL_INCLUDES
*/

#include <intrin.h>
#include <unordered_map>
#include <map>
#include <d3d11.h>

// Defines
uintptr_t BaseAddress = reinterpret_cast<uintptr_t>(GetModuleHandleA(0));
#define UFG_RVA(x)		(BaseAddress + x)
#define UFG_RVA_PTR(x)	reinterpret_cast<void*>(UFG_RVA(x))
#define UFG_RVA_GET(x)	(reinterpret_cast<uintptr_t>(x) - BaseAddress)

#define UFG_CONST_CHAR(x) reinterpret_cast<const char*>(UFG_RVA(x))

// Asserts
#define UFG_ASSERT_CLASS(className, classSize) \
    static_assert(sizeof(className) == classSize, "Size of class: '" #className "' is invalid!")
#define UFG_ASSERT_STRUCT(structName, structSize) \
    static_assert(sizeof(structName) == structSize, "Size of struct: '" #structName "' is invalid!")

// Pads
#define UFG_PAD_INSERT(x, y) x ## y
#define UFG_PAD_DEFINE(x, y) UFG_PAD_INSERT(x, y)
#define UFG_PAD(size) char UFG_PAD_DEFINE(padding_, __LINE__)[size]
#define UFG_PAD_ALIGN(size) private: UFG_PAD(size); public:

template <uint32_t Index, typename ReturnType, typename... Args>
__forceinline ReturnType UFG_VCall(void* p_Instance, Args... p_Args)
{
	void* m_Function = *reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(p_Instance) + sizeof(void*) * Index);
	return reinterpret_cast<ReturnType(__fastcall*)(void*, Args...)>(m_Function)(p_Instance, p_Args...);
}

// Math
#include "Math/.Math.hxx"

#include "Templates.hpp"
#include "Classes.hpp"
#include "Enums.hpp"
#include "Typedefs.hpp"
#include "Functions.hpp"

// Globals
#include "Globals/D3D.hxx"
#include "Globals/Window.hxx"

// Engine (Havok)
#include "Engine/Havok/.Includes.hpp"

// Engine (Scaleform)
#include "Engine/Scaleform/.Includes.hpp"

// Engine (Skookum)
#include "Engine/Skookum/.Skookum.hxx"

// Defines
#include "Defines/NodePlayables.hpp"
#include "Defines/BoneUID.hpp"
#include "Defines/QSymbolsDictionary.hpp"
#include "Defines/StringDictionary.hpp"
#include "Defines/TypeUID.hpp"

// Engine Important
#include "Engine/Metrics.hpp"
#include "Engine/Resources.hpp"
#include "Engine/MemoryPool.hpp"
#include "Engine/LinearAllocator.hpp"

#include "Engine/PropertySet/.PropertySet.hxx"
#include "Engine/Reflect.hpp"
#include "Engine/ResourceInventory.hpp"
#include "Engine/ResourceWarehouse.hpp"

// Engine (Illusion)
#include "Engine/Illusion/.Illusion.hpp"
#include "Engine/Illusion.hpp" // TODO: Move this to dedicated 'Illusion' folder.

// Engine (UEL)
#include "Engine/UEL/Value.hpp"
#include "Engine/UEL/Member.hpp"
#include "Engine/UEL/Expression.hpp"

// Engine (Render)
#include "Engine/Render/BeamManager.hpp"
#include "Engine/Render/VDynamic.hpp"
#include "Engine/Render/Poly.hpp"
#include "Engine/Render/RainManager.hpp"
#include "Engine/Render/View.hpp"
#include "Engine/Render/Context.hxx"
#include "Engine/Render/Callbacks.hxx"
#include "Engine/Render.hpp"

// Engine (UI)
#include "Engine/UI/.UI.hpp"

// Engine
#include "Engine/Actions.hpp"
#include "Engine/AIAwareness.hpp"
#include "Engine/AKSoundEngine.hpp"
#include "Engine/Animation.hpp"
#include "Engine/Attachment.hpp"
#include "Engine/AudioEntity.hpp"
#include "Engine/BigFile.hpp"
#include "Engine/BSP.hpp"
#include "Engine/Collision.hpp"
#include "Engine/Skeleton.hpp"
#include "Engine/Creature.hpp"
#include "Engine/DataStreamer.hpp"
#include "Engine/DamageRig.hpp"
#include "Engine/DebugDrawManager.hpp"
#include "Engine/Rig.hpp"
#include "Engine/Model.hpp"
#include "Engine/Components.hpp"
#include "Engine/Door.hpp"
#include "Engine/FXManager.hpp"
#include "Engine/LoadingLogic.hpp"
#include "Engine/ObjectResourceManager.hpp"
#include "Engine/Parkour.hpp"
#include "Engine/Sim.hpp"
#include "Engine/VoiceProfile.hpp"
#include "Engine/SimVehicle.hpp"
#include "Engine/SimWeapon.hpp"
#include "Engine/SimCharacter.hpp"
#include "Engine/SimObjectUtility.hpp"
#include "Engine/RenderWorld.hpp"
#include "Engine/SectionChooser.hpp"
#include "Engine/SectionLayout.hpp"
#include "Engine/Camera.hpp"
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
#include "Game/Vehicle.hpp"
#include "Game/TiledMap.hpp"
#include "Game/PedSpawnManager.hpp"
#include "Game/ProgressionTracker.hpp"
#include "Game/RaceManager.hpp"
#include "Game/RadarSystem.hpp"
#include "Game/RoadNetwork.hpp"
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

#ifdef SDK_SD_OPTIONAL_INCLUDES
	#include "Optional/PermFile/.Includes.hpp"
	#include "Optional/StringHash.hpp"
#endif

#include "Utils.hpp"