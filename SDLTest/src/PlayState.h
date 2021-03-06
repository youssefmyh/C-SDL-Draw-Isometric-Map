/*
 * PlayState.h
 *
 *  Created on: Jun 17, 2015
 *      Author: Home
 */

#ifndef PLAYSTATE_H_
#define PLAYSTATE_H_

#include "GameState.h"
#include <iostream>
#include "GameObject.h"
#include <vector>
using namespace::std;
class PlayState: public GameState {
public:
	PlayState();
	virtual ~PlayState();
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const {
		return s_playID;
	};
private :
	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;
};

#endif /* PLAYSTATE_H_ */
