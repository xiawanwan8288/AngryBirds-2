//
//  Pig.h
//  AndryPanda
//
//  Created by user on 13-7-2.
//
//

#ifndef __AndryPanda__Pig__
#define __AndryPanda__Pig__

#include <iostream>
#include "Box2D.h"
#include "SpriteBase.h"
class Pig:public SpriteBase
{
public:
    Pig(CCPoint p,b2World *world,CCLayer *layer);
    ~Pig();
};
#endif /* defined(__AndryPanda__Pig__) */
