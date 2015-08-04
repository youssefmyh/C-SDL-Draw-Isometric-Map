/*
 * PlayState.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: Home
 */

#include "PlayState.h"
#include "Player.h"
#include "LoaderParams.h"
#include "Game.h"
#include "PauseState.h"
#include "InputHandler.h"
#include "GameOverState.h"
#include "StateParser.h"
const string PlayState::s_playID = "PLAY";

PlayState::PlayState() {
	// TODO Auto-generated constructor stub

}

PlayState::~PlayState() {
	// TODO Auto-generated destructor stub
}

void PlayState::update() {
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		TheGame::instance()->getGameStateMachine()->pushstate(new PauseState());
	}
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
	if(false){
	 TheGame::instance()->getGameStateMachine()->pushstate(new GameOverState());
	}
}

void PlayState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter() {
	cout << "\nHeli In" << '\n';

	StateParser stateParser;

	stateParser.parseState("assets/attack.xml",s_playID,&m_gameObjects,&m_textureIDList);

//	if (!TheTextureManager::Instance()->load("img/helicopter.png",
//			"helicopter", TheGame::instance()->getRenderer())) {
//		return false;
//	}
//	if (!TheTextureManager::Instance()->load("img/helicopter2.png",
//			"helicopter2", TheGame::instance()->getRenderer())) {
//		return false;
//	}

//	GameObject *player = new Player();
//	player->load(new LoaderParams(100, 100, 128, 55, "helicopter"));
//	GameObject *player2 = new Enemy(new LoaderParams(100, 300, 128, 55, "helicopter2"));
//	player2->load(new LoaderParams(100, 300, 128, 55, "helicopter2"));
//
//	m_gameObjects.push_back(player);
//	m_gameObjects.push_back(player2);

	cout << "\nHeli In Fail" << '\n';
	return true;
}
bool PlayState::onExit() {
	cout << "PlayState onExit";
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance() ->clearFromTextureMap("helicopter");
	std::cout << "exiting PlayState\n";
	return true;
}
