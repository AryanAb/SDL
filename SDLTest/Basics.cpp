#include "Basics.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <stdio.h>

Window::Window()
{
	gWindow = nullptr;
	gScreenSurface = nullptr;
	gHelloWorld = nullptr;
	gCurrentSurface = nullptr;
}

Window::~Window()
{
}

bool Window::initialize()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL could not initialize! SDL_Error:  " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 625, 475, SDL_WINDOW_SHOWN);
		SDL_SetWindowResizable(gWindow, SDL_FALSE);
		//SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

		if (gWindow == nullptr)
		{
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
				success = false;
			}
			else
			{
				Window::gScreenSurface = SDL_GetWindowSurface(gWindow);
			}
		}
	}

	return success;	
}

SDL_Surface* blue::loadSurface(std::string path, SDL_Surface* gScreenSurface)
{
	SDL_Surface* optimizedSurface = nullptr;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		std::cout << "Unable to load image " << path.c_str() << "! SDL_Error: " << IMG_GetError() << std::endl;
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
		if (optimizedSurface == nullptr)
		{
			std::cout << "Unable to optimize image " << path.c_str() << "! SDL_Error: " << SDL_GetError() << std::endl;
		}
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

blue::Vec2 blue::clickPos()
{
	Vec2 loc;
	int x, y;
	SDL_GetMouseState(&x, &y);
	loc.x = x;
	loc.y = y;
	std::cout << loc.x << " " << loc.y << std::endl;
	return loc;
}

void Window::close()
{
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = nullptr;

	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	SDL_Quit();
}

/*bool loadMedia()
{
	bool success = true;

	//Load default surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("Images/press.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == nullptr)
	{
		std::cout << "Failed to load up image" << std::endl;
		success = false;
	}

	//Load up surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("Images/up.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == nullptr)
	{
		std::cout << "Failed to load up image" << std::endl;
		success = false;
	}

	//Load down surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("Images/down.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == nullptr)
	{
		std::cout << "Failed to load up image" << std::endl;
		success = false;
	}

	//Load left surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("Images/left.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == nullptr)
	{
		std::cout << "Failed to load up image" << std::endl;
		success = false;
	}

	//Load right surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("Images/right.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == nullptr)
	{
		std::cout << "Failed to load up image" << std::endl;
		success = false;
	}

	return success;
}*/

bool Window::loadMedia()
{
	bool success = true;

	gHelloWorld = blue::loadSurface("Images/loaded.png", gScreenSurface);
	if (gHelloWorld == nullptr)
	{
		std::cout << "Failed to load PNG image" << std::endl;
		success = true;
	}

	return success;
}

void blue::getVersion()
{
	SDL_version compiled;
	SDL_version linked;

	SDL_VERSION(&compiled);
	SDL_GetVersion(&linked);
	printf("Compiled against SDL version: %d.%d.%d ...\n", compiled.major, compiled.minor, compiled.patch);
	printf("Linking against SDL version: %d.%d.%d.\n", linked.major, linked.minor, linked.patch);
}
