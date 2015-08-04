/*
 * PauseState.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: Home
 */

#include "PauseState.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "Game.h"
#include "LoaderParams.h"
#include "MainMenuState.h"
const std::string PauseState::s_pauseID = "PAUSE";

PauseState::PauseState() {
	// TODO Auto-generated constructor stub

}

PauseState::~PauseState() {
	// TODO Auto-generated destructor stub
}

void PauseState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}
void PauseState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PauseState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	TheTextureManager::Instance()->clearFromTextureMap("resume");
	TheTextureManager::Instance()->clearFromTextureMap("main");
	return true;
}

bool PauseState::onEnter() {
	if (!TheTextureManager::Instance()->load("assets/resume.png", "resume",
			TheGame::instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/main.png", "main",
			TheGame::instance()->getRenderer())) {
		return false;
	}

	MenuButton *resumeButton = new MenuButton();
	resumeButton->load(new LoaderParams(100, 100, 200, 100, "resume"));
	resumeButton->setCallBack(s_pauseToMain);
	MenuButton *mainButton = new MenuButton();
	mainButton->load(new LoaderParams(100, 200, 200, 100, "main"));
	mainButton->setCallBack(s_resumeToPlay);

	m_gameObjects.push_back(resumeButton);
	m_gameObjects.push_back(mainButton);
	return true;

}

void PauseState::s_pauseToMain() {
	TheGame::instance()->getGameStateMachine()->changeState(new MainMenuState());

}
void PauseState::s_resumeToPlay() {
	TheGame::instance()->getGameStateMachine()->popState();

}
