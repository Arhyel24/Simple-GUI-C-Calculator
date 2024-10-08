#include <windows.h>
#include "calculator.h"
#include "resource.h"

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	static Calculator calculator(hwnd);
	
	switch(Message) {
		case WM_CREATE: {
			calculator.createUI(hwnd);
			break;
		}
		
		case WM_PAINT: {
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);
			
			RECT rect;
			GetClientRect(hwnd, &rect);
			HBRUSH brush = CreateSolidBrush(RGB(105,105,105));
			
			FillRect(hdc, &rect, brush);
			DeleteObject(brush);
	
			EndPaint(hwnd, &ps);
		}
		
		case WM_COMMAND: {
			calculator.handleButtonClicked(hwnd, LOWORD(wParam));
			break;
		}
		
		case WM_ERASEBKGND: {
			HDC hdc = (HDC)wParam;
			RECT rect;
			GetClientRect(hwnd, &rect);
			FillRect(hdc, &rect, CreateSolidBrush(RGB(240,240,240)));
			return 1;
		}
		
		case WM_CTLCOLORBTN: {
			HDC hdc = (HDC)wParam;
			SetBkColor(hdc, RGB(255, 255, 255));
			SetTextColor(hdc, RGB(200,200,200));
			return (LRESULT)CreateSolidBrush(RGB(200,200,200));
		}
		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}


/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(240,0,0)));
	wc.lpszClassName = "CalculatorWindowClass";
	wc.hIcon		 = LoadIcon(NULL,"A"); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, "A"); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(0,"CalculatorWindowClass","Calculator",WS_VISIBLE|WS_OVERLAPPEDWINDOW & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		235, /*width */
		360, /* height */
		NULL,NULL,hInstance,NULL);		

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	
	HMENU hMenu = LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MENU_MAIN));
	
	if (!hMenu) {
		MessageBox(NULL, "Load Menu Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return -1;
	}
	
	if (!SetMenu(hwnd, hMenu)) {
		MessageBox(NULL, "Failed to set Menu!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return -1;	
	}

	
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
