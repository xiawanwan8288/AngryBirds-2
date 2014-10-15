//
//  SpriteBase.cpp
//  AndryPanda
//
//  Created by user on 13-7-2.
//
//

#include "SpriteBase.h"


/*
SpriteBase::SpriteBase()
{
    
}
SpriteBase::~SpriteBase()
{
    
}
*/
void SpriteBase::destory()
{
    
    char name[20];
    //不同的无题destroy的状态
    switch (this->getTag())
    {
        case ICE_ID:
            strcpy(name,"littleice");
            break;
            
        case BIRD_ID:
            strcpy(name,"yumao");
            break;
            
        case PIG_ID:
            this->destoryPig();
            this->getParent()->removeChild(this, true);
            return;
        default:
            strcpy(name,"littlewood");
            break;
    }
    
    
    for (int i = 0; i<10; i++)
    {
        int random = arc4random()%3+1;
        int range = 6;
        
        char t[30];
        sprintf(t, "%s%d.png",name,random);
        CCSprite *temp = CCSprite::create(t);

        temp->setScale((float)(arc4random()%5/10.1f));
        
        temp->setPosition(CCPointMake(this->getPosition().x+arc4random()%10*range-20, this->getPosition().y+arc4random()%10*range-10));
        CCMoveTo *actionMove = CCMoveTo::create(1.0f, CCPointMake(this->getPosition().x+arc4random()%10*range-20, this->getPosition().y+arc4random()%10*range-10)) ;
        
        CCFadeOut *actionAlpha = CCFadeOut::create(1.0);
        CCCallFuncN *actionMoveEnd = CCCallFuncN::create(this, callfuncN_selector(SpriteBase::runEnd));
        CCRotateTo *actionRotate = CCRotateTo::create(1.0, arc4random()%180);
        CCSpawn *mut = CCSpawn::create(actionMove,actionAlpha,actionRotate,NULL);
        CCSequence *seq = CCSequence::create(mut,actionMoveEnd,NULL);
        temp->runAction(seq);
        _myLayer->addChild(temp);
    }
    
    /*
    UIImage *image = [UIImage imageNamed:@"smoke.png"];
    CCTexture2D * somkeTexture = [[CCTexture2D alloc]initWithImage:image];
    NSMutableArray *frams = [NSMutableArray array];
    for (int i=0; i<4; i++) {
        [frams addObject:[[CCSpriteFrame alloc]initWithTexture:somkeTexture rect:CGRectMake(0+i*image.size.width/4, 0, image.size.width/4, image.size.height)]];
    }
    CCAnimation *animation = [CCAnimation animationWithFrames:frams delay:0.1f];
    id actionMoveEnd = [CCCallFuncN actionWithTarget:self selector:@selector(runEnd:)];
    CCSequence * m = [CCSequence actions:[CCAnimate actionWithAnimation:animation restoreOriginalFrame:NO] , actionMoveEnd,nil];
    [self runAction:m];
    
    
    CCLabelTTF *label = [CCLabelTTF labelWithString:@"" fontName:@"Marker Felt" fontSize:32];
    switch (self.tag) {
        case ICE_ID:
            [label setString:@"500"];
            [label setColor:ccc3(0, 250, 0)];
            [myLayer sprite:self withScore:500];
            break;
    }
    
  
    label.position = self.position;
    id action1 = [CCScaleTo actionWithDuration:0.5f scale:0.4];
    
    id action2 = [CCScaleBy actionWithDuration:0.5f scale:0];
    [label runAction:[CCSequence actions:action1,action2,actionMoveEnd, nil]];
    
    [myLayer addChild:label];
     */

}

//猪已经销毁，显示得分动画
void SpriteBase::destoryPig()
{
    char t[30];
    sprintf(t, "10000%i.png",arc4random()%3+1);
    CCSprite *score = CCSprite::create(t);
    score->setScale(0.2);
    score->setPosition(this->getPosition());
    
    CCScaleTo *action1 = CCScaleTo::create(0.25f, 0.4);
    CCScaleBy *action2 = CCScaleBy::create(0.5f, 0);
    CCCallFuncN *actionMoveEnd =CCCallFuncN::create(this, callfuncN_selector(SpriteBase::runEnd));
    CCSequence *seq = CCSequence::create(action1,action2,actionMoveEnd,NULL);
    score->runAction(seq);
    _myLayer->addChild(score);
    //加分的操作在别的地方完成了（或者是）
    //[myLayer sprite:self withScore:10000];
}
 
void SpriteBase::runEnd(CCObject *pSender)
{
    CCSprite *temp = (CCSprite*)pSender;
    if (temp->getTag() == BIRD_ID) {
        this->destoryBody(pSender);
    }
    temp->getParent()->removeChild(temp, true);
}
void SpriteBase::destoryBody(CCObject *pSender)
{
    CCSprite *temp = (CCSprite*)pSender;
    temp->setTag(0);
    
    for (b2Body* b = _myWorld->GetBodyList(); b; b = b->GetNext())
	{
		if (b->GetUserData() != NULL)
        {
			SpriteBase *myActor = (SpriteBase *)b->GetUserData();
            if (myActor->getTag() == 0)
            {
                _myWorld->DestroyBody(b);
            }
        }
    }
    temp = NULL;
}
