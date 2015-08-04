//
//  ObjectLayer.cpp
//  SDLTest
//
//  Created by youssef on 7/1/15.
//  Copyright (c) 2015 SDL. All rights reserved.
//

#include "ObjectLayer.h"
void ObjectLayer::update()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}


void ObjectLayer::render()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}