#include "tigr/tigr.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


Tigr *backdrop, *screen;


int main(int argc, char *argv[])
{
	
	
	
	// Make a window and an off-screen backdrop.
	screen = tigrWindow(320, 200, "GUI", 0);
	backdrop = tigrBitmap(screen->w, screen->h);

	// Fill in the background.
	tigrClear(backdrop, tigrRGB(255,255,255));
	
    // Repeat till they close the window.
	while (!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE))
	{
		//mira si el mouse está dentro del boton
		int mouseXPos, mouseYPos, buttons;
		tigrMouse(screen, &mouseXPos, &mouseYPos, &buttons);

		//Debug de tigrMouse
		//printf("Mouse at %d - %d with input: %d\n", mouseXPos, mouseYPos, buttons);

		bool mouseOverButton = false;
		if(mouseXPos >= 100 && mouseXPos <= 230 && mouseYPos >= 100 && mouseYPos <= 130) {
			mouseOverButton = true;
		}
	
		// Composite the GUI
		tigrBlit(screen, backdrop, 0,0,0,0, backdrop->w, backdrop->h);
		
		//dibuja un rectangulo dependiendo del mouse
		if(mouseOverButton && buttons == 1)
			tigrFillRect(screen, 100, 100, 130, 30, tigrRGB(0,0,150));
		else
			tigrFillRect(screen, 100, 100, 130, 30, tigrRGB(150,150,150));

		//dibuja el texto
		tigrPrint(screen, tfont, 120, 110, tigrRGB(0xff, 0x00, 0x00), "Rama Master.");
		


		// Update the window.
		tigrUpdate(screen);
	}

	
	tigrFree(backdrop);
	tigrFree(screen);
	return 0;
}