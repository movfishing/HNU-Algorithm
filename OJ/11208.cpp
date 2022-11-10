#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#define mod 10000
#define ll long long
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;
const ll N = 2;
int f[50] = {0, 1, 1};
struct Matrix
{
    ll a[N][N];
    Matrix()
    {
        mem(a, 0);
    }
    void init()
    {
        mem(a, 0);
        for (ll i = 0; i < N; i++)
            a[i][i] = 1;
    }
};
void print(Matrix a)
{
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
            printf("%d ", a.a[i][j]);
        puts("");
    }
}
Matrix mul(Matrix a, Matrix b)
{
    Matrix ans;
    for (ll i = 0; i < N; i++)
        for (ll j = 0; j < N; j++)
            for (ll k = 0; k < N; k++)
            {
                ans.a[i][j] += a.a[i][k] * b.a[k][j];
                ans.a[i][j] %= mod;
            }
    return ans;
}
Matrix mat_pow(Matrix a, ll n)
{
    Matrix ans;
    ans.init();
    while (n)
    {
        if (n & 1)
            ans = mul(ans, a);
        a = mul(a, a);
        n >>= 1;
    }
    return ans;
}

ll n;

int main()
{
    for (int i = 3; i <= 40; i++)
        f[i] = f[i - 1] + f[i - 2];

    while (~scanf("%lld", &n))
    {
        if (n < 40)
        {
            printf("%d\n", f[n]);
        }
        else
        {
            double cnt = (1.0 + sqrt(5.0)) / 2;
            double x = -0.5 * log10(5.0) + n * log10(cnt);
            x = x - int(x); //取小数部分
            x = pow(10.0, x);
            x = floor(x * 1000); //前四位
            Matrix A;
            A.a[0][0] = A.a[0][1] = A.a[1][0] = 1;
            Matrix ans = mat_pow(A, n);
            printf("%d...%04lld\n", (int)x, ans.a[0][1]);
        }
    }
    return 0;
}
