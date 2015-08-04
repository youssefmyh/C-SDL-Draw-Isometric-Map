/*
 * Enemy.cpp
 *
 *  Created on: Jun 14, 2015
 *      Author: Home
 */

#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) {
	m_velocity.setY(2);
	m_velocity.setX(0.001);
	SDLGameObject::load(pParams);

	// TODO Auto-generated constructor stub
}

Enemy::~Enemy() {
	// TODO Auto-generated destructor stub
}
void Enemy::load(const LoaderParams* pParams) {
	SDLGameObject::load(pParams);
}

void Enemy::clean() {
	SDLGameObject::clean();

}

void Enemy::draw() {
	SDLGameObject::draw();
}

void Enemy::update() {
	m_currentFrame = int((SDL_GetTicks() / 100) % 6);
	SDLGameObject::update();

	if(m_position.getY()<0)
	{
		m_velocity.setY(2);
	}else
	if(m_position.getY()>400)
	{
		m_velocity.setY(-2);
	}


}
