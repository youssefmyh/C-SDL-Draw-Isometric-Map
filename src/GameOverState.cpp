/*
 * GameOverState.cpp
 *
 *  Created on: Jun 20, 2015
 *      Author: youssef
 */

#include "GameOverState.h"
#include "TextureManager.h"
#include "MenuState.h"
#include "PlayState.h"
#include "Game.h"
#include "MenuButton.h"
#include "AnimatedGraphic.h"
#include "MainMenuState.h"
const std::string GameOverState::s_gameOverID = "GAMEOVER";
GameOverState::GameOverState() {
	// TODO Auto-generated constructor stub

}

GameOverState::~GameOverState() {
	// TODO Auto-generated destructor stub
}

void GameOverState::s_gameOverToMain() {
	TheGame::instance()->getGameStateMachine()->changeState(new MainMenuState());
}
void GameOverState::s_restartPlay() {
	TheGame::instance()->getGameStateMachine()->changeState(new PlayState());
}
void GameOverState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}
void GameOverState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}
bool GameOverState::onExit() {
	return true;
}

bool GameOverState::onEnter() {
	if (!TheTextureManager::Instance()->load("assets/gameover.png",
			"gameovertext", TheGame::instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/main.png", "mainbutton",
			TheGame::instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/restart.png",
			"restartbutton", TheGame::instance()->getRenderer())) {
		return false;
	}
	GameObject* gameOverText = new AnimatedGraphic(
			new LoaderParams(200, 100, 190, 30, "gameovertext"), 2);
	MenuButton* button1 = new MenuButton();
	button1->load(new LoaderParams(200, 200, 200, 80, "mainbutton"));

	button1->setCallBack(s_gameOverToMain);

	MenuButton* button2 = new MenuButton();
	button2->load(new LoaderParams(200, 300, 200, 80, "restartbutton"));

	button2->setCallBack(s_restartPlay);
	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	return true;
}
