/*
 * GameObject.h
 *
 *  Created on: Jun 14, 2015
 *      Author: Home
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include <iostream>
#include <SDL2/SDL.h>
#include "TextureManager.h"
#include "LoaderParams.h"
using namespace std;
class GameObject {
public:
	GameObject();
	virtual void load(const LoaderParams *pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual ~GameObject();
protected:
	int m_x;
	int m_y;
	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	int m_width, m_height;

};

#endif /* GAMEOBJECT_H_ */
