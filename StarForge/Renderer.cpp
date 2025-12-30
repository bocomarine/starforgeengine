
#include "Renderer.h"  

// global declarations
IDXGISwapChain* swapchain;             // the pointer to the swap chain interface
ID3D11Device* dev;                     // the pointer to our Direct3D device interface
ID3D11DeviceContext* devcon;           // the pointer to our Direct3D device context



// this function initializes and prepares Direct3D for use
// this function initializes and prepares Direct3D for use
void InitD3D(HWND hWnd)
{
    // create a struct to hold information about the swap chain
    DXGI_SWAP_CHAIN_DESC scd;

    // clear out the struct for use
    ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));

    // fill the swap chain description struct
    scd.BufferCount = 1;                                    // one back buffer
    scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;     // use 32-bit color
    scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;      // how swap chain is to be used
    scd.OutputWindow = hWnd;                                // the window to be used
    scd.SampleDesc.Count = 4;                               // how many multisamples
    scd.Windowed = TRUE;                                    // windowed/full-screen mode

    // create a device, device context and swap chain using the information in the scd struct
    D3D11CreateDeviceAndSwapChain(NULL,
        D3D_DRIVER_TYPE_HARDWARE,
        NULL,
        NULL,
        NULL,
        NULL,
        D3D11_SDK_VERSION,
        &scd,
        &swapchain,
        &dev,
        NULL,
        &devcon);
}

// this is the function that cleans up Direct3D and COM
void CleanD3D()
{
    // close and release all existing COM objects
    if (swapchain) { swapchain->Release(); swapchain = nullptr; }
    if (dev) { dev->Release(); dev = nullptr; }
    if (devcon) { devcon->Release(); devcon = nullptr; }
}