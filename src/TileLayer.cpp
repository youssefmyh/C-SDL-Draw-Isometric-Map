/*
 * TileLayer.cpp
 *
 *  Created on: Jun 29, 2015
 *      Author: youssef
 */

#include "TileLayer.h"
#include "Game.h"


TileLayer::~TileLayer()
{
}

void TileLayer::update() {
    m_position+=m_velocity;
      m_velocity.setX(2);
}
void TileLayer::render() {
    
   int sx,sy,x2,y2=0;
    
    sx=m_position.getX()/m_tileSize;
    sy=m_position.getY()/m_tileHeight;
//
//    x2=int(m_position.getX())%m_tileSize;
//    y2=int(m_position.getY())%m_tileSize;

    for (int r=0; r<m_tileIDs.size(); r++)
    {
        for (int c=0; c<m_tileIDs[r].size(); c++)
        {
          
            int start_x, start_y;
            start_x = (TheGame::instance()->getGameWidth()/2) - (m_tileSize/2); // adjust x start position
            start_y = ((TheGame::instance()->getGameHeight()/2) - (m_tileHeight/2))/m_tileSize; // adjust y start position
            
            int id=m_tileIDs[r+sy][c+sx];
            if(id==0)
                continue;
            Tileset tileset=getTilesetByID(id);
            id--;
            int x,y;
            x = start_x + ((c*(m_tileSize/2)) - (r*(m_tileSize/2)));
            y = start_y + (((r*m_tileHeight) + (c*m_tileHeight))/2);
            
//            //MOVEMENT
//            // include velocity
            x += 4;
            y += 4;
            
      
           

            SDL_Rect tileRect;
            tileRect.h = tileset.tileHeight;
            tileRect.w = tileset.tileWidth;
            tileRect.x = x;
            tileRect.y = y;
          
            
            
            TheTextureManager::Instance()->drawTile(tileset.name, tileset.margin, tileset.spacing,
            tileset.tileWidth,tileset.tileHeight, (id - (tileset.firstGridID - 1)) /tileset.numColumns, (id - (tileset.firstGridID - 1)) %tileset.numColumns, TheGame::instance()->getRenderer(),&tileRect);
        }
    }
    
    
}

TileLayer::TileLayer(int tileWidth,int tileHeight, const std::vector<Tileset> &tilesets) :
m_position(0, 0), m_velocity(0, 0), m_tilesets(tilesets),m_tileSize(tileWidth),m_tileHeight(tileHeight) {
    m_numColumns=(TheGame::instance()->getGameWidth()/m_tileSize);
    m_numRows=(TheGame::instance()->getGameHeight()/m_tileHeight);

}

Tileset TileLayer::getTilesetByID(int tileID)
{
    for(int i = 0; i < m_tilesets.size(); i++)
    {
        if( i + 1 <= m_tilesets.size() - 1)
        {
            if(tileID >= m_tilesets[i].firstGridID&&tileID < m_tilesets[i +
                                                                        1].firstGridID)
            {
                return m_tilesets[i];
            } }
        else {
            return m_tilesets[i];
        }
    }
    std::cout << "did not find tileset, returning empty tileset\n";
    Tileset t;
    return t;
}




