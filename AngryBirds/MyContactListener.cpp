//
//  MyContactListener.cpp
//  AndryPanda
//
//  Created by user on 13-7-3.
//
//

#include "MyContactListener.h"
MyContactListener :: MyContactListener()
{
    
}
MyContactListener :: MyContactListener(b2World *w, CCLayer *c)
{
    _world = w;
    _layer = c;
}
MyContactListener :: ~MyContactListener()
{
    
}

void MyContactListener :: BeginContact(b2Contact *contact)
{
    
}
void MyContactListener:: EndContact(b2Contact *contact)
{
    
}
void MyContactListener:: PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{
    
}
//根据碰撞强度见血
void MyContactListener:: PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
{
    // solver计算完成后调用的函数
    float force = impulse->normalImpulses[0];
    if (force > 2)
    {
        SpriteBase *spriteA = (SpriteBase *)contact->GetFixtureA()->GetBody()->GetUserData();
        SpriteBase *spriteB = (SpriteBase *)contact->GetFixtureB()->GetBody()->GetUserData();
        if (spriteA && spriteB)
        {
            if (spriteA->getTag() == BIRD_ID)
            {
                Bird *bird = (Bird *)spriteA;
                bird->hitAnimation(bird->getPosition());
            }
            else
            {
                spriteA->_HP=spriteA->_HP-force;
            }
            
            if (spriteB->getTag() == BIRD_ID)
            {
                Bird *bird = (Bird *)spriteB;
                bird->hitAnimation(bird->getPosition());
            } else
            {
                spriteB->_HP = spriteB->_HP-force;
            }
            
        }
        
    }
}
