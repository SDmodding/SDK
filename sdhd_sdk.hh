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

#ifndef SDK_GDI
	#define NOGDI
	#define NOBITMAP
#endif
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <d3d11.h>

#define DIRECTINPUT_VERSION 0x800
#include <dinput.h>
#include <Xinput.h>

//--------------------------------------------------
//	SDK Includes
//--------------------------------------------------

#include "sdk/types.hh"
#include "sdk/globals.hh"
#include "sdk/defines.hh"
#include "sdk/utils.hh"
#include "sdk/forwards.hh"
#include "sdk/hooks.hh"

#include "sdk/bone_uid.hh"
#include "sdk/resource_uid.hh"
#include "sdk/stateparam_uid.hh"

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
#include "quark/circulararray.hh"
#include "quark/fixedarray.hh"
#include "quark/safearray.hh"
#include "quark/bitarray.hh"
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
#include "quark/halfmath.hh"
#include "quark/extramath.hh"
#include "quark/qbox.hh"
#include "quark/process.hh"
#include "quark/beziercurve.hh"
#include "quark/spline.hh"
#include "quark/qbytestream.hh"

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
#include "quark/memorypoollinearallocator.hh"
#include "quark/vramemorypool.hh"
#include "quark/memorystream.hh"

#include "quark/file.hh"
#include "quark/resourcefilesystem.hh"

#include "quark/averagewindow.hh"
#include "quark/pidcontroller.hh"

#include "quark/task.hh"
#include "quark/reflection.hh"

#include "quark/reflection/reflectarray.hh"
#include "quark/reflection/reflectstring.hh"
#include "quark/reflection/reflecttype.hh"
#include "quark/reflection/reflectinventory.hh"

#include "quark/internal/resourceinternal.hh"

//--------------------------------------------------
//	Other Contrib
//--------------------------------------------------

#include "contrib/havok/havok.hh"
#include "contrib/scaleform/scaleform.hh"
#include "contrib/steam/steam.hh"

//--------------------------------------------------
//	Illusion
//--------------------------------------------------

#include "illusion/pc/illusionplat.hh"
#include "illusion/illusion.hh"

#include "illusion/pc/modelplat.hh"

#include "illusion/bonepalette.hh"
#include "illusion/vertexdecl.hh"
#include "illusion/vertexdescriptor.hh"
#include "illusion/primitive.hh"
#include "illusion/state.hh"

#include "illusion/shader.hh"
#include "illusion/shadertemplate.hh"
#include "illusion/illusionuser/shaderuser.hh"

#include "illusion/renderstate.hh"

#include "illusion/illusionuser/textureuser.hh"
#include "illusion/texture.hh"
#include "illusion/rtexture.hh"
#include "illusion/pc/textureplat.hh"

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
#include "illusion/renderqueue.hh"

#include "illusion/memimageschema.hh"

#include "illusion/internal/factoryplat.hh"

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

#include "agogcore/avcompactarraybase.hh"
#include "agogcore/avcompactsorted.hh"

#include "agogcore/amemory.hh"

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

#include "render/culling/rasterize.hh"
#include "render/culling/culling.hh"
#include "render/culling/cullinfo.hh"

//--------------------------------------------------
//	Render
//--------------------------------------------------

#include "render/dynamic.hh"
#include "render/altcoloreffect.hh"
#include "render/viewmetrics.hh"
#include "render/view.hh"
#include "render/timeofday.hh"

#include "render/envcubemap.hh"
#include "render/loadscreen.hh"

#include "render/render.hh"
#include "render/rendercontext.hh"
#include "render/depthoffield.hh"

#include "render/skinning/skinning.hh"
#include "render/skinning/softbody.hh"

#include "render/pc/renderplat.hh"

#include "render/font.hh"

#include "render/debugdraw.hh"

#include "render/renderworldscreenshot.hh"

//--------------------------------------------------
//	Main
//--------------------------------------------------

#include "main/bigfilelogic.hh"

//--------------------------------------------------
//	Streamer
//--------------------------------------------------

#include "streamer/streampool.hh"
#include "streamer/streamingmemorymanager.hh"
#include "streamer/datastreamer.hh"
#include "streamer/streamermetrics.hh"
#include "streamer/streamresourceloader.hh"
#include "streamer/streamfilewrapper.hh"
#include "streamer/bigfile.hh"

//--------------------------------------------------
//	SceneDB
//--------------------------------------------------

#include "scenedb/bsp.hh"
#include "scenedb/streamingmemorymanager.hh"
#include "scenedb/scenedb.hh"
#include "scenedb/scenerygroup.hh"
#include "scenedb/sectionlayout.hh"
#include "scenedb/sectionchooser.hh"

//--------------------------------------------------
//	Audio
//--------------------------------------------------

#include "audio/ratelimitedfloat.hh"
#include "audio/regioncontainmentinfo.hh"
#include "audio/audioevent.hh"
#include "audio/audioentity.hh"
#include "audio/oneshot.hh"
#include "audio/oneshothandle.hh"

#include "audio/globalaudio.hh"

//--------------------------------------------------
//	UEL
//--------------------------------------------------

#include "uel/uel.hh"
#include "uel/parameterdeclarations.hh"

//--------------------------------------------------
//	ActionTree (Dependencies)
//--------------------------------------------------

#include "actiontree/binarray.hh"
#include "actiontree/binptrarray.hh"
#include "actiontree/binstring.hh"
#include "actiontree/enums.hh"
#include "actiontree/tracksenum.hh"

//--------------------------------------------------
//	Expression
//--------------------------------------------------

#include "expression/membermap.hh"

//--------------------------------------------------
//	ActionTree (Dependencies 2)
//--------------------------------------------------

#include "actiontree/condition.hh"
#include "actiontree/track.hh"
#include "actiontree/task.hh"
#include "actiontree/actionid.hh"

//--------------------------------------------------
//	ActionTree (Tasks, Tracks)
//--------------------------------------------------

#include "animation/actiontree/tasksanimation.hh"
#include "animation/actiontree/tracksanimation.hh"

#include "camera/actiontree/taskscamera.hh"
#include "camera/actiontree/trackscamera.hh"

//--------------------------------------------------
//	Animation
//--------------------------------------------------

#include "animation/weightsetdatabase.hh"
#include "animation/attachment.hh"
#include "animation/animationdatabase.hh"
#include "animation/animationresource.hh"
#include "animation/motionphase.hh"
#include "animation/skeletalanimation.hh"
#include "animation/blendtree.hh"
#include "animation/riginventory.hh"
#include "animation/riginstance.hh"
#include "animation/riginfo.hh"
#include "animation/skeleton.hh"
#include "animation/skeletalpose.hh"
#include "animation/posedrivers.hh"
#include "animation/poserecipe.hh"
#include "animation/posetask.hh"
#include "animation/creature.hh"
#include "animation/modeldatabase.hh"
#include "animation/damagerig.hh"

//--------------------------------------------------
//	Wayfinder
//--------------------------------------------------

#include "wayfinder/wayfinder.hh"

//--------------------------------------------------
//	Event System
//--------------------------------------------------

#include "eventsystem/eventbase.hh"
#include "eventsystem/eventdescriptions.hh"

//--------------------------------------------------
//	Ticket
//--------------------------------------------------

#include "ticket/ticket.hh"
#include "ticket/ticketbooth.hh"

//--------------------------------------------------
//	AI
//--------------------------------------------------

#include "ai/aibasics.hh"

#include "ai/factionenum.hh"
#include "ai/faction.hh"

#include "ai/nearbycharactermanager.hh"

#include "ai/aisidewalkdata_game.hh"
#include "ai/aisidewalkgraph.hh"

#include "ai/stimulusdescriptions.hh"
#include "ai/stimulusparameters.hh"
#include "ai/stimulus.hh"

#include "ai/awareness/awarenessprofileanimation.hh"

//--------------------------------------------------
//	ActionTree
//--------------------------------------------------

#include "actiontree/actiontreecomponentbase.hh"

#include "actiontree/actionnode.hh"
#include "actiontree/actioncontext.hh"
#include "actiontree/actioncontroller.hh"
#include "actiontree/intention.hh"

#include "actiontree/actionnodeplayabledatabase.hh"

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
#include "skookumscript/ssmethodcall.hh"
#include "skookumscript/ssobjectid.hh"
#include "skookumscript/ssclass.hh"
#include "skookumscript/ssactorclass.hh"
#include "skookumscript/ssinvokedbase.hh"
#include "skookumscript/ssinvokedcoroutine.hh"
#include "skookumscript/ssinvokedmethod.hh"
#include "skookumscript/sscode.hh"
#include "skookumscript/sssymbol.hh"
#include "skookumscript/ssbrain.hh"
#include "skookumscript/sscontextclassbase.hh"
#include "skookumscript/ssinvokableclass.hh"
#include "skookumscript/sstypedcontext.hh"
#include "skookumscript/ssparser.hh"

//--------------------------------------------------
//	Skookum
//--------------------------------------------------

#include "skookum/tstimer.hh"
#include "skookum/scriptcache.hh"

//--------------------------------------------------
//	Gameplay (Action Tree)
//--------------------------------------------------

#include "gameplay/actiontree/conditionsgame.hh"
#include "gameplay/actiontree/tasksgame.hh"
#include "gameplay/actiontree/tracksgame.hh"

//--------------------------------------------------
//	Schema
//--------------------------------------------------

#include "schema/schema_baseanimation.hh"
#include "schema/schema_health.hh"
#include "schema/schema_interactable.hh"
#include "schema/schema_missionfailcondition.hh"
#include "schema/schema_physicsmover.hh"
#include "schema/schema_streamedresource.hh"

#include "schema/schema_simobjectproperties.hh"
#include "schema/schema_characterproperties.hh"

#include "schema/schema_sensor.hh"

//--------------------------------------------------
//	Object Resource Management
//--------------------------------------------------

#include "objectresourcemanagement/resourcerequest.hh"
#include "objectresourcemanagement/truecrowddefinition.hh"
#include "objectresourcemanagement/truecrowddatabase.hh"
#include "objectresourcemanagement/meshresourceloader.hh"
#include "objectresourcemanagement/resourcepool.hh"
#include "objectresourcemanagement/objectresourcemanager.hh"

//--------------------------------------------------
//	Part Database
//--------------------------------------------------

#include "partdatabase/parttypes.hh"
#include "partdatabase/partdatabase.hh"
#include "partdatabase/partloader.hh"

//--------------------------------------------------
//	Progression
//--------------------------------------------------

#include "progression/persistentdata/basictypes.hh"

#include "progression/gamestat/gamesnapshot.hh"
#include "progression/gamestat/gamestatdefinitions.hh"
#include "progression/gamestat/gamestattracker.hh"
#include "progression/gamestat/gamesaveload.hh"

#include "progression/pdatriggertracker.hh"
#include "progression/objectivetracker.hh"
#include "progression/secondaryobjectivetracker.hh"
#include "progression/casetracker.hh"

#include "progression/scenesettings.hh"
#include "progression/ssgameslice.hh"
#include "progression/gameslice.hh"
#include "progression/gameslicestreamer.hh"

//--------------------------------------------------
//	Flow Control
//--------------------------------------------------

#include "flowcontrol/gamesetup.hh"
#include "flowcontrol/gamestate.hh"
#include "flowcontrol/gamestatecommon.hh"
#include "flowcontrol/flowcontrol.hh"

//--------------------------------------------------
//	Physics
//--------------------------------------------------

#include "physics/threadsafequeue.hh"
#include "physics/baseobj.hh"
#include "physics/bitarray.hh"
#include "physics/broadphase.hh"
#include "physics/constraints.hh"
#include "physics/collisionlayers.hh"
#include "physics/destructionbase.hh"
#include "physics/objectproperties.hh"
#include "physics/collisionmesh.hh"
#include "physics/sensorphantom.hh"
#include "physics/statemachine.hh"
#include "physics/sweptspherequery.hh"
#include "physics/explosion.hh"
#include "physics/volumeproperties.hh"
#include "physics/phantomcallback.hh"
#include "physics/wind.hh"

#include "physics/vehicleinput.hh"
#include "physics/physicsvehicledna.hh"

#include "physics/activeregion.hh"
#include "physics/customcollisionfilter.hh"
#include "physics/raycast.hh"
#include "physics/worldboundaries.hh"

#include "physics/worldcollisionevents.hh"

#include "physics/physicsmemory.hh"
#include "physics/physicssystem.hh"
#include "physics/physics.hh"

//--------------------------------------------------
//	Road Network
//--------------------------------------------------

#include "roadnetwork/roadnetworknode.hh"
#include "roadnetwork/roadnetworkwayfinding.hh"
#include "roadnetwork/roadnetworkresources.hh"
#include "roadnetwork/roadnetworkguide.hh"
#include "roadnetwork/roadnetworkspawnpoint.hh"
#include "roadnetwork/roadnetworkvisibilearea.hh"

//--------------------------------------------------
//	Daemon Manager
//--------------------------------------------------

#include "daemonmanager/daemon.hh"

//--------------------------------------------------
//	Navigation
//--------------------------------------------------

#include "navigation/navparams.hh"
#include "navigation/navposition.hh"
#include "navigation/navresource.hh"
#include "navigation/navdynamicoutline.hh"

#include "navigation/havok/havoknavposition.hh"

#include "navigation/navobject.hh"
#include "navigation/navwaypoint.hh"
#include "navigation/navobjectparkour.hh"
#include "navigation/navpath.hh"
#include "navigation/navdaemon.hh"

#include "navigation/navtestdeferrer.hh"
#include "navigation/navmodulepathing.hh"
#include "navigation/navmodulelocal.hh"
#include "navigation/navmodulecontroller.hh"

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
#include "sim/interfaces/statecomponent.hh"
#include "sim/interfaces/charactercontrollerinterface.hh"

//--------------------------------------------------
//	Camera (Dependencies)
//--------------------------------------------------

#include "camera/camera.hh"
#include "camera/base.hh"
#include "camera/director.hh"
#include "camera/subject.hh"

//--------------------------------------------------
//	Sim Components (Important)
//--------------------------------------------------

#include "sim/components/statecomponent.hh"

#include "sim/components/targeting/subtargetinglocationdynamic.hh"
#include "sim/components/targeting/subtargetingprofile.hh"
#include "sim/components/targeting/targetingsimobject.hh"
#include "sim/components/targeting/targetingmap.hh"
#include "sim/components/targeting/targetingsystembasecomponent.hh"

#include "sim/components/transformnodecomponent.hh"

#include "sim/components/charactersubjectcomponent.hh"

#include "sim/components/compositelookcomponent.hh"

#include "sim/components/progressiontriggercomponent.hh"

//--------------------------------------------------
//	Props
//--------------------------------------------------

#include "props/components/doorcomponent.hh"

//--------------------------------------------------
//	Gamescene
//--------------------------------------------------

#include "gamescene/scenelayerresource.hh"
#include "gamescene/sceneobjectproperties.hh"

#include "gamescene/components/hintcomponentbase.hh"
#include "gamescene/components/marker.hh"

//--------------------------------------------------
//	NIS
//--------------------------------------------------

#include "nis/nistracks.hh"

#include "nis/nislightgroup.hh"
#include "nis/nisnodes.hh"
#include "nis/nisinstance.hh"
#include "nis/nisspatialdata.hh"
#include "nis/nismanager.hh"

//--------------------------------------------------
//	Spawning
//--------------------------------------------------

#include "spawning/spawninterface.hh"
#include "spawning/trafficregion.hh"

//--------------------------------------------------
//	Progression 2
//--------------------------------------------------

#include "progression/upgrades/storefronttracker.hh"
#include "progression/progressiontracker.hh"

//--------------------------------------------------
//	Camera (Components)
//--------------------------------------------------

#include "camera/gamecameracomponent.hh"
#include "camera/animatedcamera.hh"
#include "camera/chasecamera.hh"
#include "camera/debugcamera.hh"
#include "camera/followcamera.hh"
#include "camera/progressioncamera.hh"
#include "camera/scriptcamera.hh"
#include "camera/turfcamera.hh"

//--------------------------------------------------
//	Object Resource Management
//--------------------------------------------------

#include "objectresourcemanagement/streamedresourcecomponent.hh"
#include "objectresourcemanagement/weaponmanager.hh"

//--------------------------------------------------
//	UEL
//--------------------------------------------------

#include "uel/component.hh"

//--------------------------------------------------
//	Skookum
//--------------------------------------------------

#include "skookum/tsactor.hh"
#include "skookum/skookummgr.hh"

//--------------------------------------------------
//	TIDO
//--------------------------------------------------

#include "tido/policescanneraudio.hh"
#include "tido/nisaudio.hh"

#include "tido/basedialogueutils.hh"
#include "tido/dialogueutils.hh"
#include "tido/audioentitycomponent.hh"
#include "tido/actoraudiocomponent.hh"
#include "tido/dialogueanimationcomponent.hh"
#include "tido/enginecurveaudio.hh"

//--------------------------------------------------
//	Model Asset
//--------------------------------------------------

#include "modelasset/modelassetdata.hh"
#include "modelasset/modelasset.hh"

//--------------------------------------------------
//	FX
//--------------------------------------------------

#include "fx/sharedpointer.hh"
#include "fx/hardwareocclusionquery.hh"
#include "fx/fxsimcomponent.hh"
#include "fx/decal.hh"
#include "fx/audiofx.hh"
#include "fx/beam.hh"
#include "fx/coronaflare.hh"
#include "fx/dynamiclight.hh"
#include "fx/effectemitter.hh"
#include "fx/flare.hh"
#include "fx/fxforce.hh"
#include "fx/geo.hh"
#include "fx/lightning.hh"
#include "fx/trackstrip.hh"
#include "fx/volumetriceffect.hh"
#include "fx/particleemittersettings.hh"
#include "fx/fxfactory.hh"
#include "fx/fxmanager.hh"

//--------------------------------------------------
//	SceneDB
//--------------------------------------------------

#include "scenedb/dynamicscenerygroup.hh"

//--------------------------------------------------
//	Physics
//--------------------------------------------------

#include "physics/bulletmanager.hh"

#include "physics/components/phantomvolumecomponent.hh"
#include "physics/components/waterfloatingtrackerbasecomponent.hh"
#include "physics/components/waterfloatingtrackercomponent.hh"

#include "physics/rigidbody.hh"
#include "physics/characterrigidbody.hh"
#include "physics/components/rigidbodycomponent.hh"

#include "physics/detectragdollpenetration.hh"
#include "physics/ragdoll.hh"

#include "physics/components/characterphysicscomponent.hh"
#include "physics/components/ragdollcomponent.hh"

#include "physics/components/sensorcomponent.hh"
#include "physics/components/statemachinecomponent.hh"

#include "physics/engine.hh"
#include "physics/transmission.hh"
#include "physics/vehicleinstance.hh"
#include "physics/brakes.hh"
#include "physics/steering.hh"
#include "physics/aerodynamics.hh"

#include "physics/physicsvehicle.hh"

#include "physics/covercorner.hh"
#include "physics/dynamiccover.hh"
#include "physics/coverdataresource.hh"
#include "physics/covercornerhandle.hh"

#include "physics/parkourcontainer.hh"
#include "physics/components/parkourcomponent.hh"

//--------------------------------------------------
//	Vehicles
//--------------------------------------------------

#include "vehicles/tempvehicletunables.hh"
#include "vehicles/vehicleeffectmanager.hh"

#include "vehicles/ai/crumbtrail.hh"
#include "vehicles/ai/racetrail.hh"
#include "vehicles/ai/navguide.hh"
#include "vehicles/ai/vehiclecombatstats.hh"
#include "vehicles/ai/vehicleformations.hh"
#include "vehicles/ai/vehiclewayfinderclient.hh"
#include "vehicles/ai/waytraversalfinder.hh"

#include "vehicles/roadnetwork/truedirectionmanager.hh"

#include "vehicles/components/vehicledrivercomponent.hh"
#include "vehicles/components/aidrivercomponent.hh"
#include "vehicles/components/vehicleeffectscomponent.hh"
#include "vehicles/components/vehiclemovercomponent.hh"
#include "vehicles/components/roadspacecomponent.hh"

#include "vehicles/components/vehicleaudiocomponent/parameters.hh"
#include "vehicles/components/vehicleaudiocomponent/enginemodel2.hh"
#include "vehicles/components/vehicleaudiocomponent/damagemodel.hh"
#include "vehicles/components/vehicleaudiocomponent/environmentalmodel.hh"
#include "vehicles/components/vehicleaudiocomponent/radio.hh"
#include "vehicles/components/vehicleaudiocomponent/driverreactions.hh"
#include "vehicles/components/vehicleaudiocomponent.hh"

#include "vehicles/components/humandrivercomponent.hh"

#include "vehicles/vehicleutil.hh"

#include "vehicles/wheeledvehiclenavigationdata.hh"
#include "vehicles/wheeledvehiclemanager.hh"

//--------------------------------------------------
//	Effects
//--------------------------------------------------

#include "effects/radarsystem.hh"

//--------------------------------------------------
//	Gamestate
//--------------------------------------------------

#include "gamestate/hk/pedspawnmanager.hh"

//--------------------------------------------------
//	AI
//--------------------------------------------------

#include "ai/cover/coverobjectbase.hh"
#include "ai/cover/coverobjectgroup.hh"
#include "ai/cover/coverobjectparkour.hh"
#include "ai/cover/coverposition.hh"

#include "ai/encounters/encounterunitinfo.hh"
#include "ai/encounters/encounterbase.hh"

#include "ai/knowledge/pedknowledgebase.hh"

//--------------------------------------------------
//	Sim Components
//--------------------------------------------------

#include "sim/components/aiming/aimingbasecomponent.hh"
#include "sim/components/aiming/aimingnpccomponent.hh"
#include "sim/components/aiming/aimingplayercomponent.hh"

#include "sim/components/actiontreecomponent.hh"
#include "sim/components/baseanimationcomponent.hh"
#include "sim/components/characteranimationcomponent.hh"
#include "sim/components/animationlodcomponent.hh"
#include "sim/components/facialactiontreecomponent.hh"

#include "sim/components/charactereffectscomponent.hh"

#include "sim/components/interactioncomponent.hh"

#include "sim/components/vehicleoccupantcomponent.hh"
#include "sim/components/characteroccupantcomponent.hh"

#include "sim/components/hitreactioncomponent.hh"
#include "sim/components/healthcomponent.hh"

#include "sim/components/facemetercomponent.hh"

#include "sim/components/inventorycomponent.hh"
#include "sim/components/inventoryitemcomponent.hh"

#include "sim/components/simobjectpropertiescomponent.hh"
#include "sim/components/simobjectcharacterpropertiescomponent.hh"
#include "sim/components/simobjectweaponpropertiescomponent.hh"

#include "sim/components/guncomponent.hh"

#include "sim/components/missionfailconditioncomponent.hh"
#include "sim/components/copunitcomponent.hh"

#include "sim/components/powermanagementcomponent.hh"
#include "sim/components/worldcontextcomponent.hh"

//--------------------------------------------------
//	ActionTree
//--------------------------------------------------

#include "actiontree/actiontreeresourcescomponent.hh"

//--------------------------------------------------
//	Render
//--------------------------------------------------

#include "render/renderworld.hh"

#include "render/components/compositedrawablecomponent.hh"
#include "render/highlighteffect.hh"

#include "render/renderstageplugin.hh"
#include "render/posteffects.hh"

#include "render/cloud.hh"
#include "render/skymarshall.hh"

//--------------------------------------------------
//	Spawning
//--------------------------------------------------

#include "spawning/parkingspot.hh"

//--------------------------------------------------
//	AI
//--------------------------------------------------

#include "ai/cops/copsystem.hh"
#include "ai/aiactiontreecomponent.hh"
#include "ai/aiscriptinterfacecomponent.hh"
#include "ai/stimulusreceivercomponent.hh"
#include "ai/aicharactercontrollercomponent.hh"
#include "ai/aientitycomponent.hh"
#include "ai/attackrightscomponent.hh"
#include "ai/getinformationcomponent.hh"
#include "ai/getinpedformationcomponent.hh"
#include "ai/hasattackrequestcomponent.hh"
#include "ai/pedformationmanagercomponent.hh"
#include "ai/groupcomponent.hh"

//--------------------------------------------------
//	Navigation
//--------------------------------------------------

#include "navigation/navcomponent.hh"

//--------------------------------------------------
//	Online2
//--------------------------------------------------

#include "online2/onlinemanager.hh"
#include "online2/osuitemanager.hh"
#include "online2/osuiteleaderboardmanager.hh"

//--------------------------------------------------
//	Movie Player
//--------------------------------------------------

#include "movieplayer/movieplayer.hh"

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
#include "ui/uiscreeninvokequeue.hh"
#include "ui/uigfxallocator.hh"
#include "ui/uigfxfileopener.hh"
#include "ui/uigfxtexture.hh"
#include "ui/uigfxtranslator.hh"
#include "ui/uitween.hh"
#include "ui/uiinputhandler.hh"
#include "ui/uiscreenmanager.hh"
#include "ui/uihktweakables.hh"

#include "ui/tiledmap/uirenderquad.hh"
#include "ui/tiledmap/uitiledmapmath.hh"
#include "ui/tiledmap/uitiledmapzoomcalc.hh"
#include "ui/tiledmap/uitiledmapwidget.hh"
#include "ui/tiledmap/uitiledmapgps.hh"

#include "ui/widget/uihktimeofdaywidget.hh"
#include "ui/widget/uihktextoverlay.hh"
#include "ui/widget/uihk_nisframecounterwidget.hh"
#include "ui/widget/uihk_nisoverlay.hh"
#include "ui/widget/uihkmessageoverlay.hh"
#include "ui/widget/uihksaveloadoverlay.hh"
#include "ui/widget/uihkloadingoverlay.hh"
#include "ui/widget/uihkpopupnotifier.hh"
#include "ui/widget/uihktutorialoverlay.hh"
#include "ui/widget/uihkhelpbarwidget.hh"
#include "ui/widget/uihkhinttext.hh"
#include "ui/widget/uihkmoneypopupwidget.hh"
#include "ui/widget/uihksocialactionmanager.hh"
#include "ui/widget/uihksecondaryobjectiveswidget.hh"
#include "ui/widget/uihksniperwidget.hh"
#include "ui/widget/uihkplayerobjective.hh"
#include "ui/widget/uipropertysetmenu.hh"

#include "ui/widget/hud/uihkgameplayhelpwidget.hh"
#include "ui/widget/hud/uihkobjectiveflasherwidget.hh"
#include "ui/widget/hud/uihkhealthmeterwidget.hh"
#include "ui/widget/hud/uihkweaponammowidget.hh"
#include "ui/widget/hud/uihkradiostationwidget.hh"
#include "ui/widget/hud/uihkactionhijackwidget.hh"
#include "ui/widget/hud/uihkbuffwidget.hh"
#include "ui/widget/hud/uihkreticlewidget.hh"
#include "ui/widget/hud/uihkdirectionaldamagewidget.hh"
#include "ui/widget/hud/uihkheatlevelwidget.hh"
#include "ui/widget/hud/uihkcombatmeterwidget.hh"
#include "ui/widget/hud/uihkobjectivedistancewidget.hh"
#include "ui/widget/hud/uihkregionindicatorwidget.hh"
#include "ui/widget/hud/uihkactionbuttonwidget.hh"
#include "ui/widget/hud/uihk_xpflasherwidget.hh"

#include "ui/widget/pda/uihk_pdaphonecontactswidget.hh"
#include "ui/widget/pda/uihk_pdainputlocker.hh"
#include "ui/widget/pda/uihk_pdarootmenuwidget.hh"
#include "ui/widget/pda/uihk_pdatextinboxwidget.hh"
#include "ui/widget/pda/uihk_pdaincomingcallwidget.hh"
#include "ui/widget/pda/uihk_pdaincomingtextwidget.hh"
#include "ui/widget/pda/uihk_pdaclockwidget.hh"
#include "ui/widget/pda/uihk_pdawidget.hh"

#include "ui/screens/uihkscreenglobaloverlay.hh"
#include "ui/screens/uihkscreenhud.hh"
#include "ui/screens/uihkscreenmainmenu.hh"

//--------------------------------------------------
//	Main
//--------------------------------------------------

#include "main/mainloop.hh"