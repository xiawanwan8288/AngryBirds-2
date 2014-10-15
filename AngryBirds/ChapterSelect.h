//
//  ChapterSelect.h
//  AngryBirds
//
//  Created by zyuq on 13-7-1.
//
//

#ifndef __AngryBirds__ChapterSelect__
#define __AngryBirds__ChapterSelect__

#include <iostream>
#include "cocos2d.h"
#include "CCScrollView.h"

using namespace cocos2d;
using namespace extension;
class ChapterSelect:public CCLayer,public CCScrollViewDelegate {
public:
    static CCScene*scene();
    virtual bool init();
    CREATE_FUNC(ChapterSelect);
    
    int deviceType;
    CCPoint backButtonLocation;
    CCPoint textLocation;
    CCPoint chapterLocation;
    CCPoint bgLocation;
    CCSize size;
    
    CCScrollView* scroller;
    int scrollLayerOffset;
    
    void getDeviceType();
    void setMenuLocation();
    void addBackground();
    void playBackgroundMusic();
    void addBackButton();
    void addChapters();
    
    void backSelect(CCObject* sender);
    void onSelectChapter(CCMenuItemImage* sender);
    void setScrollLayerOffset();
    CCLayer* initLayer(CCString* chapterName,int chapterNumber,bool chapterUnlocked,CCSize screenSize);
    
    virtual void scrollViewDidScroll(CCScrollView* view);
    virtual void scrollViewDidZoom(CCScrollView* view);
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    // optional
    
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent) ;
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
    void adjustScrollView();
    
    virtual void onEnter();
    
};

#endif /* defined(__AngryBirds__ChapterSelect__) */
