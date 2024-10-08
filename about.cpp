#include "about.h"
#include <windows.h>

LRESULT CALLBACK AboutWndProc(HWND hwndAbout, UINT Message, WPARAM wParam, LPARAM lParam) {
	
	switch(Message) {
		case WM_PAINT: {
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwndAbout, &ps);
			
			RECT rect;
			GetClientRect(hwndAbout, &rect);
			HBRUSH brush = CreateSolidBrush(RGB(240,240,240));
			
			FillRect(hdc, &rect, brush);
			DeleteObject(brush);
			
			HFONT hFont = CreateFont(38,0,0,0,FW_NORMAL,FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Times New Roman");
			
			HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);
			
			
			RECT nameRect = {20,20,rect.right - 20,40};
			SetBkMode(hdc, TRANSPARENT);
			DrawText(hdc, "Calculator", -1, &nameRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			
			
			HFONT hFFont = CreateFont(18,0,0,0,FW_NORMAL,FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Times New Roman");
			
			SelectObject(hdc, hFFont);
			DeleteObject(hFont);
			
			RECT versionRect = {20,40,rect.right - 20,60};
			RECT descriptionRect = {40,100,rect.right - 20,rect.bottom - 20};
			SetBkMode(hdc, TRANSPARENT);
			SetTextColor(hdc, RGB(0,0,0));		
			
			DrawText(hdc, "Calculator++ is a simple yet powerful calculator application built with C++ and the Windows API.", -1, &descriptionRect, DT_CENTER | DT_VCENTER | DT_WORDBREAK );
//			DrawText(hdc, "It provides a intuitive interface for users to perform basic arithmetic operations, as well as more advanced calculations.", -1, &descriptionRect, DT_CENTER | DT_VCENTER | DT_WORDBREAK );
//			DrawText(hdc, "The project was started in 2018 as a personal project to learn and experiment with C++ and Windows programming.", -1, &descriptionRect, DT_CENTER | DT_VCENTER | DT_WORDBREAK );
//			DrawText(hdc, "Over the years, it has evolved to include new features and improvements, thanks to the contributions and feedback from the open-source community.", -1, &descriptionRect, DT_CENTER | DT_VCENTER | DT_WORDBREAK );
//			DrawText(hdc, "Calculator++ is free and open-source software, licensed under the GNU General Public License (GPL) version 3.0.", -1, &descriptionRect, DT_CENTER | DT_VCENTER | DT_WORDBREAK );
//			DrawText(hdc, "You are welcome to use, modify, and distribute the software as per the terms of the license.", -1, &descriptionRect, DT_CENTER | DT_VCENTER | DT_WORDBREAK );
//			DrawText(hdc, "If you have any suggestions, bug reports, or contributions, please feel free to reach out to us on GitHub.", -1, &descriptionRect, DT_CENTER | DT_VCENTER | DT_WORDBREAK );
			EndPaint(hwndAbout, &ps);
		}
//		case WM_CLOSE: 
//			ShowWindow(hwndAbout, SW_HIDE);
//			return 0;
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwndAbout, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
void openAboutWindow(HWND hwndMain) {
	WNDCLASSEX wc; /* A properties struct of our window */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = AboutWndProc; /* This is where we will send messages to */
	wc.hInstance	 = GetModuleHandle(NULL);
	
	wc.lpszClassName = "AboutWindowClass";
	RegisterClassEx(&wc);
	

	HWND hwndAbout = CreateWindowEx(0,"AboutWindowClass","About", WS_OVERLAPPEDWINDOW & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		300, /*width */
		400, /* height */
		hwndMain,NULL,GetModuleHandle(NULL),NULL);		

	
	ShowWindow(hwndAbout, SW_SHOW);
}
