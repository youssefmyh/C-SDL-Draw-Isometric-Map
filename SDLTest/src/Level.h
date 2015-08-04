/*
 * Level.h
 *
 *  Created on: Jun 28, 2015
 *      Author: Home
 */

#ifndef LEVEL_H_
#define LEVEL_H_
#include <iostream>
#include <vector>
#include "Layer.h"
struct Tileset {
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;
	std::string name;

};

class Level {
public:

	virtual ~Level();
	void update();
	void render();
	std::vector<Tileset> *getTileSets() {
		return &m_tilesets;
	}
	std::vector<Layer*> *getlayers() {
		return &m_layers;
	}
private:
	friend class LevelParser;
	std::vector<Tileset> m_tilesets;
	std::vector<Layer*> m_layers;
	Level();
};

#endif /* LEVEL_H_ */
