//
//  ChapterParser.cpp
//  AngryBirds
//
//  Created by zyuq on 13-7-1.
//
//

#include "ChapterParser.h"
#include "tinyxml.h"
#include "tinystr.h"
#include "Chapters.h"
#include "Chapter.h"
#include <string.h>
using namespace std;
static Chapters* chapters=NULL;
Chapters* ChapterParser::loadData()
{
    if (chapters==NULL) {
        chapters=new Chapters();
    }else
    {
        return chapters;
    }
     //chapters=new Chapters();
    string filepath =  CCFileUtils::sharedFileUtils()->fullPathForFilename("Chapters.xml");
    
   // const char* str=CCFileUtils::fullPathForFilename("Chapters.xml");
    TiXmlDocument* myDocument=new TiXmlDocument(filepath.c_str());
    myDocument->LoadFile();
    TiXmlElement* RootElement=myDocument->RootElement();
    TiXmlElement* element=RootElement->FirstChildElement();
    while (element) {
        TiXmlElement* name=element->FirstChildElement();
        TiXmlElement* age=name->NextSiblingElement();
        TiXmlElement* unlocked=age->NextSiblingElement();
        bool temp;
        if (strcmp((char*)unlocked->FirstChild()->Value(), "0")==0) {
            temp=false;
        }else{
            temp=true;
        }
        
        Chapter* chapter=new Chapter((char*)name->FirstChild()->Value(),(int)age->FirstChild()->Value(),temp);
        chapters->getArray()->addObject((CCObject*)chapter);
        element=element->NextSiblingElement();
    }
    return chapters;
    
}