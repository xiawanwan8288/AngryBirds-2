//
//  StartGame.h
//  AngryBirds
//
//  Created by zyuq on 13-6-27.
//
//

#ifndef __AngryBirds__StartGame__
#define __AngryBirds__StartGame__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class StartGame:public CCLayer {
public:
    static CCScene* scene();
    StartGame();
    ~StartGame();
    virtual bool init();
    CREATE_FUNC(StartGame);
    
    
    int deviceType;
    bool isSoundOpen;
    
   
    CCSize screenSize;
    
    //音效设置
    
    void getDeviceType();
    
    
    void addBackgroundSprite();
    void addGameTitle();
    void initUI();
    
    void startGame();
    void aboutGame();
    void menuSoundCallback();
    
};

#endif /* defined(__AngryBirds__StartGame__) */
