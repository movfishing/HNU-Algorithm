#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <fstream>
#include <stack>

using namespace std;

stack<int> ans;

int value = 0;

void packet(vector<int> &w, vector<int> &v, int c)
{
    stack<int> temp;
    int now_c = c;
    int t_value = 0;
    for (int i = 0; i < w.size(); i++)
    {
        if (now_c >= w[i])
        {
            now_c -= w[i];
            temp.push(i);
            t_value += v[i];
        }
    }
    if (t_value > value)
    {
        value = t_value;
        ans = temp;
    }
    while (1)
    {
        int prev = temp.top();
        temp.pop();
        now_c += w[prev];
        t_value -= v[prev];
        if (prev == w.size() - 1)
        {
            prev = temp.top();
            temp.pop();
            now_c += w[prev];
            t_value -= v[prev];
        }
        for (int i = prev + 1; i < w.size(); i++)
        {
            if (now_c >= w[i])
            {
                now_c -= w[i];
                temp.push(i);
                t_value += v[i];
            }
        }
        if (t_value > value)
        {
            value = t_value;
            ans = temp;
        }
        if (temp.size() == 0)
            break;
        else if (temp.top() == w.size() - 1 && temp.size() == 1)
            break;
    }
}

int main()
{
    ifstream examples("D:/VS Code C++ works/AlgorithmHomeworks/Exp2/examples.txt");
    ofstream in("D:/VS Code C++ works/AlgorithmHomeworks/Exp2/Q2ans.txt", ios::trunc);
    if (!examples.is_open())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
    int groups;
    int thing_num;
    examples >> groups;
    int groupslen = groups;
    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime); //采用QueryPerformanceFrequency进行精确计时

    while (groups--)
    {
        examples >> thing_num;
        vector<int> w; // weight
        vector<int> v; // value
        int c;
        examples >> c;
        int init_weight;
        int init_value;
        for (int i = 0; i < thing_num; i++)
        {
            examples >> init_weight >> init_value;
            w.push_back(init_weight);
            v.push_back(init_value);
        } //读取测试用例文件

        packet(w, v, c);

        in << "Group " << groupslen - groups << " max_value = " << value << endl;

        in << "answer :";

        while (!ans.empty())
        {
            in << " " << ans.top();
            ans.pop();
        }
        in << endl;
        value = 0;
    }

    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    printf("%d groups, time cost: %f\n", groupslen, time);

    examples.close();
    system("pause");
    return 0;
}
