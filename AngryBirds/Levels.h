//
//  Levels.h
//  AngryBirds
//
//  Created by zyuq on 13-7-1.
//
//

#ifndef __AngryBirds__Levels__
#define __AngryBirds__Levels__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class Levels:public CCObject {
public:
    CCArray *_levels;
public:
    Levels();
    ~Levels();
};

#endif /* defined(__AngryBirds__Levels__) */
