#include <iostream>
#include <math.h>
#define N 1001
#define M 1001

using namespace std;

int ans[N + 1][M + 1] = {0};
int nums[N] = {0};

int minmaxnum(int n, int m)
{
    int maxnum = 0;
    for (int i = 1; i <= n; i++)
    {
        ans[i][1] = ans[i - 1][1] + nums[i];
    }
    for (int j = 2; j <= m; j++)
    {
        for (int i = j; i <= n; i++)
        {
            int temp = INT_MAX;
            for (int k = 1; k < i; k++)
            {
                maxnum = max(ans[i][1] - ans[k][1], ans[k][j - 1]);
                if (temp > maxnum)
                    temp = maxnum;
            }
            ans[i][j] = temp;
        }
    }
    return ans[n][m];
}

int main()
{
}