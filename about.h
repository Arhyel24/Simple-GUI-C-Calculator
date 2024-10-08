#ifndef ABOUT_H
#define ABOUT_H

#include <windows.h>
void openAboutWindow(HWND hwndMain);

class About {
	public: 
		About(HWND hwnd);
		void openAboutWindow(HWND hwndMain);
		
	private: 
		HWND hwndAbout;
};


#endif //ABOUT.H
