#include <iostream>

using namespace std;

int div(int n)
{
    if (n == 1)
        return 1;
    n /= 2;
    int answer = 1;
    for (int i = 1; i <= n; i++)
    {
        answer += div(i);
    }
    return answer;
}

int main()
{
    int n;
    cin >> n;
    int count = div(n);
    cout << count << endl;
    system("pause");
}