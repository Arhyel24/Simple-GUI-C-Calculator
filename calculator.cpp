#include <windows.h>
#include <iostream>
#include "calculator.h"
#include "resource.h"
#include "about.h"


Calculator::Calculator(HWND hwnd) : hwnd_(hwnd) {}


void Calculator::createUI(HWND hwnd) {
	
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);
	//Text Field;
	HFONT hFont = CreateFont(34,0,0,0,FW_NORMAL,FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "Times New Roman");
		
	hwndText = CreateWindowEx(0,"Edit","",WS_CHILD | WS_VISIBLE | WS_BORDER | ES_READONLY | WS_DISABLED | ES_RIGHT, 10, 10, 210, 40, hwnd, (HMENU)1, NULL, NULL);
	
//	SendMessage(hwndText, WM_SETFONT,(WPARAM)hFont,0);
	
	hwndButtonAc = CreateWindowEx(0,"BUTTON","AC",WS_CHILD | WS_VISIBLE, 10, 60, 40, 40, hwnd, (HMENU)2, NULL, NULL);
	hwndButtonDel = CreateWindowEx(0,"BUTTON","Del",WS_CHILD | WS_VISIBLE, 60, 60, 40, 40, hwnd, (HMENU)3, NULL, NULL);
	hwndButtonAdd = CreateWindowEx(0,"BUTTON","+",WS_CHILD | WS_VISIBLE, 110, 60, 40, 40, hwnd, (HMENU)4, NULL, NULL);
	hwndButtonSub = CreateWindowEx(0,"BUTTON","-",WS_CHILD | WS_VISIBLE, 160, 60, 60, 40, hwnd, (HMENU)5, NULL, NULL);
	hwndButton7 = CreateWindowEx(0,"BUTTON","7",WS_CHILD | WS_VISIBLE, 10, 110, 40, 40, hwnd, (HMENU)6, NULL, NULL);
	hwndButton8 = CreateWindowEx(0,"BUTTON","8",WS_CHILD | WS_VISIBLE, 60, 110, 40, 40, hwnd, (HMENU)7, NULL, NULL);
	hwndButton9 = CreateWindowEx(0,"BUTTON","9",WS_CHILD | WS_VISIBLE, 110, 110, 40, 40, hwnd, (HMENU)8, NULL, NULL);
	hwndButtonMul = CreateWindowEx(0,"BUTTON","*",WS_CHILD | WS_VISIBLE, 160, 110, 60, 40, hwnd, (HMENU)9, NULL, NULL);
	hwndButton4 = CreateWindowEx(0,"BUTTON","4",WS_CHILD | WS_VISIBLE, 10, 160, 40, 40, hwnd, (HMENU)10, NULL, NULL);
	hwndButton5 = CreateWindowEx(0,"BUTTON","5",WS_CHILD | WS_VISIBLE, 60, 160, 40, 40, hwnd, (HMENU)11, NULL, NULL);
	hwndButton6 = CreateWindowEx(0,"BUTTON","6",WS_CHILD | WS_VISIBLE, 110, 160, 40, 40, hwnd, (HMENU)12, NULL, NULL);
	hwndButtonDiv = CreateWindowEx(0,"BUTTON","/",WS_CHILD | WS_VISIBLE, 160, 160, 60, 40, hwnd, (HMENU)13, NULL, NULL);
	hwndButton1 = CreateWindowEx(0,"BUTTON","1",WS_CHILD | WS_VISIBLE, 10, 210, 40, 40, hwnd, (HMENU)14, NULL, NULL);
	hwndButton2 = CreateWindowEx(0,"BUTTON","2",WS_CHILD | WS_VISIBLE, 60, 210, 40, 40, hwnd, (HMENU)15, NULL, NULL);
	hwndButton3 = CreateWindowEx(0,"BUTTON","3",WS_CHILD | WS_VISIBLE, 110, 210, 40, 40, hwnd, (HMENU)16, NULL, NULL);
	hwndButton00 = CreateWindowEx(0,"BUTTON","00",WS_CHILD | WS_VISIBLE, 10, 260, 40, 40, hwnd, (HMENU)17, NULL, NULL);
	hwndButton0 = CreateWindowEx(0,"BUTTON","0",WS_CHILD | WS_VISIBLE, 60, 260, 40, 40, hwnd, (HMENU)18, NULL, NULL);
	hwndButtonPo = CreateWindowEx(0,"BUTTON",".",WS_CHILD | WS_VISIBLE, 110, 260, 40, 40, hwnd, (HMENU)19, NULL, NULL);
	hwndButtonEq = CreateWindowEx(0,"BUTTON","=",WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON, 160, 210, 60, 90, hwnd, (HMENU)20, NULL, NULL);
}

void CopyText(HWND hwndText) {
    OpenClipboard(hwndText);
    EmptyClipboard();
    HGLOBAL hClipboardData = GlobalAlloc(GMEM_DDESHARE, 1024);
    char* pszText = (char*)GlobalLock(hClipboardData);
    GetWindowText(hwndText, pszText, 1024);
    GlobalUnlock(hClipboardData);
    SetClipboardData(CF_TEXT, hClipboardData);
    CloseClipboard();
}

void Calculator::handleButtonClicked(HWND hwnd, int buttonId) {
	static Calculator calculator(hwnd);
	//Handle button click
	
//	MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
	switch (buttonId) {
				case 2: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					strcat(text, "");
					SetWindowText(hwndText, "");
					break;
				}
				case 3: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					int len = strlen(text);
					if (len > 0) {
						text[len - 1];
					}
//					strcat(text, "");
					SetWindowText(hwndText, text);
					break;
				}
				case 4: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					strcat(text, "+");
					SetWindowText(hwndText, text);
					break;
				}
				case 5: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					strcat(text, "-");
					SetWindowText(hwndText, text);
					break;
				}
				case 6: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					strcat(text, "7");
					SetWindowText(hwndText, text);
					break;
				}
				case 7: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					strcat(text, "8");
					SetWindowText(hwndText, text);
					break;
				}
				case 8: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					strcat(text, "9");
					SetWindowText(hwndText, text);
					break;
				}
				case 9: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					strcat(text, "*");
					SetWindowText(hwndText, text);
					break;
				}
				case 10: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					strcat(text, "4");
					SetWindowText(hwndText, text);
					break;
				}
				case 11: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					strcat(text, "5");
					SetWindowText(hwndText, text);
					break;
				}
				case 12: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					strcat(text, "6");
					SetWindowText(hwndText, text);
					break;
				}
				case 13: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					strcat(text, "/");
					SetWindowText(hwndText, text);
					break;
				}
				case 14: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					strcat(text, "1");
					SetWindowText(hwndText, text);
					break;
				}
				case 15: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					strcat(text, "2");
					SetWindowText(hwndText, text);
					break;
				}
				case 16: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					strcat(text, "3");
					SetWindowText(hwndText, text);
					break;
				}
				case 17: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					strcat(text, "00");
					SetWindowText(hwndText, text);
					break;
				}
				case 18: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					strcat(text, "0");
					SetWindowText(hwndText, text);
					break;
				}
				case 19: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					strcat(text, ".");
					SetWindowText(hwndText, text);
					break;
				}
				case 20: {
					char text[256];
					GetWindowText(hwndText, text, 256);
					
					
					float num1, num2;
					char operation;
					
					if (sscanf(text, "%f %c %f", &num1, &operation, &num2)) {
						double result;
						
						switch (operation) {
							case '+': 
								result =num1 + num2;
								break;
							case '-':  
								result =num1 - num2;
								break;
							case '*':  
								result =num1 * num2;
								break;
							case '/': 
								if(num2!=0) {
									result =num1 / num2;
								} else {
									SetWindowText(hwndText, "Error!");
									break;
								}
								
								break;
							default: 
								SetWindowText(hwndText, "Error");
								break;
						}
						char resultText[256];
						sprintf(resultText,"%2.2f", result);
						SetWindowText(hwndText, resultText);
					} else {
						SetWindowText(hwndText, "Error");
					}
					break;
				}
				case ID_FILE_COPY: {
//					char text[256];
//					GetWindowText(hwndText, text, 256);
					
					CopyText(hwndText);
					
					break;
				}
				case ID_FILE_EXIT: {
					EnableWindow(hwnd, FALSE);
					int result = MessageBox(NULL, "Exit calculator?", "Confirm", MB_ICONWARNING | MB_YESNO);
					
					if (result == 6) {
						PostQuitMessage(0);
					} 
					
					EnableWindow(hwnd, TRUE);
					break;
				}
				case ID_ABOUTABOUT: 
					MessageBox(NULL, "Calculator++ is a simple yet powerful calculator application built with C++ and the Windows API.\n"
                     "It provides a intuitive interface for users to perform basic arithmetic operations, as well as more advanced calculations.\n"
                     "The project was started in 2018 as a personal project to learn and experiment with C++ and Windows programming.\n"
                     "Over the years, it has evolved to include new features and improvements, thanks to the contributions and feedback from the open-source community.\n"
                     "Calculator++ is free and open-source software, licensed under the GNU General Public License (GPL) version 3.0.\n"
                     "You are welcome to use, modify, and distribute the software as per the terms of the license.\n"
                     "If you have any suggestions, bug reports, or contributions, please feel free to reach out to us on GitHub.",
                     "Changelog", MB_OK | MB_ICONINFORMATION);
					break;
				case ID_ABOUTCHANGELOG:
					MessageBox(NULL, "Changelog:\n"
                     "Version 1.0.0:\n"
                     "- Initial release\n"
                     "- Basic arithmetic operations\n"
                     "- Advanced calculations\n"
                     "Version 1.1.0:\n"
                     "- Added new features\n"
                     "- Improved performance\n"
                     "Version 1.2.0:\n"
                     "- Fixed bugs\n"
                     "- Added more advanced calculations\n"
                     "Version 1.3.0:\n"
                     "- Improved user interface\n"
                     "- Added support for more advanced math functions",
                     "Changelog", MB_OK | MB_ICONINFORMATION);
					break;
				case ID_ABOUTHELP: 
					MessageBox(NULL, "Welcome to Calculator++! This is a simple yet powerful calculator application built with C++ and the Windows API.\n"
                     "For more information, please visit our website or GitHub page.",
                     "Help", MB_OK | MB_ICONINFORMATION);
					break;
				case WM_PASTE:
					break;
				case WM_LBUTTONDOWN:
					break;
			}
}

