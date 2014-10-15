//
//  Level.h
//  AngryBirds
//
//  Created by zyuq on 13-7-1.
//
//

#ifndef __AngryBirds__Level__
#define __AngryBirds__Level__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class Level:public CCObject {
public:
    char *_name;
    int _number;
    bool _unlocked;
    int _stars;
    char *_data;
    bool _levelClear;
public:
    Level(char *name,int number,bool unlocked,int stars,char *data,bool levelClear);
    ~Level();
};

#endif /* defined(__AngryBirds__Level__) */
