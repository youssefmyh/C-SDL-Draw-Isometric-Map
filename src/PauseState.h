/*
 * PauseState.h
 *
 *  Created on: Jun 18, 2015
 *      Author: youssef
 */

#ifndef PAUSESTATE_H_
#define PAUSESTATE_H_

#include "GameState.h"
#include <iostream>
#include <vector>
#include "GameObject.h"


using namespace std;
class PauseState: public GameState {
public:
	PauseState();
	virtual ~PauseState();
	virtual void update();
	virtual void render();

	virtual bool onExit();
	virtual bool onEnter();

	virtual std::string getStateID() const {return s_pauseID;}

private:
	static const std::string s_pauseID;
	static void s_pauseToMain();
	static void s_resumeToPlay();
	std::vector<GameObject*> m_gameObjects;


};

#endif /* PAUSESTATE_H_ */
