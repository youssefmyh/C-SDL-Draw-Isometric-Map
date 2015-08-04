/*
 * MenuButton.h
 *
 *  Created on: Jun 17, 2015
 *      Author: youssef
 */

#ifndef MENUBUTTON_H_
#define MENUBUTTON_H_

#include "SDLGameObject.h"
#include "LoaderParams.h"
enum button_state {
	MOUSE_OUT = 0, MOUSE_OVER = 1, CLICKED = 2
};
class MenuButton: public SDLGameObject {
public:
	MenuButton();
	virtual ~MenuButton();
	virtual void draw();
	virtual void update();
	virtual void clean();
	int getCallBackID() const {
		return m_callBackID;
	}
	void load(const LoaderParams *params);
	void setCallBack(void(*callback)()){m_callback=callback;}
private:
	void(*m_callback)();
	bool m_bReleased;
	int m_callBackID;
};

#endif /* MENUBUTTON_H_ */
