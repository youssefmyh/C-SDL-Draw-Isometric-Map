/*
 * Player.h
 *
 *  Created on: Jun 14, 2015
 *      Author: Home
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "LoaderParams.h"
#include "SDLGameObject.h"

class Player: public SDLGameObject {
public:
	Player();
	virtual ~Player();
	void draw();
	void update();
	void clean();
	void load(const LoaderParams *pParams);

};

#endif /* PLAYER_H_ */
