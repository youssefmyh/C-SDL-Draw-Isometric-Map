/*
 * AnimatedGraphic.cpp
 *
 *  Created on: Jun 20, 2015
 *      Author: youssef
 */

#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams, int animSpeed) :
	m_animSpeed(animSpeed) {
	// TODO Auto-generated constructor stub
	SDLGameObject::load(pParams);

}
void AnimatedGraphic::load(const LoaderParams* pParams)
{
	SDLGameObject::load(pParams);

}

AnimatedGraphic::~AnimatedGraphic() {
	// TODO Auto-generated destructor stub
}
void AnimatedGraphic::update() {
	m_currentFrame = int(
			((SDL_GetTicks() / (1000 / m_animSpeed)) % 6));

}
