//
//  LoadingScreen.h
//  AngryBirds
//
//  Created by zyuq on 13-6-26.
//
//

#ifndef __AngryBirds__LoadingScreen__
#define __AngryBirds__LoadingScreen__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class LoadingScreen:public CCLayer {
    
public:
    CCSize  winSize;
    CCPoint winCenter;
    bool isLoading;
    CCProgressTimer* progress;
    float           progressInterval;
    int             assetCount;
    
    //设备类型
    int deviceType;
    static CCScene* scene();
    virtual bool init();
    CREATE_FUNC(LoadingScreen);
    void judgeDeviceType();
    virtual void onEnter();
    virtual void onExit();
    virtual void onEnterTransitionDidFinish();
    void loadMusic(CCArray* musicFiles);
    void loadSounds(CCArray* soundClips);
    void loadSpriteSheets(CCArray* spriteSheets)
    ;
    void loadImage(CCArray* images);
    void loadAssets(CCArray* assets);
    void progressUpdate();
    void loadingCompleted();
    
};

#endif /* defined(__AngryBirds__LoadingScreen__) */
