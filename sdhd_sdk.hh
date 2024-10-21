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

/* Contrib */
#include "contrib/fastdelegate.hh"

/* Quark */

#include "quark/types.hh"
#include "quark/checksum.hh"
#include "quark/array.hh"
#include "quark/list.hh"
#include "quark/safepointer.hh"
#include "quark/treerb.hh"
#include "quark/treerb64.hh"
#include "quark/offset.hh"
#include "quark/math.hh"
#include "quark/resource.hh"
#include "quark/string.hh"
#include "quark/sharedstring.hh"
#include "quark/qset.hh"
#include "quark/qsymbol.hh"
#include "quark/qticks.hh"

/* ActionTree */

#include "actiontree/binarray.hh"
#include "actiontree/binptrarray.hh"
#include "actiontree/binstring.hh"

/* UEL */

#include "uel/uel.hh"

/* Expression */

#include "expression/membermap.hh"

/* ActionTree */

#include "actiontree/actiontreecomponentbase.hh"
#include "actiontree/condition.hh"
#include "actiontree/track.hh"
#include "actiontree/task.hh"
#include "actiontree/actionid.hh"
#include "actiontree/actionnode.hh"
#include "actiontree/actioncontext.hh"
#include "actiontree/actioncontroller.hh"

/* PropertySet */

#include "propertyset/qpropertyset.hh"

/* Flowcontrol */

#include "flowcontrol/gamestate.hh"
#include "flowcontrol/gamestatecommon.hh"
#include "flowcontrol/flowcontrol.hh"

/* Schema */

#include "schema/schema_health.hh"

/* Physics */

#include "physics/bulletmanager.hh"
#include "physics/explosion.hh"

/* Sim */

#include "sim/rebindingcomponenthandle.hh"
#include "sim/simobject.hh"
#include "sim/simobjectgame.hh"
#include "sim/simobjectutil.hh"
#include "sim/sim.hh"
#include "sim/localplayer.hh"
#include "sim/metrics.hh"

#include "sim/interfaces/updateinterface.hh"

#include "sim/components/transformnodecomponent.hh"
#include "sim/components/hitreactioncomponent.hh"
#include "sim/components/healthcomponent.hh"

/* Gamescene */

#include "gamescene/scenelayerresource.hh"
#include "gamescene/sceneobjectproperties.hh"

/* UI */

#include "ui/uihkutils.hh"