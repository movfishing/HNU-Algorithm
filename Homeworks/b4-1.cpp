#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct event
{
    int time;
    bool status; //标识是开始时间还是结束时间
};

bool cmp(event a, event b)
{
    return a.time > b.time;
}

int manage(vector<event> &a)
{
    sort(a.begin(), a.end(), cmp);
    int sum = 0, temp = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].status)
            temp++; //若为开始时间，则会场数+1
        else
            temp--; //若为结束时间，则回收会场，会场数-1
        if ((i == a.size() - 1 || a[i].time < a[i + 1].time) && sum < temp)
            sum = temp; //当需要新增会场时，才更新结果值
    }
    return sum;
}

int main()
{
}