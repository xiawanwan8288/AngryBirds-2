//
//  LoadingScreen.cpp
//  AngryBirds
//
//  Created by zyuq on 13-6-26.
//
//

#include "LoadingScreen.h"
#include "StartGame.h"
#include "Const.h"
#include "GameData.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
CCScene* LoadingScreen::scene()
{
    CCScene* scene=CCScene::create();
    LoadingScreen* layer=LoadingScreen::create();
    scene->addChild(layer);
    return scene;
    
}
bool LoadingScreen::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    winSize=CCDirector::sharedDirector()->getWinSize();
    winCenter=ccp(winSize.width/2, winSize.height/2);
    this->judgeDeviceType();
    if (deviceType==kDeviceTypeIphone5OrNewTouch) {
        CCSprite* bgSprite=CCSprite::create("loadingbg-iphone5.png");
        bgSprite->setScale(2);

        bgSprite->setPosition(winCenter);
        this->addChild(bgSprite, -1);
    }else if(deviceType==kDeviceTypeNotIphone5)
    {
        CCSprite* bgSprite=CCSprite::create("loadingbg.png");
              bgSprite->setPosition(winCenter);
        this->addChild(bgSprite,-1);
    }

    progress=CCProgressTimer::create(CCSprite::create("progressbar.png"));
    progress->setPosition(winCenter);
    progress->setType(kCCProgressTimerTypeBar);
    progress->setPercentage(0.0);
    progress->setScale(0.5);
    progress->setMidpoint(ccp(0,0.5));
    progress->setBarChangeRate(ccp(1,0));
    this->addChild(progress);
    
    
    CCLabelTTF* loadingLabel=CCLabelTTF::create("Loading", "Arial", 20);
    loadingLabel->setPosition(ccpAdd(progress->getPosition(), ccp(30, 0)));
    this->addChild(loadingLabel);
    

    char temp[50];
    sprintf(temp, "preloadAssetManifest.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(temp);
    CCDictionary* dic=CCDictionary::createWithContentsOfFile(temp);
    CCArray* spriteSheets=(CCArray*)dic->objectForKey("SpriteSheets");
    CCArray* images=(CCArray*)dic->objectForKey("Images");
    CCArray* soundFX=(CCArray*)dic->objectForKey("SoundFX");
    CCArray* music=(CCArray*)dic->objectForKey("Music");
    CCArray* assets=(CCArray*)dic->objectForKey("Assets");
    assetCount=spriteSheets->count()+images->count()+soundFX->count()+music->count()+assets->count();
    progressInterval=100/(float)assetCount;
    isLoading=true;
    this->schedule(schedule_selector(LoadingScreen::progressUpdate),0.5);
    if (soundFX) {

        this->loadSounds(soundFX);

    }
    if (spriteSheets) {

        this->loadSpriteSheets(spriteSheets);
    }
    if (images) {

        this->loadImage(images);
    }
    if (music) {

        this->loadMusic(music);
    }
    if (assets) {

        this->loadAssets(assets);
    }

        
    return true;
    
    
}

void LoadingScreen::judgeDeviceType()
{
    CCSize result=CCDirector::sharedDirector()->getWinSize();
    if (result.height==480) {
        GameData::shareData()->isDeviceIphone5=false;
        deviceType=kDeviceTypeNotIphone5;
    }else if(result.height==568)
    {
        GameData::shareData()->isDeviceIphone5=true;
        deviceType=kDeviceTypeIphone5OrNewTouch;
    }
}

void LoadingScreen::onEnter()
{
    CCLog("on enter");
    CCLayer::onEnter();
    
}
void LoadingScreen::onEnterTransitionDidFinish()
{
    CCLog("onEnterTransitionDidFinish");
    CCLayer::onEnterTransitionDidFinish();

//    
}


void LoadingScreen::loadMusic(CCArray* musicFiles)
{
 
    for (int i=0;i<musicFiles->count();i++) {
        const char* music=((CCString*)musicFiles->objectAtIndex(i))->m_sString.c_str();
        SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(music);
        --assetCount;
     
    
    }
}
void LoadingScreen::loadSounds(CCArray* soundClips)
{
    for (int i=0;i<soundClips->count();i++) {
        const char* music=((CCString*)soundClips->objectAtIndex(i))->m_sString.c_str();
        SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(music);
        --assetCount;
      
        
    }

}
void LoadingScreen::loadSpriteSheets(CCArray* spriteSheets)
{
    for (int i=0;i<spriteSheets->count();i++) {
        const char* spriteFile=((CCString*)spriteSheets->objectAtIndex(i))->m_sString.c_str();
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(spriteFile);
        --assetCount;
        

    }
}
void LoadingScreen::loadImage(CCArray* images)
{
    for (int i=0;i<images->count();i++) {
        const char* spriteFile=((CCString*)images->objectAtIndex(i))->m_sString.c_str();
        CCTextureCache::sharedTextureCache()->addImage(spriteFile);
        --assetCount;
       
        
    }
}
void LoadingScreen::loadAssets(CCArray* assets)
{
    for (int i=0;i<assets->count();i++) {
        --assetCount;
     
        
    }
}
void LoadingScreen::progressUpdate()
{
    if (isLoading) {
        
    
    progress->setPercentage(100-progressInterval*assetCount);
    if (progress->getPercentage()<100) {
        CCProgressTo* to=CCProgressTo::create(0.5, progress->getPercentage());
        progress->runAction(to);
    }
    else{
        isLoading=false;
        CCProgressFromTo* end=CCProgressFromTo::create(0.3, progress->getPercentage(), 100);
        CCCallFunc* func=CCCallFunc::create(this, callfunc_selector(LoadingScreen::loadingCompleted));
        CCSequence* seq=CCSequence::create(end,func,NULL);
        progress->runAction(seq);
    }
    }
    
}
void LoadingScreen::loadingCompleted()
{
    CCLog("gasd");
    CCTransitionFade* fade=CCTransitionFade::create(0.5,StartGame::scene());
    CCDirector::sharedDirector()->replaceScene(fade);
}

void LoadingScreen::onExit()
{
    this->unscheduleAllSelectors();
    this->unschedule(schedule_selector (LoadingScreen::update));
}







