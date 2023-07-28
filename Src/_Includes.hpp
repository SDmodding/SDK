#pragma once

/*
// Use this define before including SDK if you don't wanna use strings inside projects and etc...
// #define SDK_SD_MINIMAL_BUILD
*/

#include <unordered_map>
#include <map>
#include <d3d11.h>

// Defines
uintptr_t BaseAddress = reinterpret_cast<uintptr_t>(GetModuleHandleA(0));
#define UFG_RVA(x)		(BaseAddress + x)
#define UFG_RVA_GET(x)	(reinterpret_cast<uintptr_t>(x) - BaseAddress)

#define UFG_PAD_INSERT(x, y) x ## y
#define UFG_PAD_DEFINE(x, y) UFG_PAD_INSERT(x, y)
#define UFG_PAD(size) char UFG_PAD_DEFINE(padding_, __LINE__)[size]

template <uint32_t Index, typename ReturnType, typename... Args>
__forceinline ReturnType UFG_VCall(void* p_Instance, Args... p_Args)
{
	void* m_Function = *reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(p_Instance) + sizeof(void*) * Index);
	return reinterpret_cast<ReturnType(__fastcall*)(void*, Args...)>(m_Function)(p_Instance, p_Args...);
}

#include "Defines/Math.hpp"

#include "Templates.hpp"
#include "Classes.hpp"
#include "Enums.hpp"
#include "Typedefs.hpp"
#include "Functions.hpp"

// Engine Havok
#include "Engine/Havok/Classes.hpp"
#include "Engine/Havok/hkpCollidable.hpp"
#include "Engine/Havok/hkpRayCast.hpp"
#include "Engine/Havok/hkpShape.hpp"
#include "Engine/Havok/hkpConvexShape.hpp"
#include "Engine/Havok/hkpBoxShape.hpp"


// Defines
#include "Defines/NodePlayables.hpp"
#include "Defines/BoneUID.hpp"
#include "Defines/StringDictionary.hpp"
#include "Defines/TypeUID.hpp"

// Engine Important
#include "Engine/Resources.hpp"
#include "Engine/Illusion.hpp"
#include "Engine/MemoryPool.hpp"
#include "Engine/Render.hpp"

#include "Engine/PropertySet.hpp"
#include "Engine/ResourceInventory.hpp"
#include "Engine/ResourceWarehouse.hpp"

// Engine Illusion
#include "Engine/Illusion/RenderThreadManager.hpp"

// Engine
#include "Engine/Metrics.hpp"

#include "Engine/Action.hpp"
#include "Engine/AKSoundEngine.hpp"
#include "Engine/Animation.hpp"
#include "Engine/Attachment.hpp"
#include "Engine/AudioEntity.hpp"
#include "Engine/BSP.hpp"
#include "Engine/Entity.hpp"
#include "Engine/Skeleton.hpp"
#include "Engine/Creature.hpp"
#include "Engine/DataStreamer.hpp"
#include "Engine/DamageRig.hpp"
#include "Engine/DebugDrawManager.hpp"
#include "Engine/Components.hpp"
#include "Engine/FXManager.hpp"
#include "Engine/ObjectResourceManager.hpp"
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
#include "Engine/TiDoGame.hpp"
#include "Engine/TrueCrowdDatabase.hpp"
#include "Engine/Wwise.hpp"

// Game
#include "Game/BulletManager.hpp"
#include "Game/EncounterBase.hpp"
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
#include "Game/Map.hpp"
#include "Game/PedSpawnManager.hpp"
#include "Game/ProgressionTracker.hpp"
#include "Game/RaceManager.hpp"
#include "Game/RadarSystem.hpp"
#include "Game/RoadNetwork.hpp"
#include "Game/SaveLoad.hpp"
#include "Game/Screen.hpp"
#include "Game/ScreenHud.hpp"
#include "Game/ScreenOverlay.hpp"
#include "Game/Store.hpp"
#include "Game/Tasks.hpp"
#include "Game/TimeOfDayManager.hpp"
#include "Game/UI.hpp"
#include "Game/Weapon.hpp"
#include "Game/WheeledVehicleManager.hpp"

#include "Globals.hpp"
#include "Utils.hpp"