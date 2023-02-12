#pragma once

#include <unordered_map>
//

uintptr_t BaseAddress = reinterpret_cast<uintptr_t>(GetModuleHandleA(0));
#define UFG_RVA(x) (BaseAddress + x)

#define UFG_PAD_INSERT(x, y) x ## y
#define UFG_PAD_DEFINE(x, y) UFG_PAD_INSERT(x, y)
#define UFG_PAD(size) char UFG_PAD_DEFINE(padding_, __LINE__)[size]

#include "Defines/Math.hpp"

#include "Templates.hpp"
#include "Classes.hpp"
#include "Enums.hpp"
#include "Typedefs.hpp"
#include "Functions.hpp"

// ..
#include "Defines/NodePlayables.hpp"
#include "Defines/BoneUID.hpp"
#include "Defines/TypeUID.hpp"

#include "Engine/Illusion.hpp"
#include "Engine/Render.hpp"

#include "Engine/Resources.hpp"
#include "Engine/PropertySet.hpp"
#include "Engine/ResourceInventory.hpp"
#include "Engine/ResourceWarehouse.hpp"

#include "Engine/Metrics.hpp"

#include "Engine/Action.hpp"
#include "Engine/Entity.hpp"
#include "Engine/Skeleton.hpp"
#include "Engine/Creature.hpp"
#include "Engine/DamageRig.hpp"
#include "Engine/Components.hpp"
#include "Engine/FXManager.hpp"
#include "Engine/Sim.hpp"
#include "Engine/SimVehicle.hpp"
#include "Engine/SimWeapon.hpp"
#include "Engine/SimCharacter.hpp"
#include "Engine/SimObjectUtility.hpp"
#include "Engine/RenderWorld.hpp"
#include "Engine/Camera.hpp"
#include "Engine/Director.hpp"
#include "Engine/StreamFileWrapper.hpp"
#include "Engine/PhysicsSystem.hpp"

// ..
#include "Game/CopSystem.hpp"
#include "Game/EventDispatcher.hpp"
#include "Game/GameCamera.hpp"
#include "Game/GameSlice.hpp"
#include "Game/GameStat.hpp"
#include "Game/Input.hpp"
#include "Game/LocalPlayer.hpp"
#include "Game/Vehicle.hpp"
#include "Game/Map.hpp"
#include "Game/ProgressionTracker.hpp"
#include "Game/RaceManager.hpp"
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

#include "Utils.hpp"

namespace UFG
{
	namespace Global
	{
		uintptr_t WndProc = UFG_RVA(0x6A2770);
		uintptr_t DXGISwapChain = UFG_RVA(0x2439B10);
		HWND* m_hWindow = reinterpret_cast<HWND*>(UFG_RVA(0x249CDF0));
	}
}