//
//  Ice.cpp
//  AndryPanda
//
//  Created by user on 13-7-2.
//
//

#include "Ice.h"
Ice::Ice(CCPoint p,b2World *world,CCLayer *layer)
{
    int x= p.x;
    int y= p.y;
    _myWorld = world;
    _myLayer = layer;

    _HP = 27;
    _fullHP = _HP;
    
    this->initWithFile("ice1.png");

    this->setPosition(ccp(x, y));
    this->setTag(ICE_ID);
    
    float scale = 2;
    
    this->setScale(scale/10);
    
    
    // Create ball body
    b2BodyDef ballBodyDef;
    ballBodyDef.type = b2_dynamicBody;
    ballBodyDef.position.Set(x/PTM_RATIO, y/PTM_RATIO);
    ballBodyDef.userData = this;
    
    b2Body * ballBody = world->CreateBody(&ballBodyDef);
    
    //    // Create block shape
    b2PolygonShape blockShape;
    blockShape.SetAsBox(this->getContentSize().width/11/PTM_RATIO,this->getContentSize().height/11/PTM_RATIO);
    
    // Create shape definition and add to body
    b2FixtureDef ballShapeDef;
    ballShapeDef.shape = &blockShape;
    ballShapeDef.density = 10.0f;
    ballShapeDef.friction = 1.0f; // We don't want the ball to have friction!
    ballShapeDef.restitution = 0;
    ballBody->CreateFixture(&ballShapeDef);
}

Ice::~Ice()
{
    
}