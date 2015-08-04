//
//  ObjectLayer.h
//  SDLTest
//
//  Created by youssef on 7/1/15.
//  Copyright (c) 2015 SDL. All rights reserved.
//

#ifndef __SDLTest__ObjectLayer__
#define __SDLTest__ObjectLayer__

#include <stdio.h>
#include "Layer.h"
#include "GameObject.h"
#include <vector>
#endif /* defined(__SDLTest__ObjectLayer__) */

class ObjectLayer :public Layer {
    
    
public:
    virtual void update();
    virtual void render();
    
    std::vector<GameObject*> *getGameObjects()
    {
        return &m_gameObjects;
    }
    
    
private:
    std::vector<GameObject*> m_gameObjects;
};