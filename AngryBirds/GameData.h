//
//  GameData.h
//  AngryBirds
//
//  Created by zyuq on 13-6-26.
//
//

#ifndef __AngryBirds__GameData__
#define __AngryBirds__GameData__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class GameData {
    
    
public:
    bool soundEffectMuted;//音效是否打开
    bool backgroundMusicMuted;//背景音乐是否打开
    
    
    //是否是第一次玩这款游戏
    bool notFirstTimeEnterStore;
    
    bool notFirstTimePlayThisGame;
    
    
    bool gamePaused;
    
    CCUserDefault* defaults;
    //关卡相关
    
    int levelsCompleted; //已通过的关卡数量
    
    int chaptersCompleted;//已完成的场景数量
    
    bool currentLevelSolved;//当前关卡是否已通过
    
    //所选场景和关卡
    
    int _selectedChapter;
    int _selectedLevel;
    
    //当前关卡的评价（非历史最佳成绩，而是此次通关时的评价，历史最佳成绩保存在Levels-Chapter1.xml中）
    
    int currentLevelStars;
    
    //该游戏专用
    
    int enemyNumberForCurrentLevel;
    
    
    
    //当前关卡名称
    char currentLevelName[50];
    
    
    //当前关卡要抛射的熊猫数量
    int pandasToTossThisLevel;
    
    int scoresToPassLevel;//通过该关卡所需的分数
    
    int bonusPerPanda; //剩下熊猫所得到的奖励分值
    
    int scoresForAllLevels; //所有关卡得分
    
    
    int levelsInLevelpack; //每个关卡部分包含多少子关卡
    
    //各关卡的历史最高得分
    
    int highScoreLevel1;
    int highScoreLevel2;
    int highScoreLevel3;
    int highScoreLevel4;
    int highScoreLevel5;
    int highScoreLevel6;
    int highScoreLevel7;
    int highScoreLevel8;
    int highScoreLevel9;
    int highScoreLevel10;
    
    
    //当前关卡得分
    int currentLevelScore;
    
    //判断设备类型
    
    bool isDeviceIphone5;
    
    static GameData* shareData();
    GameData();
    ~GameData();
    
};

#endif /* defined(__AngryBirds__GameData__) */
