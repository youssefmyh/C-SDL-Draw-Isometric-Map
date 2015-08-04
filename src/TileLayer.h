/*
 * TileLayer.h
 *
 *  Created on: Jun 29, 2015
 *      Author: youssef
 */

#ifndef TILELAYER_H_
#define TILELAYER_H_

#include "Layer.h"
#include <iostream>
#include <vector>
#include "Level.h"
#include "Vector2D.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
using namespace std;
class TileLayer: public Layer {
public:
	virtual ~TileLayer();
       TileLayer(int tileSize, int tileHeight,const std::vector<Tileset> &tilesets);
       virtual void update();
       virtual void render();
       void setTileIDs(const std::vector<std::vector<int> > & data)
       {
           m_tileIDs = data;
       }
       void setTileSize(int tileSize)
       {
           m_tileSize = tileSize;
       }
       Tileset getTilesetByID(int tileID);
     private:
       int m_numColumns;
       int m_numRows;
       int m_tileSize;
    int m_tileHeight;
       Vector2D m_position;
       Vector2D m_velocity;
       const std::vector<Tileset> &m_tilesets;
       std::vector<std::vector<int> > m_tileIDs;

};

#endif /* TILELAYER_H_ */
