/*
 * MenuState.h
 *
 *  Created on: Jun 25, 2015
 *      Author: Home
 */

#ifndef MENUSTATE_H_
#define MENUSTATE_H_

#include "GameState.h"
#include <vector>
#include <iostream>
using namespace std;

class MenuState: public GameState {
protected:
	typedef void (*Callback)();
	virtual void setCallbacks(const std::vector<Callback> &callbacks) = 0;
	std::vector<Callback> m_callbacks;
};

#endif /* MENUSTATE_H_ */
