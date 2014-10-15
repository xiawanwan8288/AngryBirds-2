//
//  MyContactListener.h
//  AndryPanda
//
//  Created by user on 13-7-3.
//
//

#ifndef __AndryPanda__MyContactListener__
#define __AndryPanda__MyContactListener__

#include <iostream>
#include "Box2d.h"
#include "SpriteBase.h"
#include "Bird.h"
using namespace std;
using namespace cocos2d;
class MyContactListener:public b2ContactListener
{
public:
    b2World *_world;
    CCLayer *_layer;
    MyContactListener();
    MyContactListener(b2World *w, CCLayer *c);
    ~MyContactListener();
    
    virtual void BeginContact(b2Contact* contact);
    virtual void EndContact(b2Contact* contact);
    virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
    virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);

};
#endif /* defined(__AndryPanda__MyContactListener__) */
