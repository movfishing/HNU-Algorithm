#include <iostream>
#include <string>

using namespace std;

int cnm(int n, int m)
{ // n个数里选m个
    int sum = 1;
    for (int i = 0; i < m; i++)
    {
        sum *= (n - i) / (i + 1);
    }
    return sum;
}

int lensum1(string s)
{
    int sum = 0;
    int len = s.length();
    int ch = 'a';
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < s[i] - ch; j++)
        {
            sum += cnm('z' - ch - j, len - i - 1);
        }
        ch = s[i] + 1;
    }
    return sum;
}

int main()
{
    int ans = 0;
    int innum = 0;
    cin >> innum;
    string s;
    while ((innum--) && cin >> s)
    {
        int sumabove = 1;
        int len = s.length();
        for (int i = 1; i < len; i++)
            sumabove += cnm(26, i);
        ans = lensum1(s) + sumabove;
        cout << ans << endl;
    }
    system("pause");
}
