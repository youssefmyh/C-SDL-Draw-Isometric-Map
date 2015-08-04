/*
 * MenuState.h
 *
 *  Created on: Jun 17, 2015
 *      Author: Home
 */

#ifndef MAINMENUSTATE_H_
#define MAINMENUSTATE_H_

#include "MenuState.h"
#include <iostream>
#include <vector>
#include "GameObject.h"
#include "TextureManager.h"
using namespace std;
class MainMenuState: public MenuState {
public:
	MainMenuState();
	virtual ~MainMenuState();
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const{return s_menuID;}

private:
	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
	std::vector<std::string> m_textureIDList;

	static void s_menuToPlay();
	static void s_exitFromMenu();
	virtual void setCallbacks(const std::vector<Callback> &callbacks);
	std::vector<Callback> m_callbacks;
};

#endif /* MENUSTATE_H_ */
