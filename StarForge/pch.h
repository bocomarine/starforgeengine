#pragma once

#include <CoreWindow.h>
#include <Windows.h>
#include "resource.h"
#include <d3d11.h>
#include "Renderer.cpp"

// include the Direct3D Library file
#pragma comment (lib, "d3d11.lib")

// global declarations
IDXGISwapChain* swapchain;             // the pointer to the swap chain interface
ID3D11Device* dev;                     // the pointer to our Direct3D device interface
ID3D11DeviceContext* devcon;           // the pointer to our Direct3D device context