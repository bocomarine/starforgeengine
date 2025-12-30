#include "pch.h"

#pragma region Global Variables
	#define MAX_NAME_STRING 256
	bool running = true;
	WCHAR WindowTitle[MAX_NAME_STRING];
	WCHAR WindowClass[MAX_NAME_STRING];
	WNDPROC Wndproc;
#pragma endregion

/*
This Game Engine Was Started in the Year of Our Lord 2025

Created By Thomas Baca, Charles Humble, DudeonTheRun 12/29/2025

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

		//Thomas Baca 12.30.2025
		//PostQuitMessage ensures the application closes and isn't running in the background
		//We should also think about resource cleanup here as well to make sure we release all memory
		//From the system before we close out. 
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
	LoadString(HINSTANCE(), IDS_PERGAMENAME, WindowTitle, MAX_NAME_STRING);
	LoadString(HINSTANCE(), IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING);
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = WindowClass;
	window_class.lpfnWndProc = windowCallback;



	//Register Class
	RegisterClass(&window_class);


	//Create Window
	HWND window = CreateWindow(window_class.lpszClassName, WindowTitle, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);

	while (running)
	{
		//Game Input
		MSG message;
		

		// Check to see if any messages are waiting in the queue
		if (PeekMessage(&message, window, 0, 0, PM_REMOVE))
		{
			// translate keystroke messages into the right format
			TranslateMessage(&message);

			// send the message to the WindowProc function
			DispatchMessage(&message);

			// check to see if it's time to quit
			if (message.message == WM_QUIT)
				break;
		}
		else
		{
			// Run game code here
			// ...
			// ...

			//Simulate Game

			//Render Game
		}
	}
}

