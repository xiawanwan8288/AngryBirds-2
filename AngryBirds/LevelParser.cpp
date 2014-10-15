//
//  LevelParser.cpp
//  AngryBirds
//
//  Created by zyuq on 13-7-1.
//
//

#include "LevelParser.h"
#include <string.h>
#include <stdlib.h>

#include "Levels.h"
#include "Level.h"
#include "tinystr.h"
#include "tinyxml.h"
//static Levels* levels=NULL;
Levels * LevelParser::loadData(int chapterNumber)
{
    Levels *levels = new Levels();
    char t[50];
    sprintf(t, "Levels_Chapter%i.xml",chapterNumber);
    string filepath =  CCFileUtils::sharedFileUtils()->fullPathForFilename(t);
    TiXmlDocument *myDocument = new TiXmlDocument(filepath.c_str());
    myDocument->LoadFile();
    TiXmlElement *element = myDocument->RootElement()->FirstChildElement();
    while (element)
    {
        TiXmlElement *name = element->FirstChildElement();
        TiXmlElement *number = name->NextSiblingElement();
        TiXmlElement *unlocked = number->NextSiblingElement();
        TiXmlElement *stars = unlocked->NextSiblingElement();
        TiXmlElement *data = stars->NextSiblingElement();
        TiXmlElement *levelClear = data->NextSiblingElement();
        bool temp;
        if(strcmp((char *)unlocked->FirstChild()->Value(), "0")==0)
        {
            temp = false;
        }
        else
        {
            temp = true;
        }
        bool temp2;
        if(strcmp((char *)levelClear->FirstChild()->Value(), "0")==0)
        {
            temp2 = false;
        }
        else
        {
            temp2 = true;
        }
        Level *level = new Level((char *)name->FirstChild()->Value(),
                                 atoi(number->FirstChild()->Value()),
                                 temp,
                                 atoi(stars->FirstChild()->Value()),
                                 (char *)data->FirstChild()->Value(),
                                 temp2);
        levels->_levels->addObject((CCObject *)level);
        element = element->NextSiblingElement();
    }
    return levels;
}