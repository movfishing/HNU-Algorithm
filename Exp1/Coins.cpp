#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <fstream>

using namespace std;

int Coins(vector<vector<int>> &a, vector<vector<int>> &b, int x, int y)
{
    vector<int> is_comp(y, 0); //用于标记a中每一列是否有与之对应的列
    vector<vector<int>> temp;
    temp.assign(a.begin(), a.end());
    int turncount = 0;
    int switchcount = 0;
    for (int i = 0; i < x; i++)
    {
        int count_0 = 0;
        int count_1 = 0;
        for (int j = 0; j < y; j++)
        {
            if (a[i][j])
                count_1++;
            else
                count_0++;
            if (b[i][j])
                count_1--;
            else
                count_0--;
        }
        if (count_0 == 0 && count_1 == 0)
            ;
        else if (count_0 * (-1) == count_1)
        {
            turncount++;
            for (int k = 0; k < y; k++)
                temp[i][k] ^= 1;
        }
        else
        {
            return -1;
        }
    }

    int flag = 0;
    for (int p = 0; p < y; p++) //然后再对于目标的每一列，查找是否有与之相同的列
    {
        int compline = 0;
        int outflag = 0;
        int has_comp = 0;
        for (int q = 0; q < y; q++)
        {
            flag = 0;
            for (int r = 0; r < x; r++)
            {
                if (b[r][p] != temp[r][q])
                    break;
                if (r == x - 1)
                {
                    flag = 1;
                    outflag = 1;
                    if (is_comp[q] == 0 && !has_comp)
                    {
                        is_comp[q] = 1;
                        has_comp = 1;
                    }
                }
            }

            if (flag && p == q)
            {
                switchcount--;
            }
        }
        if (outflag)
            switchcount++;
        else
            return -1;
    }
    turncount += switchcount / 2 + switchcount % 2;
    for (auto i : is_comp)
    {
        if (i == 0)
            return -1;
    }
    return turncount;
}

int main()
{
    ifstream examples("D:/VS Code C++ works/AlgorithmHomeworks/Exp1/examples.txt");
    ofstream in("D:/VS Code C++ works/AlgorithmHomeworks/Exp1/Q4ans.txt", ios::trunc);
    if (!examples.is_open())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
    int n = 0;
    examples >> n;
    n /= 2;
    int len = n;

    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime); //采用QueryPerformanceFrequency进行精确计时

    while (n--)
    {
        vector<vector<int>> coins1;
        vector<vector<int>> coins2;
        int x, y;
        examples >> x;
        examples >> y;
        int num;
        vector<int> temp;
        for (int i = 0; i < x; i++)
        {
            coins1.push_back(temp);
            for (int j = 0; j < y; j++)
            {
                examples >> num;
                coins1[i].push_back(num);
            }
        }
        for (int i = 0; i < x; i++)
        {
            coins2.push_back(temp);
            for (int j = 0; j < y; j++)
            {
                examples >> num;
                coins2[i].push_back(num);
            }
        } //读取测试用例文件
        in << Coins(coins1, coins2, x, y) << endl;
    }

    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    printf("%d groups, time cost: %f\n", len, time);

    examples.close();
    system("pause");
    return 0;
}