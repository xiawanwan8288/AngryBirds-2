//
//  Ice.h
//  AndryPanda
//
//  Created by user on 13-7-2.
//
//

#ifndef __AndryPanda__Ice__
#define __AndryPanda__Ice__

#include <iostream>
#include "Box2D.h"
#include "SpriteBase.h"
using namespace cocos2d;
class Ice:public SpriteBase
{
public:
    Ice(CCPoint p,b2World *world,CCLayer *layer);
    ~Ice();
};
#endif /* defined(__AndryPanda__Ice__) */
