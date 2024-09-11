#include <iostream>
#include "speechmanager.h"
int main() {
    srand((unsigned int)time(NULL));
    SpeechManager sm;
    int choice = 0;
    // for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
    // {
    //     cout << "选手编号: " << it->first << " 选手姓名: " << it->second.m_Name << " 选手分数: " << it->second.m_Score[0] << endl;
    // }
    // for (vector<int>::iterator it = sm.v1.begin(); it != sm.v1.end(); it++)
    // {
    //     cout << "比赛编号: " << *it << endl;
    // }
    
    
    while (true)
    {
        sm.ShowMenu();
        cout << "请输入你的选择: " << endl;
        cin >> choice ;
        switch (choice)
        {
        case 1: //开始比赛
            {
                sm.StartSpeech();
                // for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
                //     {
                //         cout << "选手编号: " << it->first << " 选手姓名: " << it->second.m_Name << " 选手分数: " << it->second.m_Score[0] << endl;
                //     }
                break;
            }
        case 2: //查看记录
            sm.ShowRecord();
            break;
        case 3: //清空记录
            sm.ClearRecord();
            break;
        case 0: //退出系统
            sm.ExitSystem();
            break;
        default:
            system("cls");
            break;
        }
    }
    
    return 0;
}