#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <fstream>
#include <math.h>

using namespace std;

int AddOil(vector<int> &dist, int n, int k) // dist has k elements
{
    int ans = 0;
    int temp = 0;
    for (int i = 0; i <= k; i++)
    {
        if (dist[i] > n)
            return -1;
        temp += dist[i];
        if (temp > n)
        {
            ans++;
            temp = dist[i];
        }
    }
    return ans;
}

int main()
{
    ifstream fin("D:/VS Code C++ works/AlgorithmHomeworks/Exp3/examples.txt");
    ofstream fout("D:/VS Code C++ works/AlgorithmHomeworks/Exp3/Q4ans.txt");
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
        vector<int> dist;
        fin >> n >> k;
        for (int i = 0; i <= k; i++)
        {
            int temp;
            fin >> temp;
            dist.push_back(temp);
        }
        int ans = AddOil(dist, n, k);
        if (ans == -1)
            fout << "Group " << groupslen - groups << " Answer: No Solution" << endl;
        else
            fout << "Group " << groupslen - groups << " Answer:" << ans << endl;
    }

    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    printf("%d groups, time cost: %f\n", groupslen, time);

    fin.close();
    fout.close();
    system("pause");
    return 0;
}