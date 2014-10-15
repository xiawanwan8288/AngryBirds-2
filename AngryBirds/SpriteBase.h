//
//  SpriteBase.h
//  AndryPanda
//
//  Created by user on 13-7-2.
//
//

#ifndef __AndryPanda__SpriteBase__
#define __AndryPanda__SpriteBase__

#include <iostream>
#include "cocos2d.h"
#include "Box2D.h"
#define PTM_RATIO 32
#define BIRD_ID 1
#define PIG_ID 2
#define ICE_ID 3
using namespace cocos2d;
//这个类作为鸟、猪和障碍物的基类
class SpriteBase:public CCSprite
{
public:
    float _HP;//现在的血量
    int _fullHP;//总共的血量
    CCLayer *_myLayer;//处于那个层上
    b2World *_myWorld;//世界
    b2Body *_myBody;//物体
public:
    void destoryBody(CCObject *pSender);
    void runEnd(CCObject *pSender);
    void destoryPig();
    void destory();
};
#endif /* defined(__AndryPanda__SpriteBase__) */
