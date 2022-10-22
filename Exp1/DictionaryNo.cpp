#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <fstream>

using namespace std;

int cnm(int n, int m)
{ // n个数里选m个
    int sum = 1;
    for (int i = 0; i < m; i++)
    {
        sum *= (n - i) / (i + 1);
    }
    return sum;
}

int lensum1(string s)
{
    int sum = 0;
    int len = s.length();
    int ch = 'a';
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < s[i] - ch; j++)
        {
            sum += cnm('z' - ch - j, len - i - 1);
        }
        ch = s[i] + 1;
    }
    return sum;
}

int DictionaryNo(string s)
{
    int ans = 0;
    int sumabove = 1;
    int len = s.length();
    for (int i = 1; i < len; i++)
        sumabove += cnm(26, i);
    ans = lensum1(s) + sumabove;
    return ans;
}

int main()
{
    ifstream examples("D:/VS Code C++ works/AlgorithmHomeworks/Exp1/examples.txt");
    ofstream in("D:/VS Code C++ works/AlgorithmHomeworks/Exp1/Q3ans.txt", ios::trunc);
    if (!examples.is_open())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }

    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime); //采用QueryPerformanceFrequency进行精确计时

    int innum = 0;
    examples >> innum;
    int len1 = innum;
    string s;
    while ((innum--) && examples >> s)
    {
        in << DictionaryNo(s) << endl;
    }

    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;

    printf("\n%d nums, time cost: %f\n", len1, time);

    examples.close();
    system("pause");
    return 0;
}