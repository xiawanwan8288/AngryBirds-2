//
//  Bird.cpp
//  AndryPanda
//
//  Created by user on 13-7-2.
//
//

#include "Bird.h"
Bird::Bird(CCPoint p,b2World *world,CCLayer *layer)
{
    _myLayer = layer;
    _myWorld = world;
    this->initWithFile("bird1.png");
    this->setTag(BIRD_ID);
    this->setPosition(p);
    _HP = 10000;
    this->setScale(0.4f);
}

Bird::~Bird()
{
    
}

void Bird::setSpeed(float x,float y,b2World *world)
{
    b2BodyDef ballBodydef;
    ballBodydef.type = b2_dynamicBody;
    ballBodydef.position.Set(this->getPosition().x/PTM_RATIO, this->getPosition().y/PTM_RATIO);
    ballBodydef.userData = this;
    b2Body *ballBody = world->CreateBody(&ballBodydef);
    _myBody = ballBody;
    
    b2PolygonShape blockShape;
    
    float size = 0.06f;
    b2Vec2 vertics[] =
    {
        b2Vec2(size ,-2*size),
        b2Vec2(2*size,-size),
        b2Vec2(2*size,size),
        
        b2Vec2(size,2*size),
        b2Vec2(-size,2*size),
        b2Vec2(-2*size,size),
        b2Vec2(-2*size,-size),
        b2Vec2(-size,-2*size)
    };
    blockShape.Set(vertics, 8);
    
    b2FixtureDef ballShapeDef;
    ballShapeDef.shape = &blockShape;
    ballShapeDef.density = 80.0f;
    ballShapeDef.friction = 1.0f;
    ballShapeDef.restitution = 0.5f;
    ballBody->CreateFixture(&ballShapeDef);
    
    b2Vec2 force = b2Vec2(x, y);
    ballBody->ApplyLinearImpulse(force,ballBodydef.position);
}

void Bird::hitAnimation(CCPoint p)
{
    float  x = p.x;
    float  y = p.y;
    for (int i = 0; i<6; i++)
    {
        int range = 2;
        
        CCSprite *temp = CCSprite::create("yumao1.png");
        temp->setScale((float)(arc4random()%5/10.1f));
        
        temp->setPosition(CCPointMake(x+arc4random()%10*range-10, y+arc4random()%10*range-10));
        CCMoveTo *actionMove = CCMoveTo::create(1.0f, CCPointMake(x+arc4random()%10*range-10, y+arc4random()%10*range-10));
        
        CCFadeOut *actionAlpha = CCFadeOut::create(1.0f);
        CCRotateBy *actionRotate = CCRotateBy::create(1.0f, arc4random()%180);
        CCCallFuncN *actionMoveEnd = CCCallFuncN::create(this, callfuncN_selector(Bird::runEnd));
        CCSpawn *mut = CCSpawn::create(actionMove,actionAlpha,actionRotate,NULL);
        CCSequence *seq = CCSequence::create(mut,actionMoveEnd,NULL);
        temp->runAction(seq);
        _myLayer->addChild(temp);
    }
//    this->getParent()->removeChild(this);
}
