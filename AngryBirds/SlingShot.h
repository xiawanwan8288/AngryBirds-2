//
//  SlingShot.h
//  AndryPanda
//
//  Created by user on 13-7-2.
//
//

#ifndef __AndryPanda__SlingShot__
#define __AndryPanda__SlingShot__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class SlingShot:public CCSprite
{
public:
    CCPoint _startPoint1;
    CCPoint _startPoint2;
    CCPoint _endPoint;
public:
    SlingShot();
    virtual void draw();
};
#endif /* defined(__AndryPanda__SlingShot__) */
