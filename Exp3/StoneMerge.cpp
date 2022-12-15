#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <fstream>
#include <math.h>

using namespace std;

vector<int> StoneMerge(vector<int> &a, int n)
{
    vector<int> ans;
    if (n == 1)
    {
        ans.push_back(a[0]);
        ans.push_back(a[0]);
        return ans;
    }
    vector<int> minHeap;
    minHeap.assign(a.begin(), a.begin() + n);
    vector<int> maxHeap;
    maxHeap.assign(a.begin(), a.begin() + n);
    int max = 0;
    int min = 0;
    int flag = 0;
    while (minHeap.size() != 2)
    {
        int tempmin = INT_MAX;
        auto tempit = minHeap.begin();
        for (auto it = minHeap.begin() + 1; it != minHeap.end() - 1; it++)
        {
            if (*(it - 1) > *(it + 1))
            {
                if (*(it + 1) < tempmin)
                {
                    tempmin = *(it + 1);
                    tempit = it + 1;
                    flag = 0;
                }
            }
            else
            {
                if (*(it - 1) < tempmin)
                {
                    tempmin = *(it - 1);
                    tempit = it - 1;
                    flag = 1;
                }
            }
        }
        if (flag)
        {
            *tempit = *(tempit + 1) + *tempit;
            tempmin = *tempit;
            minHeap.erase(tempit + 1);
        }
        else
        {
            *tempit = *(tempit - 1) + *tempit;
            tempmin = *tempit;
            minHeap.erase(tempit - 1);
        }
        min += tempmin;
    }
    min += minHeap[0] + minHeap[1];

    while (maxHeap.size() != 2)
    {
        int tempmax = 0;
        auto tempit = maxHeap.begin();
        for (auto it = maxHeap.begin() + 1; it != maxHeap.end() - 1; it++)
        {
            if (*(it - 1) < *(it + 1))
            {
                if (*(it + 1) > tempmax)
                {
                    tempmax = *(it + 1);
                    tempit = it + 1;
                    flag = 0;
                }
            }
            else
            {
                if (*(it - 1) > tempmax)
                {
                    tempmax = *(it - 1);
                    tempit = it - 1;
                    flag = 1;
                }
            }
        }
        if (flag)
        {
            *tempit = *(tempit + 1) + *tempit;
            tempmax = *tempit;
            maxHeap.erase(tempit + 1);
        }
        else
        {
            *tempit = *(tempit - 1) + *tempit;
            tempmax = *tempit;
            maxHeap.erase(tempit - 1);
        }
        max += tempmax;
    }
    max += maxHeap[0] + maxHeap[1];
    ans.push_back(min);
    ans.push_back(max);
    return ans;
}

int main()
{
    ifstream fin("D:/VS Code C++ works/AlgorithmHomeworks/Exp3/examples.txt");
    ofstream fout("D:/VS Code C++ works/AlgorithmHomeworks/Exp3/Q2ans.txt");
    int groups;
    fin >> groups;
    int groupslen = groups;
    vector<int> a(10000, 0);

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
        vector<int> ans = StoneMerge(a, n);
        fout << "Group " << groupslen - groups << " Answer: Min Score: " << ans[0] << " Max Score: " << ans[1] << endl;
    }

    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    printf("%d groups, time cost: %f\n", groupslen, time);

    fin.close();
    fout.close();
    system("pause");
    return 0;
}