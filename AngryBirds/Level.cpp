//
//  Level.cpp
//  AngryBirds
//
//  Created by zyuq on 13-7-1.
//
//

#include "Level.h"
Level::Level(char *name,int number,bool unlocked,int stars,char *data,bool levelClear)
{
    
    _name = new char[strlen(name)+1];
    strcpy(_name, name);
    _number=number;
    _unlocked= unlocked;
    _stars = stars;
    _data = new char[strlen(data)+1];
    strcpy(_data, data);
    _levelClear = levelClear;
    
}
Level::~Level()
{
    delete _name;
    delete _data;
}
