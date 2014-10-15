//
//  Chapters.cpp
//  AngryBirds
//
//  Created by zyuq on 13-7-1.
//
//

#include "Chapters.h"
Chapters::Chapters()
{
    _chapters=CCArray::createWithCapacity(5);
    _chapters->retain();
}
Chapters::~Chapters()
{
     _chapters->release();
}
CCArray* Chapters::getArray()
{
    return _chapters;
}