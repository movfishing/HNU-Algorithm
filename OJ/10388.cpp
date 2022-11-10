#include <iostream>

using namespace std;

int len, m;
long long A, B;

long long quick_pow(long long a, long long b, int m)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

int main()
{
    long long ans = 0;
    scanf("%d %d", &m, &len);
    for (int i = 0; i < len; i++)
    {
        scanf("%lld %lld", &A, &B);
        ans = (ans + quick_pow(A, B, m)) % m;
    }
    printf("%lld\n", ans);
    return 0;
}
