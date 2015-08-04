/*
 * PlayerCreator.h
 *
 *  Created on: Jun 24, 2015
 *      Author: Home
 */

#ifndef PLAYERCREATOR_H_
#define PLAYERCREATOR_H_

#include "GameObjectFactory.h"
#include "GameObject.h"
#include "Player.h"
class PlayerCreator: public BaseCreator {
public:
	 GameObject* createGameObject()const
	{
		 return new Player();
	}
	PlayerCreator();
	virtual ~PlayerCreator();
};

#endif /* PLAYERCREATOR_H_ */
