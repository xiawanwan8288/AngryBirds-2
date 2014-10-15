//
//  LevelSelection.cpp
//  AngryBirds
//
//  Created by zyuq on 13-7-3.
//
//

#include "LevelSelection.h"
#include "GameData.h"
#include "Const.h"
#include "ChapterSelect.h"

#include "Chapter.h"
#include "Chapters.h"
#include "ChapterParser.h"

#include "Level.h"
#include "Levels.h"
#include "LevelParser.h"

#include "GameLayer.h"

CCScene* LevelSelection::scene()
{
    CCScene* scene=CCScene::create();
    LevelSelection* layer=LevelSelection::create();
    scene->addChild(layer);
    return scene;
}



bool LevelSelection::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    screenSize=CCDirector::sharedDirector()->getWinSize();
    this->readData();
    this->getDeviceType();
    this->setMenuLoaction();
    this->addChapterIntro();
    this->addBackButton();
    this->addLevelSelectBg();
    this->addLevelMenu();
    return true;
}
void LevelSelection::getDeviceType()
{
    if (GameData::shareData()->isDeviceIphone5==false) {
        deviceType=kDeviceTypeNotIphone5;
    }else if(GameData::shareData()->isDeviceIphone5==true)
    {
        deviceType=kDeviceTypeIphone5OrNewTouch;
    }
}

void LevelSelection::readData()
{
   // currentChapter=GameData::shareData()->selectedChapter;
    //直接指定为1,完善后从gamedata获取
    currentChapter=1;
}

void LevelSelection::setMenuLoaction()
{
    backButtonLocation=ccp(screenSize.width*0.85,screenSize.height*0.1);
    levelMenuLocation=ccp(screenSize.width*0.5,screenSize.height*0.45);
    bgLocation=ccp(screenSize.width*0.5, screenSize.height*0.5);
    chapterIntroLocation=ccp(screenSize.width*0.5,screenSize.height*0.75);
    chapterTitleLocation=ccp(screenSize.width*0.5,screenSize.height*0.85);
}

void LevelSelection::addChapterIntro()
{
    switch (currentChapter) {
        case 1:
            chapterTitle=CCLabelTTF::create("迷雾岛", "ArialMT", 16);
            chapterIntro=CCLabelTTF::create("迷雾重重,熊猫人喜欢探索这神秘的世界", "ArialMT", 12);
            chapterIntro->setPosition(chapterIntroLocation);
            chapterTitle->setPosition(chapterTitleLocation);
            this->addChild(chapterIntro);
            this->addChild(chapterTitle);
            break;
        case 2:
            chapterTitle=CCLabelTTF::create("竹子林", "ArialMT", 16);
            chapterIntro=CCLabelTTF::create("海滩上生长着一片浓郁的森林,是熊猫人细细的力图", "ArialMT", 12);
            chapterIntro->setPosition(chapterIntroLocation);
            chapterTitle->setPosition(chapterTitleLocation);
            this->addChild(chapterIntro);
            this->addChild(chapterTitle);

            break;
        case 3:
            chapterTitle=CCLabelTTF::create("无风谷", "ArialMT", 16);
            chapterIntro=CCLabelTTF::create("透过那挂满葡萄的枝条可以隐约看见繁华的农场和集市", "ArialMT", 12);
            chapterIntro->setPosition(chapterIntroLocation);
            chapterTitle->setPosition(chapterTitleLocation);
            this->addChild(chapterIntro);
            this->addChild(chapterTitle);

            break;
        case 4:
            chapterTitle=CCLabelTTF::create("昆仑山", "ArialMT", 16);
            chapterIntro=CCLabelTTF::create("昆仑山北部陡峭的山峰致电,传说中神仙聚集的地方", "ArialMT", 12);
            chapterIntro->setPosition(chapterIntroLocation);
            chapterTitle->setPosition(chapterTitleLocation);
            this->addChild(chapterIntro);
            this->addChild(chapterTitle);

            break;
        case 5:
            chapterTitle=CCLabelTTF::create("欢乐谷", "ArialMT", 16);
            chapterIntro=CCLabelTTF::create("这里升腾着迷离的浓雾,周围群山环绕", "ArialMT", 12);
            chapterIntro->setPosition(chapterIntroLocation);
            chapterTitle->setPosition(chapterTitleLocation);
            this->addChild(chapterIntro);
            this->addChild(chapterTitle);

            break;
            
        default:
            break;
    }
}

void LevelSelection::addBackButton()
{
    CCMenuItemImage* backButton=CCMenuItemImage::create("back.png", "back.png");
    backButton->setTarget(this, menu_selector(LevelSelection::backToStart));
    CCMenu* menuButton=CCMenu::create(backButton,NULL);
    menuButton->setPosition(ccp(70, screenSize.height*0.9));
    this->addChild(menuButton);
}


void LevelSelection::addLevelSelectBg()
{
    CCSprite* background;
    if (deviceType==kDeviceTypeNotIphone5) {
        background=CCSprite::create("menu_background.png");
    }else if(deviceType==kDeviceTypeIphone5OrNewTouch)
    {
        background=CCSprite::create("menu_background-iphone5.png");
    }
    background->setPosition(bgLocation);
    this->addChild(background, zOrderLevelBg);
}
//添加关卡信息
void LevelSelection::addLevelMenu()
{

    int selectedChapter=1;
    CCString* selectedChapterName;
    Chapters* selectedChapters=ChapterParser::loadData();
    CCLog("%d",selectedChapters->getArray()->count());
    //从所有的关卡数据中,获取当前选中关卡的信息
    for (int i=0; i<selectedChapters->getArray()->count(); i++) {
        Chapter* chapter=(Chapter*)((selectedChapters->_chapters)->objectAtIndex(i));
        CCLog("chapte name:%s",chapter->name);
        CCString* str=CCString::create(chapter->getName());
        if (chapter->getNumber()==selectedChapter) {
            selectedChapterName=str;
        }
    }
    
    CCMenu* levelMenu=CCMenu::create();
    CCArray* overlay=CCArray::create();
    //overlay->retain();
    CCLog("aaa");
    CCLog("int %d",selectedChapter);
    
    //获取所有的关卡信息
    Levels* selectedLevels=LevelParser::loadData(selectedChapter);
    CCLog("bbb");
    //遍历此章节对应的关卡信息,
    for (int j=0; j<(selectedLevels->_levels)->count(); j++) {
        Level* level=(Level*)((selectedLevels->_levels)->objectAtIndex(j));
        CCLog("%sddddd",level->_name);
        //每一关卡的背景图片,可以点击
        CCMenuItemImage* item=CCMenuItemImage::create("level_bg_iphone.png", "level_bg_iphone.png");
        item->setTarget(this, menu_selector(LevelSelection::onPlay));
        item->setTag(level->_number);
        item->setEnabled(level->_unlocked);
        levelMenu->addChild(item);
        //如果关卡加锁了,添加一个枷锁的图片
        if (!level->_unlocked) {
            CCSprite* overlaySprite=CCSprite::create("level_lock_iphone.png");
            overlaySprite->setTag(level->_number);
            overlay->addObject(overlaySprite);
        }else
        {
            int stars=level->_stars;
            char temp[50];
            sprintf(temp, "%dStar-Normal-iPhone.png",stars);
            CCSprite* overlaySprite=CCSprite::create(temp);
            overlaySprite->setTag(level->_number);
            overlay->addObject(overlaySprite);
        }
    }
    
    levelMenu->alignItemsInColumns(5,5,NULL);
    levelMenu->setPosition(levelMenuLocation);
    this->addChild(levelMenu);
    CCLog("aaaa");
    
    CCLayer* overlays=CCLayer::create();
    CCLayer* labels=CCLayer::create();
    CCLog("cccccccc");
    for (int i=0; i<levelMenu->getChildrenCount(); i++) {
        CCLog("ffff%d",levelMenu->getChildrenCount());
        CCMenuItemImage* item=(CCMenuItemImage*)((levelMenu->getChildren())->objectAtIndex(i));
        char temp[10];
        sprintf(temp, "%d",item->getTag());
         CCLog("lkjhg");
        //添加label
        CCLabelTTF* label=CCLabelTTF::create(temp, "Marker Felt", 25);
        label->setAnchorPoint(item->getAnchorPoint());
        label->setPosition(item->getPosition());
        labels->addChild(label,zOrderLevelText);
        CCLog("mmmmm");
        for (int j=0; j<overlay->count(); j++) {
            CCSprite* overSprite=(CCSprite*)overlay->objectAtIndex(j);
            if (overSprite->getTag()==item->getTag()) {
                overSprite->setAnchorPoint(item->getAnchorPoint());
                overSprite->setPosition(item->getPosition());
                overlays->addChild(overSprite,zOrderLevelText);
            }
        }
    }
    CCLog("dddd");
    overlays->setAnchorPoint(levelMenu->getAnchorPoint());
    labels->setAnchorPoint(levelMenu->getAnchorPoint());
    overlays->setPosition(levelMenu->getPosition());
    labels->setPosition(levelMenu->getPosition());
    this->addChild(labels);
    this->addChild(overlays);
  //  overlays->release();
   // labels->release();
    

}


void LevelSelection::onPlay()
{
    CCDirector::sharedDirector()->replaceScene(GameLayer::scene());
}
void LevelSelection::backToStart()
{
    CCDirector::sharedDirector()->replaceScene(ChapterSelect::scene());
}
LevelSelection::LevelSelection()
{
    
}

LevelSelection::~LevelSelection()
{
    
}