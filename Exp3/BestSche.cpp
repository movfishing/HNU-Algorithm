#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <fstream>
#include <math.h>

using namespace std;

int BestSchedule(vector<int> &a, vector<int> &b, int n)
{
    int timea = 0;
    int timeb = 0;
    for (int i = 0; i < n; i++)
    {
        if (max(timea + a[i], timeb) > max(timea, timeb + b[i]))
        {
            timeb += b[i];
        }
        else
        {
            timea += a[i];
        }
    }
    return max(timea, timeb);
}

int main()
{
    ifstream fin("D:/VS Code C++ works/AlgorithmHomeworks/Exp3/examples.txt");
    ofstream fout("D:/VS Code C++ works/AlgorithmHomeworks/Exp3/Q1ans.txt");
    int groups;
    fin >> groups;
    int groupslen = groups;
    vector<int> a(10000, 0);
    vector<int> b(10000, 0);

    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime); // 采用QueryPerformanceFrequency进行精确计时

    while (groups--)
    {
        int n;

        fin >> n;
        for (int i = 0; i < n; i++)
        {
            int temp;
            fin >> temp;
            a[i] = temp;
        }
        for (int i = 0; i < n; i++)
        {
            int temp;
            fin >> temp;
            b[i] = temp;
        }
        fout << "Group " << groupslen - groups << " Answer: " << BestSchedule(a, b, n) << endl;
    }

    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    printf("%d groups, time cost: %f\n", groupslen, time);

    fin.close();
    fout.close();
    system("pause");
    return 0;
}