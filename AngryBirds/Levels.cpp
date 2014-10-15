//
//  Levels.cpp
//  AngryBirds
//
//  Created by zyuq on 13-7-1.
//
//

#include "Levels.h"
Levels::Levels()
{
    _levels=CCArray::create();
    _levels->retain();
}
Levels::~Levels()
{
     _levels->release();
}