#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <ctime>
#include "speaker.h"
using namespace std;
class SpeechManager {
public:
    SpeechManager();
    void ShowMenu();
    void ExitSystem();
    void initSpeech();
    void CreateSpeaker();
    void StartSpeech();
    void SpeechDraw();
    void SpeechContest();
    void ShowScore();
    void SaveRecord();
    void LoadRecord();
    void ShowRecord();
    void ClearRecord();
    ~SpeechManager();
    //12名选手编号 容器
    vector<int>v1;
    //第一轮晋级6名选手编号 容器
    vector<int>v2;  
    //胜利前三名 容器
    vector<int>vVictory;
    map<int, Speaker> m_Speaker;//编号对应选手
    int m_Index;
    bool fileIsEmpty;
    map<int, vector<string>> m_Record;
};