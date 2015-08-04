/*
 * SDLGameObject.cpp
 *
 *  Created on: Jun 14, 2015
 *      Author: youssef
 */

#include "SDLGameObject.h"
#include "Game.h"
SDLGameObject::SDLGameObject() :m_velocity(0,0),m_acceleration(0,0),m_position(0,0){
	// TODO Auto-generated constructor stub


}

void SDLGameObject::load(const LoaderParams *pParams){
	// TODO Auto-generated constructor stub
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_currentFrame = 1;
	m_currentRow = 1;

}

SDLGameObject::~SDLGameObject() {
	// TODO Auto-generated destructor stub
}

void SDLGameObject::draw() {
	if(m_velocity.getX()>0)
	{
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(),m_position.getY(), m_width,
				m_height, m_currentRow, m_currentFrame,
				Game::instance()->getRenderer(),SDL_FLIP_HORIZONTAL);
	}else
	{
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(),m_position.getY(), m_width,
				m_height, m_currentRow, m_currentFrame,
				Game::instance()->getRenderer());
	}

}
void SDLGameObject::clean() {
}
void SDLGameObject::update() {
	m_velocity += m_acceleration;
	m_position += m_velocity;

}

