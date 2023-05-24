# SDK
Re-written SDK from debug symbols & some wrapped functions to access them easily

# Contributing 
You can create issues & pull requests if you reversed something yourself and it can be added later on, but most basic stuff that already exist in debug symbols will be ignored.

# Info
This is just cloned repo from latest SDK-Dev but meant for public, main point of this repo is so people can have access to basic SDK and build their own stuff around game and have some basic information of how this thing works...

If you just build this without modifying anything, you get basic debug menu with some testing features like: 
- hud stuff (action, dialog, hint, mission health, mission progress, map blip)
- script camera (this can be used to fly around)
- day manager (time, rain, wind)
- player teleport (offset, waypoint)
- player animation (you need exact animation name)
- vehicle spawning

__Update 24. May 2023:__
- There has been huge updates that might break the solution itself and I don't willing to trying to fix that, so if you even bother using this I recommend making new project and including SDK as external include and just include the main header file inside SDK called `_Includes.hpp`. You can still copy some needed stuff to begin with or fix the solution by yourself.

# Callbacks
**OnDialogBox** - This callback is called when you initialized any game dialog box and user clicked on button

**OnGameUpdate** - This callback is called before game updates all stuff, so you can modify animations, positions, etc... (Call here all stuff around game because this is synced with game thread!)

**OnRender** - This callback is called on DX Present update, we just use it for ImGui render, but you can use it to render other stuff...

# Before use
The SDK is working on first initial release of definitive edition from steam.

If you have latest game version installed from steam just download this executable and replace it in your game folder.

[Download: sdhdship.exe](https://mega.nz/file/fK5SWARD#1fAWkxAHaKCIMDaJ5XAQKvjs6gK4RCQo5ZlvvtHWtVw)
