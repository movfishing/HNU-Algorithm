#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <fstream>

using namespace std;

void MergeCtrl(vector<int> *from, vector<int> *to, int left, int mid, int right)
{
    int l = left;
    int r = mid + 1;
    int n = l;
    while (l <= mid && r <= right)
    {
        if ((*from)[l] > (*from)[r])
        {
            (*to)[n] = (*from)[r];
            n++;
            r++;
        }
        else
        {
            (*to)[n] = (*from)[l];
            n++;
            l++;
        }
    }
    if (l > mid)
    {
        while (r <= right)
        {
            (*to)[n] = (*from)[r];
            n++;
            r++;
        }
    }
    else
    {
        while (l <= mid)
        {
            (*to)[n] = (*from)[l];
            n++;
            l++;
        }
    }
}

void Merge(vector<int> *from, vector<int> *to, int s)
{
    int len = (*from).size();
    int i = 0;
    while (i <= len - (s << 1))
    {
        MergeCtrl(from, to, i, i + s - 1, i + (s << 1) - 1);
        i += (s << 1);
    }
    if (i < len - s)
    {
        MergeCtrl(from, to, i, i + s - 1, len - 1);
    }
    else
    {
        for (int j = i; j < len; j++)
        {
            (*to)[j] = (*from)[j];
        }
    }
}

vector<int> Hsort(vector<int> &a)
{
    int s = 1;
    vector<int> b(a);
    while (s < a.size())
    {
        Merge(&a, &b, s);
        s = s << 1;
        Merge(&b, &a, s);
        s = s << 1;
    }
    return a;
}

int main()
{
    ifstream examples("D:/VS Code C++ works/AlgorithmHomeworks/Exp1/examples.txt");
    ofstream in("D:/VS Code C++ works/AlgorithmHomeworks/Exp1/Q2ans.txt", ios::trunc);
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

        vector<int> ans = Hsort(nums);

        for (auto i : ans)
        {
            in << i << " ";
        }
        in << "\n"
           << endl;
    }

    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    printf("\n%d groups, time cost: %f\n", groupslen, time);

    examples.close();
    system("pause");
    return 0;
}