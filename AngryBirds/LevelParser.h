//
//  LevelParser.h
//  AngryBirds
//
//  Created by zyuq on 13-7-1.
//
//

#ifndef __AngryBirds__LevelParser__
#define __AngryBirds__LevelParser__

#include <iostream>
#include "cocos2d.h"
#include "Levels.h"
using namespace cocos2d;
using namespace std;
class LevelParser:public CCObject {
public:
   // Levels* levels;

    static Levels * loadData(int chapterNumber);
};

#endif /* defined(__AngryBirds__LevelParser__) */
