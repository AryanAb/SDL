#include "SDL.h"
#include <iostream>
#include <stdio.h>
#include "Basics.h"

int main(int argc, char *argv[])
{

	Window win;

	bool isRunning = true;

	SDL_Event e;

	win.gCurrentSurface = win.gKeyPressSurfaces[win.KEY_PRESS_SURFACE_DEFAULT];

	if (!win.initialize())
	{
		std::cout << "Failed to initialize!" << std::endl;
	}
	else
	{

		blue::getVersion();

		if (!win.loadMedia()) 
		{
			std::cout << "Failed to load media" << std::endl;
		}
		else
		{

			while (isRunning)
			{

				while (SDL_PollEvent(&e) != 0)
				{
					switch (e.type)
					{
					case SDL_QUIT:
						isRunning = false;
						break;
					case SDL_KEYDOWN:
						switch (e.key.keysym.sym)
						{
						case SDLK_UP:
							win.gCurrentSurface = win.gKeyPressSurfaces[win.KEY_PRESS_SURFACE_UP];
							break;

						case SDLK_DOWN:
							win.gCurrentSurface = win.gKeyPressSurfaces[win.KEY_PRESS_SURFACE_DOWN];
							break;

						case SDLK_LEFT:
							win.gCurrentSurface = win.gKeyPressSurfaces[win.KEY_PRESS_SURFACE_LEFT];
							break;

						case SDLK_RIGHT:
							win.gCurrentSurface = win.gKeyPressSurfaces[win.KEY_PRESS_SURFACE_RIGHT];
							break;

						default:
							win.gCurrentSurface = win.gKeyPressSurfaces[win.KEY_PRESS_SURFACE_DEFAULT];
							break;
						}
					case SDL_MOUSEBUTTONDOWN:
						// when clicked, get mouse location
						blue::clickPos();
					}
				}

				/*SDL_Rect stretchRect;
				stretchRect.x = 0;
				stretchRect.y = 0;
				stretchRect.w = 625;
				stretchRect.h = 475;*/
				SDL_BlitSurface(win.gHelloWorld, nullptr, win.gScreenSurface, nullptr);
				//SDL_BlitSurface(init.gCurrentSurface, nullptr, init.gScreenSurface, nullptr);

				SDL_UpdateWindowSurface(win.gWindow);

			}

		}
	}

	win.close();

	return 0;
}