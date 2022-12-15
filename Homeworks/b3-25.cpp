#include <iostream>
#include <math.h>
#define N 1001
#define K 1001

using namespace std;

int ans[N + 1][K + 1] = {0};

int r[N];

int f(int i, int j)
{
    int sum = 0;
    for (int p = i; p <= j; p++)
    {
        sum += r[p] * r[p];
    }
    return sqrt(sum);
}

int cpu(int n, int m)
{
    int temp1 = f(n - 1, n - 1);
    int maxnum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (f(i, i) > temp1)
            temp1 = f(i, i);
        ans[i][1] = f(i, n - 1);
        if (n - i <= m)
            ans[i][n - i] = temp1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int k = 2; k <= m; k++)
        {
            int temp2 = INT_MAX;
            for (int j = i; j <= n - k; j++)
            {
                maxnum = max(f(i, j), ans[j + 1][k - 1]);
                if (maxnum < temp2)
                    temp2 = maxnum;
            }
            ans[i][k] = temp2;
        }
        for (int k = n - i + 1; k <= m; k++)
            ans[i][k] = ans[i][n - i];
    }
    return ans[0][m];
}