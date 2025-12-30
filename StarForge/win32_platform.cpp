#include "pch.h"

//Variables
bool running = true;

WNDPROC Wndproc;

//Constants
const wchar_t CLASS_NAME[] = L"Star Forge";
/*
This Game Engine Was Started in the Year of Our Lord 2025

Created By Thomas Baca 12/29/2025

This Engine is just a revisit to what I did in college and to keep skillset built up over the last 2 decades sharp
and AI code free. This is a Library of Knowledge Learned the old fashion way. Read, Research, Develop, Iterate

This Engine will focus on Space Themed Something... We will figure that out as we go.

Code should be Clean, Bug Free as much as humanly possible, no ai generated code no matter how tempting. 

We Seek the Stars!!!!!!!!!

Challege yourself and Deny yourself the easy path! 

Document what must be documented to provide clear structure and Organization
BUILD BUILD BUILD BUILD this is Forever Project!

*/

LRESULT windowCallback(HWND hwnd, UINT unit, WPARAM wparam, LPARAM lparam)
{
	LRESULT result = 0;

	switch (unit)
	{
	case WM_CLOSE:
	case WM_DESTROY: {
		running = false;
		PostQuitMessage(0);
	}break;

	default:
	{
		result = DefWindowProc(hwnd, unit, wparam, lparam);
	}
	}
	return result;
}

/// <summary>
/// Main Window To The Application
/// </summary>
/// <param name="hInstance"></param>
/// <param name="hPrevInstance"></param>
/// <param name="lpCmdLine"></param>
/// <param name="nShowCmd"></param>
/// <returns></returns>

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int  nShowCmd)
{
	//Windows Class
	WNDCLASS window_class = {};
	
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = CLASS_NAME;
	window_class.lpfnWndProc = windowCallback;
	//Register Class
	RegisterClass(&window_class);


	//Create Window
	HWND window = CreateWindow(window_class.lpszClassName, CLASS_NAME, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);

	while (running)
	{
		//Game Input
		MSG message;
		while (PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		//Simulate Game
		
		//Render Game
	}
}

