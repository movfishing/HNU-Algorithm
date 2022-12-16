#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

#define N 1000

int n;
int pay[N][N];
int Min = INT_MAX;
int sum = 0;
int has_work[N]; // 标记第i个人是否已经被安排工作

void dfs(int t)
{
    if (t >= n)
    {
        if (Min > sum)
        {
            Min = sum;
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!has_work[i])
        {
            has_work[i] = 1;
            sum += pay[t][i];
            if (sum < Min)
                dfs(t + 1);
            has_work[i] = 0;
            sum -= pay[t][i];
        }
    }
}

int main()
{
    ifstream examples("D:/VS Code C++ works/AlgorithmHomeworks/Exp4/examples.txt");
    ofstream in("D:/VS Code C++ works/AlgorithmHomeworks/Exp4/Q4ans.txt", ios::trunc);
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
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                examples >> pay[i][j];
            }
            has_work[i] = 0;
        }
        dfs(0);
        in << "Group " << groupslen - groups << " answer = " << Min << endl;
    }

    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    printf("%d groups, time cost: %f\n", groupslen, time);

    examples.close();
    system("pause");
    return 0;
}