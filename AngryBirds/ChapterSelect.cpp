//
//  ChapterSelect.cpp
//  AngryBirds
//
//  Created by zyuq on 13-7-1.
//
//

#include "ChapterSelect.h"
#include "GameData.h"
#include "Const.h"
#include "StartGame.h"
#include "CCScrollView.h"

#include "Chapter.h"
#include "Chapters.h"
#include "ChapterParser.h"
#include "LevelSelection.h"
using namespace extension;
//获取设备类型
CCScene* ChapterSelect::scene()
{
    CCScene* scene=CCScene::create();
    ChapterSelect* layer=ChapterSelect::create();
    scene->addChild(layer);
    return scene;
}
void ChapterSelect::getDeviceType()
{
    if (GameData::shareData()->isDeviceIphone5==false) {
        deviceType=kDeviceTypeNotIphone5;
    }else if(GameData::shareData()->isDeviceIphone5==true)
    {
        deviceType=kDeviceTypeIphone5OrNewTouch;
    }
}
void ChapterSelect::setMenuLocation()
{
    size=CCDirector::sharedDirector()->getWinSize();
    CCLog("winSize:%f,%f",size.width,size.height);
    backButtonLocation=ccp(size.width*0.85,size.height*0.1);
    textLocation=ccp(size.width*0.5,size.height*0.75);
    chapterLocation=ccp(size.width*0.5, size.height*0.5);
    bgLocation=ccp(size.width*0.5, size.height*0.5);
}

void ChapterSelect::addBackground()
{
    CCSprite* background;
    if (deviceType==kDeviceTypeNotIphone5) {
        background=CCSprite::create("menu_background.png");
    }else if(deviceType==kDeviceTypeIphone5OrNewTouch)
    {
        background=CCSprite::create("menu_background-iphone5.png");
    }
    background->setPosition(bgLocation);
    this->addChild(background, zOrderChapterBg);
}

void ChapterSelect::playBackgroundMusic()
{
    
}
void ChapterSelect::addBackButton()
{
    CCMenuItemImage* backButton=CCMenuItemImage::create("back.png", "back.png");
    backButton->setTarget(this, menu_selector(ChapterSelect::backSelect));
    CCMenu* menuButton=CCMenu::create(backButton,NULL);
    menuButton->setPosition(ccp(70, size.height*0.9));
    this->addChild(menuButton);
}

void ChapterSelect::backSelect(CCObject* sender)
{
    CCDirector::sharedDirector()->replaceScene(StartGame::scene());
}
CCLayer* ChapterSelect::initLayer(CCString* chapterName,int chapterNumber,bool chapterUnlocked,CCSize screenSize)
{
    CCLayer* layer=CCLayer::create();
    if (chapterNumber==1) {
        CCMenuItemImage* image=CCMenuItemImage::create("mini1_bg_iphone.png", "mini1_bg_iphone.png");
        image->setTarget(this, menu_selector(ChapterSelect::onSelectChapter));
        image->setTag(chapterNumber);
        CCMenu* menu=CCMenu::create(image,NULL);
        menu->setPosition(ccp(240, 100));
        menu->alignItemsVertically();
        layer->addChild(menu, 5,1);
        
        
        CCMenuItemFont* text=CCMenuItemFont::create("迷雾岛");
        text->setTag(chapterNumber);
        CCMenu* menu2=CCMenu::create(text,NULL);
        menu2->setAnchorPoint(ccp(0, 0));
        menu2->setPosition(ccp(size.width*0.5, size.height*0.8));
        
        layer->addChild(menu2,6,1);
        
    }else if(chapterNumber==2)
    {
        CCMenuItemImage* image=CCMenuItemImage::create("mini2_bg_iphone.png", "mini2_bg_iphone.png");
        image->setTarget(this, menu_selector(ChapterSelect::onSelectChapter));
        image->setTag(chapterNumber);
        CCMenu* menu=CCMenu::create(image,NULL);
        menu->alignItemsVertically();
        layer->addChild(menu,5,1);
        
        
        CCMenuItemFont* text=CCMenuItemFont::create("竹子林");
        text->setTag(chapterNumber);
        CCMenu* menu2=CCMenu::create(text,NULL);
        menu2->setAnchorPoint(ccp(0, 0));
        menu2->setPosition(ccp(size.width*0.5, size.height*0.8));
        
        layer->addChild(menu2,6,1);

    }else if(chapterNumber==3)
    {
        CCMenuItemImage* image=CCMenuItemImage::create("mini3_bg_iphone.png", "mini3_bg_iphone.png");
        image->setTarget(this, menu_selector(ChapterSelect::onSelectChapter));
        image->setTag(chapterNumber);
        CCMenu* menu=CCMenu::create(image,NULL);
        menu->alignItemsVertically();
        layer->addChild(menu,5,1);
        
        //CCMenuItemFont* text=CCMenuItemFont::initWithString(<#const char *value#>, <#cocos2d::CCObject *target#>, <#SEL_MenuHandler selector#>)
        CCMenuItemFont* text=CCMenuItemFont::create("无风谷");
        text->setTag(chapterNumber);
        CCMenu* menu2=CCMenu::create(text,NULL);
        menu2->setAnchorPoint(ccp(0, 0));
        menu2->setPosition(ccp(size.width*0.5, size.height*0.8));
        
        layer->addChild(menu2,6,1);

    }else if(chapterNumber==4)
    {
        CCMenuItemImage* image=CCMenuItemImage::create("mini4_bg_iphone.png", "mini4_bg_iphone.png");
        image->setTarget(this, menu_selector(ChapterSelect::onSelectChapter));
        image->setTag(chapterNumber);
        CCMenu* menu=CCMenu::create(image,NULL);
        menu->alignItemsVertically();
        layer->addChild(menu,9,1);
        
        CCMenuItemImage* lockImage=CCMenuItemImage::create("mini_lock_iphone.png", "mini_lock_iphone.png");
        
         lockImage->setTarget(this, menu_selector(ChapterSelect::onSelectChapter));
        lockImage->setTag(chapterNumber);
        CCMenu* menulock=CCMenu::create(lockImage,NULL);
        menulock->alignItemsVertically();
        layer->addChild(menulock, 2,1);
    
        
        
        CCMenuItemFont* text=CCMenuItemFont::create("昆仑山");
        text->setTag(chapterNumber);
        CCMenu* menu2=CCMenu::create(text,NULL);
        menu2->setAnchorPoint(ccp(0, 0));
        menu2->setPosition(ccp(size.width*0.5, size.height*0.8));
        
        layer->addChild(menu2,78,1);
    }else if (chapterNumber==5)
    {
        CCMenuItemImage* image=CCMenuItemImage::create("mini5_bg_iphone.png", "mini5_bg_iphone.png");
        image->setTarget(this, menu_selector(ChapterSelect::onSelectChapter));
        image->setTag(chapterNumber);
        CCMenu* menu=CCMenu::create(image,NULL);
        menu->alignItemsVertically();
        layer->addChild(menu);
        
        CCMenuItemImage* lockImage=CCMenuItemImage::create("mini_lock_iphone.png", "mini_lock_iphone.png");
        
        lockImage->setTarget(this, menu_selector(ChapterSelect::onSelectChapter));
        lockImage->setTag(chapterNumber);
        CCMenu* menulock=CCMenu::create(lockImage,NULL);
        menulock->alignItemsVertically();
        layer->addChild(menulock, 2);
        
        
        
        CCMenuItemFont* text=CCMenuItemFont::create("欢乐谷");
        text->setTag(chapterNumber);
        CCMenu* menu2=CCMenu::create(text,NULL);
        menu2->setAnchorPoint(ccp(0, 0));
        menu2->setPosition(ccp(size.width*0.5, size.height*0.8));
        
        layer->addChild(menu2);

        
    }
    return layer;
}
void ChapterSelect::setScrollLayerOffset()
{
    if (deviceType==kDeviceTypeIphone5OrNewTouch) {
        scrollLayerOffset=250;
    }else if (deviceType==kDeviceTypeNotIphone5)
    {
        scrollLayerOffset=180;
    }
}
void ChapterSelect::onSelectChapter(CCMenuItemImage* sender)
{
    CCLog("sender tag is %d",sender->getTag());
  //  GameData::shareData()->selectedChapter=sender.tag;
    CCTransitionMoveInL* fade=CCTransitionMoveInL::create(1.0, LevelSelection::scene());
    CCDirector::sharedDirector()->replaceScene(fade);
    
}
void ChapterSelect::addChapters()
{
    //创建scrollView
    scroller=CCScrollView::create();
    scroller->setAnchorPoint(CCPointZero);
    scroller->setPosition(CCPointZero);
    scroller->setBounceable(false);
    //设置scrollView的内容大小
    scroller->setContentSize(CCSizeMake(size.width*5, size.height*0.8));
    //设置scrol可以显示的部分
    scroller->setViewSize(CCSizeMake(480, 250));
    //scroller->setContentOffset(ccp(200,0));
    //创建scrollView对应的层
    CCLayer* containLayer=CCLayer::create();
    containLayer->setAnchorPoint(CCPointZero);
    containLayer->setPosition(CCPointZero);
    //设置层的大小
    containLayer->setContentSize(CCSizeMake(size.width*5, size.height*0.8));

    Chapters* chapters=ChapterParser::loadData();

    
    CCLog("count=%d",chapters->getArray()->count());
    for (int i=0; i<chapters->_chapters->count(); i++) {
        //Chapter* chapter=(Chapter*)((chapters->_chapters)->objectAtIndex(i));
       // CCString* str=CCString::create(chapter->getName());
        char chapterBg[50];
        sprintf(chapterBg, "mini%d_bg_iphone.png",i+1);
        CCMenuItemImage* chapterImage=CCMenuItemImage::create(chapterBg, chapterBg);
        chapterImage->setAnchorPoint(ccp(0,0.8));
        chapterImage->setTarget(this, menu_selector(ChapterSelect::onSelectChapter));
        
        chapterImage->setTag(i);
        chapterImage->setPosition(ccp(150+size.width*i, size.height*0.6));
        CCMenu* menu=CCMenu::create(chapterImage,NULL);
        menu->setPosition(CCPointZero);
        containLayer->addChild(menu);
        
   
    }
    scroller->setContainer(containLayer);
    scroller->setTouchEnabled(true);
    scroller->setDirection(kCCScrollViewDirectionHorizontal);  //设置滚动的方向，有三种可以选择
    scroller->setDelegate(this);
    this->addChild(scroller);

}

void ChapterSelect::scrollViewDidScroll(CCScrollView* view)
{
    
}
void ChapterSelect::scrollViewDidZoom(CCScrollView* view)
{
    
}

bool ChapterSelect::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    return true;
}

void ChapterSelect::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
   // CCLOG("move");
}



void ChapterSelect::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)

{
    
    adjustScrollView();
    
}

void ChapterSelect::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    adjustScrollView();
}


void ChapterSelect::adjustScrollView()
{
    // 关闭CCScrollView中的自调整
    scroller->unscheduleAllSelectors();
    int x = scroller->getContentOffset().x;
    CCLOG("offset=%d",x);
    
    int offset = (int) x % 480;
    // 调整位置
    CCPoint adjustPos;
    // 调整动画时间
    float adjustAnimDelay;
    // 向右滑动是正   向左滑动是负
    if (offset < -200) {
        // 计算下一页位置，时间
        adjustPos = ccpSub(scroller->getContentOffset(), ccp(480 + offset, 0));
        adjustAnimDelay = (float) (480 + offset) / 800;
    }
    else {
        // 计算当前页位置，时间
        adjustPos = ccpSub(scroller->getContentOffset(), ccp(offset, 0));
        // 这里要取绝对值，否则在第一页往左翻动的时，保证adjustAnimDelay为正数
        adjustAnimDelay = (float) abs(offset) / 800;
    }
    // 调整位置
    
    scroller->setContentOffsetInDuration(adjustPos, adjustAnimDelay);
    
}

void ChapterSelect::onEnter()
{
    CCLayer::onEnter();
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 1, true);
}
bool ChapterSelect::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    this->getDeviceType();
    this->setMenuLocation();
    this->addBackground();
    this->addBackButton();
    this->addChapters();
    return true;
    
}





