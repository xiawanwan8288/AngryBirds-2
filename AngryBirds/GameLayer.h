//
//  GameLayer.h
//  AndryPanda
//
//  Created by user on 13-7-3.
//
//

#ifndef __AndryPanda__GameLayer__
#define __AndryPanda__GameLayer__

#include <iostream>
#include "cocos2d.h"
#include "Box2D.h"
#include "Bird.h"
#include "Pig.h"
#include "Ice.h"
#include "SlingShot.h"

using namespace std;
using namespace cocos2d;
class GameLayer:public CCLayer
{
public:
    int score;
    CCArray *birds;
    Bird *currentBird;
    bool gameStart;
    bool gameFinish;
    
    SlingShot *slingShot;
    int touchStatus;
    
    b2World *world;
    
    CCArray *birdsArray;
    
    
public:
    ~GameLayer();
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameLayer);
    void createWorld();
    void createLevel();
    void update(float dt);
    void jump();
    void restart();
    
    float getRatio(CCPoint p1,CCPoint p2);
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
};
#endif /* defined(__AndryPanda__GameLayer__) */
