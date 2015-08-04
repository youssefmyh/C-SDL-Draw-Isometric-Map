/*
 * GameState.h
 *
 *  Created on: Jun 17, 2015
 *      Author: Home
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
class GameState {
public:
	GameState();
	virtual ~GameState();
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID()const=0;
protected:
   std::vector<std::string> m_textureIDList;
};

#endif /* GAMESTATE_H_ */
