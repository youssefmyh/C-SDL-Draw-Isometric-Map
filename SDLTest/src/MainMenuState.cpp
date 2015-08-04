/*
 * MenuState.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: Home
 */

#include "MainMenuState.h"
#include "Game.h"
#include "MenuButton.h"
#include "StateParser.h"
const std::string MainMenuState::s_menuID = "MENU";

MainMenuState::MainMenuState() {
	// TODO Auto-generated constructor stub

}

MainMenuState::~MainMenuState() {
	// TODO Auto-generated destructor stub
}

void MainMenuState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void MainMenuState::setCallbacks(const std::vector<Callback> &callbacks)
{
	for(int i=0;i<m_gameObjects.size();i++)
	{
		GameObject *gameObject=m_gameObjects[i];
		if(dynamic_cast<MenuButton*>(gameObject))
		{
			MenuButton *menuButton=dynamic_cast<MenuButton*>(gameObject);
			menuButton->setCallBack(m_callbacks[menuButton->getCallBackID()]);
		}


	}

}

void MainMenuState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool MainMenuState::onEnter() {
	cout << "MenuState onEnter" << '\n';

	StateParser stateParser;
	stateParser.parseState("assets/attack.xml",s_menuID,&m_gameObjects,&m_textureIDList);
	m_callbacks.push_back(0);

	m_callbacks.push_back(s_menuToPlay);
	m_callbacks.push_back(s_exitFromMenu);
	setCallbacks(m_callbacks);

	return true;
}
bool MainMenuState::onExit() {
	for(int i = 0; i < m_textureIDList.size(); i++)
	   {
	     TheTextureManager::Instance()->
	     clearFromTextureMap(m_textureIDList[i]);
	   }
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");

	return true;
}

void MainMenuState::s_menuToPlay() {
	TheGame::instance()->getGameStateMachine()->pushstate(new PlayState());
}
void MainMenuState::s_exitFromMenu() {

	TheGame::instance()->quit();

}
