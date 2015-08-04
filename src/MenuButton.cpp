/*
 * MenuButton.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: youssef
 */

#include "MenuButton.h"
#include "Vector2D.h"
#include "InputHandler.h"
MenuButton::MenuButton(){

}

MenuButton::~MenuButton() {
	// TODO Auto-generated destructor stub
}
void MenuButton::load(const LoaderParams* pParams)
{
	m_callBackID=pParams->getCallBackID();
	m_currentFrame = MOUSE_OUT;

	SDLGameObject::load(pParams);

}
void MenuButton::draw() {
	SDLGameObject::draw();
}
void MenuButton::update() {
	Vector2D *m_Mouseposition = TheInputHandler::Instance()->getMousePosition();
	if (m_Mouseposition->getX() < m_position.getX() + m_width
			&& m_Mouseposition->getX() > m_position.getX()
			&& m_Mouseposition->getY() < m_position.getY() + m_height
			&& m_Mouseposition->getY() > m_position.getY()) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased)
		{
			cout<<"clicked";
			m_currentFrame = CLICKED;
			m_callback();
			m_bReleased = false;
		} else if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			cout<<"clicked";
			m_currentFrame = MOUSE_OVER;
			m_bReleased = true;
		}
	} else {
		m_currentFrame = MOUSE_OUT;
	}
}
void MenuButton::clean() {
	SDLGameObject::clean();
}
