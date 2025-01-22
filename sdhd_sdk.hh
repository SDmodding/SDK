//==================================================================================================
//
//		DESCRIPTION:
//			- This is main include file for Sleeping Dogs: Definitive Edition (SDK Dev-kit).
//			
//		REQUIREMENTS:
//			- At least C++17, some features are only enabled under C++20
//			- Windows & x64 Build only (You're building DLL for game so it should be obvious)
//			- MSVC (Probably Clang should work too, but not recommended)
// 
//==================================================================================================
#pragma once

#if (__cplusplus >= 202002L || _MSVC_LANG >= 202002L)
	#define SDK_CXX20 1
#endif

static_assert(sizeof(void*) == 8, "ERROR: (void*) isn't 64-bit make sure you're compiling for x64.");

//--------------------------------------------------
//	Includes
//--------------------------------------------------

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <new>
#include <xmmintrin.h>

//--------------------------------------------------
//	Windows Includes
//--------------------------------------------------

#define NOGDI
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <d3d11.h>

#define DIRECTINPUT_VERSION 0x800
#include <dinput.h>

//--------------------------------------------------
//	SDK Includes
//--------------------------------------------------

#include "sdk/types.hh"
#include "sdk/globals.hh"
#include "sdk/defines.hh"
#include "sdk/utils.hh"
#include "sdk/forwards.hh"
#include "sdk/hooks.hh"

#include "sdk/resource_uid.hh"

//--------------------------------------------------
//	Contrib
//--------------------------------------------------

#include "contrib/fastdelegate.hh"

#include "contrib/ak/soundengine/common/aktypes.hh"

//--------------------------------------------------
//	Quark
//--------------------------------------------------

#include "quark/types.hh"
#include "quark/checksum.hh"
#include "quark/array.hh"
#include "quark/fixedarray.hh"
#include "quark/safearray.hh"
#include "quark/bitflags.hh"
#include "quark/bitfield.hh"
#include "quark/list.hh"
#include "quark/safepointer.hh"
#include "quark/tree64.hh"
#include "quark/treerb.hh"
#include "quark/treerb64.hh"
#include "quark/offset.hh"
#include "quark/colour.hh"
#include "quark/noise.hh"
#include "quark/math.hh"
#include "quark/extramath.hh"
#include "quark/process.hh"
#include "quark/beziercurve.hh"
#include "quark/spline.hh"

#include "quark/internal/allocator.hh"

#include "quark/rangedvalue.hh"
#include "quark/resource.hh"
#include "quark/string.hh"
#include "quark/sharedstring.hh"
#include "quark/qset.hh"
#include "quark/qsymbol.hh"
#include "quark/qwisesymbol.hh"
#include "quark/qticks.hh"

#include "quark/memorypool.hh"
#include "quark/vramemorypool.hh"
#include "quark/memorystream.hh"

#include "quark/averagewindow.hh"
#include "quark/pidcontroller.hh"

#include "quark/task.hh"
#include "quark/reflection.hh"

#include "quark/reflection/reflectarray.hh"
#include "quark/reflection/reflectstring.hh"
#include "quark/reflection/reflecttype.hh"

//--------------------------------------------------
//	Other Contrib
//--------------------------------------------------

#include "contrib/havok/havok.hh"
#include "contrib/scaleform/scaleform.hh"

//--------------------------------------------------
//	Illusion
//--------------------------------------------------

#include "illusion/pc/modelplat.hh"

#include "illusion/bonepalette.hh"
#include "illusion/vertexdecl.hh"
#include "illusion/primitive.hh"
#include "illusion/state.hh"

#include "illusion/shader.hh"
#include "illusion/shadertemplate.hh"
#include "illusion/illusionuser/shaderuser.hh"

#include "illusion/renderstate.hh"

#include "illusion/illusionuser/textureuser.hh"
#include "illusion/texture.hh"
#include "illusion/rtexture.hh"

#include "illusion/pc/targetplat.hh"
#include "illusion/target.hh"

#include "illusion/material.hh"
#include "illusion/materialmodifier.hh"
#include "illusion/rmaterial.hh"

#include "illusion/model.hh"
#include "illusion/rmodel.hh"

#include "illusion/pc/unorderedaccessplat.hh"
#include "illusion/unorderedaccess.hh"

#include "illusion/stateblock.hh"

#include "illusion/stateargs.hh"
#include "illusion/submitcontext.hh"

//--------------------------------------------------
//	Agog Core
//--------------------------------------------------

#include "agogcore/astringref.hh"
#include "agogcore/astring.hh"
#include "agogcore/asymbol.hh"
#include "agogcore/anamed.hh"
#include "agogcore/aidptr.hh"
#include "agogcore/alist.hh"
#include "agogcore/aparraybase.hh"
#include "agogcore/apsizedarraybase.hh"
#include "agogcore/aparray.hh"
#include "agogcore/apcompactarray.hh"
#include "agogcore/arefcount.hh"
#include "agogcore/arefptr.hh"
#include "agogcore/apsorted.hh"

//--------------------------------------------------
//	Input
//--------------------------------------------------

#include "input/input.hh"
#include "input/hk/inputhk_pc.hh"
#include "input/pc/inputplat.hh"

//--------------------------------------------------
//	Hard Drive
//--------------------------------------------------

#include "harddrive/harddrivecontainer.hh"

//--------------------------------------------------
//	Shaders
//--------------------------------------------------

#include "shaders/stateblocks.hh"

//--------------------------------------------------
//	Render (Culling)
//--------------------------------------------------

#include "render/culling/culling.hh"
#include "render/culling/cullinfo.hh"

//--------------------------------------------------
//	Render
//--------------------------------------------------

#include "render/altcoloreffect.hh"
#include "render/viewmetrics.hh"
#include "render/view.hh"
#include "render/timeofday.hh"

#include "render/envcubemap.hh"
#include "render/loadscreen.hh"

#include "render/render.hh"
#include "render/rendercontext.hh"
#include "render/depthoffield.hh"

#include "render/pc/renderplat.hh"

//--------------------------------------------------
//	Camera
//--------------------------------------------------

#include "camera/camera.hh"

//--------------------------------------------------
//	Main
//--------------------------------------------------

#include "main/mainloop.hh"

//--------------------------------------------------
//	Streamer
//--------------------------------------------------

#include "streamer/datastreamer.hh"

//--------------------------------------------------
//	SceneDB
//--------------------------------------------------

#include "scenedb/streamingmemorymanager.hh"

//--------------------------------------------------
//	Audio
//--------------------------------------------------

#include "audio/ratelimitedfloat.hh"
#include "audio/regioncontainmentinfo.hh"
#include "audio/audioentity.hh"
#include "audio/audioevent.hh"
#include "audio/oneshot.hh"
#include "audio/oneshothandle.hh"

//--------------------------------------------------
//	ActionTree (Dependencies)
//--------------------------------------------------

#include "actiontree/binarray.hh"
#include "actiontree/binptrarray.hh"
#include "actiontree/binstring.hh"
#include "actiontree/tracksenum.hh"

//--------------------------------------------------
//	UEL
//--------------------------------------------------

#include "uel/uel.hh"
#include "uel/parameterdeclarations.hh"

//--------------------------------------------------
//	Expression
//--------------------------------------------------

#include "expression/membermap.hh"

//--------------------------------------------------
//	Animation
//--------------------------------------------------

#include "animation/weightsetdatabase.hh"
#include "animation/riginventory.hh"
#include "animation/skeleton.hh"
#include "animation/skeletalpose.hh"

//--------------------------------------------------
//	Wayfinder
//--------------------------------------------------

#include "wayfinder/wayfinder.hh"

//--------------------------------------------------
//	AI
//--------------------------------------------------

#include "ai/aibasics.hh"
#include "ai/faction.hh"
#include "ai/awareness/awarenessprofileanimation.hh"

#include "ai/vehicles/vehiclewayfinderclient.hh"
#include "ai/vehicles/waytraversalfinder.hh"

//--------------------------------------------------
//	ActionTree
//--------------------------------------------------

#include "actiontree/actiontreecomponentbase.hh"
#include "actiontree/condition.hh"
#include "actiontree/track.hh"
#include "actiontree/task.hh"
#include "actiontree/actionid.hh"
#include "actiontree/actionnode.hh"
#include "actiontree/actioncontext.hh"
#include "actiontree/actioncontroller.hh"
#include "actiontree/intention.hh"

//--------------------------------------------------
//	PropertySet
//--------------------------------------------------

#include "propertyset/propertysymbols.hh"
#include "propertyset/qpropertyset.hh"
#include "propertyset/qpropertylist.hh"
#include "propertyset/propertysetcache.hh"
#include "propertyset/propertysethandle.hh"
#include "propertyset/propertysetmanager.hh"
#include "propertyset/propertysetwrapper.hh"

//--------------------------------------------------
//	Skookum Script
//--------------------------------------------------

#include "skookumscript/sstyped.hh"
#include "skookumscript/ssclassdescbase.hh"
#include "skookumscript/ssqualifier.hh"
#include "skookumscript/ssparameterbase.hh"
#include "skookumscript/ssparameters.hh"
#include "skookumscript/ssobjectbase.hh"
#include "skookumscript/ssinstance.hh"
#include "skookumscript/ssdatainstance.hh"
#include "skookumscript/ssactor.hh"
#include "skookumscript/ssinvokablebase.hh"
#include "skookumscript/ssexpressionbase.hh"
#include "skookumscript/ssidentifier.hh"
#include "skookumscript/ssinvocation.hh"
#include "skookumscript/sscoroutine.hh"
#include "skookumscript/ssmethod.hh"
#include "skookumscript/ssobjectid.hh"
#include "skookumscript/ssclass.hh"
#include "skookumscript/ssactorclass.hh"
#include "skookumscript/ssinvokedbase.hh"
#include "skookumscript/ssinvokedcoroutine.hh"

//--------------------------------------------------
//	Skookum
//--------------------------------------------------

#include "skookum/tstimer.hh"

//--------------------------------------------------
//	Object Resource Management
//--------------------------------------------------

#include "objectresourcemanagement/resourcerequest.hh"
#include "objectresourcemanagement/truecrowddatabase.hh"
#include "objectresourcemanagement/meshresourceloader.hh"

//--------------------------------------------------
//	Part Database
//--------------------------------------------------

#include "partdatabase/parttypes.hh"
#include "partdatabase/partdatabase.hh"
#include "partdatabase/partloader.hh"

//--------------------------------------------------
//	Spawning
//--------------------------------------------------

#include "spawning/spawninterface.hh"

//--------------------------------------------------
//	Progression
//--------------------------------------------------

#include "progression/persistentdata/basictypes.hh"

#include "progression/gamestat/gamesnapshot.hh"
#include "progression/gamestat/gamestatdefinitions.hh"
#include "progression/gamestat/gamestattracker.hh"
#include "progression/gamestat/gamesaveload.hh"

#include "progression/upgrades/storefronttracker.hh"

#include "progression/pdatriggertracker.hh"
#include "progression/scenesettings.hh"
#include "progression/ssgameslice.hh"
#include "progression/gameslice.hh"

//--------------------------------------------------
//	Flow Control
//--------------------------------------------------

#include "flowcontrol/gamestate.hh"
#include "flowcontrol/gamestatecommon.hh"
#include "flowcontrol/flowcontrol.hh"

//--------------------------------------------------
//	Event System
//--------------------------------------------------

#include "eventsystem/eventbase.hh"

//--------------------------------------------------
//	Schema
//--------------------------------------------------

#include "schema/schema_health.hh"
#include "schema/schema_missionfailcondition.hh"
#include "schema/schema_physicsmover.hh"

//--------------------------------------------------
//	Physics
//--------------------------------------------------

#include "physics/baseobj.hh"
#include "physics/bitarray.hh"
#include "physics/constraints.hh"
#include "physics/collisionlayers.hh"
#include "physics/destructionbase.hh"
#include "physics/objectproperties.hh"
#include "physics/collisionmesh.hh"
#include "physics/sensorphantom.hh"
#include "physics/statemachine.hh"
#include "physics/sweptspherequery.hh"
#include "physics/bulletmanager.hh"
#include "physics/explosion.hh"
#include "physics/wind.hh"

#include "physics/vehicleinput.hh"
#include "physics/physicsvehicledna.hh"

//--------------------------------------------------
//	Road Network
//--------------------------------------------------

#include "roadnetwork/roadnetworknode.hh"
#include "roadnetwork/roadnetworkspawnpoint.hh"

//--------------------------------------------------
//	Sim
//--------------------------------------------------

#include "sim/rebindingcomponenthandle.hh"
#include "sim/simobject.hh"
#include "sim/simobjectgame.hh"
#include "sim/simobjectutil.hh"
#include "sim/sim.hh"
#include "sim/localplayer.hh"
#include "sim/metrics.hh"

#include "sim/interfaces/updateinterface.hh"

//--------------------------------------------------
//	UEL
//--------------------------------------------------

#include "uel/component.hh"

//--------------------------------------------------
//	Skookum
//--------------------------------------------------

#include "skookum/tsactor.hh"

//--------------------------------------------------
//	Model Asset
//--------------------------------------------------

#include "modelasset/modelassetdata.hh"
#include "modelasset/modelasset.hh"

//--------------------------------------------------
//	Physics
//--------------------------------------------------

#include "physics/components/waterfloatingtrackerbasecomponent.hh"
#include "physics/components/waterfloatingtrackercomponent.hh"

#include "physics/rigidbody.hh"
#include "physics/components/rigidbodycomponent.hh"

#include "physics/physicsvehicle.hh"

//--------------------------------------------------
//	Vehicles
//--------------------------------------------------

#include "vehicles/tempvehicletunables.hh"

#include "vehicles/ai/vehiclecombatstats.hh"

#include "vehicles/components/vehicledrivercomponent.hh"
#include "vehicles/components/aidrivercomponent.hh"
#include "vehicles/components/vehiclemovercomponent.hh"

//--------------------------------------------------
//	Effects
//--------------------------------------------------

#include "effects/radarsystem.hh"

//--------------------------------------------------
//	Gamestate
//--------------------------------------------------

#include "gamestate/hk/pedspawnmanager.hh"

//--------------------------------------------------
//	Gameplay
//--------------------------------------------------

#include "gameplay/actiontree/tasksgame.hh"
#include "gameplay/actiontree/tracksgame.hh"

//--------------------------------------------------
//	Sim Components
//--------------------------------------------------

#include "sim/components/targeting/subtargetinglocationdynamic.hh"
#include "sim/components/targeting/subtargetingprofile.hh"
#include "sim/components/targeting/targetingsimobject.hh"
#include "sim/components/targeting/targetingmap.hh"
#include "sim/components/targeting/targetingsystembasecomponent.hh"

#include "sim/components/transformnodecomponent.hh"
#include "sim/components/actiontreecomponent.hh"

#include "sim/components/vehicleoccupantcomponent.hh"
#include "sim/components/characteroccupantcomponent.hh"

#include "sim/components/hitreactioncomponent.hh"
#include "sim/components/healthcomponent.hh"

#include "sim/components/simobjectpropertiescomponent.hh"
#include "sim/components/missionfailconditioncomponent.hh"

//--------------------------------------------------
//	FX
//--------------------------------------------------

#include "fx/sharedpointer.hh"
#include "fx/hardwareocclusionquery.hh"
#include "fx/fxsimcomponent.hh"
#include "fx/beam.hh"
#include "fx/fxmanager.hh"

//--------------------------------------------------
//	Gamescene
//--------------------------------------------------

#include "gamescene/scenelayerresource.hh"
#include "gamescene/sceneobjectproperties.hh"

#include "gamescene/components/hintcomponentbase.hh"
#include "gamescene/components/marker.hh"

//--------------------------------------------------
//	Spawning
//--------------------------------------------------

#include "spawning/parkingspot.hh"

//--------------------------------------------------
//	AI
//--------------------------------------------------

#include "ai/encounters/encounterunitinfo.hh"
#include "ai/encounters/encounterbase.hh"

#include "ai/cops/copsystem.hh"
#include "ai/aiscriptinterfacecomponent.hh"

//--------------------------------------------------
//	UI
//--------------------------------------------------

#include "ui/uihkutils.hh"
#include "ui/uilanguages.hh"
#include "ui/uilocalizationchunk.hh"
#include "ui/uimessage.hh"
#include "ui/uiscreenrenderable.hh"
#include "ui/uiscreen.hh"
#include "ui/uiscreenfactory.hh"
#include "ui/uigfxallocator.hh"
#include "ui/uigfxfileopener.hh"
#include "ui/uigfxtexture.hh"
#include "ui/uigfxtranslator.hh"
#include "ui/uitween.hh"
#include "ui/uiinputhandler.hh"
#include "ui/uiscreenmanager.hh"