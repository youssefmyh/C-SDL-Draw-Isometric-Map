/*
 * InputHandler.h
 *
 *  Created on: Jun 15, 2015
 *      Author: youssef
 */

#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_
#include <SDL2/SDL.h>
#include <vector>
#include <SDL2/SDL_joystick.h>
#include "Vector2D.h"
enum mouse_buttons {
	LEFT = 0, MIDDLE = 1, RIGHT = 2
};

class InputHandler {
public:
	static InputHandler* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void clean();
	void initialiseJoysticks();
	bool getMouseButtonState(int buttonNumber);
	bool joysticksInitialised() {
		return m_bJoysticksInitialised;
	}
	Vector2D *getMousePosition();
	bool isKeyDown(SDL_Scancode key);
	virtual ~InputHandler();
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);
	void onKeyDown();
	void onKeyUp();
private:
	InputHandler();
	static InputHandler *s_pInstance;
	bool m_bJoysticksInitialised;
	std::vector<SDL_Joystick*> m_joysticks;
	std::vector<bool> m_mouseButtonState;
	Vector2D *m_mousePosition;
	const Uint8* m_keystates;
};
typedef InputHandler TheInputHandler;
#endif /* INPUTHANDLER_H_ */
