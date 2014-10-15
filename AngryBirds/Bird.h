//
//  Bird.h
//  AndryPanda
//
//  Created by user on 13-7-2.
//
//

#ifndef __AndryPanda__Bird__
#define __AndryPanda__Bird__

#include <iostream>
#include "Box2D.h"
#include "cocos2d.h"

#include "SpriteBase.h"
using namespace cocos2d;
class Bird:public SpriteBase
{
public:
    bool _isFly;
    bool _isReady;
    
public:
    Bird(CCPoint p,b2World *world,CCLayer *layer);
    ~Bird();
    void setSpeed(float x,float y,b2World *world);
    void hitAnimation(CCPoint p);
};
#endif /* defined(__AndryPanda__Bird__) */
