/*
 * Level.cpp
 *
 *  Created on: Jun 28, 2015
 *      Author: Home
 */

#include "Level.h"

Level::Level() {
	// TODO Auto-generated constructor stub

}

Level::~Level() {
	// TODO Auto-generated destructor stub
}

void Level::render() {
	for (int i = 0; i < m_layers.size(); ++i) {
	//	m_layers[i].render();
	}
}
void Level::update() {
	for (int i = 0; i < m_layers.size(); ++i) {
		//m_layers[i].update();
	}
}
