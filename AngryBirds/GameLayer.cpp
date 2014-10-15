//
//  GameLayer.cpp
//  AndryPanda
//
//  Created by user on 13-7-3.
//
//

#include "GameLayer.h"
#include "Bird.h"
#include "SlingShot.h"
#include "Ice.h"
#include "Pig.h"
#include "Box2D.h"
#include "MyContactListener.h"
#define TOUCH_UNKNOW 0
#define TOUCH_SHOTBIRD 1
//拉点位置
#define SLINGSHOT_POS CCPointMake(85, 125)

CCScene* GameLayer::scene()
{
    CCScene *scene = CCScene::create();
    CCLayer *layer = GameLayer::create();
    scene->addChild(layer);
    return scene;
}
GameLayer::~GameLayer()
{
    
}
bool GameLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    
    //背景
    CCSprite *bgSprite = CCSprite::create("bg.png");
    bgSprite->setPosition(ccp(winSize.width/2,winSize.height/2));
    this->addChild(bgSprite);
    
    //弹弓
    CCSprite *leftShot = CCSprite::create("leftshot.png");
    leftShot->setPosition(ccp(85, 110));
    this->addChild(leftShot);
    
    CCSprite *rightShot = CCSprite::create("rightshot.png");
    rightShot->setPosition(ccp(85, 110));
    this->addChild(rightShot);
    
    //皮筋
    slingShot = new SlingShot();
    slingShot->_startPoint1 = ccp(82,130);
    slingShot->_startPoint2 = ccp(92, 128);
    slingShot->_endPoint = SLINGSHOT_POS;
    
    slingShot->setContentSize(CCSizeMake(480, 320));
    slingShot->setPosition(ccp(winSize.width/2, winSize.height/2));
    this->addChild(slingShot);
    
    //开启触摸
    this->setTouchEnabled(true);
    
    //创建物理世界
    this->createWorld();
    
    //创建关
    birdsArray = CCArray::create();
    birdsArray->retain();
    this->createLevel();
    
    //
    CCMenuItemImage *item1 = CCMenuItemImage::create("restart.png", "restart.png");
    item1->setTarget(this, menu_selector(GameLayer::restart));
    CCMenu *menu = CCMenu::create(item1,NULL);
    menu->setPosition(ccp(50, 280));
    this->addChild(menu);

    return true;
}
void GameLayer::restart()
{
    CCDirector::sharedDirector()->replaceScene(GameLayer::scene());
}


void GameLayer::createWorld()
{
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    b2Vec2 gravity;
    gravity.Set(0.0f, -10.0f);
    world = new b2World(gravity);
    
    world->SetAllowSleeping(true);
    world->SetContinuousPhysics(true);
    uint32 flags = 0;
    flags += b2Draw::e_shapeBit;
    
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0);
    b2Body* groundBody = world->CreateBody(&groundBodyDef);
    
    b2EdgeShape groundBox;
    //下面
    groundBox.Set(b2Vec2(0,91.0/PTM_RATIO), b2Vec2(s.width/PTM_RATIO,91.0/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);
    //上面
    groundBox.Set(b2Vec2(0,s.height/PTM_RATIO), b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);
    //左右
    groundBox.Set(b2Vec2(0,s.height/PTM_RATIO), b2Vec2(0,0));
    groundBody->CreateFixture(&groundBox,0);
    
    groundBox.Set(b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO), b2Vec2(s.width/PTM_RATIO,0));
    groundBody->CreateFixture(&groundBox,0);
    
    MyContactListener *listener = new MyContactListener(world,this);
    world->SetContactListener(listener);
    
    this-> scheduleUpdate();
}

void GameLayer::update(float dt)
{
    int velocityIterations = 8;
    int positionIterations = 1;
    world->Step(dt, velocityIterations, positionIterations);
    for (b2Body *b = world->GetBodyList(); b; b = b->GetNext())
	{
		if (b->GetUserData() != NULL)
        {
			SpriteBase *oneSprite = (SpriteBase *)b->GetUserData();
            CCSprite* myActor = (CCSprite*)b->GetUserData();
            myActor->setPosition( CCPointMake( b->GetPosition().x * PTM_RATIO, b->GetPosition().y * PTM_RATIO) );
            myActor->setRotation( -1 * CC_RADIANS_TO_DEGREES(b->GetAngle()) );

            //如果小鸟停止运动删除小鸟
            if (oneSprite->getTag() == BIRD_ID)
            {
                if (!b->IsAwake())
                {
                    world->DestroyBody(b);
                    oneSprite->destory();
                    this->jump();
                }
            }
            //其他的当血量少于0时删除
            if (oneSprite->_HP <= 0)
            {
                world->DestroyBody(b);
                oneSprite->destory();
                oneSprite->removeFromParent();
            }
		}
	}
}

void GameLayer::createLevel()
{
    //场景的创建             
    Ice *ice = new Ice(ccp(250,100),world,this);
    this->addChild(ice);
    Ice *ice1 = new Ice(ccp(250,120),world,this);
    this->addChild(ice1);
    Ice *ice3 = new Ice(ccp(250,140),world,this);
    this->addChild(ice3);
    Ice *ice4 = new Ice(ccp(250,160),world,this);
    this->addChild(ice4);
    
    Ice *ice5 = new Ice(ccp(300,100),world,this);
    this->addChild(ice5);
    Ice *ice6 = new Ice(ccp(300,130),world,this);
    this->addChild(ice6);
    
    Pig *pp = new Pig(ccp(360,100),world,this);
    this->addChild(pp);
    Pig *pp1 = new Pig(ccp(320,100),world,this);
    this->addChild(pp1);
    
    Bird *bird1 = new Bird(SLINGSHOT_POS,world,this);
    Bird *bird2 = new Bird(SLINGSHOT_POS,world,this);
    Bird *bird3 = new Bird(SLINGSHOT_POS,world,this);
    
    bird1->setPosition(ccp(10,100));
    bird2->setPosition(ccp(30,100));
    bird3->setPosition(ccp(50,100));
    
    this->addChild(bird1);
    this->addChild(bird2);
    this->addChild(bird3);
    
    birdsArray->addObject(bird1);
    birdsArray->addObject(bird2);
    birdsArray->addObject(bird3);
    this->jump();
    
}
void GameLayer::jump()
{
    if(birdsArray->count()>0)
    {
        currentBird = (Bird *) birdsArray->objectAtIndex(0);
        birdsArray->removeObject(currentBird);
        CCJumpTo *jumpTo = CCJumpTo::create(1.0,SLINGSHOT_POS, 50, 1);
        currentBird->runAction(jumpTo);
    }
    else
    {
        //判断输赢
    }
}
#pragma mark - touch

float GameLayer::getRatio(CCPoint p1,CCPoint p2)
{
    return (p2.y-p1.y)/(p2.x-p1.x);
}

void GameLayer::registerWithTouchDispatcher()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool GameLayer::ccTouchBegan(CCTouch *touch,CCEvent *event)
{
    touchStatus = TOUCH_UNKNOW;
    CCPoint location = touch->getLocation();
    if(currentBird == NULL)
    {
        return false;
    }
    //判断是不是按在鸟上
    CCRect birdRect = currentBird->boundingBox();
    if(birdRect.containsPoint(location))
    {
        touchStatus = TOUCH_SHOTBIRD;
        return true;
    }
    return false;
}

void GameLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    if (touchStatus == TOUCH_SHOTBIRD)
    {
        CCPoint location = pTouch->getLocation();
        if(location.x>10&&location.y>80)
        {
            slingShot->_endPoint = location;
            currentBird->setPosition(location);
        }
    }
}

void GameLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    if (touchStatus == TOUCH_SHOTBIRD)
    {
        CCPoint location = touch->getLocation();
        slingShot->_endPoint = SLINGSHOT_POS;
        float x =(85.0f-location.x)*60.0f/70.0f;
        float y =(125.0f-location.y)*60.0f/70.0f;
        currentBird->setSpeed(x, y, world);
    }
}
