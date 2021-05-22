#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <string>
#include <ctime>
#include <math.h>
#include "SDKsound.h"
#include "SDKwavefile.h"
#include "Math.h"

#pragma comment(lib, "dsound.lib")

using namespace std;
using namespace math;

using Vector2 = D3DXVECTOR2;
using Vector3 = D3DXVECTOR3;
using Matrix = D3DXMATRIX;
using Rect = RECT;
using Color = D3DXCOLOR;
using DXImage = LPDIRECT3DTEXTURE9;
using DXImageInfo = D3DXIMAGE_INFO;
using Sprite = LPD3DXSPRITE;
using Font = LPD3DXFONT;
using Sound = CSound;
using SoundBuffer = LPDIRECTSOUNDBUFFER;
using DXSoundManager = CSoundManager;

#define Device DXUTGetD3D9Device()
#define DeltaTime DXUTGetElapsedTime()

#define Vec2Zero Vector2(0, 0)
#define Vec2Center Vector2(0.5f, 0.5f)
#define Vec2One Vector2(1, 1)
#define RectZero Rect{ 0, 0, 0, 0 }
#define RectFill Rect{ -1, -1, -1, -1 }
#define Palette(r, g, b, a) D3DCOLOR_RGBA((long)(255 * (r / 100.f)), (long)(255 * (g / 100.f)), (long)(255 * (b / 100.f)), (long)(255 * (a / 100.f)))
#define ColorDef(a) Palette(100, 100, 100, a)
#define ColorDark(a) Palette(0, 0, 0, a)

#define WinName L"프레임워크"
#define IsWin true
#define WinSize Vector2(1440, 960)
#define WinCenter (WinSize * 0.5f)
#define WinColor Palette(0, 0, 0, 100)
#define MapSize Vector2(2400, 1350)
#define MapCenter (WinSize * 0.5f)

#include "Singleton.h"
#include "CameraManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "SoundManager.h"
#include "RenderManager.h"
#include "SceneManager.h"
#include "TextureManager.h"

#define CameraM CameraManager::GetInstance()
#define InputM InputManager::GetInstance()
#define ObjectM ObjectManager::GetInstance()
#define SoundM SoundManager::GetInstance()
#define RenderM RenderManager::GetInstance()
#define SceneM SceneManager::GetInstance()
#define TextureM TextureManager::GetInstance()
