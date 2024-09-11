#include <iostream>
#include "speechmanager.h"
SpeechManager::SpeechManager() {
    //初始化属性
    this->initSpeech();
    //创建选手
    this->CreateSpeaker(); 
    //获取往届记录
    this->LoadRecord();
}
void SpeechManager::ShowMenu() {
    cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void SpeechManager::ExitSystem() {
    cout << "欢迎下次继续使用!" << endl;
    exit(0);
}
void SpeechManager::initSpeech() {
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();
    this->m_Index = 1;
    this->m_Record.clear();
}
void SpeechManager::CreateSpeaker() {
    string NameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < NameSeed.size(); i++)
    {
        string name = "选手";
        name += NameSeed[i];
        
        Speaker sp;
        sp.m_Name = name;
        for (int i = 0; i < 2; i++)
        {
            sp.m_Score[i] = 0;
        }
        //12名选手的编号
        this->v1.push_back(i + 10001);
        //选手编号 以及对应的选手 存放在map容器之中
        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }  
}
void SpeechManager::SpeechDraw() {
    cout << "第 << " << this->m_Index << " >> 轮比赛选手正在抽签!" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "抽签后演讲顺序如下: " << endl;
    if (this->m_Index == 1)
    {
        random_shuffle(v1.begin(), v1.end());
        for (vector<int>::iterator it = v1.begin(); it!= v1.end(); it++) {
            cout << *it << " ";
        } 
        cout << endl;
    }
    else
    {
        random_shuffle(v2.begin(), v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}
void SpeechManager::SpeechContest() {
    cout << "---------- 第"<< this->m_Index << "轮正式比赛开始: -----------" << endl;
    multimap<double, int, greater<int>> groupscore;
    int num = 0; //记录人员数, 6人一组
    vector<int> v_src; //比赛的人员容器
    if (this->m_Index == 1)
    {
        v_src = v1;
    }
    else
    {
        v_src = v2;
    }
    //遍历所有参赛选手
    for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++)
    {
        num++;
        deque<double> d;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.f;
            d.push_back(score);
        }
        sort(d.begin(), d.end(), greater<double>());
        d.pop_back();
        d.pop_front();
        double sum = accumulate(d.begin(), d.end(), 0.0f);
        double avg = sum / (double)d.size(); 
        //每个人平均分
        this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
        groupscore.insert(make_pair(avg, *it));
        if (num % 6 == 0)
        {
            cout << "第" << num / 6 << "小组比赛的名次: " << endl;
            for (multimap<double, int, greater<int>>::iterator it = groupscore.begin(); it != groupscore.end(); it++)
            {
                cout << "编号: " << it->second << "姓名: " << this->m_Speaker[it->second].m_Name << " 成绩: " << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl; 
            }
            int count = 0;
            //取前三名
            for (multimap<double, int, greater<int>>::iterator it = groupscore.begin(); it != groupscore.end() && count < 3; it++, count++)
            {
                if (this->m_Index == 1)
                {
                    v2.push_back((*it).second);
                }
                else
                {
                    vVictory.push_back((*it).second);
                }  
            }
            groupscore.clear();
            cout << endl;
        }
    }
    cout << "---------- 第" << this->m_Index << "轮比赛结束! -----------" << endl; 
}
void SpeechManager::ShowScore() {
    cout << "--------第" << this->m_Index << "轮晋级选手信息如下: --------" << endl;
    vector<int>v;
    if (this->m_Index == 1) {
        v = v2;
    }
    else {
        v = vVictory;
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "编号: " << *it << " 姓名: " << this->m_Speaker[*it].m_Name << " 成绩: " << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
    }
    cout << endl;
    
    //this->ShowMenu();
}
void SpeechManager::SaveRecord() {
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);//用输出的方式打开文件  --写文件
    //将每个人的文件写入文件中
    for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
    {
        ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
    }
    ofs << endl;
    ofs.close();
    cout << "比赛记录已保存!" << endl;
    //有记录了, 文件不为空了
    this->fileIsEmpty = false;
}
void SpeechManager::StartSpeech() {
    //第一轮比赛
    //1.抽签
    SpeechDraw();
    //2.比赛
    SpeechContest();
    //3.显示晋级结果
    ShowScore();
    //第二轮比赛
    this->m_Index++;
    //1.再次抽签
    SpeechDraw();
    //2.比赛
    SpeechContest();
    //3.显示最终结果
    ShowScore();
    //4.保存分数
    SaveRecord();
    this->initSpeech();
    this->CreateSpeaker();
    this->LoadRecord();
    cout << "本届比赛完毕!" << endl;
}
void SpeechManager::LoadRecord() {
    ifstream ifs("speech.csv", ios::in); //输入流对象 读取文件
    if (!ifs.is_open())
    {
        this->fileIsEmpty = true;
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件为空!" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }
    this->fileIsEmpty = false;
    ifs.putback(ch);// 读取单个字符放回去
    string data;
    int index = 0;
    while (ifs >> data)
    {
        vector<string> v;
        int pos = 1;
        int start = 0;
        while (true)
        {
            pos = data.find(",", start);// 从零开始查找
            if (pos == -1)
            {
                break; //找不到break返回
            }
            string tmp = data.substr(start, pos - start); // 找到了, 进行分割 参数1 起始位置, 参数2 截取长度
            v.push_back(tmp);
            start = pos + 1; // 起始位置下一个字符
        }
        this->m_Record.insert(make_pair(index, v));
        index++; 
    }
    ifs.close();
}
void SpeechManager::ShowRecord() {
    if (this->fileIsEmpty)
    {
        cout << "文件不存在, 或记录为空!" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_Record.size(); i++)
        {
            cout << "第" << i + 1 << "届" << 
                    "冠军编号: " << this->m_Record[i][0] << " 得分: " << this->m_Record[i][1] << " "
                    "亚军编号: " << this->m_Record[i][2] << " 得分: " << this->m_Record[i][3] << " "
                    "季军编号: " << this->m_Record[i][4] << " 得分: " << this->m_Record[i][5] << endl;
        }
    }   
}
void SpeechManager::ClearRecord() {
    cout << "确认清空?" << endl;
    cout << "1.确认" << endl;
    cout << "2.取消" << endl;
    int choice = 0;
    cin >> choice;
    if (choice == 1)
    {
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();
        this->initSpeech();
        this->CreateSpeaker();
        this->LoadRecord();
        cout << "比赛记录已清空!" << endl;
    }
    
}
SpeechManager::~SpeechManager() {

}
