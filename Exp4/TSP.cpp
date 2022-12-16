#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <fstream>
#include <stack>
#define N 1000
#define INF 1e7
using namespace std;

struct node
{
    int cl;   // 当前走过的路径长度
    int rl;   // 剩余结点最小边权值之和
    int zl;   // cl+rl,路径长度下界
    int id;   // 处理的第几个景点
    int x[N]; // 记录当前路径
    node() {}
    node(int c, int r, int z, int i)
    {
        cl = c;
        rl = r;
        zl = z;
        id = i;
        memset(x, 0, sizeof(x));
    }
};

int m[N][N];  // 邻接矩阵存储无向带权图
int bestx[N]; // 最优解路径
int bestl;    // 最优解长度
int n, M;     // 景点数目,路径数目
int minv[N];  // 每个顶点最小边权值
int minsum;   // 每个顶点最小边权值之和

void init() // 初始化，注意初始化和计算函数调用的位置
{
    int i, j;
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            m[i][j] = INF;
    memset(bestx, 0, sizeof(bestx));
    bestl = INF;
}

void cal() // 计算每个顶点的最小边权值
{
    minsum = 0;
    memset(minv, 0, sizeof(minv));
    int temp, i, j;
    for (i = 1; i <= n; ++i)
    {
        temp = INF;
        for (j = 1; j <= n; ++j)
            if (m[i][j] != INF && m[i][j] < temp)
                temp = m[i][j];
        minv[i] = temp;
        minsum += temp;
    }
}

struct cmp
{
    bool operator()(node n1, node n2) // 当前路径长度短的优先级高
    {
        return n1.zl > n2.zl; // 最小堆
    }
};

void TSP()
{
    priority_queue<node, vector<node>, cmp> q;
    node temp(0, minsum, minsum, 2); // 起点已经确定，从第2个景点开始
    int t;
    for (int i = 1; i <= n; ++i)
        temp.x[i] = i; // 初始化解向量
    q.push(temp);
    node live; // 活结点
    while (!q.empty())
    {
        live = q.top();
        q.pop();
        t = live.id;
        if (t == n) // 处理到倒数第二个景点
        {
            if (m[live.x[t - 1]][live.x[t]] != INF && m[live.x[t]][1] != INF) // 满足约束条件，有路径
            {
                if (live.cl + m[live.x[t - 1]][live.x[t]] + m[live.x[t]][1] < bestl) // 更新最优解
                {
                    bestl = live.cl + m[live.x[t - 1]][live.x[t]] + m[live.x[t]][1];
                    for (int i = 1; i <= n; ++i)
                        bestx[i] = live.x[i];
                }
            }
            continue;
        }

        if (live.cl >= bestl) // 不满足限界条件
            continue;

        for (int j = t; j <= n; ++j) // 排列树,j不能定义为整个函数的局部变量，循环过程中会出现混乱
        {
            if (m[live.x[t - 1]][live.x[j]] != INF) // 满足约束条件
            {
                int cl = live.cl + m[live.x[t - 1]][live.x[j]];
                int rl = live.rl - minv[live.x[j]];
                int zl = cl + rl;
                if (zl < bestl) // 满足限界条件
                {
                    temp = node(cl, rl, zl, t + 1);
                    for (int k = 1; k <= n; ++k)
                        temp.x[k] = live.x[k];
                    swap(temp.x[t], temp.x[j]);
                    q.push(temp);
                }
            }
        }
    }
}

int main()
{
    ifstream examples("D:/VS Code C++ works/AlgorithmHomeworks/Exp4/examples.txt");
    ofstream in("D:/VS Code C++ works/AlgorithmHomeworks/Exp4/Q2ans.txt", ios::trunc);
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
    QueryPerformanceCounter(&nBeginTime); // 采用QueryPerformanceFrequency进行精确计时

    while (groups--)
    {
        init();
        examples >> n;
        M = (n * (n + 1)) / 2;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; j++)
            {
                examples >> m[i][j];
                if (m[i][j] == -1)
                    m[i][j] = INF;
            }
        }
        cal(); // 计算minv[],minxum
        TSP();
        in << "Group " << groupslen - groups << " distance: " << bestl << endl;
        in << "way: ";
        for (int i = 1; i <= n; ++i)
            in << bestx[i] << "-->";
        in << bestx[1] << endl;
    }
    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    printf("%d groups, time cost: %f\n", groupslen, time);

    examples.close();
    system("pause");
    return 0;
}