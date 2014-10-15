//
//  Chapter.h
//  AngryBirds
//
//  Created by zyuq on 13-7-1.
//
//

#ifndef __AngryBirds__Chapter__
#define __AngryBirds__Chapter__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class Chapter:public CCObject{
public:
    char* name;
    int number;
    bool unlocked;
public:
    void setNumber(int number);
    int getNumber();
    bool getUnlocked();
    char* getName();
    Chapter(char* _name,int _number,bool unlocked);
    ~Chapter();
};

#endif /* defined(__AngryBirds__Chapter__) */
