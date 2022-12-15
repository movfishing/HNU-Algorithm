#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int group;
int arr_len;
int num;
vector<int> temp;

long long maxNum(vector<vector<int>> &arr)
{
    vector<long long> init(arr_len, 0);
    vector<vector<long long>> ans(arr_len, init);
    for (int i = 0; i < arr_len; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == 0)
                ans[i][j] = arr[i][j];
            else if (j == 0)
            {
                ans[i][j] = ans[i - 1][j] + arr[i][j];
            }
            else if (i == j)
            {
                ans[i][j] = ans[i - 1][j - 1] + arr[i][j];
            }
            else
            {
                ans[i][j] = max(ans[i - 1][j - 1] + arr[i][j], ans[i - 1][j] + arr[i][j]);
            }
        }
    }
    long long maxnum = 0;
    for (int i = 0; i < arr_len; i++)
    {
        if (ans[arr_len - 1][i] > maxnum)
            maxnum = ans[arr_len - 1][i];
    }
    return maxnum;
}

int main()
{
    cin >> group;
    while (group--)
    {
        vector<vector<int>> arr;
        cin >> arr_len;
        for (int i = 0; i < arr_len; i++)
        {
            arr.push_back(temp);
            for (int j = 0; j <= i; j++)
            {
                cin >> num;
                arr[i].push_back(num);
            }
        }
        cout << maxNum(arr) << endl;
    }
    return 0;
}