//
//  ChapterParser.h
//  AngryBirds
//
//  Created by zyuq on 13-7-1.
//
//

#ifndef __AngryBirds__ChapterParser__
#define __AngryBirds__ChapterParser__

#include <iostream>
#include "cocos2d.h"
#include "Chapters.h"
using namespace cocos2d;
class ChapterParser:public CCObject {
    
    
public:
    static Chapters* loadData();
};

#endif /* defined(__AngryBirds__ChapterParser__) */
