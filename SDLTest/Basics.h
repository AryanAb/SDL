#pragma once

#include "SDL.h"
#include <iostream>
#include <stdio.h>
#include "SDL_image.h"

class Window
{
public:

	enum KeyPressSurfaces
	{
		KEY_PRESS_SURFACE_DEFAULT,
		KEY_PRESS_SURFACE_UP,
		KEY_PRESS_SURFACE_DOWN,
		KEY_PRESS_SURFACE_LEFT,
		KEY_PRESS_SURFACE_RIGHT,
		KEY_PRESS_SURFACE_TOTAL
	};

	bool initialize();
	bool loadMedia();
	void close();

	Window();
	~Window();

	SDL_Window* gWindow;
	SDL_Surface* gScreenSurface;
	SDL_Surface* gHelloWorld;
	SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
	SDL_Surface* gCurrentSurface;

private:
	//SDL_Window* gWindow;
	//SDL_Surface* gScreenSurface;
	//SDL_Surface* gHelloWorld;

};

namespace blue
{

	struct Vec2
	{
		int x;
		int y;
	};

	// gets the version of SDL linking and compiling
	void getVersion();

	// loads a surface
	SDL_Surface* loadSurface(std::string path, SDL_Surface* gScreenSurface);

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

	Vec2 clickPos();

}