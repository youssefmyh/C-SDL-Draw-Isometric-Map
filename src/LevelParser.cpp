/*
 * LevelParser.cpp
 *
 *  Created on: Jun 29, 2015
 *      Author: youssef
 */

#include "LevelParser.h"
#include "TextureManager.h"
#include "Game.h"
#include <zlib.h>
#include "TileLayer.h"
#include "base64.h"
#include "GameObjectFactory.h"
#include "LoaderParams.h"
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
    pRoot->Attribute("tileheight", &m_tileheight);

	for (TiXmlElement *e = pRoot->FirstChildElement(); e != NULL; e=e->NextSiblingElement()) {
		if (e->Value() == std::string("tileset")) {
			parseTilesets(e, pLevel->getTileSets());
		}
	}

	for (TiXmlElement *e = pRoot->FirstChildElement(); e != NULL; e=e->NextSiblingElement()) {
		if (e->Value() == std::string("objectgroup")||e->Value() == std::string("layer"))
        {
            if(e->FirstChildElement()->Value() == std::string("object")){
                parseObjectLayer(e, pLevel->getlayers());
            }
            else
            if(e->FirstChildElement()->Value() == std::string("data")){
			parseTileLayers(e, pLevel->getlayers(), pLevel->getTileSets());
            }
		}
	}
    
    for (TiXmlElement *e = pRoot->FirstChildElement(); e != NULL; e=e->NextSiblingElement()) {
        if (e->Value() == std::string("properties")) {
            parseTexture(e);
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
    if(pTileSetRoot->Attribute("spacing", &tileset.spacing)==NULL)
        tileset.spacing=0;
    if(pTileSetRoot->Attribute("margin", &tileset.margin)==NULL)
        tileset.margin=0;

	pTileSetRoot->Attribute("firstgid", &tileset.firstGridID);
	tileset.name = pTileSetRoot->Attribute("name");

	pRooTileSet->Attribute("width", &tileset.width);
	pRooTileSet->Attribute("height", &tileset.height);
	tileset.numColumns = tileset.width / (tileset.tileWidth + tileset.spacing);

	pTileSets->push_back(tileset);

}
void LevelParser::parseTileLayers(TiXmlElement *pTileElement, std::vector<
		Layer*> *pLayers, const std::vector<Tileset> *pTileSets) {

	TileLayer *ptileLayer = new TileLayer(m_tileSize, m_tileheight,*pTileSets);
	std::vector < vector<int> > data;
	std::string decodedIDs;

	TiXmlElement *PDataNode;

	for (TiXmlElement *e = pTileElement->FirstChildElement(); e != NULL; e=e->NextSiblingElement()) {
		if (e->Value() == std::string("data")) {
			PDataNode = e;
		}
	}

	for (TiXmlNode *e = PDataNode->FirstChild(); e != NULL; e=e->NextSibling()) {
		TiXmlText *text = e->ToText();
		std::string t = text->Value();
		decodedIDs = base64_decode(t);
	}

	uLong numGids=m_width*m_height*sizeof(int);
	std::vector<unsigned> gids(numGids);
	uncompress((Bytef*)&gids[0],&numGids,(const Bytef*)decodedIDs.c_str(),decodedIDs.size());

    
    std::vector<int> layerRow(m_width);
    
    for (int i=0; i<m_height; i++) {
        data.push_back(layerRow);
    }
    
    for (int row=0; row<m_height; row++) {
        for (int cols=0; cols<m_width; cols++) {
            data[row][cols]=gids[row*m_width+cols];
        }
    }
    
    ptileLayer->setTileIDs(data);
    pLayers->push_back(ptileLayer);

}

void LevelParser::parseTexture(TiXmlElement *pTextureRoot)
{
    TheTextureManager::Instance()->load(pTextureRoot->FirstChildElement()->Attribute("value"), pTextureRoot->FirstChildElement()->Attribute("name"), TheGame::instance()->getRenderer());

}
void LevelParser::parseObjectLayer(TiXmlElement *pObjectElement,std::vector<Layer*> *pLayers)
{
    ObjectLayer *objectLayer=new ObjectLayer();
    for (TiXmlElement *e = pObjectElement->FirstChildElement(); e != NULL; e=e->NextSiblingElement()) {
        if (e->Value() == std::string("object")) {
            int x,y,width,height,numFrames,callbackID,animSpeed;
            std::string textureID;
            e->Attribute("x", &x);
            e->Attribute("y", &y);
            e->Attribute("width", &width);
            e->Attribute("height", &height);
            
           GameObject *pGameObject= TheGameObjectFactory::instance()->create(e->Attribute("type"));
            for (TiXmlElement *properties = e->FirstChildElement(); properties != NULL; properties=properties->NextSiblingElement())
            {
                if (properties->Value() == std::string("properties"))
                {
                    for (TiXmlElement *property = properties->FirstChildElement(); property != NULL; property=property->NextSiblingElement())
                    {
                        if(property->Attribute("name") == std::string("numFrames"))
                        {
                            property->Attribute("value" ,&numFrames);
                        }
                        else if(property->Attribute("name") ==
                                std::string("textureHeight"))
                        {
                            property->Attribute("value", &height);
                        }
                        else if(property->Attribute("name") ==
                                std::string("textureID"))
                        {
                            textureID = property->Attribute("value");
                        }
                        else if(property->Attribute("name") ==
                                std::string("textureWidth"))
                        {
                            property->Attribute("value", &width);
                        }
                        else if(property->Attribute("name") ==
                                std::string("callbackID"))
                        {
                            property->Attribute("value", &callbackID);
                        }
                        else if(e->Attribute("name") ==
                                std::string("animSpeed"))
                        {
                            property->Attribute("value", &animSpeed);
                        }
                    }
                    
                }
                
            }
            
            
            pGameObject->load(new LoaderParams(x,y,width,height,numFrames,animSpeed,callbackID,textureID));
            objectLayer->getGameObjects()->push_back(pGameObject);
        }
    
    
    
    
    }
    pLayers->push_back(objectLayer);
}

