/*
 * Player.cpp
 *
 *  Created on: Jun 14, 2015
 *      Author: youssef
 */

#include "Player.h"
#include "InputHandler.h"
#include "Vector2D.h"
Player::Player()
	 {
	// TODO Auto-generated constructor stub
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

void Player::clean() {
	SDLGameObject::clean();

}

void Player::draw() {
	SDLGameObject::draw();
}
void Player::load(const LoaderParams *pParams)
  {
    SDLGameObject::load(pParams);
  }
void Player::update() {
	m_currentFrame = int((SDL_GetTicks() / 100) % 6);
		Vector2D* vec=TheInputHandler::Instance()->getMousePosition();
		m_velocity=(*vec-m_position)/100;
	//
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
		m_velocity.setY(2);
	}
	SDLGameObject::update();
}
