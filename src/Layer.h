/*
 * Layer.h
 *
 *  Created on: Jun 28, 2015
 *      Author: youssef
 */

#ifndef LAYER_H_
#define LAYER_H_
#include <iostream>
#include <vector>
class Layer {
public:
	Layer();
	virtual ~Layer();
	virtual void render()=0;
	virtual void update()=0;


};

#endif /* LAYER_H_ */
