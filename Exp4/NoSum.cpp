#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

#define N 1000

int F[N][N], answer[N][N];

int n, maxValue;

int judge(int t, int k)
{
    int i, j;
    for (i = 1; i <= F[k][0]; i++)
    {
        for (j = i + 1; j <= F[k][0]; j++)
        {
            if (F[k][i] + F[k][j] == t)
                return 0;
        }
    }
    return 1;
}

void dfs(int t)
{
    if (t > maxValue)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= F[i][0]; j++)
            {
                answer[i][j] = F[i][j];
            }
        }
        maxValue = t;
    }

    for (int i = 0; i < n; i++)
    {
        F[i][F[i][0] + 1] = t;
        if (judge(t, i))
        {
            F[i][0] += 1;
            dfs(t + 1);
            F[i][0] -= 1;
        }
    }
}

int main()
{
    ifstream examples("D:/VS Code C++ works/AlgorithmHomeworks/Exp4/examples.txt");
    ofstream in("D:/VS Code C++ works/AlgorithmHomeworks/Exp4/Q3ans.txt", ios::trunc);
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
        examples >> n;
        maxValue = 0;
        dfs(1);
        in << "Group " << groupslen - groups << " answer = " << maxValue - 1 << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= answer[i][0]; j++)
            {
                in << answer[i][j] << " ";
            }
            in << endl;
        }
    }

    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    printf("%d groups, time cost: %f\n", groupslen, time);

    examples.close();
    system("pause");
    return 0;
}