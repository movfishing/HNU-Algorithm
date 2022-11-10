#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <fstream>

using namespace std;

#define INFINITY INT_MAX

struct Graph
{
    int sign;
    vector<int> sides;
}; //初始化注意：无边则边长为INFINITY，为自身时则边长为0.

vector<Graph> G;

vector<int> Dist; //初始化为G大小

vector<int> Prevs; //初始化为G大小,均为-1

int side_length(int point1, int point2)
{
    return G[point1].sides[point2];
}

void Dijkstra(int src)
{
    vector<int> V(G.size(), 0); //初始化为G大小
    int prev = src;
    for (int i = 0; i < G.size(); i++)
    {
        Dist[i] = side_length(src, i);
        if (Dist[i] != INFINITY)
            Prevs[i] = src;
        V[i] = 0;
    }

    V[src] = 1;

    for (int p = 0; p < G.size(); p++)
    {
        int temp = INFINITY;
        for (int i = 0; i < G.size(); i++)
        {
            if ((!V[i]) && (Dist[i] < temp))
            {
                prev = i;
                temp = Dist[i];
            }
        }
        V[prev] = 1;
        for (int i = 0; i < G.size(); i++)
        {
            if ((!V[i]) && (side_length(prev, i) != INFINITY))
            {
                int newDist = side_length(prev, i) + Dist[prev];
                if (newDist < Dist[i])
                {
                    Dist[i] = newDist;
                    Prevs[i] = prev;
                }
            }
        }
    }
}

int main()
{
    ifstream examples("D:/VS Code C++ works/AlgorithmHomeworks/Exp2/examples.txt");
    ofstream in("D:/VS Code C++ works/AlgorithmHomeworks/Exp2/Q1ans.txt", ios::trunc);
    if (!examples.is_open())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
    int groups;
    int point_num;
    examples >> groups;
    int groupslen = groups;
    int src;
    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime); //采用QueryPerformanceFrequency进行精确计时

    while (groups--)
    {
        examples >> point_num;
        examples >> src;
        vector<int> init(point_num, 0);
        vector<int> init2(point_num, -1);
        Graph a;
        a.sides = init;
        a.sign = 0;
        vector<Graph> temp(point_num, a);
        G.assign(temp.begin(), temp.end());
        Dist.assign(init.begin(), init.end());
        Prevs.assign(init2.begin(), init2.end());
        for (int i = 0; i < point_num; i++)
        {
            examples >> G[i].sign;
            for (int j = 0; j < point_num; j++)
            {
                examples >> G[i].sides[j];
                if (G[i].sides[j] == -1)
                    G[i].sides[j] = INFINITY;
            }
        } //读取测试用例文件

        Dijkstra(src);

        int prev;

        in << "Group " << groupslen - groups << ":" << endl;
        for (int i = 0; i < G.size(); i++)
        {
            int flag = 1;
            prev = i;
            while (prev != src)
            {
                in << prev << " <- ";
                prev = Prevs[prev];
                if (prev == -1)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                in << src << "   Distance = " << Dist[i] << endl;
            else
                in << "no way" << endl;
        }
        in << endl;
    }

    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    printf("%d groups, time cost: %f\n", groupslen, time);

    examples.close();
    system("pause");
    return 0;
}