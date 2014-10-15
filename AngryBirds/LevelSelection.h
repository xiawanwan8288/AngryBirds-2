//
//  LevelSelection.h
//  AngryBirds
//
//  Created by zyuq on 13-7-3.
//
//

#ifndef __AngryBirds__LevelSelection__
#define __AngryBirds__LevelSelection__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class LevelSelection:public CCLayer {
public:
    static CCScene* scene();
    LevelSelection();
    virtual bool init();
    CREATE_FUNC(LevelSelection);
    ~LevelSelection();
    
    int currentChapter;
    CCPoint backButtonLocation;
    CCPoint textLocation;
    CCPoint levelMenuLocation;
    CCPoint bgLocation;
    CCPoint chapterTitleLocation;
    CCPoint chapterIntroLocation;
    
    CCSize screenSize;
    CCLabelTTF* chapterTitle;
    CCLabelTTF* chapterIntro;
    int deviceType;
    void getDeviceType();
    void readData();
    void setMenuLoaction();
    void addChapterIntro();
    void addBackButton();
    void backToStart();
    void addLevelSelectBg();
    void addLevelMenu();
    
    void onPlay();


};

#endif /* defined(__AngryBirds__LevelSelection__) */
