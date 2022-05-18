/*
 * main.cc
 *
 *  Created on: 18 мая 2022 г.
 *      Author: Vlad
 */


#include <iostream>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>
#include "Window.h"

int main(int, char **)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	Window w {1920, 1080};
	w.main_loop();
	return 0;
}


