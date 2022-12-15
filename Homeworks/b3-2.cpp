#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int time_cost(int *f, int *t, int n, int S)
{
    int max_time = 0; //最长可能消耗时间
    for (int i = 0; i < n; i++)
    {
        max_time += t[i];
    }
    max_time += S * n;
    int time[max_time + 1][n + 1] = {INT_MAX};
    int fs, t_end; //批次的总费用系数，批次的完成时间
    int costs = 0;
    for (int i = n; i > 0; i--)
    {
        for (int j = max_time; j >= 0; j--)
        { // j时刻开始
            fs = 0;
            t_end = S + j;
            for (int k = i; k <= n; k++)
            { //[i,n]
                fs += f[k - 1];
                t_end += t[k - 1];
                costs = fs * t_end;
                if (k != n)
                    costs += time[k + 1][t_end]; //如果没有完成全部的作业，其后还有作业k+1~n
                time[i][j] = min(time[i][j], costs);
            }
        }
    }
}

int main()
{
}