#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <fstream>
#include <math.h>

using namespace std;

struct City
{
    bool operator<(City c)
    {
        return x <= c.x;
    }
    City()
    {
        x = w = c = 0;
    }
    static void initCity(int n);
    int x;
    int w;
    int c;
};

City *city;

vector<int> inittemp(1001, 0);

vector<vector<int>> ans(1001, inittemp);
vector<vector<int>> cost(1001, inittemp);
vector<vector<int>> Prevs(1001, inittemp);

int getCost(int i, int j)
{
    return city[i].w * (city[i].x - city[j].x);
}

void initCity(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cost[0][i] = city[i].c;
        for (int j = 1; j < i; j++)
        {
            cost[0][i] -= getCost(j, i);
        }
    }

    int mid = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            mid = (city[i].x + city[j].x) / 2 + (city[i].x + city[j].x) % 2;
            cost[i][j] += city[j].c;
            for (int k = i + 1; k < j; k++)
            {
                if (city[k].x > mid)
                {
                    cost[i][j] -= getCost(k, i) + getCost(k, j);
                }
            }
        }
    }
}

int MidValue(int k, int n)
{
    initCity(n);
    int nowk = 0;
    for (int i = 1; i <= n; i++)
    {
        nowk = min(i, k);
        for (int j = 1; j <= nowk; j++)
        {
            int isi = ans[i - 1][j - 1] + cost[Prevs[i - 1][j - 1]][i];
            if (j == i)
            {
                Prevs[i][j] = i;
                ans[i][j] = isi;
            }
            else
            {
                int noti = ans[i - 1][j] + getCost(i, Prevs[i - 1][j]);
                if (isi <= noti)
                {
                    Prevs[i][j] = i;
                    ans[i][j] = isi;
                }
                else
                {
                    Prevs[i][j] = Prevs[i - 1][j];
                    ans[i][j] = noti;
                }
            }
        }
    }
    int min = ans[n][1];
    for (int i = 1; i <= k; i++)
    {
        if (ans[n][i] < min)
        {
            min = ans[n][i];
        }
    }
    return min;
}

int main()
{
    ifstream fin("D:/VS Code C++ works/AlgorithmHomeworks/Exp3/examples.txt");
    ofstream fout("D:/VS Code C++ works/AlgorithmHomeworks/Exp3/Q3ans.txt");
    int groups;
    fin >> groups;
    int groupslen = groups;

    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime); // 采用QueryPerformanceFrequency进行精确计时

    while (groups--)
    {
        int n, k;
        fin >> n >> k;
        city = new City[n + 1];
        for (int i = 0; i < n; i++)
        {
            fin >> city[i + 1].x >> city[i + 1].w >> city[i + 1].c;
        }
        for (int i = 0; i <= n; i++)
        {
            ans[i] = inittemp;
            cost[i] = inittemp;
            Prevs[i] = inittemp;
        }
        fout << "Group " << groupslen - groups << " Answer:" << MidValue(k, n) << endl;
        delete[] city;
    }

    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    printf("%d groups, time cost: %f\n", groupslen, time);

    fin.close();
    fout.close();
    system("pause");
    return 0;
}