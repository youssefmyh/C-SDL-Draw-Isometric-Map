/*
 * MenuButtonCreator.h
 *
 *  Created on: Jun 25, 2015
 *      Author: Home
 */

#ifndef MENUBUTTONCREATOR_H_
#define MENUBUTTONCREATOR_H_

#include "GameObjectFactory.h"
#include "MenuButton.h"
class MenuButtonCreator: public BaseCreator {
public:
	 GameObject* createGameObject()const
	{
		 return new MenuButton();
	}
	MenuButtonCreator();
	virtual ~MenuButtonCreator();
};

#endif /* MENUBUTTONCREATOR_H_ */
