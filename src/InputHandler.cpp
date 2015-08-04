/*
 * InputHandler.cpp
 *
 *  Created on: Jun 15, 2015
 *      Author: youssef
 */

#include "InputHandler.h"
#include "Game.h"
using namespace std;
InputHandler *InputHandler::s_pInstance = 0;
InputHandler::InputHandler() {
	// TODO Auto-generated constructor stub
	for (int i = 0; i < 3; i++) {
		m_mouseButtonState.push_back(false);
	}
	m_mousePosition = new Vector2D(0, 0);
	m_keystates = SDL_GetKeyboardState(0);
}

InputHandler::~InputHandler() {
	// TODO Auto-generated destructor stub
}

void InputHandler::update() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT: {
			TheGame::instance()->quit();
			TheGame::instance()->clean();
		}
			break;
		case SDL_MOUSEBUTTONDOWN: {
			onMouseButtonDown(event);
		}
			break;
		case SDL_MOUSEBUTTONUP: {
			onMouseButtonUp(event);
		}
			break;
		case SDL_MOUSEMOTION: {
			onMouseMove(event);
		}
			break;
		case SDL_KEYDOWN: {
			onKeyDown();
		}
			break;
		case SDL_KEYUP: {
			onKeyUp();
		}
			break;
		default:
			break;
		}

	}
}
void InputHandler::clean() {
	if (m_bJoysticksInitialised) {
		for (unsigned int i = 0; i < m_joysticks.size(); i++) {
			SDL_JoystickClose(m_joysticks[i]);
		}
	}
}
bool InputHandler::getMouseButtonState(int buttonNumber) {
	return m_mouseButtonState[buttonNumber];

}

void InputHandler::initialiseJoysticks() {
	if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0) {
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}
	if (SDL_NumJoysticks() > 0) {
		for (int i = 0; i < SDL_NumJoysticks(); i++) {
			SDL_Joystick *joyStick = SDL_JoystickOpen(i);
			if (SDL_JoystickOpen(i)) {
				m_joysticks.push_back(joyStick);
			} else {
				cout << SDL_GetError() << '\n';
			}
		}
		SDL_JoystickEventState(SDL_ENABLE);
		m_bJoysticksInitialised = true;
		cout << "Initialised" << m_joysticks.size() << '\n';
	} else {
		m_bJoysticksInitialised = false;
		cout << "No Joy Stick" << '\n';
	}

}

bool InputHandler::isKeyDown(SDL_Scancode key) {

	if (m_keystates != 0) {
		if (m_keystates[key] == 1) {
			return true;
		} else {
			return false;
		}

	}
	return false;
}

Vector2D *InputHandler::getMousePosition() {
	return m_mousePosition;
}

void InputHandler::onMouseMove(SDL_Event& event) {
	m_mousePosition->setX(event.button.x);
	m_mousePosition->setY(event.button.y);
}
void InputHandler::onMouseButtonDown(SDL_Event& event) {
	if (event.button.button == SDL_BUTTON_LEFT) {
		cout << "SDL_BUTTON_LEFT" << '\n';
		m_mouseButtonState[LEFT] = true;
	}
	if (event.button.button == SDL_BUTTON_RIGHT) {
		cout << "SDL_BUTTON_RIGHT" << '\n';
		m_mouseButtonState[RIGHT] = true;

	}
	if (event.button.button == SDL_BUTTON_MIDDLE) {
		cout << "SDL_BUTTON_MIDDLE" << '\n';
		m_mouseButtonState[MIDDLE] = true;

	}
}
void InputHandler::onMouseButtonUp(SDL_Event& event) {
	if (event.button.button == SDL_BUTTON_LEFT) {
		cout << "SDL_BUTTON_LEFT UP" << '\n';
		m_mouseButtonState[LEFT] = false;

	}
	if (event.button.button == SDL_BUTTON_RIGHT) {
		cout << "SDL_BUTTON_RIGHT UP" << '\n';
		m_mouseButtonState[RIGHT] = false;

	}
	if (event.button.button == SDL_BUTTON_MIDDLE) {
		cout << "SDL_BUTTON_MIDDLE UP" << '\n';
		m_mouseButtonState[MIDDLE] = false;

	}
}
void InputHandler::onKeyDown() {
}
void InputHandler::onKeyUp() {
}
