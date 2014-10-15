//
//  Chapter.cpp
//  AngryBirds
//
//  Created by zyuq on 13-7-1.
//
//

#include "Chapter.h"
void Chapter::setNumber(int number)
{
   this->number=number;
    
}
int Chapter::getNumber()
{
    return number;
}
bool Chapter::getUnlocked()
{
    return unlocked;
}
char* Chapter::getName()
{
    return name;
}



Chapter::Chapter(char* _name,int _number,bool unlocked)
{
    this->name=new char(strlen(_name)+1);
    strcpy(name, _name);
    this->number=number;
    this->unlocked=unlocked;
}
Chapter::~Chapter()
{
    
}













