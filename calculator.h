#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <windows.h>

class Calculator {
	public: 
		Calculator(HWND hwnd);
		void createUI(HWND hwnd);
		void handleButtonClicked(HWND hwnd, int buttinId);
		
		HWND hwndText;
		
	private: 
		HWND hwnd_;
		HWND hwndButton1;
		HWND hwndButton2;
		HWND hwndButton3;
		HWND hwndButton4;
		HWND hwndButton5;
		HWND hwndButton6;
		HWND hwndButton7;
		HWND hwndButton8;
		HWND hwndButton9;
		HWND hwndButton0;
		HWND hwndButton00;
		HWND hwndButtonPo;
		HWND hwndButtonAdd;
		HWND hwndButtonSub;
		HWND hwndButtonMul;
		HWND hwndButtonDiv;
		HWND hwndButtonEq;
		HWND hwndButtonDel;
		HWND hwndButtonAc;
		HWND hwndButtonCl;
};

#endif //CALCULATOR.H
