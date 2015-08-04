/*
 * GameObject.cpp
 *
 *  Created on: Jun 14, 2015
 *      Author: youssef
 */

#include "GameObject.h"
#include "Game.h"
GameObject::GameObject() {
	// TODO Auto-generated constructor stub

}

GameObject::~GameObject() {
	// TODO Auto-generated destructor stub
}
void GameObject::load(const LoaderParams *pParams) {
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_textureID = pParams->getTextureID();
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_currentRow = 1;
	m_currentFrame = 1;

}

void GameObject::clean() {
}
void GameObject::update() {
	m_x += 1;
	m_currentFrame = int((SDL_GetTicks() / 100) % 6);
}
void GameObject::draw() {
	TextureManager::Instance()->drawFrame(m_textureID.c_str(), m_x, m_y,
			m_width, m_height, m_currentRow, m_currentFrame,
			Game::instance()->getRenderer());
}
