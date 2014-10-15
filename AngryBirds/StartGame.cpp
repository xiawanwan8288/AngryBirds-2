//
//  StartGame.cpp
//  AngryBirds
//
//  Created by zyuq on 13-6-27.
//
//

#include "StartGame.h"
#include "GameData.h"
#include "Const.h"
#include "SimpleAudioEngine.h"
#include "ChapterSelect.h"
using namespace CocosDenshion;


CCScene* StartGame::scene()
{
    CCScene* scene=CCScene::create();
    StartGame* layer=StartGame::create();
    scene->addChild(layer);
    return scene;
}
 bool StartGame::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    isSoundOpen=true;
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("bg_startgamescene.mp3", true);
    this->getDeviceType();
    this->addBackgroundSprite();
    this->addGameTitle();
    this->initUI();
    return true;
}

StartGame::StartGame()
{
    
}



StartGame::~StartGame()
{

    
}
//获取设备类型
void StartGame::getDeviceType()
{
    if (GameData::shareData()->isDeviceIphone5==false) {
        deviceType=kDeviceTypeNotIphone5;
    }else if(GameData::shareData()->isDeviceIphone5==true)
    {
        deviceType=kDeviceTypeIphone5OrNewTouch;
    }
}
//添加背景
void StartGame::addBackgroundSprite()
{
    screenSize=CCDirector::sharedDirector()->getWinSize();
    CCSprite* bgGameStart;
        if (deviceType==kDeviceTypeNotIphone5) {
          bgGameStart=CCSprite::create("bg_startgame.png");
        }else if(deviceType==kDeviceTypeIphone5OrNewTouch)
        {
            bgGameStart=CCSprite::create("bg_startgame-iphone5@2x.png");
            bgGameStart->setScale(2);
        }

    bgGameStart->setPosition(ccp(screenSize.width/2, screenSize.height/2));
    this->addChild(bgGameStart, -1);
}
//添加标题
void StartGame::addGameTitle()
{
   CCLabelTTF* gameTitle=CCLabelTTF::create("AngryBirds", "Helvetica", 34);
    gameTitle->setPosition(ccp(screenSize.width/2, screenSize.height*0.85));
    this->addChild(gameTitle,0);
}
//初始化UI
void StartGame::initUI()
{
    screenSize=CCDirector::sharedDirector()->getWinSize();
   CCMenuItemImage* playItem=CCMenuItemImage::create("button_begin.png", "button_begin.png");
    playItem->setTarget(this, menu_selector(StartGame::startGame));
    playItem->setPosition(ccp(screenSize.width/2, screenSize.height*0.60));
    playItem->runAction(CCScaleTo::create(1.0, 1.2));
    playItem->setTag(1);
    //playItem->setScale(0.5);
    
  CCMenuItemImage* aboutItem=CCMenuItemImage::create("about.png", "about.png");
    aboutItem->setTarget(this, menu_selector(StartGame::aboutGame));
    aboutItem->setPosition(ccp(screenSize.width/2, screenSize.height/3));
   // aboutItem->setScale(0.5);
    CCMenuItemImage* soundOn=CCMenuItemImage::create("soundon.png", "soundon.png");
    CCMenuItemImage* soundOff=CCMenuItemImage::create("soundoff.png", "soundoff.png");
    CCMenuItemToggle* soundItem=CCMenuItemToggle::createWithTarget(this, menu_selector(StartGame::menuSoundCallback), soundOn,soundOff,NULL);
    soundItem->setPosition(ccp(800, 80));
    soundItem->setTarget(this, menu_selector(StartGame::menuSoundCallback));
    
    CCMenu* menu=CCMenu::create(playItem,aboutItem,soundItem,NULL);
    menu->setTag(10);
    menu->setPosition(CCPointZero);
    this->addChild(menu);
    
    
    
}

//开始界面
void StartGame::startGame()
{
    CCMenu* menu=(CCMenu*)this->getChildByTag(10);
    CCSprite* playItem=(CCSprite*)menu->getChildByTag(1);
    playItem->runAction(CCScaleTo::create(1.4, 1.4));
    CCDirector::sharedDirector()->replaceScene(ChapterSelect::scene());
}



//关于界面
void StartGame::aboutGame()
{
    
}

void StartGame::menuSoundCallback()
{
    if (isSoundOpen) {
        SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
        isSoundOpen=false;
    }else
    {
        SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
        isSoundOpen=true;
    }
}