#include <iostream>
#include <math.h>
#define N 1001
#define K 1001

using namespace std;

int ans[N + 1][K + 1] = {0};

int num[N];

int cal(int i, int j)
{
    int temp = 0;
    int cal_n = 0;
    for (int p = i; p <= j; p++)
    {
        cal_n += num[p] * pow(10, temp);
        temp++;
    }
    return cal_n;
}

int maxmul(int n, int m)
{
    int maxnum = 0;
    for (int i = 1; i <= n; i++)
        ans[i][1] = cal(0, i);
    for (int j = 2; j <= m; j++)
    {
        for (int i = j; i <= n; i++)
        {
            int temp = 0;
            for (int k = 1; k < i; k++)
            {
                maxnum = ans[k][j - 1] * cal(k, i);
                if (temp < maxnum)
                    temp = maxnum;
            }
            ans[i][j] = temp;
        }
    }
    return ans[n][m];
}