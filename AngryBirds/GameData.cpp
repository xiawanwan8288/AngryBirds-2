//
//  GameData.cpp
//  AngryBirds
//
//  Created by zyuq on 13-6-26.
//
//

#include "GameData.h"
#include "Const.h"
static GameData *sharedData = NULL;
GameData* GameData::shareData()
{
    if (sharedData==NULL) {
        sharedData=new GameData();
    }
    return sharedData;
}


GameData::GameData()
{
    defaults=CCUserDefault::sharedUserDefault();
    isDeviceIphone5=defaults->getBoolForKey("isDeviceIphone5");
    
}
