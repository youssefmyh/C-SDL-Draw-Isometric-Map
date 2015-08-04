/*
 * GameStateMachine.h
 *
 *  Created on: Jun 17, 2015
 *      Author: Home
 */

#ifndef GAMESTATEMACHINE_H_
#define GAMESTATEMACHINE_H_
#include "GameState.h"
#include "iostream"
#include <vector>
using namespace std;
class GameStateMachine {
public:
	GameStateMachine();
	virtual ~GameStateMachine();
	void pushstate(GameState *pState);
	void popState();
	void changeState(GameState *pState);
	void render();
	void update();

private :
	std::vector<GameState *> m_gameStates;

};

#endif /* GAMESTATEMACHINE_H_ */
