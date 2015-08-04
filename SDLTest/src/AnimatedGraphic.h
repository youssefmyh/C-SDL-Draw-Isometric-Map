/*
 * AnimatedGraphic.h
 *
 *  Created on: Jun 20, 2015
 *      Author: Home
 */

#ifndef ANIMATEDGRAPHIC_H_
#define ANIMATEDGRAPHIC_H_

#include "SDLGameObject.h"

class AnimatedGraphic: public SDLGameObject {
public:
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);
	virtual ~AnimatedGraphic();
	virtual void update();
	void load(const LoaderParams* pParams);

private:
	int m_animSpeed;
};

#endif /* ANIMATEDGRAPHIC_H_ */
