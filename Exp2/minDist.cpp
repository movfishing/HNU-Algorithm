#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <windows.h>
#include <fstream>

using namespace std;

vector<vector<int>> Dist;

void minDist(string A, string B, int k)
{
    Dist[0][0] = 0;
    for (int i = 1; i < Dist.size(); i++)
    {
        Dist[i][0] = Dist[i - 1][0] + k;
    }
    for (int j = 1; j < Dist[0].size(); j++)
    {
        Dist[0][j] = Dist[0][j - 1] + k;
    }
    for (int i = 1; i < Dist.size(); i++)
    {
        for (int j = 1; j < Dist[0].size(); j++)
        {
            Dist[i][j] = min(min(Dist[i - 1][j] + k, Dist[i][j - 1] + k), Dist[i - 1][j - 1] + abs(A[i - 1] - B[j - 1]));
        }
    }
}

int main()
{
    ifstream examples("D:/VS Code C++ works/AlgorithmHomeworks/Exp2/examples.txt");
    ofstream in("D:/VS Code C++ works/AlgorithmHomeworks/Exp2/Q3ans.txt", ios::trunc);
    if (!examples.is_open())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
    int groups;
    examples >> groups;
    string init_str;
    int groupslen = groups;
    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime); //采用QueryPerformanceFrequency进行精确计时

    while (groups--)
    {
        examples >> init_str;
        string A = init_str;
        examples >> init_str;
        string B = init_str;
        int k;
        examples >> k;

        int m = A.length();
        int n = B.length();

        vector<int> temp(n + 1, 0);
        vector<vector<int>> init_vector(m + 1, temp);
        Dist.assign(init_vector.begin(), init_vector.end());

        minDist(A, B, k);

        in << "Group " << groupslen - groups << " Distance = " << Dist.back().back() << endl;
    }

    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    printf("%d groups, time cost: %f\n", groupslen, time);

    examples.close();
    system("pause");
    return 0;
}