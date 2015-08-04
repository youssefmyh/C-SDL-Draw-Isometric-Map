/*
 * LevelParser.cpp
 *
 *  Created on: Jun 29, 2015
 *      Author: Home
 */

#include "LevelParser.h"
#include "TextureManager.h"
#include "Game.h"
#include <zlib.h>
#include "TileLayer.h"
#include "base64.h"
LevelParser::LevelParser() {
	// TODO Auto-generated constructor stub

}

LevelParser::~LevelParser() {
	// TODO Auto-generated destructor stub
}

Level *LevelParser::parseLevel(const char *levelFile) {

	TiXmlDocument levelDocument;
	if (!levelDocument.LoadFile(levelFile)) {
		cout << "not able to open file " << levelFile << '\n';
		return NULL;
	}

	Level *pLevel = new Level();
	TiXmlElement *pRoot = levelDocument.RootElement();
	pRoot->Attribute("width", &m_width);
	pRoot->Attribute("height", &m_height);
	pRoot->Attribute("tilewidth", &m_tileSize);

	for (TiXmlElement *e = pRoot->FirstChildElement(); e != NULL; e->NextSiblingElement()) {
		if (e->Value() == std::string("tileset")) {
			parseTilesets(e, pLevel->getTileSets());
		}
	}

	for (TiXmlElement *e = pRoot->FirstChildElement(); e != NULL; e->NextSiblingElement()) {
		if (e->Value() == std::string("layer")) {
			parseTileLayers(e, pLevel->getlayers(), pLevel->getTileSets());
		}
	}

	return pLevel;
}

void LevelParser::parseTilesets(TiXmlElement *pTileSetRoot,
		std::vector<Tileset> *pTileSets) {

	TiXmlElement *pRooTileSet = pTileSetRoot->FirstChildElement();

	TheTextureManager::Instance()->load(pRooTileSet->Attribute("source"),
			pTileSetRoot->Attribute("name"), TheGame::instance()->getRenderer());
	Tileset tileset;
	pTileSetRoot->Attribute("tilewidth", &tileset.tileWidth);
	pTileSetRoot->Attribute("tileheight", &tileset.tileHeight);
	pTileSetRoot->Attribute("spacing", &tileset.spacing);
	pTileSetRoot->Attribute("margin", &tileset.margin);
	pTileSetRoot->Attribute("firstgid", &tileset.firstGridID);
	tileset.name = pTileSetRoot->Attribute("name");

	pRooTileSet->Attribute("width", &tileset.width);
	pRooTileSet->Attribute("height", &tileset.height);
	tileset.numColumns = tileset.width / (tileset.width + tileset.spacing);

	pTileSets->push_back(tileset);

}
void LevelParser::parseTileLayers(TiXmlElement *pTileElement, std::vector<
		Layer*> *pLayers, const std::vector<Tileset> *pTileSets) {

	TileLayer *tileLayer = new TileLayer(m_tileSize, *pTileSets);
	std::vector < vector<int> > data;
	std::string decodedIDs;

	TiXmlElement *PDataNode;

	for (TiXmlElement *e = pTileElement->FirstChildElement(); e != NULL; e->NextSiblingElement()) {
		if (e->Value() == std::string("data")) {
			PDataNode = e;
		}
	}

	for (TiXmlNode *e = PDataNode->FirstChild(); e != NULL; e->NextSibling()) {
		TiXmlText *text = e->ToText();
		std::string t = text->Value();
		decodedIDs = base64_decode(t);
	}

	uLong numGids=m_width*m_height*sizeof(int);
	std::vector<unsigned> gids(numGids);
	uncompress((Bytef*)&gids[0],&numGids,(const Bytef*)decodedIDs.c_str(),decodedIDs.size());


}
