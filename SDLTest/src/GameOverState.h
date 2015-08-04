/*
 * GameOverState.h
 *
 *  Created on: Jun 20, 2015
 *      Author: Home
 */

#ifndef GAMEOVERSTATE_H_
#define GAMEOVERSTATE_H_

#include "GameState.h"
#include <iostream>
#include <vector>
#include "GameObject.h"
using namespace std;
class GameOverState: public GameState {
public:
	GameOverState();
	virtual ~GameOverState();
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const {
		return s_gameOverID;
	}

private:
	static const std::string s_gameOverID;
	static void s_gameOverToMain();
	static void s_restartPlay();
	std::vector<GameObject*> m_gameObjects;
};

#endif /* GAMEOVERSTATE_H_ */
