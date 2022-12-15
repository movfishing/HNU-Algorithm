#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int maxmerge(int a[], int n)
{
    sort(a, a + n, cmp);
    int sum = 0, temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp += a[i];
        sum += temp - 1;
    }
    return sum;
}

int minmerge(int a[], int n)
{
    sort(a, a + n);
    int sum = 0, temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp += a[i];
        sum += temp - 1;
    }
    return sum;
}