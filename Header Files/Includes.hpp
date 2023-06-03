#pragma once
#define WIN32_LEAN_AND_MEAN

/*-------Windows-------*/
#include <windows.h>
#include <iostream>
#include <TlHelp32.h>
#include <thread>
#include <vector>
#include <map>
#include <array>
#include <mutex>
#include <string>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <codecvt>
#include <algorithm>
#include <xmmintrin.h>
#include <emmintrin.h>
#include <urlmon.h>
#include <mmsystem.h>
#include <tchar.h>
#include <random>

/*-------Hypervisor-------*/
//#include <glitch/Log/Log.h>
//#include <glitch/vManager/vManager.h>
//using namespace vManager::driver.noPool;
#define HV false

#if HV == true
#include "memory.hpp"
#elif HV == false
#include "..//Driver.hpp"
#endif

/*-------DirectX-11-------*/
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <D3DX11tex.h>
#include <d3d11.h>
#include <dwmapi.h>
#pragma comment(lib, "d3dx11.lib")

/*-------Json-------*/
#include "Json.hpp"

/*-------Xor-String-------*/
#include "XorStr.hpp"

/*-------Resources-------*/
#include "image.hpp"
#include "font.hpp"

#include "Math.hpp"
#include "Structs.hpp"
#include "Global.hpp"
#include "Offsets.hpp"
#include "Utils.hpp"
#include "Unity.hpp"

/*Game Classes And Structs*/
#include "ItemContainer.hpp"
#include "PlayerModel.hpp"
#include "PlayerInput.hpp"
#include "BaseMovement.hpp"
#include "ModelState.hpp"
#include "PlayerEyes.hpp"
#include "PlayerInventory.hpp"
#include "BasePlayer.hpp"
#include "Players.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Movement.hpp"
#include "Weapon.hpp"
#include "Enviorment.hpp"

/*-------Esp-------*/
#include "Esp.hpp"
#include "Menu.hpp"
#include "Misc.hpp"

/*Threads*/
int Overlay();
int UpdateLists();
int UpdatePositions();
int Misc();
int Aimbot();

