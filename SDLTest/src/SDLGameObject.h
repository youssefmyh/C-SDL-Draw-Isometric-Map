/*
 * SDLGameObject.h
 *
 *  Created on: Jun 14, 2015
 *      Author: Home
 */

#ifndef SDLGAMEOBJECT_H_
#define SDLGAMEOBJECT_H_

#include "GameObject.h"
#include "Vector2D.h"
class SDLGameObject: public GameObject {
public:
	SDLGameObject();
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual ~SDLGameObject();
	virtual void load(const LoaderParams* pParams)=0;
protected:
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
};

#endif /* SDLGAMEOBJECT_H_ */
