/*
 * GameObjectFactory.h
 *
 *  Created on: Jun 24, 2015
 *      Author: youssef
 */

#ifndef GAMEOBJECTFACTORY_H_
#define GAMEOBJECTFACTORY_H_
#include <string.h>
#include <map>
#include "GameObject.h"
#include <iostream>
class BaseCreator
{
public:
	virtual GameObject* createGameObject()const=0;
	virtual ~BaseCreator(){}

};

class GameObjectFactory {
public:

	static GameObjectFactory *instance()
	{
		if(p_instance==0)
			p_instance=new GameObjectFactory();
			return p_instance;
	}
	virtual ~GameObjectFactory();
	bool registerType(std::string TypeID,BaseCreator *pcreator)
	{
		std::map<std::string,BaseCreator*>::iterator it=m_creators.find(TypeID);
		if(it != m_creators.end())
		{
			delete pcreator;
			return false;
		}

		m_creators[TypeID]=pcreator;
		return true;
	}

	GameObject * create(std::string typeID)
	{
		std::map<std::string,BaseCreator*>::iterator it=m_creators.find(typeID);
		if(it == m_creators.end())
		{
			std::cout << "could not find type: " << typeID << "\n";
			return 0;
		}
		BaseCreator *pCreator=(*it).second;
		return pCreator->createGameObject();


	}


private :
	GameObjectFactory();
	std::map<std::string,BaseCreator*> m_creators;
	static GameObjectFactory *p_instance;
};
typedef GameObjectFactory TheGameObjectFactory;
#endif /* GAMEOBJECTFACTORY_H_ */
