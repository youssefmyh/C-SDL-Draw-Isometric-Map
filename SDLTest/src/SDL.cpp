//============================================================================
// Name        : SDL.cpp
// Author      : test
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"
#include "Vector2D.h"
using namespace std;
bool init(const char * title, int xPos, int yPos, int w, int h, int flags);

Game *g_game = 0;
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;
int main() {
	Uint32 framestart, frameTime;

	g_game = TheGame::instance();
	g_game->init("First Window", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 600, 800, SDL_WINDOW_SHOWN);

	while (g_game->running()) {
		framestart = SDL_GetTicks();
		g_game->handleEvenets();
		g_game->update();
		g_game->render();
		frameTime = SDL_GetTicks() - framestart;
		if (frameTime < DELAY_TIME) {
			SDL_Delay((int) (DELAY_TIME - frameTime));
		} else {
			SDL_Delay(DELAY_TIME);
		}
	}
	return 1;
}

