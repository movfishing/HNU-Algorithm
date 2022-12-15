#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <fstream>

using namespace std;

vector<int> maxOrder(vector<int> &arr)
{
    vector<int> tail(arr.size(), 0);
    vector<int> sign(arr.size(), 0);
    vector<int> update(arr.size(), 0);
    tail[0] = arr[0];
    sign[0] = 0;
    int end = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > tail[end])
        {
            if (update[end] == 1)
            {
                for (int j = end; j >= 0; j--)
                {
                    if (update[j])
                    {
                        sign[j] = tail[j];
                        update[j] = 0;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            tail[++end] = arr[i];
            sign[end] = arr[i];
        }
        else
        { //找到tail中比arr[i]小的最大的数
            int left = 0;
            int right = end;
            while (left < right)
            {
                int mid = left + ((right - left) >> 1);
                if (tail[mid] < arr[i])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }
            tail[left] = arr[i];
            update[left] = 1;
        }
    }
    return sign;
}

int main()
{
    ifstream examples("D:/VS Code C++ works/AlgorithmHomeworks/Exp2/examples.txt");
    ofstream in("D:/VS Code C++ works/AlgorithmHomeworks/Exp2/Q4ans.txt", ios::trunc);
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
        int arr_len;
        examples >> arr_len;
        vector<int> arr(arr_len, 0);
        for (int i = 0; i < arr_len; i++)
        {
            examples >> arr[i];
        }
        vector<int> ans = maxOrder(arr);
        int ans_len = 1;
        for (int i = 1; i < ans.size(); i++)
        {
            if (ans[i] == 0)
                break;
            ans_len++;
        }
        in << "Group " << groupslen - groups << " length = " << ans_len << endl;
        in << "Order: ";
        for (int i = 0; i < ans_len; i++)
        {
            in << ans[i] << " ";
        }
        in << endl;
    }

    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    printf("%d groups, time cost: %f\n", groupslen, time);

    examples.close();
    system("pause");
    return 0;
}