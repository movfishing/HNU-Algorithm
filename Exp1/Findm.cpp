#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <fstream>

using namespace std;

vector<int> ans(2, 0);

void findm(vector<int> &nums, int left, int right)
{
    if (!(right - left) || right - left == 1) //当仅有1个或两个元素时
    {
        if (nums[right] > nums[left])
        {
            if (nums[right] > ans[1])
                ans[1] = nums[right];
            if (nums[left] < ans[0])
                ans[0] = nums[left];
        }
        else
        {
            if (nums[left] > ans[1])
                ans[1] = nums[left];
            if (nums[right] < ans[0])
                ans[0] = nums[right];
        }
    }
    else
    {
        int mid = (left + right) >> 1;
        findm(nums, left, mid);
        findm(nums, mid + 1, right); //二分，递归
    }
}

int main()
{
    ifstream examples("D:/VS Code C++ works/AlgorithmHomeworks/Exp1/examples.txt");
    ofstream in("D:/VS Code C++ works/AlgorithmHomeworks/Exp1/Q1ans.txt", ios::trunc);
    if (!examples.is_open())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
    vector<int> nums;
    int num;
    int groups;
    int numslen;
    examples >> groups;
    int groupslen = groups;

    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime); //采用QueryPerformanceFrequency进行精确计时

    while (groups--)
    {
        examples >> numslen;

        for (int i = 0; i < numslen; i++)
        {
            examples >> num;
            if (i >= nums.size())
                nums.push_back(num);
            else
                nums[i] = num;
        } //读取测试用例文件

        ans[0] = nums[0];

        if (numslen == 1)
            ans[1] = nums[0];

        ans[1] = nums[1];

        findm(nums, 0, numslen - 1);

        in << "the max num is" << ans[1] << endl;
        in << "the min num is" << ans[0] << endl;
        in << endl;
    }

    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    printf("%d groups, time cost: %f\n", groupslen, time);

    examples.close();
    system("pause");
    return 0;
}