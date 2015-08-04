/*
 * Game.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: youssef
 */

#include "Game.h"
#include <iostream>
#include "InputHandler.h"
#include "MainMenuState.h"
#include "GameObjectFactory.h"
#include "MenuButtonCreator.h"
#include "PlayerCreator.h"
#include "LevelParser.h"
using namespace std;
Game* Game::s_pinstance = 0;
bool Game::init(const char * title, int xPos, int yPos, int w, int h, int flags) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow(title, xPos, yPos, w, h, flags);
        
		if (m_pWindow != 0) {
			m_pRender = SDL_CreateRenderer(m_pWindow, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		}
        
		TheTextureManager::Instance()->load("img/animate-alpha.png", "animate",
				m_pRender);
		m_player = new Player();
		m_player->load(new LoaderParams(1, 1, 128, 82, "animate"));
		m_enemy1 = new Enemy(new LoaderParams(100, 100, 128, 82, "animate"));
		m_enemy2 = new Enemy(new LoaderParams(1, 150, 128, 82, "animate"));
		m_enemy3 = new Enemy(new LoaderParams(100, 200, 128, 82, "animate"));

		TheInputHandler::Instance()->initialiseJoysticks();
		TheGameObjectFactory::instance()->registerType("MenuButton", new
		   MenuButtonCreator());

		TheGameObjectFactory::instance()->registerType("helicopter", new PlayerCreator());
        TheGameObjectFactory::instance()->registerType("Player", new PlayerCreator());

		TheGameObjectFactory::instance()->registerType("helicopter2", new  PlayerCreator());
        
      		cout<<"m_pgameStateMachine init";

	} else {
		return false;
	}
	m_bRunning = true;
	m_currentGameState = PLAY;
	m_pgameStateMachine=new GameStateMachine();
	m_pgameStateMachine->pushstate(new MainMenuState());
  
	return true;
}

void Game::render() {
	//SDL_SetRenderDrawColor(m_pRender, 255, 0, 0, 255);

	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
	m_pgameStateMachine->render();
	SDL_RenderPresent(m_pRender);
    SDL_RenderClear(m_pRender);
}

void Game::clean() {
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRender);
	SDL_Quit();
}
void Game::handleEvenets() {
	TheInputHandler::Instance()->update();
	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pgameStateMachine->changeState(new PlayState());
	}
}
void Game::update() {
	switch (m_currentGameState) {
	case MENU:
		break;

	case PLAY:
		for (std::vector<GameObject*>::size_type i = 0; i
				!= m_gameObjects.size(); i++) {
			m_gameObjects[i]->update();
		}
		break;
	case GAMEOVER:
		break;
	}
	m_pgameStateMachine->update();

}
void Game::quit() {
	m_bRunning = false;
	clean();
}
