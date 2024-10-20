//==================================================================================================
//
//		DESCRIPTION:
//			- This is main include file for Sleeping Dogs: Definitive Edition (SDK Dev-kit).
//			
//		REQUIREMENTS:
//			- At least C++17
//			- Windows & x64 Build only (You're building DLL for game so it should be obvious)
//			- MSVC (Probably Clang should work too, but not recommended)
// 
//==================================================================================================
#pragma once

static_assert(sizeof(void*) == 8, "ERROR: (void*) isn't 64-bit make sure you're compiling for x64.");

/* Includes */

#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <new>

/* Windows Includes */

#define NOGDI
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <d3d11.h>

/* SDK Includes */

#include "types.hh"
#include "globals.hh"
#include "defines.hh"

/* Contrib Includes */
#include "contrib/fastdelegate.hh"

/* Quark Includes */

#include "quark/checksum.hh"
#include "quark/array.hh"
#include "quark/list.hh"
#include "quark/safepointer.hh"
#include "quark/treerb.hh"
#include "quark/offset.hh"
#include "quark/math.hh"
#include "quark/resource.hh"
#include "quark/string.hh"
#include "quark/qset.hh"
#include "quark/qsymbol.hh"
#include "quark/qticks.hh"

/* PropertySet Includes */

#include "propertyset/qpropertyset.hh"

/* Sim Includes */

#include "sim/rebindingcomponenthandle.hh"
#include "sim/simobject.hh"
#include "sim/simobjectgame.hh"
#include "sim/simobjectutil.hh"
#include "sim/sim.hh"
#include "sim/localplayer.hh"
#include "sim/metrics.hh"

#include "sim/components/transformnodecomponent.hh"

/* Gamescene Includes */

#include "gamescene/scenelayerresource.hh"
#include "gamescene/sceneobjectproperties.hh"