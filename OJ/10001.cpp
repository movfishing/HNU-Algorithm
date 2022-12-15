#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <fstream>

using namespace std;

int arr_len;
int num;

int maxOrder(vector<int> &arr)
{
    vector<int> tail(arr.size(), 0);
    tail[0] = arr[0];
    int end = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > tail[end])
        {
            tail[++end] = arr[i];
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
        }
    }
    return end + 1;
}

int main()
{
    vector<int> arr;
    cin >> arr_len;
    for (int i = 0; i < arr_len; i++)
    {
        cin >> num;
        arr.push_back(num);
    }
    cout << maxOrder(arr) << endl;
    return 0;
}