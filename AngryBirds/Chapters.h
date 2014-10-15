//
//  Chapters.h
//  AngryBirds
//
//  Created by zyuq on 13-7-1.
//
//

#ifndef __AngryBirds__Chapters__
#define __AngryBirds__Chapters__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class Chapters:public CCObject {
    
public:
    CCArray* _chapters;
public:
    Chapters();
    ~Chapters();
    CCArray* getArray();
};

#endif /* defined(__AngryBirds__Chapters__) */
