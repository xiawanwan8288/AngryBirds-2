//
//  Pig.cpp
//  AndryPanda
//
//  Created by user on 13-7-2.
//
//

#include "Pig.h"
Pig::Pig(CCPoint p,b2World *world,CCLayer *layer)
{
    int x= p.x;
    int y= p.y;
    _myWorld = world;
    _myLayer = layer;
    this->initWithFile("pig1.png");
    this->setPosition(p);
    this->setTag(PIG_ID);
    _HP = 1;
    float scale = 2.0;
    this->setScale(scale/10);
    
    b2BodyDef ballBodyDef;
    ballBodyDef.type = b2_dynamicBody;
    ballBodyDef.position.Set(x/PTM_RATIO, y/PTM_RATIO);
    ballBodyDef.userData = this;
    
    b2Body * ballBody = world->CreateBody(&ballBodyDef);
    
    _myBody = ballBody;
    
    float size = 0.12f;
    b2PolygonShape blockShape;
    b2Vec2 vertices[] = {
        b2Vec2(size ,-2*size),
        b2Vec2(2*size,-size),
        b2Vec2(2*size,size),
        
        b2Vec2(size,2*size),
        b2Vec2(-size,2*size),
        b2Vec2(-2*size,size),
        b2Vec2(-2*size,-size),
        b2Vec2(-size,-2*size)
    };
    blockShape.Set(vertices, 8);
    
    // Create shape definition and add to body
    b2FixtureDef ballShapeDef;
    ballShapeDef.shape = &blockShape;
    ballShapeDef.density = 80.0f;
    ballShapeDef.friction = 80.0f; // We don't want the ball to have friction!
    ballShapeDef.restitution = 0.15f;
    ballBody->CreateFixture(&ballShapeDef);

}
Pig::~Pig()
{
    
}