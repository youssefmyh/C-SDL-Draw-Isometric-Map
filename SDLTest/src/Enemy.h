/*
 * Enemy.h
 *
 *  Created on: Jun 14, 2015
 *      Author: Home
 */

#ifndef ENEMY_H_
#define ENEMY_H_

#include "LoaderParams.h"
#include "SDLGameObject.h"
class Enemy: public SDLGameObject {
public:
	Enemy(const LoaderParams* pParams);
	virtual ~Enemy();
	void load(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
};

#endif /* ENEMY_H_ */
