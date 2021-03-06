/*
 * LevelParser.h
 *
 *  Created on: Jun 29, 2015
 *      Author: Home
 */

#ifndef LEVELPARSER_H_
#define LEVELPARSER_H_
#include "Level.h"
#include "tinyxml.h"
 class LevelParser {
public:
	LevelParser();
	virtual ~LevelParser();
	Level *parseLevel(const char *levelFile);

private:
	void parseTilesets(TiXmlElement *pTileSetRoot,std::vector<Tileset> *pTileSets);
	void parseTileLayers(TiXmlElement *pTileElement,std::vector<Layer*> *pLayers,const std::vector<Tileset> *pTileSets);
	int m_tileSize;
	int m_width;
	int m_height;

};

#endif /* LEVELPARSER_H_ */
